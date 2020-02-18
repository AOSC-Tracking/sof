// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2016 Intel Corporation. All rights reserved.
//
// Author: Liam Girdwood <liam.r.girdwood@linux.intel.com>

#include <sof/audio/component.h>
#include <sof/common.h>
#include <sof/debug/panic.h>
#include <sof/drivers/interrupt.h>
#include <sof/drivers/ipc.h>
#include <sof/lib/alloc.h>
#include <sof/lib/memory.h>
#include <sof/list.h>
#include <sof/sof.h>
#include <sof/string.h>
#include <ipc/topology.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>

static SHARED_DATA struct comp_driver_list cd;

static const struct comp_driver *get_drv(uint32_t type)
{
	struct comp_driver_list *drivers = comp_drivers_get();
	struct list_item *clist;
	const struct comp_driver *drv = NULL;
	struct comp_driver_info *info;
	uint32_t flags;

	irq_local_disable(flags);

	/* search driver list for driver type */
	list_for_item(clist, &drivers->list) {
		info = container_of(clist, struct comp_driver_info, list);
		if (info->drv->type == type) {
			drv = info->drv;
			platform_shared_commit(info, sizeof(*info));
			goto out;
		}

		platform_shared_commit(info, sizeof(*info));
	}

out:
	platform_shared_commit(drivers, sizeof(*drivers));
	irq_local_enable(flags);
	return drv;
}

struct comp_dev *comp_new(struct sof_ipc_comp *comp)
{
	struct comp_dev *cdev;
	const struct comp_driver *drv;

	/* find the driver for our new component */
	drv = get_drv(comp->type);
	if (!drv) {
		trace_error(TRACE_CLASS_COMP, "comp_new() error: driver not found, comp->type = %u",
			    comp->type);
		return NULL;
	}

	/* validate size of ipc config */
	if (IPC_IS_SIZE_INVALID(*COMP_IPC_GET_CONFIG(comp))) {
		IPC_SIZE_ERROR_TRACE(TRACE_CLASS_COMP,
				     *COMP_IPC_GET_CONFIG(comp));
		return NULL;
	}

	/* create the new component */
	cdev = drv->ops.new(comp);
	if (!cdev) {
		comp_cl_err(drv, "comp_new() error: unable to create the new component");
		return NULL;
	}

	cdev->drv = drv;
	list_init(&cdev->bsource_list);
	list_init(&cdev->bsink_list);

	return cdev;
}

int comp_register(struct comp_driver_info *drv)
{
	struct comp_driver_list *drivers = comp_drivers_get();
	uint32_t flags;

	irq_local_disable(flags);
	list_item_prepend(&drv->list, &drivers->list);
	platform_shared_commit(drv, sizeof(*drv));
	platform_shared_commit(drivers, sizeof(*drivers));
	irq_local_enable(flags);

	return 0;
}

void comp_unregister(struct comp_driver_info *drv)
{
	uint32_t flags;

	irq_local_disable(flags);
	list_item_del(&drv->list);
	platform_shared_commit(drv, sizeof(*drv));
	irq_local_enable(flags);
}

int comp_set_state(struct comp_dev *dev, int cmd)
{
	int requested_state = comp_get_requested_state(cmd);
	int ret = 0;

	if (dev->state == requested_state) {
		comp_info(dev, "comp_set_state(), state already set to %u",
			  dev->state);
		return COMP_STATUS_STATE_ALREADY_SET;
	}

	switch (cmd) {
	case COMP_TRIGGER_START:
		if (dev->state == COMP_STATE_PREPARE) {
			dev->state = COMP_STATE_ACTIVE;
		} else {
			comp_err(dev, "comp_set_state() error: wrong state = %u, COMP_TRIGGER_START",
				 dev->state);
			ret = -EINVAL;
		}
		break;
	case COMP_TRIGGER_RELEASE:
		if (dev->state == COMP_STATE_PAUSED) {
			dev->state = COMP_STATE_ACTIVE;
		} else {
			comp_err(dev, "comp_set_state() error: wrong state = %u, COMP_TRIGGER_RELEASE",
				 dev->state);
			ret = -EINVAL;
		}
		break;
	case COMP_TRIGGER_STOP:
		if (dev->state == COMP_STATE_ACTIVE ||
		    dev->state == COMP_STATE_PAUSED) {
			dev->state = COMP_STATE_PREPARE;
		} else {
			comp_err(dev, "comp_set_state() error: wrong state = %u, COMP_TRIGGER_STOP",
				 dev->state);
			ret = -EINVAL;
		}
		break;
	case COMP_TRIGGER_XRUN:
		/* reset component status to ready at xrun */
		dev->state = COMP_STATE_READY;
		break;
	case COMP_TRIGGER_PAUSE:
		/* only support pausing for running */
		if (dev->state == COMP_STATE_ACTIVE) {
			dev->state = COMP_STATE_PAUSED;
		} else {
			comp_err(dev, "comp_set_state() error: wrong state = %u, COMP_TRIGGER_PAUSE",
				 dev->state);
			ret = -EINVAL;
		}
		break;
	case COMP_TRIGGER_RESET:
		/* reset always succeeds */
		if (dev->state == COMP_STATE_ACTIVE ||
		    dev->state == COMP_STATE_PAUSED) {
			comp_err(dev, "comp_set_state() error: wrong state = %u, COMP_TRIGGER_RESET",
				 dev->state);
			ret = 0;
		}
		dev->state = COMP_STATE_READY;
		break;
	case COMP_TRIGGER_PREPARE:
		if (dev->state == COMP_STATE_READY) {
			dev->state = COMP_STATE_PREPARE;
		} else {
			comp_err(dev, "comp_set_state() error: wrong state = %u, COMP_TRIGGER_PREPARE",
				 dev->state);
			ret = -EINVAL;
		}
		break;
	default:
		break;
	}

	return ret;
}

void sys_comp_init(struct sof *sof)
{
	sof->comp_drivers = platform_shared_get(&cd, sizeof(cd));

	list_init(&sof->comp_drivers->list);

	platform_shared_commit(sof->comp_drivers, sizeof(*sof->comp_drivers));
}

int comp_get_copy_limits(struct comp_dev *dev, struct comp_copy_limits *cl)
{
	/* Get source and sink buffer addresses */
	cl->source = list_first_item(&dev->bsource_list, struct comp_buffer,
				     sink_list);
	cl->sink = list_first_item(&dev->bsink_list, struct comp_buffer,
				   source_list);

	cl->frames = audio_stream_avail_frames(&cl->source->stream,
					       &cl->sink->stream);
	cl->source_frame_bytes = audio_stream_frame_bytes(&cl->source->stream);
	cl->sink_frame_bytes = audio_stream_frame_bytes(&cl->sink->stream);
	cl->source_bytes = cl->frames * cl->source_frame_bytes;
	cl->sink_bytes = cl->frames * cl->sink_frame_bytes;

	return 0;
}

/* Function overwrites PCM parameters (frame_fmt, buffer_fmt, channels, rate)
 * with buffer parameters when specific flag is set.
 */
static void comp_update_params(uint32_t flag,
			       struct sof_ipc_stream_params *params,
			       struct comp_buffer *buffer)
{
	if (flag & BUFF_PARAMS_FRAME_FMT)
		params->frame_fmt = buffer->stream.frame_fmt;

	if (flag & BUFF_PARAMS_BUFFER_FMT)
		params->buffer_fmt = buffer->buffer_fmt;

	if (flag & BUFF_PARAMS_CHANNELS)
		params->channels = buffer->stream.channels;

	if (flag & BUFF_PARAMS_RATE)
		params->rate = buffer->stream.rate;
}

int comp_verify_params(struct comp_dev *dev, uint32_t flag,
		       struct sof_ipc_stream_params *params)
{
	struct list_item *buffer_list;
	struct list_item *source_list;
	struct list_item *sink_list;
	struct list_item *clist;
	struct comp_buffer *sinkb;
	struct comp_buffer *buf;
	int dir = dev->direction;

	if (!params) {
		comp_err(dev, "comp_verify_params() error: !params");
		return -EINVAL;
	}

	source_list = comp_buffer_list(dev, PPL_DIR_UPSTREAM);
	sink_list = comp_buffer_list(dev, PPL_DIR_DOWNSTREAM);

	/* searching for endpoint component e.g. HOST, DETECT_TEST, which
	 * has only one sink or one source buffer.
	 */
	if (list_is_empty(source_list) != list_is_empty(sink_list)) {
		if (!list_is_empty(source_list))
			buf = list_first_item(&dev->bsource_list,
					      struct comp_buffer,
					      sink_list);
		else
			buf = list_first_item(&dev->bsink_list,
					      struct comp_buffer,
					      source_list);

		/* update specific pcm parameter with buffer parameter if
		 * specific flag is set.
		 */
		comp_update_params(flag, params, buf);

		/* overwrite buffer parameters with modified pcm
		 * parameters
		 */
		buffer_set_params(buf, params, BUFFER_UPDATE_FORCE);

		/* set component period frames */
		component_set_period_frames(dev, buf->stream.rate);
	} else {
		/* for other components we iterate over all downstream buffers
		 * (for playback) or upstream buffers (for capture).
		 */
		buffer_list = comp_buffer_list(dev, dir);

		list_for_item(clist, buffer_list) {
			buf = buffer_from_list(clist, struct comp_buffer,
					       dir);

			comp_update_params(flag, params, buf);

			buffer_set_params(buf, params, BUFFER_UPDATE_FORCE);
		}

		/* fetch sink buffer in order to calculate period frames */
		sinkb = list_first_item(&dev->bsink_list, struct comp_buffer,
					source_list);

		component_set_period_frames(dev, sinkb->stream.rate);
	}

	return 0;
}
