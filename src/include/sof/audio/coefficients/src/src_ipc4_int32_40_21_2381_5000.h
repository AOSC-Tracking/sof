/* SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright(c) 2022 Intel Corporation. All rights reserved.
 *
 */

#include <sof/audio/src/src.h>
#include <stdint.h>

const int32_t src_int32_40_21_2381_5000_fir[800] = {
	-468122,
	2413421,
	-2431744,
	-8059184,
	32250942,
	-50455235,
	18167697,
	103339919,
	-301962118,
	505099718,
	1584505529,
	466085452,
	-298557870,
	109677294,
	12146792,
	-47829807,
	32173892,
	-8749438,
	-1968686,
	2275190,
	-483354,
	2548955,
	-2906262,
	-7312189,
	32210645,
	-52971178,
	24282173,
	96465032,
	-304404496,
	544461919,
	1582669302,
	427488798,
	-294232279,
	115469491,
	6238202,
	-45107278,
	31983321,
	-9382287,
	-1518506,
	2135067,
	-496179,
	2680959,
	-3390710,
	-6509373,
	32049518,
	-55365323,
	30470666,
	89062335,
	-305846157,
	584100773,
	1579000846,
	389377666,
	-289027415,
	120710855,
	459807,
	-42300061,
	31683368,
	-9957314,
	-1082512,
	1993826,
	-506304,
	2808577,
	-3883453,
	-5651915,
	31764440,
	-57625478,
	36712855,
	81143584,
	-306250075,
	623943561,
	1573508147,
	351818039,
	-282986742,
	125397718,
	-5171415,
	-39420546,
	31278461,
	-10474346,
	-661898,
	1852209,
	-513436,
	2930930,
	-4382751,
	-4741256,
	31352674,
	-59739622,
	42987711,
	72722593,
	-305581180,
	663916299,
	1566203157,
	314873829,
	-276154975,
	129528360,
	-10639426,
	-36481059,
	30773296,
	-10933446,
	-257745,
	1710923,
	-517283,
	3047122,
	-4886766,
	-3779104,
	30811893,
	-61695953,
	49273552,
	63815246,
	-303806489,
	703943917,
	1557101762,
	278606730,
	-268577931,
	133102974,
	-15929164,
	-33493813,
	30172808,
	-11334904,
	128981,
	1570637,
	-517558,
	3156241,
	-5393561,
	-2767432,
	30140198,
	-63482940,
	55548107,
	54439487,
	-300895232,
	743950440,
	1546223737,
	243076082,
	-260302381,
	136123615,
	-21026571,
	-30470874,
	29482143,
	-11679228,
	497429,
	1431982,
	-513979,
	3257367,
	-5901112,
	-1708485,
	29336138,
	-65089370,
	61788579,
	44615313,
	-296818978,
	783859178,
	1533592698,
	208338745,
	-251375902,
	138594155,
	-25918619,
	-27424112,
	28706639,
	-11967137,
	846861,
	1295548,
	-506269,
	3349574,
	-6407309,
	-604771,
	28398730,
	-66504402,
	67971714,
	34364757,
	-291551748,
	823592908,
	1519236032,
	174448980,
	-241846725,
	140520225,
	-30593331,
	-24365169,
	27851791,
	-12199549,
	1176651,
	1161886,
	-494165,
	3431932,
	-6909961,
	540934,
	27327474,
	-67717615,
	74073875,
	23711866,
	-285070127,
	863074072,
	1503184829,
	141458331,
	-231763587,
	141909156,
	-35039800,
	-21305416,
	26923233,
	-12377571,
	1486285,
	1031503,
	-477413,
	3503516,
	-7406807,
	1725592,
	26122370,
	-68719058,
	80071114,
	12682669,
	-277353373,
	902224968,
	1485473794,
	109415528,
	-221175584,
	142769914,
	-39248198,
	-18255924,
	25926709,
	-12502491,
	1775357,
	904863,
	-455772,
	3563407,
	-7895520,
	2945904,
	24783933,
	-69499299,
	85939250,
	1305140,
	-268383513,
	940967943,
	1466141157,
	78366391,
	-210132023,
	143113032,
	-43209788,
	-15227423,
	24868046,
	-12575763,
	2043569,
	782388,
	-429019,
	3610700,
	-8373718,
	4198321,
	23313204,
	-70049474,
	91653949,
	-10390845,
	-258145436,
	979225596,
	1445228570,
	48353740,
	-198682277,
	142950539,
	-46916928,
	-12230281,
	23753132,
	-12598995,
	2290724,
	664455,
	-396950,
	3644506,
	-8838968,
	5479042,
	21711761,
	-70361336,
	97190808,
	-22373560,
	-246626979,
	1016920965,
	1422780994,
	19417324,
	-186875640,
	142295887,
	-50363072,
	-9274465,
	22587889,
	-12573942,
	2516728,
	551400,
	-359377,
	3663960,
	-9288798,
	6784031,
	19981731,
	-70427298,
	102525437,
	-34609485,
	-233819003,
	1053977734,
	1398846579,
	-8406251,
	-174761190,
	141163866,
	-53542762,
	-6369524,
	21378251,
	-12502490,
	2721584,
	443514,
	-316139,
	3668223,
	-9720704,
	8109018,
	18125791,
	-70240480,
	107633549,
	-47063374,
	-219715466,
	1090320421,
	1373476538,
	-35083576,
	-162387648,
	139570530,
	-56451631,
	-3524554,
	20130140,
	-12386645,
	2905385,
	341046,
	-267098,
	3656491,
	-10132165,
	9449512,
	16147179,
	-69794753,
	112491043,
	-59698321,
	-204313482,
	1125874574,
	1346725006,
	-60584492,
	-149803245,
	137533109,
	-59086380,
	-748188,
	18849442,
	-12228520,
	3068316,
	244203,
	-212142,
	3627997,
	-10520647,
	10800815,
	14049695,
	-69084781,
	117074099,
	-72475841,
	-187613377,
	1160566967,
	1318648903,
	-84882124,
	-137055591,
	135069924,
	-61444775,
	1951436,
	17541987,
	-12030323,
	3210646,
	153151,
	-151189,
	3582018,
	-10883615,
	12158031,
	11837701,
	-68106060,
	121359261,
	-85355955,
	-169618733,
	1194325787,
	1289307773,
	-107952914,
	-124191548,
	132200303,
	-63525619,
	4566681,
	16213525,
	-11794345,
	3332723,
	68017,
	-84185,
	3517883,
	-11218548,
	13516078,
	9516120,
	-66854956,
	125323538,
	-98297276,
	-150336422,
	1227080819,
	1258763636,
	-129776639,
	-111257109,
	128944485,
	-65328739,
	7090436,
	14869710,
	-11522947,
	3434970,
	-11112,
	-11112,
	3434970,
	-11522947,
	14869710,
	7090436,
	-65328739,
	128944485,
	-111257109,
	-129776639,
	1258763636,
	1227080819,
	-150336422,
	-98297276,
	125323538,
	-66854956,
	9516120,
	13516078,
	-11218548,
	3517883,
	-84185,
	68017,
	3332723,
	-11794345,
	16213525,
	4566681,
	-63525619,
	132200303,
	-124191548,
	-107952914,
	1289307773,
	1194325787,
	-169618733,
	-85355955,
	121359261,
	-68106060,
	11837701,
	12158031,
	-10883615,
	3582018,
	-151189,
	153151,
	3210646,
	-12030323,
	17541987,
	1951436,
	-61444775,
	135069924,
	-137055591,
	-84882124,
	1318648903,
	1160566967,
	-187613377,
	-72475841,
	117074099,
	-69084781,
	14049695,
	10800815,
	-10520647,
	3627997,
	-212142,
	244203,
	3068316,
	-12228520,
	18849442,
	-748188,
	-59086380,
	137533109,
	-149803245,
	-60584492,
	1346725006,
	1125874574,
	-204313482,
	-59698321,
	112491043,
	-69794753,
	16147179,
	9449512,
	-10132165,
	3656491,
	-267098,
	341046,
	2905385,
	-12386645,
	20130140,
	-3524554,
	-56451631,
	139570530,
	-162387648,
	-35083576,
	1373476538,
	1090320421,
	-219715466,
	-47063374,
	107633549,
	-70240480,
	18125791,
	8109018,
	-9720704,
	3668223,
	-316139,
	443514,
	2721584,
	-12502490,
	21378251,
	-6369524,
	-53542762,
	141163866,
	-174761190,
	-8406251,
	1398846579,
	1053977734,
	-233819003,
	-34609485,
	102525437,
	-70427298,
	19981731,
	6784031,
	-9288798,
	3663960,
	-359377,
	551400,
	2516728,
	-12573942,
	22587889,
	-9274465,
	-50363072,
	142295887,
	-186875640,
	19417324,
	1422780994,
	1016920965,
	-246626979,
	-22373560,
	97190808,
	-70361336,
	21711761,
	5479042,
	-8838968,
	3644506,
	-396950,
	664455,
	2290724,
	-12598995,
	23753132,
	-12230281,
	-46916928,
	142950539,
	-198682277,
	48353740,
	1445228570,
	979225596,
	-258145436,
	-10390845,
	91653949,
	-70049474,
	23313204,
	4198321,
	-8373718,
	3610700,
	-429019,
	782388,
	2043569,
	-12575763,
	24868046,
	-15227423,
	-43209788,
	143113032,
	-210132023,
	78366391,
	1466141157,
	940967943,
	-268383513,
	1305140,
	85939250,
	-69499299,
	24783933,
	2945904,
	-7895520,
	3563407,
	-455772,
	904863,
	1775357,
	-12502491,
	25926709,
	-18255924,
	-39248198,
	142769914,
	-221175584,
	109415528,
	1485473794,
	902224968,
	-277353373,
	12682669,
	80071114,
	-68719058,
	26122370,
	1725592,
	-7406807,
	3503516,
	-477413,
	1031503,
	1486285,
	-12377571,
	26923233,
	-21305416,
	-35039800,
	141909156,
	-231763587,
	141458331,
	1503184829,
	863074072,
	-285070127,
	23711866,
	74073875,
	-67717615,
	27327474,
	540934,
	-6909961,
	3431932,
	-494165,
	1161886,
	1176651,
	-12199549,
	27851791,
	-24365169,
	-30593331,
	140520225,
	-241846725,
	174448980,
	1519236032,
	823592908,
	-291551748,
	34364757,
	67971714,
	-66504402,
	28398730,
	-604771,
	-6407309,
	3349574,
	-506269,
	1295548,
	846861,
	-11967137,
	28706639,
	-27424112,
	-25918619,
	138594155,
	-251375902,
	208338745,
	1533592698,
	783859178,
	-296818978,
	44615313,
	61788579,
	-65089370,
	29336138,
	-1708485,
	-5901112,
	3257367,
	-513979,
	1431982,
	497429,
	-11679228,
	29482143,
	-30470874,
	-21026571,
	136123615,
	-260302381,
	243076082,
	1546223737,
	743950440,
	-300895232,
	54439487,
	55548107,
	-63482940,
	30140198,
	-2767432,
	-5393561,
	3156241,
	-517558,
	1570637,
	128981,
	-11334904,
	30172808,
	-33493813,
	-15929164,
	133102974,
	-268577931,
	278606730,
	1557101762,
	703943917,
	-303806489,
	63815246,
	49273552,
	-61695953,
	30811893,
	-3779104,
	-4886766,
	3047122,
	-517283,
	1710923,
	-257745,
	-10933446,
	30773296,
	-36481059,
	-10639426,
	129528360,
	-276154975,
	314873829,
	1566203157,
	663916299,
	-305581180,
	72722593,
	42987711,
	-59739622,
	31352674,
	-4741256,
	-4382751,
	2930930,
	-513436,
	1852209,
	-661898,
	-10474346,
	31278461,
	-39420546,
	-5171415,
	125397718,
	-282986742,
	351818039,
	1573508147,
	623943561,
	-306250075,
	81143584,
	36712855,
	-57625478,
	31764440,
	-5651915,
	-3883453,
	2808577,
	-506304,
	1993826,
	-1082512,
	-9957314,
	31683368,
	-42300061,
	459807,
	120710855,
	-289027415,
	389377666,
	1579000846,
	584100773,
	-305846157,
	89062335,
	30470666,
	-55365323,
	32049518,
	-6509373,
	-3390710,
	2680959,
	-496179,
	2135067,
	-1518506,
	-9382287,
	31983321,
	-45107278,
	6238202,
	115469491,
	-294232279,
	427488798,
	1582669302,
	544461919,
	-304404496,
	96465032,
	24282173,
	-52971178,
	32210645,
	-7312189,
	-2906262,
	2548955,
	-483354,
	2275190,
	-1968686,
	-8749438,
	32173892,
	-47829807,
	12146792,
	109677294,
	-298557870,
	466085452,
	1584505529,
	505099718,
	-301962118,
	103339919,
	18167697,
	-50455235,
	32250942,
	-8059184,
	-2431744,
	2413421,
	-468122

};

struct src_stage src_int32_40_21_2381_5000 = {
	11, 21, 40, 20, 800, 21, 40, 0, 0,
	src_int32_40_21_2381_5000_fir};
