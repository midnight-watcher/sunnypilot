#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5883224282319393425) {
   out_5883224282319393425[0] = delta_x[0] + nom_x[0];
   out_5883224282319393425[1] = delta_x[1] + nom_x[1];
   out_5883224282319393425[2] = delta_x[2] + nom_x[2];
   out_5883224282319393425[3] = delta_x[3] + nom_x[3];
   out_5883224282319393425[4] = delta_x[4] + nom_x[4];
   out_5883224282319393425[5] = delta_x[5] + nom_x[5];
   out_5883224282319393425[6] = delta_x[6] + nom_x[6];
   out_5883224282319393425[7] = delta_x[7] + nom_x[7];
   out_5883224282319393425[8] = delta_x[8] + nom_x[8];
   out_5883224282319393425[9] = delta_x[9] + nom_x[9];
   out_5883224282319393425[10] = delta_x[10] + nom_x[10];
   out_5883224282319393425[11] = delta_x[11] + nom_x[11];
   out_5883224282319393425[12] = delta_x[12] + nom_x[12];
   out_5883224282319393425[13] = delta_x[13] + nom_x[13];
   out_5883224282319393425[14] = delta_x[14] + nom_x[14];
   out_5883224282319393425[15] = delta_x[15] + nom_x[15];
   out_5883224282319393425[16] = delta_x[16] + nom_x[16];
   out_5883224282319393425[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_266692242281043755) {
   out_266692242281043755[0] = -nom_x[0] + true_x[0];
   out_266692242281043755[1] = -nom_x[1] + true_x[1];
   out_266692242281043755[2] = -nom_x[2] + true_x[2];
   out_266692242281043755[3] = -nom_x[3] + true_x[3];
   out_266692242281043755[4] = -nom_x[4] + true_x[4];
   out_266692242281043755[5] = -nom_x[5] + true_x[5];
   out_266692242281043755[6] = -nom_x[6] + true_x[6];
   out_266692242281043755[7] = -nom_x[7] + true_x[7];
   out_266692242281043755[8] = -nom_x[8] + true_x[8];
   out_266692242281043755[9] = -nom_x[9] + true_x[9];
   out_266692242281043755[10] = -nom_x[10] + true_x[10];
   out_266692242281043755[11] = -nom_x[11] + true_x[11];
   out_266692242281043755[12] = -nom_x[12] + true_x[12];
   out_266692242281043755[13] = -nom_x[13] + true_x[13];
   out_266692242281043755[14] = -nom_x[14] + true_x[14];
   out_266692242281043755[15] = -nom_x[15] + true_x[15];
   out_266692242281043755[16] = -nom_x[16] + true_x[16];
   out_266692242281043755[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_157508777103841027) {
   out_157508777103841027[0] = 1.0;
   out_157508777103841027[1] = 0.0;
   out_157508777103841027[2] = 0.0;
   out_157508777103841027[3] = 0.0;
   out_157508777103841027[4] = 0.0;
   out_157508777103841027[5] = 0.0;
   out_157508777103841027[6] = 0.0;
   out_157508777103841027[7] = 0.0;
   out_157508777103841027[8] = 0.0;
   out_157508777103841027[9] = 0.0;
   out_157508777103841027[10] = 0.0;
   out_157508777103841027[11] = 0.0;
   out_157508777103841027[12] = 0.0;
   out_157508777103841027[13] = 0.0;
   out_157508777103841027[14] = 0.0;
   out_157508777103841027[15] = 0.0;
   out_157508777103841027[16] = 0.0;
   out_157508777103841027[17] = 0.0;
   out_157508777103841027[18] = 0.0;
   out_157508777103841027[19] = 1.0;
   out_157508777103841027[20] = 0.0;
   out_157508777103841027[21] = 0.0;
   out_157508777103841027[22] = 0.0;
   out_157508777103841027[23] = 0.0;
   out_157508777103841027[24] = 0.0;
   out_157508777103841027[25] = 0.0;
   out_157508777103841027[26] = 0.0;
   out_157508777103841027[27] = 0.0;
   out_157508777103841027[28] = 0.0;
   out_157508777103841027[29] = 0.0;
   out_157508777103841027[30] = 0.0;
   out_157508777103841027[31] = 0.0;
   out_157508777103841027[32] = 0.0;
   out_157508777103841027[33] = 0.0;
   out_157508777103841027[34] = 0.0;
   out_157508777103841027[35] = 0.0;
   out_157508777103841027[36] = 0.0;
   out_157508777103841027[37] = 0.0;
   out_157508777103841027[38] = 1.0;
   out_157508777103841027[39] = 0.0;
   out_157508777103841027[40] = 0.0;
   out_157508777103841027[41] = 0.0;
   out_157508777103841027[42] = 0.0;
   out_157508777103841027[43] = 0.0;
   out_157508777103841027[44] = 0.0;
   out_157508777103841027[45] = 0.0;
   out_157508777103841027[46] = 0.0;
   out_157508777103841027[47] = 0.0;
   out_157508777103841027[48] = 0.0;
   out_157508777103841027[49] = 0.0;
   out_157508777103841027[50] = 0.0;
   out_157508777103841027[51] = 0.0;
   out_157508777103841027[52] = 0.0;
   out_157508777103841027[53] = 0.0;
   out_157508777103841027[54] = 0.0;
   out_157508777103841027[55] = 0.0;
   out_157508777103841027[56] = 0.0;
   out_157508777103841027[57] = 1.0;
   out_157508777103841027[58] = 0.0;
   out_157508777103841027[59] = 0.0;
   out_157508777103841027[60] = 0.0;
   out_157508777103841027[61] = 0.0;
   out_157508777103841027[62] = 0.0;
   out_157508777103841027[63] = 0.0;
   out_157508777103841027[64] = 0.0;
   out_157508777103841027[65] = 0.0;
   out_157508777103841027[66] = 0.0;
   out_157508777103841027[67] = 0.0;
   out_157508777103841027[68] = 0.0;
   out_157508777103841027[69] = 0.0;
   out_157508777103841027[70] = 0.0;
   out_157508777103841027[71] = 0.0;
   out_157508777103841027[72] = 0.0;
   out_157508777103841027[73] = 0.0;
   out_157508777103841027[74] = 0.0;
   out_157508777103841027[75] = 0.0;
   out_157508777103841027[76] = 1.0;
   out_157508777103841027[77] = 0.0;
   out_157508777103841027[78] = 0.0;
   out_157508777103841027[79] = 0.0;
   out_157508777103841027[80] = 0.0;
   out_157508777103841027[81] = 0.0;
   out_157508777103841027[82] = 0.0;
   out_157508777103841027[83] = 0.0;
   out_157508777103841027[84] = 0.0;
   out_157508777103841027[85] = 0.0;
   out_157508777103841027[86] = 0.0;
   out_157508777103841027[87] = 0.0;
   out_157508777103841027[88] = 0.0;
   out_157508777103841027[89] = 0.0;
   out_157508777103841027[90] = 0.0;
   out_157508777103841027[91] = 0.0;
   out_157508777103841027[92] = 0.0;
   out_157508777103841027[93] = 0.0;
   out_157508777103841027[94] = 0.0;
   out_157508777103841027[95] = 1.0;
   out_157508777103841027[96] = 0.0;
   out_157508777103841027[97] = 0.0;
   out_157508777103841027[98] = 0.0;
   out_157508777103841027[99] = 0.0;
   out_157508777103841027[100] = 0.0;
   out_157508777103841027[101] = 0.0;
   out_157508777103841027[102] = 0.0;
   out_157508777103841027[103] = 0.0;
   out_157508777103841027[104] = 0.0;
   out_157508777103841027[105] = 0.0;
   out_157508777103841027[106] = 0.0;
   out_157508777103841027[107] = 0.0;
   out_157508777103841027[108] = 0.0;
   out_157508777103841027[109] = 0.0;
   out_157508777103841027[110] = 0.0;
   out_157508777103841027[111] = 0.0;
   out_157508777103841027[112] = 0.0;
   out_157508777103841027[113] = 0.0;
   out_157508777103841027[114] = 1.0;
   out_157508777103841027[115] = 0.0;
   out_157508777103841027[116] = 0.0;
   out_157508777103841027[117] = 0.0;
   out_157508777103841027[118] = 0.0;
   out_157508777103841027[119] = 0.0;
   out_157508777103841027[120] = 0.0;
   out_157508777103841027[121] = 0.0;
   out_157508777103841027[122] = 0.0;
   out_157508777103841027[123] = 0.0;
   out_157508777103841027[124] = 0.0;
   out_157508777103841027[125] = 0.0;
   out_157508777103841027[126] = 0.0;
   out_157508777103841027[127] = 0.0;
   out_157508777103841027[128] = 0.0;
   out_157508777103841027[129] = 0.0;
   out_157508777103841027[130] = 0.0;
   out_157508777103841027[131] = 0.0;
   out_157508777103841027[132] = 0.0;
   out_157508777103841027[133] = 1.0;
   out_157508777103841027[134] = 0.0;
   out_157508777103841027[135] = 0.0;
   out_157508777103841027[136] = 0.0;
   out_157508777103841027[137] = 0.0;
   out_157508777103841027[138] = 0.0;
   out_157508777103841027[139] = 0.0;
   out_157508777103841027[140] = 0.0;
   out_157508777103841027[141] = 0.0;
   out_157508777103841027[142] = 0.0;
   out_157508777103841027[143] = 0.0;
   out_157508777103841027[144] = 0.0;
   out_157508777103841027[145] = 0.0;
   out_157508777103841027[146] = 0.0;
   out_157508777103841027[147] = 0.0;
   out_157508777103841027[148] = 0.0;
   out_157508777103841027[149] = 0.0;
   out_157508777103841027[150] = 0.0;
   out_157508777103841027[151] = 0.0;
   out_157508777103841027[152] = 1.0;
   out_157508777103841027[153] = 0.0;
   out_157508777103841027[154] = 0.0;
   out_157508777103841027[155] = 0.0;
   out_157508777103841027[156] = 0.0;
   out_157508777103841027[157] = 0.0;
   out_157508777103841027[158] = 0.0;
   out_157508777103841027[159] = 0.0;
   out_157508777103841027[160] = 0.0;
   out_157508777103841027[161] = 0.0;
   out_157508777103841027[162] = 0.0;
   out_157508777103841027[163] = 0.0;
   out_157508777103841027[164] = 0.0;
   out_157508777103841027[165] = 0.0;
   out_157508777103841027[166] = 0.0;
   out_157508777103841027[167] = 0.0;
   out_157508777103841027[168] = 0.0;
   out_157508777103841027[169] = 0.0;
   out_157508777103841027[170] = 0.0;
   out_157508777103841027[171] = 1.0;
   out_157508777103841027[172] = 0.0;
   out_157508777103841027[173] = 0.0;
   out_157508777103841027[174] = 0.0;
   out_157508777103841027[175] = 0.0;
   out_157508777103841027[176] = 0.0;
   out_157508777103841027[177] = 0.0;
   out_157508777103841027[178] = 0.0;
   out_157508777103841027[179] = 0.0;
   out_157508777103841027[180] = 0.0;
   out_157508777103841027[181] = 0.0;
   out_157508777103841027[182] = 0.0;
   out_157508777103841027[183] = 0.0;
   out_157508777103841027[184] = 0.0;
   out_157508777103841027[185] = 0.0;
   out_157508777103841027[186] = 0.0;
   out_157508777103841027[187] = 0.0;
   out_157508777103841027[188] = 0.0;
   out_157508777103841027[189] = 0.0;
   out_157508777103841027[190] = 1.0;
   out_157508777103841027[191] = 0.0;
   out_157508777103841027[192] = 0.0;
   out_157508777103841027[193] = 0.0;
   out_157508777103841027[194] = 0.0;
   out_157508777103841027[195] = 0.0;
   out_157508777103841027[196] = 0.0;
   out_157508777103841027[197] = 0.0;
   out_157508777103841027[198] = 0.0;
   out_157508777103841027[199] = 0.0;
   out_157508777103841027[200] = 0.0;
   out_157508777103841027[201] = 0.0;
   out_157508777103841027[202] = 0.0;
   out_157508777103841027[203] = 0.0;
   out_157508777103841027[204] = 0.0;
   out_157508777103841027[205] = 0.0;
   out_157508777103841027[206] = 0.0;
   out_157508777103841027[207] = 0.0;
   out_157508777103841027[208] = 0.0;
   out_157508777103841027[209] = 1.0;
   out_157508777103841027[210] = 0.0;
   out_157508777103841027[211] = 0.0;
   out_157508777103841027[212] = 0.0;
   out_157508777103841027[213] = 0.0;
   out_157508777103841027[214] = 0.0;
   out_157508777103841027[215] = 0.0;
   out_157508777103841027[216] = 0.0;
   out_157508777103841027[217] = 0.0;
   out_157508777103841027[218] = 0.0;
   out_157508777103841027[219] = 0.0;
   out_157508777103841027[220] = 0.0;
   out_157508777103841027[221] = 0.0;
   out_157508777103841027[222] = 0.0;
   out_157508777103841027[223] = 0.0;
   out_157508777103841027[224] = 0.0;
   out_157508777103841027[225] = 0.0;
   out_157508777103841027[226] = 0.0;
   out_157508777103841027[227] = 0.0;
   out_157508777103841027[228] = 1.0;
   out_157508777103841027[229] = 0.0;
   out_157508777103841027[230] = 0.0;
   out_157508777103841027[231] = 0.0;
   out_157508777103841027[232] = 0.0;
   out_157508777103841027[233] = 0.0;
   out_157508777103841027[234] = 0.0;
   out_157508777103841027[235] = 0.0;
   out_157508777103841027[236] = 0.0;
   out_157508777103841027[237] = 0.0;
   out_157508777103841027[238] = 0.0;
   out_157508777103841027[239] = 0.0;
   out_157508777103841027[240] = 0.0;
   out_157508777103841027[241] = 0.0;
   out_157508777103841027[242] = 0.0;
   out_157508777103841027[243] = 0.0;
   out_157508777103841027[244] = 0.0;
   out_157508777103841027[245] = 0.0;
   out_157508777103841027[246] = 0.0;
   out_157508777103841027[247] = 1.0;
   out_157508777103841027[248] = 0.0;
   out_157508777103841027[249] = 0.0;
   out_157508777103841027[250] = 0.0;
   out_157508777103841027[251] = 0.0;
   out_157508777103841027[252] = 0.0;
   out_157508777103841027[253] = 0.0;
   out_157508777103841027[254] = 0.0;
   out_157508777103841027[255] = 0.0;
   out_157508777103841027[256] = 0.0;
   out_157508777103841027[257] = 0.0;
   out_157508777103841027[258] = 0.0;
   out_157508777103841027[259] = 0.0;
   out_157508777103841027[260] = 0.0;
   out_157508777103841027[261] = 0.0;
   out_157508777103841027[262] = 0.0;
   out_157508777103841027[263] = 0.0;
   out_157508777103841027[264] = 0.0;
   out_157508777103841027[265] = 0.0;
   out_157508777103841027[266] = 1.0;
   out_157508777103841027[267] = 0.0;
   out_157508777103841027[268] = 0.0;
   out_157508777103841027[269] = 0.0;
   out_157508777103841027[270] = 0.0;
   out_157508777103841027[271] = 0.0;
   out_157508777103841027[272] = 0.0;
   out_157508777103841027[273] = 0.0;
   out_157508777103841027[274] = 0.0;
   out_157508777103841027[275] = 0.0;
   out_157508777103841027[276] = 0.0;
   out_157508777103841027[277] = 0.0;
   out_157508777103841027[278] = 0.0;
   out_157508777103841027[279] = 0.0;
   out_157508777103841027[280] = 0.0;
   out_157508777103841027[281] = 0.0;
   out_157508777103841027[282] = 0.0;
   out_157508777103841027[283] = 0.0;
   out_157508777103841027[284] = 0.0;
   out_157508777103841027[285] = 1.0;
   out_157508777103841027[286] = 0.0;
   out_157508777103841027[287] = 0.0;
   out_157508777103841027[288] = 0.0;
   out_157508777103841027[289] = 0.0;
   out_157508777103841027[290] = 0.0;
   out_157508777103841027[291] = 0.0;
   out_157508777103841027[292] = 0.0;
   out_157508777103841027[293] = 0.0;
   out_157508777103841027[294] = 0.0;
   out_157508777103841027[295] = 0.0;
   out_157508777103841027[296] = 0.0;
   out_157508777103841027[297] = 0.0;
   out_157508777103841027[298] = 0.0;
   out_157508777103841027[299] = 0.0;
   out_157508777103841027[300] = 0.0;
   out_157508777103841027[301] = 0.0;
   out_157508777103841027[302] = 0.0;
   out_157508777103841027[303] = 0.0;
   out_157508777103841027[304] = 1.0;
   out_157508777103841027[305] = 0.0;
   out_157508777103841027[306] = 0.0;
   out_157508777103841027[307] = 0.0;
   out_157508777103841027[308] = 0.0;
   out_157508777103841027[309] = 0.0;
   out_157508777103841027[310] = 0.0;
   out_157508777103841027[311] = 0.0;
   out_157508777103841027[312] = 0.0;
   out_157508777103841027[313] = 0.0;
   out_157508777103841027[314] = 0.0;
   out_157508777103841027[315] = 0.0;
   out_157508777103841027[316] = 0.0;
   out_157508777103841027[317] = 0.0;
   out_157508777103841027[318] = 0.0;
   out_157508777103841027[319] = 0.0;
   out_157508777103841027[320] = 0.0;
   out_157508777103841027[321] = 0.0;
   out_157508777103841027[322] = 0.0;
   out_157508777103841027[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_488772806955075569) {
   out_488772806955075569[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_488772806955075569[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_488772806955075569[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_488772806955075569[3] = dt*state[12] + state[3];
   out_488772806955075569[4] = dt*state[13] + state[4];
   out_488772806955075569[5] = dt*state[14] + state[5];
   out_488772806955075569[6] = state[6];
   out_488772806955075569[7] = state[7];
   out_488772806955075569[8] = state[8];
   out_488772806955075569[9] = state[9];
   out_488772806955075569[10] = state[10];
   out_488772806955075569[11] = state[11];
   out_488772806955075569[12] = state[12];
   out_488772806955075569[13] = state[13];
   out_488772806955075569[14] = state[14];
   out_488772806955075569[15] = state[15];
   out_488772806955075569[16] = state[16];
   out_488772806955075569[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4053952474543882038) {
   out_4053952474543882038[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4053952474543882038[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4053952474543882038[2] = 0;
   out_4053952474543882038[3] = 0;
   out_4053952474543882038[4] = 0;
   out_4053952474543882038[5] = 0;
   out_4053952474543882038[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4053952474543882038[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4053952474543882038[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4053952474543882038[9] = 0;
   out_4053952474543882038[10] = 0;
   out_4053952474543882038[11] = 0;
   out_4053952474543882038[12] = 0;
   out_4053952474543882038[13] = 0;
   out_4053952474543882038[14] = 0;
   out_4053952474543882038[15] = 0;
   out_4053952474543882038[16] = 0;
   out_4053952474543882038[17] = 0;
   out_4053952474543882038[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4053952474543882038[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4053952474543882038[20] = 0;
   out_4053952474543882038[21] = 0;
   out_4053952474543882038[22] = 0;
   out_4053952474543882038[23] = 0;
   out_4053952474543882038[24] = 0;
   out_4053952474543882038[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4053952474543882038[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4053952474543882038[27] = 0;
   out_4053952474543882038[28] = 0;
   out_4053952474543882038[29] = 0;
   out_4053952474543882038[30] = 0;
   out_4053952474543882038[31] = 0;
   out_4053952474543882038[32] = 0;
   out_4053952474543882038[33] = 0;
   out_4053952474543882038[34] = 0;
   out_4053952474543882038[35] = 0;
   out_4053952474543882038[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4053952474543882038[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4053952474543882038[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4053952474543882038[39] = 0;
   out_4053952474543882038[40] = 0;
   out_4053952474543882038[41] = 0;
   out_4053952474543882038[42] = 0;
   out_4053952474543882038[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4053952474543882038[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4053952474543882038[45] = 0;
   out_4053952474543882038[46] = 0;
   out_4053952474543882038[47] = 0;
   out_4053952474543882038[48] = 0;
   out_4053952474543882038[49] = 0;
   out_4053952474543882038[50] = 0;
   out_4053952474543882038[51] = 0;
   out_4053952474543882038[52] = 0;
   out_4053952474543882038[53] = 0;
   out_4053952474543882038[54] = 0;
   out_4053952474543882038[55] = 0;
   out_4053952474543882038[56] = 0;
   out_4053952474543882038[57] = 1;
   out_4053952474543882038[58] = 0;
   out_4053952474543882038[59] = 0;
   out_4053952474543882038[60] = 0;
   out_4053952474543882038[61] = 0;
   out_4053952474543882038[62] = 0;
   out_4053952474543882038[63] = 0;
   out_4053952474543882038[64] = 0;
   out_4053952474543882038[65] = 0;
   out_4053952474543882038[66] = dt;
   out_4053952474543882038[67] = 0;
   out_4053952474543882038[68] = 0;
   out_4053952474543882038[69] = 0;
   out_4053952474543882038[70] = 0;
   out_4053952474543882038[71] = 0;
   out_4053952474543882038[72] = 0;
   out_4053952474543882038[73] = 0;
   out_4053952474543882038[74] = 0;
   out_4053952474543882038[75] = 0;
   out_4053952474543882038[76] = 1;
   out_4053952474543882038[77] = 0;
   out_4053952474543882038[78] = 0;
   out_4053952474543882038[79] = 0;
   out_4053952474543882038[80] = 0;
   out_4053952474543882038[81] = 0;
   out_4053952474543882038[82] = 0;
   out_4053952474543882038[83] = 0;
   out_4053952474543882038[84] = 0;
   out_4053952474543882038[85] = dt;
   out_4053952474543882038[86] = 0;
   out_4053952474543882038[87] = 0;
   out_4053952474543882038[88] = 0;
   out_4053952474543882038[89] = 0;
   out_4053952474543882038[90] = 0;
   out_4053952474543882038[91] = 0;
   out_4053952474543882038[92] = 0;
   out_4053952474543882038[93] = 0;
   out_4053952474543882038[94] = 0;
   out_4053952474543882038[95] = 1;
   out_4053952474543882038[96] = 0;
   out_4053952474543882038[97] = 0;
   out_4053952474543882038[98] = 0;
   out_4053952474543882038[99] = 0;
   out_4053952474543882038[100] = 0;
   out_4053952474543882038[101] = 0;
   out_4053952474543882038[102] = 0;
   out_4053952474543882038[103] = 0;
   out_4053952474543882038[104] = dt;
   out_4053952474543882038[105] = 0;
   out_4053952474543882038[106] = 0;
   out_4053952474543882038[107] = 0;
   out_4053952474543882038[108] = 0;
   out_4053952474543882038[109] = 0;
   out_4053952474543882038[110] = 0;
   out_4053952474543882038[111] = 0;
   out_4053952474543882038[112] = 0;
   out_4053952474543882038[113] = 0;
   out_4053952474543882038[114] = 1;
   out_4053952474543882038[115] = 0;
   out_4053952474543882038[116] = 0;
   out_4053952474543882038[117] = 0;
   out_4053952474543882038[118] = 0;
   out_4053952474543882038[119] = 0;
   out_4053952474543882038[120] = 0;
   out_4053952474543882038[121] = 0;
   out_4053952474543882038[122] = 0;
   out_4053952474543882038[123] = 0;
   out_4053952474543882038[124] = 0;
   out_4053952474543882038[125] = 0;
   out_4053952474543882038[126] = 0;
   out_4053952474543882038[127] = 0;
   out_4053952474543882038[128] = 0;
   out_4053952474543882038[129] = 0;
   out_4053952474543882038[130] = 0;
   out_4053952474543882038[131] = 0;
   out_4053952474543882038[132] = 0;
   out_4053952474543882038[133] = 1;
   out_4053952474543882038[134] = 0;
   out_4053952474543882038[135] = 0;
   out_4053952474543882038[136] = 0;
   out_4053952474543882038[137] = 0;
   out_4053952474543882038[138] = 0;
   out_4053952474543882038[139] = 0;
   out_4053952474543882038[140] = 0;
   out_4053952474543882038[141] = 0;
   out_4053952474543882038[142] = 0;
   out_4053952474543882038[143] = 0;
   out_4053952474543882038[144] = 0;
   out_4053952474543882038[145] = 0;
   out_4053952474543882038[146] = 0;
   out_4053952474543882038[147] = 0;
   out_4053952474543882038[148] = 0;
   out_4053952474543882038[149] = 0;
   out_4053952474543882038[150] = 0;
   out_4053952474543882038[151] = 0;
   out_4053952474543882038[152] = 1;
   out_4053952474543882038[153] = 0;
   out_4053952474543882038[154] = 0;
   out_4053952474543882038[155] = 0;
   out_4053952474543882038[156] = 0;
   out_4053952474543882038[157] = 0;
   out_4053952474543882038[158] = 0;
   out_4053952474543882038[159] = 0;
   out_4053952474543882038[160] = 0;
   out_4053952474543882038[161] = 0;
   out_4053952474543882038[162] = 0;
   out_4053952474543882038[163] = 0;
   out_4053952474543882038[164] = 0;
   out_4053952474543882038[165] = 0;
   out_4053952474543882038[166] = 0;
   out_4053952474543882038[167] = 0;
   out_4053952474543882038[168] = 0;
   out_4053952474543882038[169] = 0;
   out_4053952474543882038[170] = 0;
   out_4053952474543882038[171] = 1;
   out_4053952474543882038[172] = 0;
   out_4053952474543882038[173] = 0;
   out_4053952474543882038[174] = 0;
   out_4053952474543882038[175] = 0;
   out_4053952474543882038[176] = 0;
   out_4053952474543882038[177] = 0;
   out_4053952474543882038[178] = 0;
   out_4053952474543882038[179] = 0;
   out_4053952474543882038[180] = 0;
   out_4053952474543882038[181] = 0;
   out_4053952474543882038[182] = 0;
   out_4053952474543882038[183] = 0;
   out_4053952474543882038[184] = 0;
   out_4053952474543882038[185] = 0;
   out_4053952474543882038[186] = 0;
   out_4053952474543882038[187] = 0;
   out_4053952474543882038[188] = 0;
   out_4053952474543882038[189] = 0;
   out_4053952474543882038[190] = 1;
   out_4053952474543882038[191] = 0;
   out_4053952474543882038[192] = 0;
   out_4053952474543882038[193] = 0;
   out_4053952474543882038[194] = 0;
   out_4053952474543882038[195] = 0;
   out_4053952474543882038[196] = 0;
   out_4053952474543882038[197] = 0;
   out_4053952474543882038[198] = 0;
   out_4053952474543882038[199] = 0;
   out_4053952474543882038[200] = 0;
   out_4053952474543882038[201] = 0;
   out_4053952474543882038[202] = 0;
   out_4053952474543882038[203] = 0;
   out_4053952474543882038[204] = 0;
   out_4053952474543882038[205] = 0;
   out_4053952474543882038[206] = 0;
   out_4053952474543882038[207] = 0;
   out_4053952474543882038[208] = 0;
   out_4053952474543882038[209] = 1;
   out_4053952474543882038[210] = 0;
   out_4053952474543882038[211] = 0;
   out_4053952474543882038[212] = 0;
   out_4053952474543882038[213] = 0;
   out_4053952474543882038[214] = 0;
   out_4053952474543882038[215] = 0;
   out_4053952474543882038[216] = 0;
   out_4053952474543882038[217] = 0;
   out_4053952474543882038[218] = 0;
   out_4053952474543882038[219] = 0;
   out_4053952474543882038[220] = 0;
   out_4053952474543882038[221] = 0;
   out_4053952474543882038[222] = 0;
   out_4053952474543882038[223] = 0;
   out_4053952474543882038[224] = 0;
   out_4053952474543882038[225] = 0;
   out_4053952474543882038[226] = 0;
   out_4053952474543882038[227] = 0;
   out_4053952474543882038[228] = 1;
   out_4053952474543882038[229] = 0;
   out_4053952474543882038[230] = 0;
   out_4053952474543882038[231] = 0;
   out_4053952474543882038[232] = 0;
   out_4053952474543882038[233] = 0;
   out_4053952474543882038[234] = 0;
   out_4053952474543882038[235] = 0;
   out_4053952474543882038[236] = 0;
   out_4053952474543882038[237] = 0;
   out_4053952474543882038[238] = 0;
   out_4053952474543882038[239] = 0;
   out_4053952474543882038[240] = 0;
   out_4053952474543882038[241] = 0;
   out_4053952474543882038[242] = 0;
   out_4053952474543882038[243] = 0;
   out_4053952474543882038[244] = 0;
   out_4053952474543882038[245] = 0;
   out_4053952474543882038[246] = 0;
   out_4053952474543882038[247] = 1;
   out_4053952474543882038[248] = 0;
   out_4053952474543882038[249] = 0;
   out_4053952474543882038[250] = 0;
   out_4053952474543882038[251] = 0;
   out_4053952474543882038[252] = 0;
   out_4053952474543882038[253] = 0;
   out_4053952474543882038[254] = 0;
   out_4053952474543882038[255] = 0;
   out_4053952474543882038[256] = 0;
   out_4053952474543882038[257] = 0;
   out_4053952474543882038[258] = 0;
   out_4053952474543882038[259] = 0;
   out_4053952474543882038[260] = 0;
   out_4053952474543882038[261] = 0;
   out_4053952474543882038[262] = 0;
   out_4053952474543882038[263] = 0;
   out_4053952474543882038[264] = 0;
   out_4053952474543882038[265] = 0;
   out_4053952474543882038[266] = 1;
   out_4053952474543882038[267] = 0;
   out_4053952474543882038[268] = 0;
   out_4053952474543882038[269] = 0;
   out_4053952474543882038[270] = 0;
   out_4053952474543882038[271] = 0;
   out_4053952474543882038[272] = 0;
   out_4053952474543882038[273] = 0;
   out_4053952474543882038[274] = 0;
   out_4053952474543882038[275] = 0;
   out_4053952474543882038[276] = 0;
   out_4053952474543882038[277] = 0;
   out_4053952474543882038[278] = 0;
   out_4053952474543882038[279] = 0;
   out_4053952474543882038[280] = 0;
   out_4053952474543882038[281] = 0;
   out_4053952474543882038[282] = 0;
   out_4053952474543882038[283] = 0;
   out_4053952474543882038[284] = 0;
   out_4053952474543882038[285] = 1;
   out_4053952474543882038[286] = 0;
   out_4053952474543882038[287] = 0;
   out_4053952474543882038[288] = 0;
   out_4053952474543882038[289] = 0;
   out_4053952474543882038[290] = 0;
   out_4053952474543882038[291] = 0;
   out_4053952474543882038[292] = 0;
   out_4053952474543882038[293] = 0;
   out_4053952474543882038[294] = 0;
   out_4053952474543882038[295] = 0;
   out_4053952474543882038[296] = 0;
   out_4053952474543882038[297] = 0;
   out_4053952474543882038[298] = 0;
   out_4053952474543882038[299] = 0;
   out_4053952474543882038[300] = 0;
   out_4053952474543882038[301] = 0;
   out_4053952474543882038[302] = 0;
   out_4053952474543882038[303] = 0;
   out_4053952474543882038[304] = 1;
   out_4053952474543882038[305] = 0;
   out_4053952474543882038[306] = 0;
   out_4053952474543882038[307] = 0;
   out_4053952474543882038[308] = 0;
   out_4053952474543882038[309] = 0;
   out_4053952474543882038[310] = 0;
   out_4053952474543882038[311] = 0;
   out_4053952474543882038[312] = 0;
   out_4053952474543882038[313] = 0;
   out_4053952474543882038[314] = 0;
   out_4053952474543882038[315] = 0;
   out_4053952474543882038[316] = 0;
   out_4053952474543882038[317] = 0;
   out_4053952474543882038[318] = 0;
   out_4053952474543882038[319] = 0;
   out_4053952474543882038[320] = 0;
   out_4053952474543882038[321] = 0;
   out_4053952474543882038[322] = 0;
   out_4053952474543882038[323] = 1;
}
void h_4(double *state, double *unused, double *out_3761869252140862000) {
   out_3761869252140862000[0] = state[6] + state[9];
   out_3761869252140862000[1] = state[7] + state[10];
   out_3761869252140862000[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2736167434181912294) {
   out_2736167434181912294[0] = 0;
   out_2736167434181912294[1] = 0;
   out_2736167434181912294[2] = 0;
   out_2736167434181912294[3] = 0;
   out_2736167434181912294[4] = 0;
   out_2736167434181912294[5] = 0;
   out_2736167434181912294[6] = 1;
   out_2736167434181912294[7] = 0;
   out_2736167434181912294[8] = 0;
   out_2736167434181912294[9] = 1;
   out_2736167434181912294[10] = 0;
   out_2736167434181912294[11] = 0;
   out_2736167434181912294[12] = 0;
   out_2736167434181912294[13] = 0;
   out_2736167434181912294[14] = 0;
   out_2736167434181912294[15] = 0;
   out_2736167434181912294[16] = 0;
   out_2736167434181912294[17] = 0;
   out_2736167434181912294[18] = 0;
   out_2736167434181912294[19] = 0;
   out_2736167434181912294[20] = 0;
   out_2736167434181912294[21] = 0;
   out_2736167434181912294[22] = 0;
   out_2736167434181912294[23] = 0;
   out_2736167434181912294[24] = 0;
   out_2736167434181912294[25] = 1;
   out_2736167434181912294[26] = 0;
   out_2736167434181912294[27] = 0;
   out_2736167434181912294[28] = 1;
   out_2736167434181912294[29] = 0;
   out_2736167434181912294[30] = 0;
   out_2736167434181912294[31] = 0;
   out_2736167434181912294[32] = 0;
   out_2736167434181912294[33] = 0;
   out_2736167434181912294[34] = 0;
   out_2736167434181912294[35] = 0;
   out_2736167434181912294[36] = 0;
   out_2736167434181912294[37] = 0;
   out_2736167434181912294[38] = 0;
   out_2736167434181912294[39] = 0;
   out_2736167434181912294[40] = 0;
   out_2736167434181912294[41] = 0;
   out_2736167434181912294[42] = 0;
   out_2736167434181912294[43] = 0;
   out_2736167434181912294[44] = 1;
   out_2736167434181912294[45] = 0;
   out_2736167434181912294[46] = 0;
   out_2736167434181912294[47] = 1;
   out_2736167434181912294[48] = 0;
   out_2736167434181912294[49] = 0;
   out_2736167434181912294[50] = 0;
   out_2736167434181912294[51] = 0;
   out_2736167434181912294[52] = 0;
   out_2736167434181912294[53] = 0;
}
void h_10(double *state, double *unused, double *out_5019928406836969817) {
   out_5019928406836969817[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5019928406836969817[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5019928406836969817[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2772140546624323337) {
   out_2772140546624323337[0] = 0;
   out_2772140546624323337[1] = 9.8100000000000005*cos(state[1]);
   out_2772140546624323337[2] = 0;
   out_2772140546624323337[3] = 0;
   out_2772140546624323337[4] = -state[8];
   out_2772140546624323337[5] = state[7];
   out_2772140546624323337[6] = 0;
   out_2772140546624323337[7] = state[5];
   out_2772140546624323337[8] = -state[4];
   out_2772140546624323337[9] = 0;
   out_2772140546624323337[10] = 0;
   out_2772140546624323337[11] = 0;
   out_2772140546624323337[12] = 1;
   out_2772140546624323337[13] = 0;
   out_2772140546624323337[14] = 0;
   out_2772140546624323337[15] = 1;
   out_2772140546624323337[16] = 0;
   out_2772140546624323337[17] = 0;
   out_2772140546624323337[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2772140546624323337[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2772140546624323337[20] = 0;
   out_2772140546624323337[21] = state[8];
   out_2772140546624323337[22] = 0;
   out_2772140546624323337[23] = -state[6];
   out_2772140546624323337[24] = -state[5];
   out_2772140546624323337[25] = 0;
   out_2772140546624323337[26] = state[3];
   out_2772140546624323337[27] = 0;
   out_2772140546624323337[28] = 0;
   out_2772140546624323337[29] = 0;
   out_2772140546624323337[30] = 0;
   out_2772140546624323337[31] = 1;
   out_2772140546624323337[32] = 0;
   out_2772140546624323337[33] = 0;
   out_2772140546624323337[34] = 1;
   out_2772140546624323337[35] = 0;
   out_2772140546624323337[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2772140546624323337[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2772140546624323337[38] = 0;
   out_2772140546624323337[39] = -state[7];
   out_2772140546624323337[40] = state[6];
   out_2772140546624323337[41] = 0;
   out_2772140546624323337[42] = state[4];
   out_2772140546624323337[43] = -state[3];
   out_2772140546624323337[44] = 0;
   out_2772140546624323337[45] = 0;
   out_2772140546624323337[46] = 0;
   out_2772140546624323337[47] = 0;
   out_2772140546624323337[48] = 0;
   out_2772140546624323337[49] = 0;
   out_2772140546624323337[50] = 1;
   out_2772140546624323337[51] = 0;
   out_2772140546624323337[52] = 0;
   out_2772140546624323337[53] = 1;
}
void h_13(double *state, double *unused, double *out_1798578478729464014) {
   out_1798578478729464014[0] = state[3];
   out_1798578478729464014[1] = state[4];
   out_1798578478729464014[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1097588029120611730) {
   out_1097588029120611730[0] = 0;
   out_1097588029120611730[1] = 0;
   out_1097588029120611730[2] = 0;
   out_1097588029120611730[3] = 1;
   out_1097588029120611730[4] = 0;
   out_1097588029120611730[5] = 0;
   out_1097588029120611730[6] = 0;
   out_1097588029120611730[7] = 0;
   out_1097588029120611730[8] = 0;
   out_1097588029120611730[9] = 0;
   out_1097588029120611730[10] = 0;
   out_1097588029120611730[11] = 0;
   out_1097588029120611730[12] = 0;
   out_1097588029120611730[13] = 0;
   out_1097588029120611730[14] = 0;
   out_1097588029120611730[15] = 0;
   out_1097588029120611730[16] = 0;
   out_1097588029120611730[17] = 0;
   out_1097588029120611730[18] = 0;
   out_1097588029120611730[19] = 0;
   out_1097588029120611730[20] = 0;
   out_1097588029120611730[21] = 0;
   out_1097588029120611730[22] = 1;
   out_1097588029120611730[23] = 0;
   out_1097588029120611730[24] = 0;
   out_1097588029120611730[25] = 0;
   out_1097588029120611730[26] = 0;
   out_1097588029120611730[27] = 0;
   out_1097588029120611730[28] = 0;
   out_1097588029120611730[29] = 0;
   out_1097588029120611730[30] = 0;
   out_1097588029120611730[31] = 0;
   out_1097588029120611730[32] = 0;
   out_1097588029120611730[33] = 0;
   out_1097588029120611730[34] = 0;
   out_1097588029120611730[35] = 0;
   out_1097588029120611730[36] = 0;
   out_1097588029120611730[37] = 0;
   out_1097588029120611730[38] = 0;
   out_1097588029120611730[39] = 0;
   out_1097588029120611730[40] = 0;
   out_1097588029120611730[41] = 1;
   out_1097588029120611730[42] = 0;
   out_1097588029120611730[43] = 0;
   out_1097588029120611730[44] = 0;
   out_1097588029120611730[45] = 0;
   out_1097588029120611730[46] = 0;
   out_1097588029120611730[47] = 0;
   out_1097588029120611730[48] = 0;
   out_1097588029120611730[49] = 0;
   out_1097588029120611730[50] = 0;
   out_1097588029120611730[51] = 0;
   out_1097588029120611730[52] = 0;
   out_1097588029120611730[53] = 0;
}
void h_14(double *state, double *unused, double *out_1188008182786197296) {
   out_1188008182786197296[0] = state[6];
   out_1188008182786197296[1] = state[7];
   out_1188008182786197296[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4744978381097828130) {
   out_4744978381097828130[0] = 0;
   out_4744978381097828130[1] = 0;
   out_4744978381097828130[2] = 0;
   out_4744978381097828130[3] = 0;
   out_4744978381097828130[4] = 0;
   out_4744978381097828130[5] = 0;
   out_4744978381097828130[6] = 1;
   out_4744978381097828130[7] = 0;
   out_4744978381097828130[8] = 0;
   out_4744978381097828130[9] = 0;
   out_4744978381097828130[10] = 0;
   out_4744978381097828130[11] = 0;
   out_4744978381097828130[12] = 0;
   out_4744978381097828130[13] = 0;
   out_4744978381097828130[14] = 0;
   out_4744978381097828130[15] = 0;
   out_4744978381097828130[16] = 0;
   out_4744978381097828130[17] = 0;
   out_4744978381097828130[18] = 0;
   out_4744978381097828130[19] = 0;
   out_4744978381097828130[20] = 0;
   out_4744978381097828130[21] = 0;
   out_4744978381097828130[22] = 0;
   out_4744978381097828130[23] = 0;
   out_4744978381097828130[24] = 0;
   out_4744978381097828130[25] = 1;
   out_4744978381097828130[26] = 0;
   out_4744978381097828130[27] = 0;
   out_4744978381097828130[28] = 0;
   out_4744978381097828130[29] = 0;
   out_4744978381097828130[30] = 0;
   out_4744978381097828130[31] = 0;
   out_4744978381097828130[32] = 0;
   out_4744978381097828130[33] = 0;
   out_4744978381097828130[34] = 0;
   out_4744978381097828130[35] = 0;
   out_4744978381097828130[36] = 0;
   out_4744978381097828130[37] = 0;
   out_4744978381097828130[38] = 0;
   out_4744978381097828130[39] = 0;
   out_4744978381097828130[40] = 0;
   out_4744978381097828130[41] = 0;
   out_4744978381097828130[42] = 0;
   out_4744978381097828130[43] = 0;
   out_4744978381097828130[44] = 1;
   out_4744978381097828130[45] = 0;
   out_4744978381097828130[46] = 0;
   out_4744978381097828130[47] = 0;
   out_4744978381097828130[48] = 0;
   out_4744978381097828130[49] = 0;
   out_4744978381097828130[50] = 0;
   out_4744978381097828130[51] = 0;
   out_4744978381097828130[52] = 0;
   out_4744978381097828130[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_5883224282319393425) {
  err_fun(nom_x, delta_x, out_5883224282319393425);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_266692242281043755) {
  inv_err_fun(nom_x, true_x, out_266692242281043755);
}
void pose_H_mod_fun(double *state, double *out_157508777103841027) {
  H_mod_fun(state, out_157508777103841027);
}
void pose_f_fun(double *state, double dt, double *out_488772806955075569) {
  f_fun(state,  dt, out_488772806955075569);
}
void pose_F_fun(double *state, double dt, double *out_4053952474543882038) {
  F_fun(state,  dt, out_4053952474543882038);
}
void pose_h_4(double *state, double *unused, double *out_3761869252140862000) {
  h_4(state, unused, out_3761869252140862000);
}
void pose_H_4(double *state, double *unused, double *out_2736167434181912294) {
  H_4(state, unused, out_2736167434181912294);
}
void pose_h_10(double *state, double *unused, double *out_5019928406836969817) {
  h_10(state, unused, out_5019928406836969817);
}
void pose_H_10(double *state, double *unused, double *out_2772140546624323337) {
  H_10(state, unused, out_2772140546624323337);
}
void pose_h_13(double *state, double *unused, double *out_1798578478729464014) {
  h_13(state, unused, out_1798578478729464014);
}
void pose_H_13(double *state, double *unused, double *out_1097588029120611730) {
  H_13(state, unused, out_1097588029120611730);
}
void pose_h_14(double *state, double *unused, double *out_1188008182786197296) {
  h_14(state, unused, out_1188008182786197296);
}
void pose_H_14(double *state, double *unused, double *out_4744978381097828130) {
  H_14(state, unused, out_4744978381097828130);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
