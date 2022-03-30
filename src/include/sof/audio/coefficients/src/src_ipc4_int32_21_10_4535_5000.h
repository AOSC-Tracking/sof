/* SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright(c) 2022 Intel Corporation. All rights reserved.
 *
 */

#include <sof/audio/src/src.h>
#include <stdint.h>

const int32_t src_int32_21_10_4535_5000_fir[2016] = {
	-75860,
	100387,
	-116374,
	117003,
	-94254,
	39176,
	57721,
	-205943,
	414365,
	-690488,
	1039604,
	-1463929,
	1961722,
	-2526444,
	3146013,
	-3802200,
	4470216,
	-5118541,
	5709032,
	-6197345,
	6533681,
	-6663866,
	6530754,
	-6075916,
	5241589,
	-3972795,
	2219586,
	60693,
	-2901214,
	6323644,
	-10336404,
	14933298,
	-20092628,
	25776860,
	-31932954,
	38493414,
	-45378175,
	52497449,
	-59755756,
	67057585,
	-74315614,
	81463530,
	-88478435,
	95425883,
	-102567267,
	110676210,
	-122305054,
	150816665,
	2045961926,
	49768785,
	-73550033,
	80073533,
	-81542017,
	80498020,
	-77856684,
	74074301,
	-69440647,
	64174573,
	-58460158,
	52461181,
	-46326622,
	40192202,
	-34180126,
	28398136,
	-22938415,
	17876677,
	-13271595,
	9164683,
	-5580647,
	2528201,
	-1318,
	-2019151,
	3563572,
	-4671408,
	5388996,
	-5767292,
	5859685,
	-5719952,
	5400423,
	-4950399,
	4414878,
	-3833592,
	3240369,
	-2662811,
	2122259,
	-1634026,
	1207839,
	-848453,
	556384,
	-328721,
	159951,
	-42768,
	-31168,
	70564,
	-83929,
	79128,
	-87643,
	120346,
	-147457,
	162368,
	-157059,
	122307,
	-48013,
	-76319,
	260982,
	-515335,
	846976,
	-1260840,
	1758265,
	-2336065,
	2985661,
	-3692334,
	4434627,
	-5183981,
	5904620,
	-6553749,
	7082066,
	-7434625,
	7552032,
	-7371958,
	6830939,
	-5866403,
	4418846,
	-2434091,
	-134488,
	3323881,
	-7159607,
	11654266,
	-16806597,
	22601198,
	-29009063,
	35989136,
	-43491184,
	51460424,
	-59844717,
	68605813,
	-77737703,
	87298676,
	-97472743,
	108701619,
	-122012627,
	140010685,
	-170945113,
	259032485,
	2032096068,
	-43239531,
	-25600275,
	48840761,
	-59392284,
	64249276,
	-65848524,
	65303289,
	-63231146,
	60032058,
	-55998646,
	51364691,
	-46327744,
	41059813,
	-35712251,
	30417744,
	-25290901,
	20428271,
	-15908247,
	11791123,
	-8119453,
	4918767,
	-2198676,
	-45671,
	1831835,
	-3188085,
	4151256,
	-4764531,
	5075236,
	-5132735,
	4986483,
	-4684312,
	4270971,
	-3786981,
	3267785,
	-2743225,
	2237303,
	-1768231,
	1348696,
	-986341,
	684377,
	-442303,
	256676,
	-121886,
	30904,
	24033,
	-50833,
	57058,
	-98093,
	138525,
	-176474,
	205673,
	-218263,
	204920,
	-155133,
	57605,
	99185,
	-326293,
	633498,
	-1028388,
	1515386,
	-2094756,
	2761633,
	-3505130,
	4307589,
	-5144008,
	5981718,
	-6780342,
	7492072,
	-8062287,
	8430520,
	-8531769,
	8298107,
	-7660568,
	6551229,
	-4905403,
	2663855,
	225091,
	-3803664,
	8103149,
	-13142927,
	18930253,
	-25461013,
	32721785,
	-40693686,
	49358778,
	-58710429,
	68770193,
	-79616481,
	91436351,
	-104627350,
	120020565,
	-139442960,
	167443014,
	-218508923,
	373424142,
	2004533704,
	-127467126,
	20678623,
	17608209,
	-36584493,
	47030458,
	-52718497,
	55347840,
	-55830613,
	54729700,
	-52434940,
	49242289,
	-45391978,
	41087622,
	-36505854,
	31801059,
	-27107548,
	22540449,
	-18196049,
	14152006,
	-10467695,
	7184801,
	-4328253,
	1907476,
	82029,
	-1656863,
	2843696,
	-3677136,
	4197552,
	-4448946,
	4476942,
	-4326959,
	4042617,
	-3664411,
	3228686,
	-2766910,
	2305249,
	-1864421,
	1459797,
	-1101727,
	796020,
	-544572,
	346052,
	-196635,
	90724,
	-21637,
	-17789,
	34667,
	-106920,
	154464,
	-202739,
	245948,
	-276541,
	285283,
	-261444,
	193145,
	-67846,
	-127008,
	403206,
	-770869,
	1237451,
	-1806698,
	2477590,
	-3243334,
	4090454,
	-4998043,
	5937219,
	-6870857,
	7753614,
	-8532297,
	9146577,
	-9530064,
	9611707,
	-9317494,
	8572392,
	-7302442,
	5436910,
	-2910383,
	-335341,
	4349736,
	-9172589,
	14833862,
	-21354667,
	28749817,
	-37032618,
	46223010,
	-56361020,
	67529222,
	-79891655,
	93765435,
	-109763550,
	129111274,
	-154452478,
	192355624,
	-264008719,
	492891020,
	1963611072,
	-202311195,
	64488010,
	-13013094,
	-13586822,
	29204662,
	-38749014,
	44426031,
	-47404492,
	48389220,
	-47854204,
	46148581,
	-43548562,
	40284063,
	-36552631,
	32526677,
	-28357094,
	24174958,
	-20092264,
	16202272,
	-12579810,
	9281734,
	-6347653,
	3800967,
	-1650218,
	-109283,
	1493592,
	-2528121,
	3245531,
	-3683631,
	3883340,
	-3886784,
	3735594,
	-3469441,
	3124842,
	-2734255,
	2325471,
	-1921281,
	1539412,
	-1192684,
	889368,
	-633687,
	426427,
	-265598,
	147130,
	-65535,
	14527,
	12432,
	-113852,
	167737,
	-225608,
	282257,
	-330599,
	361665,
	-364720,
	327525,
	-236757,
	78594,
	160555,
	-493169,
	929621,
	-1477097,
	2138486,
	-2911262,
	3786444,
	-4747673,
	5770472,
	-6821739,
	7859532,
	-8833164,
	9683664,
	-10344581,
	10743153,
	-10801781,
	10439793,
	-9575390,
	8127698,
	-6018804,
	3175608,
	468667,
	-4973555,
	10391288,
	-16767995,
	24146713,
	-32573070,
	42105069,
	-52829498,
	64889750,
	-78534718,
	94209821,
	-112740382,
	135741621,
	-166673462,
	214159567,
	-306445665,
	616237758,
	1909826405,
	-267312968,
	105107083,
	-42442240,
	9139880,
	11139899,
	-24234448,
	32772006,
	-38136550,
	41151679,
	-42361075,
	42157146,
	-40844735,
	38674274,
	-35859464,
	32586715,
	-29020067,
	25303599,
	-21562518,
	17903611,
	-14415488,
	11168883,
	-8217162,
	5597108,
	-3330026,
	1423136,
	128771,
	-1341476,
	2239348,
	-2853303,
	3218776,
	-3373796,
	3357197,
	-3207046,
	2959309,
	-2646784,
	2298321,
	-1938317,
	1586478,
	-1257819,
	962883,
	-708112,
	496366,
	-327511,
	199061,
	-106815,
	45473,
	-9191,
	-118651,
	177957,
	-244484,
	313721,
	-379194,
	432380,
	-462748,
	457935,
	-404091,
	286382,
	-89666,
	-200675,
	597754,
	-1112097,
	1750480,
	-2514738,
	3400609,
	-4396653,
	5483328,
	-6632257,
	7805768,
	-8956728,
	10028718,
	-10956573,
	11667274,
	-12081184,
	12113585,
	-11676445,
	10680331,
	-9036330,
	6657842,
	-3462036,
	-629279,
	5689694,
	-11789603,
	18999638,
	-27397160,
	37077553,
	-48173379,
	60887214,
	-75549977,
	92730507,
	-113458130,
	139724248,
	-175784441,
	232306582,
	-344825825,
	742189634,
	1843832692,
	-322161122,
	141902224,
	-70138440,
	31150847,
	-6798230,
	-9475097,
	20631067,
	-28224954,
	33174402,
	-36077326,
	37358831,
	-37344589,
	36299414,
	-34448115,
	31986831,
	-29089060,
	25908695,
	-22581407,
	19225169,
	-15940431,
	12810243,
	-9900523,
	7260585,
	-4923961,
	2909535,
	-1222962,
	-141675,
	1200036,
	-1975584,
	2497619,
	-2799349,
	2916067,
	-2883499,
	2736351,
	-2507111,
	2225109,
	-1915851,
	1600614,
	-1296292,
	1015463,
	-766642,
	554682,
	-381285,
	245576,
	-144708,
	74456,
	-29776,
	-121115,
	184791,
	-258838,
	339541,
	-421170,
	495821,
	-553375,
	581591,
	-566356,
	492106,
	-342428,
	100836,
	248299,
	-718664,
	1320828,
	-2060995,
	2939752,
	-3950856,
	5080134,
	-6304549,
	7591494,
	-8898367,
	10172464,
	-11351231,
	12362869,
	-13127301,
	13557456,
	-13560820,
	13041162,
	-11900316,
	10039870,
	-7362535,
	3772953,
	822449,
	-6517046,
	13407817,
	-21602551,
	31232468,
	-42473823,
	55585291,
	-70974933,
	89326958,
	-111861070,
	140921238,
	-181517678,
	246300759,
	-378176441,
	869409332,
	1766428201,
	-366692910,
	174334639,
	-95610026,
	52025635,
	-24253686,
	5228872,
	8254615,
	-17878102,
	24627609,
	-29139208,
	31859729,
	-33127591,
	33215657,
	-32354637,
	30745968,
	-28568757,
	25983345,
	-23132920,
	20144096,
	-17126989,
	14175158,
	-11365632,
	8759151,
	-6400694,
	4320335,
	-2534387,
	1046831,
	149042,
	-1068842,
	1735201,
	-2175893,
	2422001,
	-2506223,
	2461332,
	-2318868,
	2108058,
	-1855002,
	1582114,
	-1307816,
	1046453,
	-808421,
	600450,
	-426021,
	285869,
	-178538,
	100947,
	-48933,
	-121086,
	187968,
	-268222,
	359012,
	-455476,
	550491,
	-634556,
	695791,
	-720096,
	691478,
	-592563,
	405299,
	-111830,
	-304456,
	857749,
	-1558544,
	2412310,
	-3418176,
	4567674,
	-5843616,
	7219161,
	-8657136,
	10109645,
	-11518032,
	12813182,
	-13916200,
	14739417,
	-15187690,
	15159911,
	-14550612,
	13251513,
	-11152784,
	8143763,
	-4112715,
	-1054922,
	7480637,
	-15300637,
	24679580,
	-35834269,
	49074976,
	-64879990,
	84037730,
	-107939367,
	139247895,
	-183665789,
	255709576,
	-405562267,
	996514845,
	1678544925,
	-400893012,
	201966219,
	-118422315,
	71375736,
	-40886817,
	19583386,
	-4104964,
	-7310311,
	15690838,
	-21694545,
	25778866,
	-28286809,
	29492901,
	-29628497,
	28895836,
	-27475716,
	25531451,
	-23210674,
	20645929,
	-17954647,
	15238895,
	-12585149,
	10064247,
	-7731617,
	5627820,
	-3779411,
	2200110,
	-892210,
	-151800,
	947494,
	-1516705,
	1885733,
	-2083625,
	2140595,
	-2086618,
	1950244,
	-1757649,
	1531931,
	-1292660,
	1055651,
	-832954,
	633023,
	-461029,
	319284,
	-207733,
	124481,
	-66321,
	-118455,
	187285,
	-272277,
	371546,
	-481198,
	595045,
	-704397,
	797974,
	-861967,
	880265,
	-834866,
	706492,
	-475390,
	122324,
	370273,
	-1017018,
	1828204,
	-2808399,
	3955063,
	-5257256,
	6694494,
	-8235826,
	9839177,
	-11451001,
	13006295,
	-14428956,
	15632497,
	-16521070,
	16990727,
	-16930815,
	16225353,
	-14754165,
	12393491,
	-9015654,
	4487179,
	1335530,
	-8614422,
	17544387,
	-28378609,
	41473089,
	-57367504,
	76940309,
	-101730107,
	134675553,
	-182087363,
	260174100,
	-426101671,
	1122098254,
	1581235120,
	-424890162,
	224463548,
	-138204223,
	88851397,
	-56380739,
	33306204,
	-16199348,
	3262559,
	6549222,
	-13899611,
	19245654,
	-22926889,
	25213211,
	-26331429,
	26480140,
	-25837910,
	24567529,
	-22817934,
	20724794,
	-18410371,
	15983077,
	-13536995,
	11151543,
	-8891390,
	6806679,
	-4933591,
	3295222,
	-1902751,
	756841,
	150776,
	-835613,
	1318706,
	-1624914,
	1781316,
	-1815747,
	1755525,
	-1626383,
	1451645,
	-1251632,
	1043301,
	-840105,
	652035,
	-485833,
	345322,
	-231832,
	144675,
	-81646,
	-113166,
	182615,
	-270751,
	376682,
	-497578,
	628316,
	-761199,
	885776,
	-988806,
	1054373,
	-1064201,
	998154,
	-834952,
	553090,
	-131939,
	-446990,
	1198654,
	-2133022,
	3253588,
	-4555935,
	6026408,
	-7640955,
	9364218,
	-11148891,
	12935429,
	-14652094,
	16215352,
	-17530603,
	18493172,
	-18989463,
	18898140,
	-18091110,
	16434019,
	-13785831,
	9996866,
	-4904339,
	-1676146,
	9965750,
	-20248917,
	32920249,
	-48570160,
	68150160,
	-93317392,
	127233340,
	-176711434,
	259418148,
	-438982255,
	1244745080,
	1475656159,
	-438951633,
	241600042,
	-154653526,
	104147564,
	-70447154,
	46132330,
	-27789181,
	13627446,
	-2610306,
	-5915895,
	12397172,
	-17161818,
	20469031,
	-22536069,
	23553571,
	-23694047,
	23116308,
	-21967458,
	20383443,
	-18488793,
	16395992,
	-14204750,
	12001384,
	-9858418,
	7834492,
	-5974603,
	4310682,
	-2862490,
	1638784,
	-638701,
	-146704,
	732831,
	-1139898,
	1391345,
	-1512341,
	1528440,
	-1464437,
	1343417,
	-1186047,
	1010082,
	-830097,
	657409,
	-500180,
	363651,
	-250493,
	161225,
	-94671,
	-105218,
	173915,
	-263498,
	374104,
	-504035,
	649346,
	-803497,
	957083,
	-1097698,
	1209941,
	-1275615,
	1274118,
	-1183051,
	979041,
	-638779,
	140233,
	535967,
	-1405040,
	2476503,
	-3752610,
	5226869,
	-6882674,
	8692153,
	-10615251,
	12599135,
	-14577921,
	16472758,
	-18192239,
	19633105,
	-20681138,
	21212128,
	-21092678,
	20180589,
	-18324365,
	15361208,
	-11112519,
	5375308,
	2093216,
	-11602784,
	23578328,
	-38648723,
	57819003,
	-82831510,
	117008832,
	-167540722,
	253256221,
	-443475704,
	1363053937,
	1363053937,
	-443475704,
	253256221,
	-167540722,
	117008832,
	-82831510,
	57819003,
	-38648723,
	23578328,
	-11602784,
	2093216,
	5375308,
	-11112519,
	15361208,
	-18324365,
	20180589,
	-21092678,
	21212128,
	-20681138,
	19633105,
	-18192239,
	16472758,
	-14577921,
	12599135,
	-10615251,
	8692153,
	-6882674,
	5226869,
	-3752610,
	2476503,
	-1405040,
	535967,
	140233,
	-638779,
	979041,
	-1183051,
	1274118,
	-1275615,
	1209941,
	-1097698,
	957083,
	-803497,
	649346,
	-504035,
	374104,
	-263498,
	173915,
	-105218,
	-94671,
	161225,
	-250493,
	363651,
	-500180,
	657409,
	-830097,
	1010082,
	-1186047,
	1343417,
	-1464437,
	1528440,
	-1512341,
	1391345,
	-1139898,
	732831,
	-146704,
	-638701,
	1638784,
	-2862490,
	4310682,
	-5974603,
	7834492,
	-9858418,
	12001384,
	-14204750,
	16395992,
	-18488793,
	20383443,
	-21967458,
	23116308,
	-23694047,
	23553571,
	-22536069,
	20469031,
	-17161818,
	12397172,
	-5915895,
	-2610306,
	13627446,
	-27789181,
	46132330,
	-70447154,
	104147564,
	-154653526,
	241600042,
	-438951633,
	1475656159,
	1244745080,
	-438982255,
	259418148,
	-176711434,
	127233340,
	-93317392,
	68150160,
	-48570160,
	32920249,
	-20248917,
	9965750,
	-1676146,
	-4904339,
	9996866,
	-13785831,
	16434019,
	-18091110,
	18898140,
	-18989463,
	18493172,
	-17530603,
	16215352,
	-14652094,
	12935429,
	-11148891,
	9364218,
	-7640955,
	6026408,
	-4555935,
	3253588,
	-2133022,
	1198654,
	-446990,
	-131939,
	553090,
	-834952,
	998154,
	-1064201,
	1054373,
	-988806,
	885776,
	-761199,
	628316,
	-497578,
	376682,
	-270751,
	182615,
	-113166,
	-81646,
	144675,
	-231832,
	345322,
	-485833,
	652035,
	-840105,
	1043301,
	-1251632,
	1451645,
	-1626383,
	1755525,
	-1815747,
	1781316,
	-1624914,
	1318706,
	-835613,
	150776,
	756841,
	-1902751,
	3295222,
	-4933591,
	6806679,
	-8891390,
	11151543,
	-13536995,
	15983077,
	-18410371,
	20724794,
	-22817934,
	24567529,
	-25837910,
	26480140,
	-26331429,
	25213211,
	-22926889,
	19245654,
	-13899611,
	6549222,
	3262559,
	-16199348,
	33306204,
	-56380739,
	88851397,
	-138204223,
	224463548,
	-424890162,
	1581235120,
	1122098254,
	-426101671,
	260174100,
	-182087363,
	134675553,
	-101730107,
	76940309,
	-57367504,
	41473089,
	-28378609,
	17544387,
	-8614422,
	1335530,
	4487179,
	-9015654,
	12393491,
	-14754165,
	16225353,
	-16930815,
	16990727,
	-16521070,
	15632497,
	-14428956,
	13006295,
	-11451001,
	9839177,
	-8235826,
	6694494,
	-5257256,
	3955063,
	-2808399,
	1828204,
	-1017018,
	370273,
	122324,
	-475390,
	706492,
	-834866,
	880265,
	-861967,
	797974,
	-704397,
	595045,
	-481198,
	371546,
	-272277,
	187285,
	-118455,
	-66321,
	124481,
	-207733,
	319284,
	-461029,
	633023,
	-832954,
	1055651,
	-1292660,
	1531931,
	-1757649,
	1950244,
	-2086618,
	2140595,
	-2083625,
	1885733,
	-1516705,
	947494,
	-151800,
	-892210,
	2200110,
	-3779411,
	5627820,
	-7731617,
	10064247,
	-12585149,
	15238895,
	-17954647,
	20645929,
	-23210674,
	25531451,
	-27475716,
	28895836,
	-29628497,
	29492901,
	-28286809,
	25778866,
	-21694545,
	15690838,
	-7310311,
	-4104964,
	19583386,
	-40886817,
	71375736,
	-118422315,
	201966219,
	-400893012,
	1678544925,
	996514845,
	-405562267,
	255709576,
	-183665789,
	139247895,
	-107939367,
	84037730,
	-64879990,
	49074976,
	-35834269,
	24679580,
	-15300637,
	7480637,
	-1054922,
	-4112715,
	8143763,
	-11152784,
	13251513,
	-14550612,
	15159911,
	-15187690,
	14739417,
	-13916200,
	12813182,
	-11518032,
	10109645,
	-8657136,
	7219161,
	-5843616,
	4567674,
	-3418176,
	2412310,
	-1558544,
	857749,
	-304456,
	-111830,
	405299,
	-592563,
	691478,
	-720096,
	695791,
	-634556,
	550491,
	-455476,
	359012,
	-268222,
	187968,
	-121086,
	-48933,
	100947,
	-178538,
	285869,
	-426021,
	600450,
	-808421,
	1046453,
	-1307816,
	1582114,
	-1855002,
	2108058,
	-2318868,
	2461332,
	-2506223,
	2422001,
	-2175893,
	1735201,
	-1068842,
	149042,
	1046831,
	-2534387,
	4320335,
	-6400694,
	8759151,
	-11365632,
	14175158,
	-17126989,
	20144096,
	-23132920,
	25983345,
	-28568757,
	30745968,
	-32354637,
	33215657,
	-33127591,
	31859729,
	-29139208,
	24627609,
	-17878102,
	8254615,
	5228872,
	-24253686,
	52025635,
	-95610026,
	174334639,
	-366692910,
	1766428201,
	869409332,
	-378176441,
	246300759,
	-181517678,
	140921238,
	-111861070,
	89326958,
	-70974933,
	55585291,
	-42473823,
	31232468,
	-21602551,
	13407817,
	-6517046,
	822449,
	3772953,
	-7362535,
	10039870,
	-11900316,
	13041162,
	-13560820,
	13557456,
	-13127301,
	12362869,
	-11351231,
	10172464,
	-8898367,
	7591494,
	-6304549,
	5080134,
	-3950856,
	2939752,
	-2060995,
	1320828,
	-718664,
	248299,
	100836,
	-342428,
	492106,
	-566356,
	581591,
	-553375,
	495821,
	-421170,
	339541,
	-258838,
	184791,
	-121115,
	-29776,
	74456,
	-144708,
	245576,
	-381285,
	554682,
	-766642,
	1015463,
	-1296292,
	1600614,
	-1915851,
	2225109,
	-2507111,
	2736351,
	-2883499,
	2916067,
	-2799349,
	2497619,
	-1975584,
	1200036,
	-141675,
	-1222962,
	2909535,
	-4923961,
	7260585,
	-9900523,
	12810243,
	-15940431,
	19225169,
	-22581407,
	25908695,
	-29089060,
	31986831,
	-34448115,
	36299414,
	-37344589,
	37358831,
	-36077326,
	33174402,
	-28224954,
	20631067,
	-9475097,
	-6798230,
	31150847,
	-70138440,
	141902224,
	-322161122,
	1843832692,
	742189634,
	-344825825,
	232306582,
	-175784441,
	139724248,
	-113458130,
	92730507,
	-75549977,
	60887214,
	-48173379,
	37077553,
	-27397160,
	18999638,
	-11789603,
	5689694,
	-629279,
	-3462036,
	6657842,
	-9036330,
	10680331,
	-11676445,
	12113585,
	-12081184,
	11667274,
	-10956573,
	10028718,
	-8956728,
	7805768,
	-6632257,
	5483328,
	-4396653,
	3400609,
	-2514738,
	1750480,
	-1112097,
	597754,
	-200675,
	-89666,
	286382,
	-404091,
	457935,
	-462748,
	432380,
	-379194,
	313721,
	-244484,
	177957,
	-118651,
	-9191,
	45473,
	-106815,
	199061,
	-327511,
	496366,
	-708112,
	962883,
	-1257819,
	1586478,
	-1938317,
	2298321,
	-2646784,
	2959309,
	-3207046,
	3357197,
	-3373796,
	3218776,
	-2853303,
	2239348,
	-1341476,
	128771,
	1423136,
	-3330026,
	5597108,
	-8217162,
	11168883,
	-14415488,
	17903611,
	-21562518,
	25303599,
	-29020067,
	32586715,
	-35859464,
	38674274,
	-40844735,
	42157146,
	-42361075,
	41151679,
	-38136550,
	32772006,
	-24234448,
	11139899,
	9139880,
	-42442240,
	105107083,
	-267312968,
	1909826405,
	616237758,
	-306445665,
	214159567,
	-166673462,
	135741621,
	-112740382,
	94209821,
	-78534718,
	64889750,
	-52829498,
	42105069,
	-32573070,
	24146713,
	-16767995,
	10391288,
	-4973555,
	468667,
	3175608,
	-6018804,
	8127698,
	-9575390,
	10439793,
	-10801781,
	10743153,
	-10344581,
	9683664,
	-8833164,
	7859532,
	-6821739,
	5770472,
	-4747673,
	3786444,
	-2911262,
	2138486,
	-1477097,
	929621,
	-493169,
	160555,
	78594,
	-236757,
	327525,
	-364720,
	361665,
	-330599,
	282257,
	-225608,
	167737,
	-113852,
	12432,
	14527,
	-65535,
	147130,
	-265598,
	426427,
	-633687,
	889368,
	-1192684,
	1539412,
	-1921281,
	2325471,
	-2734255,
	3124842,
	-3469441,
	3735594,
	-3886784,
	3883340,
	-3683631,
	3245531,
	-2528121,
	1493592,
	-109283,
	-1650218,
	3800967,
	-6347653,
	9281734,
	-12579810,
	16202272,
	-20092264,
	24174958,
	-28357094,
	32526677,
	-36552631,
	40284063,
	-43548562,
	46148581,
	-47854204,
	48389220,
	-47404492,
	44426031,
	-38749014,
	29204662,
	-13586822,
	-13013094,
	64488010,
	-202311195,
	1963611072,
	492891020,
	-264008719,
	192355624,
	-154452478,
	129111274,
	-109763550,
	93765435,
	-79891655,
	67529222,
	-56361020,
	46223010,
	-37032618,
	28749817,
	-21354667,
	14833862,
	-9172589,
	4349736,
	-335341,
	-2910383,
	5436910,
	-7302442,
	8572392,
	-9317494,
	9611707,
	-9530064,
	9146577,
	-8532297,
	7753614,
	-6870857,
	5937219,
	-4998043,
	4090454,
	-3243334,
	2477590,
	-1806698,
	1237451,
	-770869,
	403206,
	-127008,
	-67846,
	193145,
	-261444,
	285283,
	-276541,
	245948,
	-202739,
	154464,
	-106920,
	34667,
	-17789,
	-21637,
	90724,
	-196635,
	346052,
	-544572,
	796020,
	-1101727,
	1459797,
	-1864421,
	2305249,
	-2766910,
	3228686,
	-3664411,
	4042617,
	-4326959,
	4476942,
	-4448946,
	4197552,
	-3677136,
	2843696,
	-1656863,
	82029,
	1907476,
	-4328253,
	7184801,
	-10467695,
	14152006,
	-18196049,
	22540449,
	-27107548,
	31801059,
	-36505854,
	41087622,
	-45391978,
	49242289,
	-52434940,
	54729700,
	-55830613,
	55347840,
	-52718497,
	47030458,
	-36584493,
	17608209,
	20678623,
	-127467126,
	2004533704,
	373424142,
	-218508923,
	167443014,
	-139442960,
	120020565,
	-104627350,
	91436351,
	-79616481,
	68770193,
	-58710429,
	49358778,
	-40693686,
	32721785,
	-25461013,
	18930253,
	-13142927,
	8103149,
	-3803664,
	225091,
	2663855,
	-4905403,
	6551229,
	-7660568,
	8298107,
	-8531769,
	8430520,
	-8062287,
	7492072,
	-6780342,
	5981718,
	-5144008,
	4307589,
	-3505130,
	2761633,
	-2094756,
	1515386,
	-1028388,
	633498,
	-326293,
	99185,
	57605,
	-155133,
	204920,
	-218263,
	205673,
	-176474,
	138525,
	-98093,
	57058,
	-50833,
	24033,
	30904,
	-121886,
	256676,
	-442303,
	684377,
	-986341,
	1348696,
	-1768231,
	2237303,
	-2743225,
	3267785,
	-3786981,
	4270971,
	-4684312,
	4986483,
	-5132735,
	5075236,
	-4764531,
	4151256,
	-3188085,
	1831835,
	-45671,
	-2198676,
	4918767,
	-8119453,
	11791123,
	-15908247,
	20428271,
	-25290901,
	30417744,
	-35712251,
	41059813,
	-46327744,
	51364691,
	-55998646,
	60032058,
	-63231146,
	65303289,
	-65848524,
	64249276,
	-59392284,
	48840761,
	-25600275,
	-43239531,
	2032096068,
	259032485,
	-170945113,
	140010685,
	-122012627,
	108701619,
	-97472743,
	87298676,
	-77737703,
	68605813,
	-59844717,
	51460424,
	-43491184,
	35989136,
	-29009063,
	22601198,
	-16806597,
	11654266,
	-7159607,
	3323881,
	-134488,
	-2434091,
	4418846,
	-5866403,
	6830939,
	-7371958,
	7552032,
	-7434625,
	7082066,
	-6553749,
	5904620,
	-5183981,
	4434627,
	-3692334,
	2985661,
	-2336065,
	1758265,
	-1260840,
	846976,
	-515335,
	260982,
	-76319,
	-48013,
	122307,
	-157059,
	162368,
	-147457,
	120346,
	-87643,
	79128,
	-83929,
	70564,
	-31168,
	-42768,
	159951,
	-328721,
	556384,
	-848453,
	1207839,
	-1634026,
	2122259,
	-2662811,
	3240369,
	-3833592,
	4414878,
	-4950399,
	5400423,
	-5719952,
	5859685,
	-5767292,
	5388996,
	-4671408,
	3563572,
	-2019151,
	-1318,
	2528201,
	-5580647,
	9164683,
	-13271595,
	17876677,
	-22938415,
	28398136,
	-34180126,
	40192202,
	-46326622,
	52461181,
	-58460158,
	64174573,
	-69440647,
	74074301,
	-77856684,
	80498020,
	-81542017,
	80073533,
	-73550033,
	49768785,
	2045961926,
	150816665,
	-122305054,
	110676210,
	-102567267,
	95425883,
	-88478435,
	81463530,
	-74315614,
	67057585,
	-59755756,
	52497449,
	-45378175,
	38493414,
	-31932954,
	25776860,
	-20092628,
	14933298,
	-10336404,
	6323644,
	-2901214,
	60693,
	2219586,
	-3972795,
	5241589,
	-6075916,
	6530754,
	-6663866,
	6533681,
	-6197345,
	5709032,
	-5118541,
	4470216,
	-3802200,
	3146013,
	-2526444,
	1961722,
	-1463929,
	1039604,
	-690488,
	414365,
	-205943,
	57721,
	39176,
	-94254,
	117003,
	-116374,
	100387,
	-75860

};

struct src_stage src_int32_21_10_4535_5000 = {
	9, 19, 21, 96, 2016, 10, 21, 0, 0,
	src_int32_21_10_4535_5000_fir};
