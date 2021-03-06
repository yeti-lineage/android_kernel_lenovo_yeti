#include <linux/input/ist520e.h>

#define ISTXXXX_IMAGE_DELAY	5
#define ISTCORE_RESET_IC_DELAY	20
#define TEST_MODE_COMMAND_ADDR 0x0804

const unsigned char ISTXXXX_GIS_CMP_TYPICAL_SPEC[TX_NUM*RX_NUM] = {
64,	64,	64,	64,	64,	63,	62,	62,	62,	61,	61,	61,	61,	60,	60,	60,	60,	59,	59,	58,	58,	58,	58,	58,	58,	58,	58,	58,	57,	57,	57,	57,	58,	58,	58,	58,	58,	58,	58,	58,	58,	59,	59,	59,	60,	60,	60,	61,	61,	61,	62,	63,		
64,	64,	64,	64,	64,	63,	63,	62,	63,	62,	61,	61,	61,	61,	60,	60,	60,	60,	60,	59,	60,	59,	59,	59,	59,	59,	59,	59,	59,	58,	58,	58,	59,	59,	59,	59,	59,	59,	59,	59,	59,	60,	60,	60,	60,	61,	61,	61,	62,	61,	62,	63,		
64,	65,	65,	65,	64,	64,	63,	63,	63,	63,	62,	62,	62,	62,	62,	62,	62,	62,	61,	58,	56,	56,	56,	56,	56,	57,	56,	56,	56,	56,	56,	56,	56,	57,	57,	57,	57,	57,	57,	57,	57,	58,	58,	59,	59,	59,	60,	61,	61,	61,	61,	62,		
64,	65,	65,	65,	64,	64,	63,	62,	63,	62,	61,	61,	61,	61,	61,	61,	60,	60,	60,	60,	59,	59,	59,	59,	59,	59,	59,	59,	59,	58,	58,	58,	59,	59,	59,	59,	59,	59,	59,	59,	58,	60,	60,	60,	60,	61,	61,	62,	62,	62,	62,	63,		
64,	65,	65,	65,	64,	64,	63,	63,	63,	62,	62,	62,	62,	61,	61,	61,	61,	61,	61,	60,	60,	60,	60,	60,	59,	60,	59,	59,	59,	59,	59,	59,	59,	59,	60,	59,	59,	59,	60,	60,	59,	60,	60,	61,	61,	61,	61,	62,	62,	62,	63,	63,		
64,	65,	65,	65,	65,	64,	64,	63,	63,	63,	62,	62,	62,	62,	62,	61,	61,	61,	61,	60,	60,	60,	60,	60,	59,	60,	59,	59,	59,	59,	59,	59,	59,	60,	60,	60,	60,	60,	60,	60,	59,	60,	61,	61,	61,	61,	62,	62,	62,	62,	63,	64,		
65,	66,	66,	65,	65,	65,	64,	63,	64,	63,	62,	63,	62,	62,	62,	62,	62,	62,	61,	61,	60,	60,	60,	60,	60,	61,	60,	60,	60,	59,	59,	59,	60,	60,	60,	60,	60,	60,	60,	60,	60,	61,	61,	61,	62,	62,	62,	62,	63,	63,	63,	64,		
65,	66,	66,	66,	65,	65,	65,	64,	64,	64,	63,	63,	63,	63,	63,	62,	62,	62,	62,	61,	61,	61,	61,	61,	61,	61,	61,	60,	60,	60,	60,	60,	60,	61,	61,	61,	61,	61,	61,	61,	60,	61,	62,	62,	62,	62,	63,	63,	63,	63,	64,	65,		
66,	67,	67,	66,	66,	66,	65,	65,	65,	64,	63,	64,	64,	63,	63,	63,	63,	63,	62,	62,	62,	62,	61,	62,	61,	62,	61,	61,	61,	61,	61,	61,	61,	61,	61,	61,	61,	61,	61,	61,	61,	62,	62,	62,	63,	63,	63,	63,	64,	64,	64,	65,		
67,	67,	67,	67,	67,	67,	66,	65,	66,	65,	64,	64,	64,	64,	64,	64,	64,	63,	63,	62,	62,	62,	62,	62,	62,	62,	62,	62,	62,	61,	61,	61,	62,	62,	62,	62,	62,	62,	62,	62,	61,	62,	63,	63,	63,	64,	64,	64,	64,	64,	65,	66,		
67,	68,	68,	68,	67,	67,	66,	66,	66,	65,	65,	65,	65,	65,	64,	64,	64,	64,	64,	63,	63,	63,	63,	63,	62,	63,	62,	62,	62,	62,	62,	62,	62,	63,	63,	63,	63,	63,	63,	63,	62,	63,	64,	64,	64,	64,	65,	65,	65,	65,	66,	66,		
68,	69,	69,	68,	68,	68,	67,	67,	67,	66,	65,	66,	66,	65,	65,	65,	65,	65,	65,	64,	64,	64,	64,	64,	63,	64,	63,	63,	63,	63,	63,	63,	63,	63,	64,	63,	63,	63,	64,	64,	63,	64,	64,	64,	65,	65,	65,	66,	66,	66,	66,	67,		
69,	69,	69,	69,	69,	68,	68,	67,	68,	67,	66,	66,	66,	66,	66,	66,	66,	65,	65,	65,	65,	64,	64,	65,	64,	65,	64,	64,	64,	63,	64,	64,	64,	64,	64,	64,	64,	64,	64,	64,	64,	65,	65,	65,	66,	66,	66,	66,	67,	66,	67,	68,		
69,	70,	70,	70,	69,	69,	68,	68,	68,	68,	67,	67,	67,	67,	67,	66,	66,	66,	66,	65,	65,	65,	65,	65,	65,	65,	65,	65,	65,	64,	64,	64,	65,	65,	65,	65,	65,	65,	65,	65,	64,	66,	66,	66,	66,	66,	67,	67,	67,	67,	68,	68,		
70,	71,	71,	71,	70,	70,	69,	69,	69,	69,	68,	68,	68,	68,	68,	68,	67,	67,	67,	67,	67,	66,	66,	66,	66,	66,	66,	66,	66,	65,	65,	66,	66,	66,	66,	66,	66,	66,	66,	66,	66,	66,	67,	67,	67,	67,	68,	68,	68,	68,	69,	69,		
71,	71,	71,	71,	71,	71,	70,	70,	70,	69,	69,	69,	69,	69,	68,	68,	68,	68,	68,	67,	67,	67,	67,	67,	67,	67,	67,	67,	66,	66,	66,	66,	66,	67,	67,	67,	67,	67,	67,	67,	66,	67,	67,	68,	68,	68,	68,	69,	69,	69,	69,	70,		
72,	73,	73,	72,	72,	72,	71,	71,	71,	70,	70,	70,	70,	70,	70,	69,	69,	69,	69,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	67,	67,	67,	68,	68,	68,	68,	68,	68,	68,	68,	67,	68,	69,	69,	69,	69,	69,	70,	70,	70,	70,	71,		
73,	73,	73,	73,	73,	73,	72,	72,	72,	71,	71,	71,	71,	71,	71,	70,	70,	70,	70,	69,	69,	69,	69,	70,	69,	70,	69,	69,	69,	68,	68,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	70,	70,	70,	70,	70,	71,	71,	71,	71,	72,		
74,	74,	75,	74,	74,	74,	73,	73,	73,	72,	72,	72,	72,	72,	72,	71,	71,	71,	71,	71,	70,	70,	70,	71,	70,	71,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	71,	71,	71,	71,	72,	72,	72,	72,	72,	73,	73,		
75,	75,	76,	75,	75,	75,	74,	74,	74,	74,	73,	73,	73,	73,	73,	73,	73,	72,	72,	72,	72,	72,	71,	72,	71,	72,	71,	71,	71,	71,	71,	71,	71,	71,	72,	71,	71,	72,	72,	72,	71,	72,	72,	72,	72,	73,	73,	73,	73,	73,	74,	74,		
76,	77,	77,	76,	76,	76,	75,	75,	75,	75,	74,	74,	74,	74,	74,	74,	74,	74,	74,	73,	73,	73,	73,	73,	73,	73,	73,	72,	72,	72,	72,	72,	72,	73,	73,	72,	73,	73,	73,	73,	72,	73,	73,	73,	74,	74,	74,	74,	74,	74,	75,	75,		
77,	78,	78,	77,	77,	77,	76,	76,	76,	76,	75,	75,	75,	75,	75,	75,	75,	75,	75,	74,	74,	74,	74,	74,	74,	74,	74,	73,	74,	73,	73,	73,	73,	74,	74,	74,	74,	74,	74,	74,	73,	74,	74,	75,	75,	75,	75,	75,	75,	75,	76,	76,		
79,	79,	79,	79,	79,	78,	78,	78,	78,	77,	77,	77,	77,	77,	76,	76,	76,	76,	76,	75,	75,	75,	75,	76,	75,	76,	75,	75,	75,	75,	75,	75,	75,	75,	75,	75,	75,	75,	75,	75,	75,	75,	76,	76,	76,	76,	76,	77,	77,	77,	77,	78,		
80,	80,	80,	80,	80,	80,	79,	79,	79,	79,	78,	78,	78,	78,	78,	78,	78,	78,	77,	77,	77,	77,	77,	77,	77,	77,	76,	76,	76,	76,	76,	76,	77,	77,	77,	77,	77,	77,	77,	77,	76,	77,	77,	77,	77,	78,	78,	78,	78,	78,	78,	79,		
81,	81,	81,	81,	81,	81,	80,	80,	80,	80,	80,	80,	79,	79,	79,	79,	79,	79,	79,	78,	78,	78,	78,	79,	78,	78,	78,	78,	78,	78,	78,	78,	78,	78,	78,	78,	78,	78,	78,	78,	78,	78,	78,	79,	79,	79,	79,	79,	79,	79,	80,	80,		
82,	83,	83,	82,	82,	82,	82,	82,	82,	81,	81,	81,	81,	81,	81,	80,	80,	80,	80,	80,	80,	80,	80,	80,	79,	80,	79,	79,	80,	79,	79,	79,	79,	80,	80,	79,	79,	80,	80,	80,	79,	80,	80,	80,	80,	80,	80,	81,	81,	81,	81,	81,		
84,	84,	84,	84,	84,	83,	83,	83,	83,	82,	82,	82,	82,	82,	82,	82,	82,	82,	82,	81,	81,	81,	81,	82,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	80,	81,	81,	81,	82,	82,	82,	82,	82,	82,	82,	83,		
85,	85,	85,	85,	85,	85,	84,	84,	84,	84,	84,	84,	84,	84,	84,	83,	83,	83,	83,	83,	83,	83,	83,	83,	82,	83,	83,	83,	83,	82,	82,	82,	83,	83,	83,	83,	83,	83,	83,	83,	82,	83,	83,	83,	83,	83,	83,	84,	84,	84,	84,	84,		
86,	87,	87,	86,	86,	86,	86,	86,	86,	85,	85,	85,	85,	85,	85,	85,	85,	85,	85,	84,	84,	84,	84,	85,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	83,	84,	84,	84,	85,	85,	85,	85,	85,	85,	85,	86,		
88,	88,	88,	88,	88,	87,	87,	87,	87,	87,	87,	87,	86,	87,	86,	86,	86,	86,	86,	86,	86,	86,	86,	86,	86,	86,	86,	86,	86,	85,	85,	85,	86,	86,	86,	86,	86,	86,	86,	86,	85,	86,	86,	86,	86,	86,	86,	87,	87,	87,	87,	87,		
89,	89,	89,	89,	89,	89,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	87,	88,	87,	87,	88,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	88,	88,	88,	88,	88,	88,	88,		
90,	90,	90,	90,	90,	90,	90,	90,	90,	90,	90,	90,	90,	90,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	88,	89,	89,	89,	89,	89,	89,	90,	89,	90,	90,	90	
};

const unsigned short ISTXXXX_GIS_4RCF_TYPICAL_SPEC[TX_NUM] = {
	1303,	1451,	1489,	1500,	1504,	1507,	1503,	1502,	1503,	1506,	1513,	1529,	1526,	1534,	1498,	1495,	1488,	1516,	1543,	1534,	1508,	1483,	1512,	1487,	1488,	1483,	1476,	1470,	1455,	1426,	1454,	1406
};

const unsigned short ISTXXXX_GIS_EOP_TYPICAL_SPEC[RX_NUM] = {
	1008,	1058,	1049,	1044,	1039,	1035,	1032,	1032,	1025,	1022,	1016,	1018,	1013,	1014,	1004,	1001,	993,	996,	999,	1009,	1005,	1014,	1008,	1015,	1014,	1013,	1018,	1020,	1029,	1037,	1036,	1043,	1040,	1037,	1046,	1047,	1049,	1054,	1064,	1070,	1063,	1069,	1071,	1076,	1075,	1079,	1080,	1085,	1085,	1095,	1101,	1096
};


const unsigned char ISTXXXX_OFILM_CMP_TYPICAL_SPEC[TX_NUM*RX_NUM] = {
97,	97,	97,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,	96,
96,	96,	96,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	94,	95,	95,	94,	95,	95,	94,	95,	94,	95,	94,	94,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,	95,
94,	94,	94,	94,	94,	94,	94,	94,	94,	94,	94,	94,	93,	93,	94,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	93,	94,	94,	94,
93,	93,	93,	93,	93,	93,	93,	93,	93,	92,	92,	92,	92,	92,	92,	92,	92,	92,	92,	92,	92,	92,	92,	92,	92,	92,	92,	91,	92,	91,	91,	91,	91,	91,	92,	91,	92,	92,	91,	91,	91,	92,	91,	92,	92,	92,	92,	92,	92,	92,	92,	92,
92,	92,	92,	92,	92,	92,	92,	92,	92,	91,	92,	91,	91,	91,	91,	91,	91,	91,	91,	91,	91,	91,	91,	91,	90,	90,	91,	90,	91,	90,	90,	90,	90,	90,	90,	90,	91,	90,	90,	90,	90,	91,	91,	91,	91,	91,	91,	91,	91,	91,	91,	92,
91,	91,	91,	91,	91,	91,	91,	91,	91,	90,	90,	90,	90,	90,	90,	90,	90,	90,	89,	90,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	89,	90,	90,	90,	90,	90,	90,	90,	90,	90,
90,	90,	90,	90,	90,	90,	90,	89,	89,	89,	89,	89,	89,	89,	89,	89,	88,	89,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	88,	89,	89,	89,	89,	89,	89,
89,	89,	89,	89,	89,	88,	88,	88,	88,	88,	88,	88,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	86,	86,	87,	86,	87,	86,	86,	87,	86,	86,	87,	86,	87,	86,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	87,	88,	88,	88,
88,	88,	88,	88,	88,	87,	87,	87,	87,	87,	87,	87,	86,	86,	86,	86,	86,	86,	86,	86,	85,	86,	85,	85,	85,	85,	85,	85,	85,	85,	85,	85,	85,	85,	85,	85,	85,	85,	85,	85,	85,	86,	86,	86,	86,	86,	86,	86,	86,	86,	87,	87,
87,	87,	87,	87,	86,	86,	86,	86,	86,	86,	86,	86,	85,	85,	85,	85,	85,	85,	85,	85,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	84,	85,	85,	85,	85,	85,	85,	86,	85,	86,
86,	86,	86,	86,	85,	85,	85,	85,	85,	85,	85,	85,	84,	84,	84,	84,	84,	84,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	83,	84,	84,	84,	84,	84,	84,	84,	84,	85,
85,	85,	85,	85,	84,	84,	84,	84,	84,	84,	84,	84,	83,	83,	83,	83,	83,	83,	82,	82,	82,	82,	82,	82,	82,	82,	82,	81,	82,	82,	81,	82,	82,	82,	82,	82,	82,	82,	82,	82,	82,	82,	82,	83,	83,	83,	83,	83,	83,	83,	83,	84,
84,	84,	84,	84,	84,	83,	83,	83,	83,	83,	83,	83,	82,	82,	82,	82,	81,	82,	81,	81,	81,	81,	81,	81,	81,	81,	81,	80,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	81,	82,	82,	82,	82,	82,	82,	82,	82,	83,
83,	83,	83,	83,	82,	82,	82,	82,	82,	81,	81,	81,	81,	81,	81,	81,	80,	81,	80,	80,	80,	80,	80,	80,	79,	79,	80,	79,	80,	79,	79,	80,	79,	79,	80,	80,	80,	80,	79,	80,	80,	80,	80,	80,	80,	81,	81,	81,	81,	81,	81,	82,
82,	83,	82,	82,	82,	82,	81,	81,	81,	81,	81,	81,	80,	80,	80,	80,	80,	80,	79,	79,	79,	79,	79,	79,	79,	79,	79,	78,	79,	79,	78,	79,	79,	78,	79,	79,	79,	79,	79,	79,	79,	79,	79,	80,	80,	80,	80,	80,	80,	80,	81,	81,
81,	81,	81,	81,	81,	80,	80,	80,	80,	80,	80,	79,	79,	79,	79,	79,	78,	79,	78,	78,	78,	78,	78,	78,	77,	77,	78,	77,	78,	77,	77,	77,	77,	77,	78,	78,	77,	77,	77,	78,	78,	78,	78,	78,	78,	79,	79,	79,	79,	79,	79,	80,
80,	81,	81,	80,	80,	80,	80,	79,	79,	79,	79,	79,	78,	78,	78,	78,	77,	78,	77,	77,	77,	77,	77,	77,	76,	77,	77,	76,	76,	76,	76,	76,	76,	76,	77,	77,	77,	77,	77,	77,	77,	77,	77,	77,	77,	78,	78,	78,	78,	79,	79,	79,
79,	80,	79,	79,	79,	79,	79,	78,	78,	78,	78,	78,	77,	77,	77,	77,	76,	77,	76,	76,	76,	76,	76,	76,	75,	75,	75,	75,	75,	75,	75,	76,	75,	75,	76,	76,	76,	76,	75,	76,	76,	76,	76,	76,	76,	77,	77,	77,	77,	77,	78,	78,
78,	79,	79,	78,	78,	78,	78,	78,	77,	77,	77,	77,	76,	76,	76,	76,	75,	76,	75,	75,	75,	75,	75,	75,	74,	75,	75,	74,	74,	74,	74,	75,	74,	74,	75,	75,	75,	75,	75,	75,	75,	75,	75,	76,	76,	76,	76,	76,	77,	77,	77,	77,
78,	78,	78,	78,	77,	77,	77,	77,	76,	76,	76,	76,	75,	75,	75,	75,	75,	75,	74,	74,	74,	74,	74,	74,	74,	74,	74,	73,	74,	74,	73,	74,	74,	73,	74,	74,	74,	74,	74,	74,	74,	74,	74,	75,	75,	75,	75,	75,	76,	76,	76,	76,
77,	78,	77,	77,	77,	76,	76,	76,	76,	76,	76,	75,	75,	75,	75,	75,	74,	74,	74,	74,	73,	73,	73,	73,	73,	73,	73,	72,	73,	73,	72,	73,	73,	73,	73,	73,	73,	73,	73,	73,	73,	74,	73,	74,	74,	74,	74,	74,	75,	75,	75,	76,
76,	77,	77,	76,	76,	76,	75,	75,	75,	75,	75,	74,	74,	74,	74,	74,	73,	73,	73,	73,	72,	72,	72,	72,	72,	72,	72,	72,	72,	72,	72,	72,	72,	72,	72,	72,	72,	72,	72,	73,	72,	73,	73,	73,	73,	73,	74,	74,	74,	74,	75,	75,
76,	76,	76,	76,	75,	75,	75,	75,	75,	74,	74,	74,	73,	73,	73,	73,	72,	73,	72,	72,	72,	72,	72,	72,	71,	71,	72,	71,	71,	71,	71,	72,	71,	71,	72,	72,	72,	72,	71,	72,	72,	72,	72,	73,	73,	73,	73,	73,	74,	74,	74,	74,
75,	76,	76,	75,	75,	75,	74,	74,	74,	74,	74,	73,	73,	73,	72,	72,	72,	72,	71,	72,	71,	71,	71,	71,	70,	71,	71,	70,	71,	70,	70,	71,	71,	71,	71,	71,	71,	71,	71,	71,	71,	72,	71,	72,	72,	72,	72,	72,	73,	73,	73,	74,
75,	75,	75,	74,	74,	74,	74,	74,	73,	73,	73,	73,	72,	72,	72,	72,	71,	71,	71,	71,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	70,	71,	70,	71,	71,	71,	71,	72,	72,	72,	72,	73,	73,	73,
74,	75,	74,	74,	74,	73,	73,	73,	73,	73,	73,	72,	72,	71,	71,	71,	71,	71,	70,	70,	70,	70,	70,	70,	69,	70,	70,	69,	70,	69,	69,	70,	69,	69,	70,	70,	70,	70,	69,	70,	70,	70,	70,	71,	71,	71,	71,	71,	72,	72,	72,	73,
74,	75,	74,	74,	73,	73,	73,	73,	72,	72,	72,	72,	71,	71,	71,	71,	70,	70,	70,	70,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	69,	70,	70,	70,	70,	71,	71,	71,	71,	72,	72,	72,
73,	74,	74,	73,	73,	73,	72,	72,	72,	72,	71,	71,	71,	71,	71,	70,	70,	70,	69,	69,	69,	69,	69,	69,	68,	68,	69,	68,	69,	68,	68,	69,	68,	68,	69,	69,	69,	69,	69,	69,	69,	69,	69,	70,	70,	70,	71,	70,	71,	71,	72,	72,
73,	74,	73,	73,	73,	72,	72,	72,	71,	71,	71,	71,	70,	70,	70,	70,	69,	70,	69,	69,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	69,	69,	69,	69,	69,	69,	70,	70,	70,	70,	71,	71,	72,
73,	73,	73,	73,	72,	72,	72,	72,	71,	71,	71,	71,	70,	70,	70,	70,	69,	69,	69,	69,	68,	68,	68,	68,	68,	68,	68,	67,	68,	68,	67,	68,	68,	68,	68,	68,	68,	68,	68,	68,	68,	69,	69,	69,	69,	69,	70,	70,	70,	70,	71,	71,
72,	73,	73,	72,	72,	72,	71,	71,	71,	71,	71,	70,	70,	69,	70,	69,	69,	69,	68,	68,	68,	68,	68,	68,	67,	67,	67,	67,	67,	67,	67,	68,	67,	67,	68,	68,	68,	68,	68,	68,	68,	69,	68,	69,	69,	69,	70,	69,	70,	70,	71,	71,
72,	73,	73,	72,	72,	72,	71,	71,	71,	71,	70,	70,	69,	69,	69,	69,	68,	69,	68,	68,	68,	68,	68,	67,	67,	67,	67,	67,	67,	67,	67,	67,	67,	67,	67,	67,	67,	67,	67,	68,	68,	68,	68,	69,	69,	69,	69,	69,	70,	70,	70,	71
};

const unsigned short ISTXXXX_OFILM_4RCF_TYPICAL_SPEC[TX_NUM] = {
	1151,	1352,	1375,	1411,	1387,	1401,	1405,	1410,	1424,	1420,	1422,	1421,	1417,	1439,	1435,	1437,	1437,	1371,	1418,	1437,	1441,	1446,	1449,	1453,	1451,	1451,	1461,	1454,	1466,	1468,	1464,	1466
};

const unsigned short ISTXXXX_OFILM_EOP_TYPICAL_SPEC[RX_NUM] = {
	1042,	1077,	1068,	1065,	1062,	1055,	1048,	1047,	1041,	1039,	1032,	1034,	1025,	1024,	1020,	1017,	1019,	1024,	1025,	1031,	1032,	1041,	1040,	1046,	1053,	1056,	1057,	1055,	1069,	1064,	1063,	1069,	1074,	1075,	1080,	1075,	1090,	1086,	1093,	1095,	1103,	1096,	1106,	1104,	1113,	1113,	1123,	1122,	1126,	1127,	1133,	1135
};

const unsigned short ISTXXXX_4RC_TYPICAL = 940;

void istxxxx_test_mode(struct ist510e *ts)
{
    unsigned char *buf;
    unsigned short *framebuf;
    unsigned short *tempframe;
	unsigned char r,t,retry;
    int ret = 0;
	unsigned int resultCNT;
	unsigned int vendor;


    buf = kmalloc(sizeof(buf)*TX_NUM*RX_NUM*2, GFP_KERNEL);
    if(buf ==NULL)
    {
        ts_log_err("can't not memmory alloc");
        goto exit_buf_alloc_istxxxx_test_mode;
    }
    ist_load_dwz(ts);
    vendor = ts->dwz_info.factory_id;
    
    framebuf = kmalloc(sizeof(framebuf)*TX_NUM*RX_NUM, GFP_KERNEL);
    if(framebuf ==NULL)
    {
        ts_log_err("can't not memmory alloc");
        goto exit_framebuf_alloc_istxxxx_test_mode;
    }
  	

    tempframe = kmalloc(sizeof(tempframe)*TX_NUM*RX_NUM, GFP_KERNEL);
    if(tempframe ==NULL)
    {
        ts_log_err("can't not memmory alloc");
        goto exit_tempframe_alloc_istxxxx_test_mode;
    }

	//4RCF
	istcore_reset_ic();
	mdelay(ISTCORE_RESET_IC_DELAY);
	buf[0] = 0x03;
	ret = istcore_i2c_write(ts,TEST_MODE_COMMAND_ADDR, 1, buf);
	ts_log_info("ret = %d", ret);
	mdelay(ISTXXXX_IMAGE_DELAY);
	retry =3;
	do{
		ret = istcore_i2c_read(ts, 0x1008, (TX_NUM*RX_NUM)*2, (unsigned char *)framebuf);
		if(*((unsigned char *)framebuf)=='G')
		    break;
		mdelay(ISTXXXX_IMAGE_DELAY);
		retry--;
		ts_log_err("retry = %d", retry);
	}while(retry);
	ts_log_info("inspection");

	//Inspection
	for(t=0; t<TX_NUM; t++)
	{
		resultCNT = 0;
		for (r=0; r<RX_NUM; r++)
		{
			if( 6 == vendor){
                ts_log_debug("4RC: index = %d, framebuf = %d, ISTXXXX_GIS_4RCF_TYPICAL_SPEC = %d", 
                r+t*RX_NUM,
                framebuf[r+t*RX_NUM],
                ISTXXXX_GIS_4RCF_TYPICAL_SPEC[t]);
			
			if (ISTXXXX_GIS_4RCF_TYPICAL_SPEC[t]*14 < framebuf[r+t*RX_NUM]*10) // SPEC : +30% // ??
			{
				resultCNT++;
			}
			}else if(1 == vendor){
                ts_log_debug("4RC: index = %d, framebuf = %d, ISTXXXX_OFILM_4RCF_TYPICAL_SPEC = %d", 
                r+t*RX_NUM,
                framebuf[r+t*RX_NUM],
                ISTXXXX_OFILM_4RCF_TYPICAL_SPEC[t]);
			
			if (ISTXXXX_OFILM_4RCF_TYPICAL_SPEC[t]*14 < framebuf[r+t*RX_NUM]*10) // SPEC : +30% // ??
			{
				resultCNT++;
			}
			}
		}

		if (resultCNT > 0)
		{
			ts->TXshortResult[t] = 1;
			ts_log_debug("TX Channel Short = %d", t);
		}
		else
		{
			ts->TXshortResult[t] = 0;
			ts_log_debug("4RCF Pass = %d", t);
		}
	}


	//EOP
	istcore_reset_ic();
	mdelay(ISTCORE_RESET_IC_DELAY);
	buf[0] = 0x02;
	//buf[1] = 0x02;
	ret = istcore_i2c_write(ts,TEST_MODE_COMMAND_ADDR, 1, buf);
	ts_log_debug("ret = %d", ret);

	mdelay(ISTXXXX_IMAGE_DELAY);
	retry =3;
	do{
		ret = istcore_i2c_read(ts, 0x1008, (TX_NUM*RX_NUM)*2, (unsigned char *)framebuf);
		if(*((unsigned char *)framebuf)=='G')
		    break;
		mdelay(ISTXXXX_IMAGE_DELAY);
		retry--;
		ts_log_err("retry = %d", retry);
	}while(retry);

	//Inspection
	for(r=0; r<RX_NUM; r++)
	{
		resultCNT = 0;
		for (t=0; t<TX_NUM; t++)
		{
			if( 6 == vendor){
            ts_log_debug("EOP: index = %d, framebuf = %d, ISTXXXX_GIS_EOP_TYPICAL_SPEC = %d", 
                r+t*RX_NUM,
                framebuf[r+t*RX_NUM],
                ISTXXXX_GIS_EOP_TYPICAL_SPEC[r]);

			if (ISTXXXX_GIS_EOP_TYPICAL_SPEC[r]*13 < framebuf[r+t*RX_NUM]*10) // SPEC : +20%
			{
				resultCNT++;
			}
			}else if(1 == vendor){
            ts_log_debug("EOP: index = %d, framebuf = %d, ISTXXXX_OFILM_EOP_TYPICAL_SPEC = %d", 
                r+t*RX_NUM,
                framebuf[r+t*RX_NUM],
                ISTXXXX_OFILM_EOP_TYPICAL_SPEC[r]);

			if (ISTXXXX_OFILM_EOP_TYPICAL_SPEC[r]*13 < framebuf[r+t*RX_NUM]*10) // SPEC : +20%
			{
				resultCNT++;
			}
				
			}
		}

		if (resultCNT > 0)
		{
			ts->RXshortResult[r] = 1;
			ts_log_debug("RX Channel Short = %d", r);
		}
		else
		{
			ts->RXshortResult[r] = 0;
			ts_log_debug("EOP Pass = %d", r);
		}
	}



	//4RC
	istcore_reset_ic();
	mdelay(ISTCORE_RESET_IC_DELAY);
    buf[0] = 0x00;
    //buf[1] = 0x00;
    ret = istcore_i2c_write(ts,TEST_MODE_COMMAND_ADDR, 1, buf);
    ts_log_debug("ret = %d", ret);

	mdelay(ISTXXXX_IMAGE_DELAY);
	retry =3;
	do{
		ret = istcore_i2c_read(ts, 0x1008, (TX_NUM*RX_NUM)*2, (unsigned char *)tempframe);
		if(*((unsigned char *)tempframe)=='G')
		    break;
		mdelay(ISTXXXX_IMAGE_DELAY);
		retry--;
		ts_log_err("retry = %d", retry);
	}while(retry);
	//1RC
	istcore_reset_ic();
	mdelay(ISTCORE_RESET_IC_DELAY);
	buf[0] = 0x01;
	//buf[1] = 0x01;
	ret = istcore_i2c_write(ts,TEST_MODE_COMMAND_ADDR, 1, buf);
	ts_log_debug("ret = %d", ret);

	mdelay(ISTXXXX_IMAGE_DELAY);
	retry =3;
	do{
		ret = istcore_i2c_read(ts, 0x1008, (TX_NUM*RX_NUM)*2, (unsigned char *)framebuf);
		if(*((unsigned char *)framebuf)=='G')
		    break;
		mdelay(ISTXXXX_IMAGE_DELAY);
		retry--;
		ts_log_err("retry = %d", retry);
	}while(retry);

	//Calculation CMP 
	for(t=0; t<TX_NUM; t++)
	{
		for (r=0; r<RX_NUM; r++)
		{
			tempframe[r+t*RX_NUM] = tempframe[r+t*RX_NUM]>0?tempframe[r+t*RX_NUM]:1;
			framebuf[r+t*RX_NUM] = framebuf[r+t*RX_NUM]*100 / tempframe[r+t*RX_NUM];

            ts_log_debug("CMP: index = %d, framebuf(CMP) = %d, tempframe(4RC) = %d", 
                r+t*RX_NUM,
                framebuf[r+t*RX_NUM],
                tempframe[r+t*RX_NUM]);
		}
	}	

	//Inspection
	for (r=0; r<RX_NUM; r++)
	{
		if (ts->RXshortResult[r] == 0)
		{
			resultCNT = 0;
			for(t=0; t<TX_NUM; t++)
			{
				if (ISTXXXX_4RC_TYPICAL*7 > tempframe[r+t*RX_NUM]*10) // SPEC : -30%
				{
					resultCNT++;
				}
				else
				{
					resultCNT = 0;
				}
			}
			if (resultCNT > 1)
			{
				ts->RXopenResult[r] = 1;
				ts_log_debug("RX Channel Open = %d", r);
			}
			else
			{
				ts->RXopenResult[r] = 0;
				ts_log_debug("RX 4RC Pass = %d", r);
			}
		}
		else
		{
			ts->RXopenResult[r] = 0;
			ts_log_debug("Skip to check 4RC RX = %d", r);
		}
	}
	

	for(t=0; t<TX_NUM; t++)
	{
		if (ts->TXshortResult[t] == 0)
		{
			resultCNT = 0;
			for (r=0; r<RX_NUM; r++)
			{
			if( 6 == vendor){
				if ((ISTXXXX_GIS_CMP_TYPICAL_SPEC[r+t*RX_NUM]*7 > framebuf[r+t*RX_NUM]*10)&&(ts->RXopenResult[r] == 0)) // SPEC : -20%
				{
					resultCNT++;
				}
			}else if( 1 == vendor){
				if ((ISTXXXX_OFILM_CMP_TYPICAL_SPEC[r+t*RX_NUM]*7 > framebuf[r+t*RX_NUM]*10)&&(ts->RXopenResult[r] == 0)) // SPEC : -20%
				{
					resultCNT++;
				}
			}
			}
			if (resultCNT > 0)
			{
				ts->TXopenResult[t] = 1;
				ts_log_debug("TX Channel Open = %d", t);
			}
			else
			{
				ts->TXopenResult[t] = 0;
				ts_log_debug("TX CMP Pass = %d", t);
			}
		}
		else
		{
			ts->TXopenResult[t] = 0;
			ts_log_debug("Skip to check CMP TX = %d", t);
		}
	}
	istcore_reset_ic();
	mdelay(100);
	kfree(tempframe);
	kfree(framebuf);
	kfree(buf);
	return;
	
exit_tempframe_alloc_istxxxx_test_mode:
	kfree(framebuf);
exit_framebuf_alloc_istxxxx_test_mode:
	kfree(framebuf);
exit_buf_alloc_istxxxx_test_mode:
	return;
}

