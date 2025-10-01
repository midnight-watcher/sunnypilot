#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5068820853483992556) {
   out_5068820853483992556[0] = delta_x[0] + nom_x[0];
   out_5068820853483992556[1] = delta_x[1] + nom_x[1];
   out_5068820853483992556[2] = delta_x[2] + nom_x[2];
   out_5068820853483992556[3] = delta_x[3] + nom_x[3];
   out_5068820853483992556[4] = delta_x[4] + nom_x[4];
   out_5068820853483992556[5] = delta_x[5] + nom_x[5];
   out_5068820853483992556[6] = delta_x[6] + nom_x[6];
   out_5068820853483992556[7] = delta_x[7] + nom_x[7];
   out_5068820853483992556[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5097641143412691511) {
   out_5097641143412691511[0] = -nom_x[0] + true_x[0];
   out_5097641143412691511[1] = -nom_x[1] + true_x[1];
   out_5097641143412691511[2] = -nom_x[2] + true_x[2];
   out_5097641143412691511[3] = -nom_x[3] + true_x[3];
   out_5097641143412691511[4] = -nom_x[4] + true_x[4];
   out_5097641143412691511[5] = -nom_x[5] + true_x[5];
   out_5097641143412691511[6] = -nom_x[6] + true_x[6];
   out_5097641143412691511[7] = -nom_x[7] + true_x[7];
   out_5097641143412691511[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3574535823991284745) {
   out_3574535823991284745[0] = 1.0;
   out_3574535823991284745[1] = 0.0;
   out_3574535823991284745[2] = 0.0;
   out_3574535823991284745[3] = 0.0;
   out_3574535823991284745[4] = 0.0;
   out_3574535823991284745[5] = 0.0;
   out_3574535823991284745[6] = 0.0;
   out_3574535823991284745[7] = 0.0;
   out_3574535823991284745[8] = 0.0;
   out_3574535823991284745[9] = 0.0;
   out_3574535823991284745[10] = 1.0;
   out_3574535823991284745[11] = 0.0;
   out_3574535823991284745[12] = 0.0;
   out_3574535823991284745[13] = 0.0;
   out_3574535823991284745[14] = 0.0;
   out_3574535823991284745[15] = 0.0;
   out_3574535823991284745[16] = 0.0;
   out_3574535823991284745[17] = 0.0;
   out_3574535823991284745[18] = 0.0;
   out_3574535823991284745[19] = 0.0;
   out_3574535823991284745[20] = 1.0;
   out_3574535823991284745[21] = 0.0;
   out_3574535823991284745[22] = 0.0;
   out_3574535823991284745[23] = 0.0;
   out_3574535823991284745[24] = 0.0;
   out_3574535823991284745[25] = 0.0;
   out_3574535823991284745[26] = 0.0;
   out_3574535823991284745[27] = 0.0;
   out_3574535823991284745[28] = 0.0;
   out_3574535823991284745[29] = 0.0;
   out_3574535823991284745[30] = 1.0;
   out_3574535823991284745[31] = 0.0;
   out_3574535823991284745[32] = 0.0;
   out_3574535823991284745[33] = 0.0;
   out_3574535823991284745[34] = 0.0;
   out_3574535823991284745[35] = 0.0;
   out_3574535823991284745[36] = 0.0;
   out_3574535823991284745[37] = 0.0;
   out_3574535823991284745[38] = 0.0;
   out_3574535823991284745[39] = 0.0;
   out_3574535823991284745[40] = 1.0;
   out_3574535823991284745[41] = 0.0;
   out_3574535823991284745[42] = 0.0;
   out_3574535823991284745[43] = 0.0;
   out_3574535823991284745[44] = 0.0;
   out_3574535823991284745[45] = 0.0;
   out_3574535823991284745[46] = 0.0;
   out_3574535823991284745[47] = 0.0;
   out_3574535823991284745[48] = 0.0;
   out_3574535823991284745[49] = 0.0;
   out_3574535823991284745[50] = 1.0;
   out_3574535823991284745[51] = 0.0;
   out_3574535823991284745[52] = 0.0;
   out_3574535823991284745[53] = 0.0;
   out_3574535823991284745[54] = 0.0;
   out_3574535823991284745[55] = 0.0;
   out_3574535823991284745[56] = 0.0;
   out_3574535823991284745[57] = 0.0;
   out_3574535823991284745[58] = 0.0;
   out_3574535823991284745[59] = 0.0;
   out_3574535823991284745[60] = 1.0;
   out_3574535823991284745[61] = 0.0;
   out_3574535823991284745[62] = 0.0;
   out_3574535823991284745[63] = 0.0;
   out_3574535823991284745[64] = 0.0;
   out_3574535823991284745[65] = 0.0;
   out_3574535823991284745[66] = 0.0;
   out_3574535823991284745[67] = 0.0;
   out_3574535823991284745[68] = 0.0;
   out_3574535823991284745[69] = 0.0;
   out_3574535823991284745[70] = 1.0;
   out_3574535823991284745[71] = 0.0;
   out_3574535823991284745[72] = 0.0;
   out_3574535823991284745[73] = 0.0;
   out_3574535823991284745[74] = 0.0;
   out_3574535823991284745[75] = 0.0;
   out_3574535823991284745[76] = 0.0;
   out_3574535823991284745[77] = 0.0;
   out_3574535823991284745[78] = 0.0;
   out_3574535823991284745[79] = 0.0;
   out_3574535823991284745[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6415917603272986290) {
   out_6415917603272986290[0] = state[0];
   out_6415917603272986290[1] = state[1];
   out_6415917603272986290[2] = state[2];
   out_6415917603272986290[3] = state[3];
   out_6415917603272986290[4] = state[4];
   out_6415917603272986290[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6415917603272986290[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6415917603272986290[7] = state[7];
   out_6415917603272986290[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3785946309862960090) {
   out_3785946309862960090[0] = 1;
   out_3785946309862960090[1] = 0;
   out_3785946309862960090[2] = 0;
   out_3785946309862960090[3] = 0;
   out_3785946309862960090[4] = 0;
   out_3785946309862960090[5] = 0;
   out_3785946309862960090[6] = 0;
   out_3785946309862960090[7] = 0;
   out_3785946309862960090[8] = 0;
   out_3785946309862960090[9] = 0;
   out_3785946309862960090[10] = 1;
   out_3785946309862960090[11] = 0;
   out_3785946309862960090[12] = 0;
   out_3785946309862960090[13] = 0;
   out_3785946309862960090[14] = 0;
   out_3785946309862960090[15] = 0;
   out_3785946309862960090[16] = 0;
   out_3785946309862960090[17] = 0;
   out_3785946309862960090[18] = 0;
   out_3785946309862960090[19] = 0;
   out_3785946309862960090[20] = 1;
   out_3785946309862960090[21] = 0;
   out_3785946309862960090[22] = 0;
   out_3785946309862960090[23] = 0;
   out_3785946309862960090[24] = 0;
   out_3785946309862960090[25] = 0;
   out_3785946309862960090[26] = 0;
   out_3785946309862960090[27] = 0;
   out_3785946309862960090[28] = 0;
   out_3785946309862960090[29] = 0;
   out_3785946309862960090[30] = 1;
   out_3785946309862960090[31] = 0;
   out_3785946309862960090[32] = 0;
   out_3785946309862960090[33] = 0;
   out_3785946309862960090[34] = 0;
   out_3785946309862960090[35] = 0;
   out_3785946309862960090[36] = 0;
   out_3785946309862960090[37] = 0;
   out_3785946309862960090[38] = 0;
   out_3785946309862960090[39] = 0;
   out_3785946309862960090[40] = 1;
   out_3785946309862960090[41] = 0;
   out_3785946309862960090[42] = 0;
   out_3785946309862960090[43] = 0;
   out_3785946309862960090[44] = 0;
   out_3785946309862960090[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3785946309862960090[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3785946309862960090[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3785946309862960090[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3785946309862960090[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3785946309862960090[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3785946309862960090[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3785946309862960090[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3785946309862960090[53] = -9.8100000000000005*dt;
   out_3785946309862960090[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3785946309862960090[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3785946309862960090[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3785946309862960090[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3785946309862960090[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3785946309862960090[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3785946309862960090[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3785946309862960090[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3785946309862960090[62] = 0;
   out_3785946309862960090[63] = 0;
   out_3785946309862960090[64] = 0;
   out_3785946309862960090[65] = 0;
   out_3785946309862960090[66] = 0;
   out_3785946309862960090[67] = 0;
   out_3785946309862960090[68] = 0;
   out_3785946309862960090[69] = 0;
   out_3785946309862960090[70] = 1;
   out_3785946309862960090[71] = 0;
   out_3785946309862960090[72] = 0;
   out_3785946309862960090[73] = 0;
   out_3785946309862960090[74] = 0;
   out_3785946309862960090[75] = 0;
   out_3785946309862960090[76] = 0;
   out_3785946309862960090[77] = 0;
   out_3785946309862960090[78] = 0;
   out_3785946309862960090[79] = 0;
   out_3785946309862960090[80] = 1;
}
void h_25(double *state, double *unused, double *out_2319808077913854028) {
   out_2319808077913854028[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6211092749006710939) {
   out_6211092749006710939[0] = 0;
   out_6211092749006710939[1] = 0;
   out_6211092749006710939[2] = 0;
   out_6211092749006710939[3] = 0;
   out_6211092749006710939[4] = 0;
   out_6211092749006710939[5] = 0;
   out_6211092749006710939[6] = 1;
   out_6211092749006710939[7] = 0;
   out_6211092749006710939[8] = 0;
}
void h_24(double *state, double *unused, double *out_5316855504508484496) {
   out_5316855504508484496[0] = state[4];
   out_5316855504508484496[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2653167150204387803) {
   out_2653167150204387803[0] = 0;
   out_2653167150204387803[1] = 0;
   out_2653167150204387803[2] = 0;
   out_2653167150204387803[3] = 0;
   out_2653167150204387803[4] = 1;
   out_2653167150204387803[5] = 0;
   out_2653167150204387803[6] = 0;
   out_2653167150204387803[7] = 0;
   out_2653167150204387803[8] = 0;
   out_2653167150204387803[9] = 0;
   out_2653167150204387803[10] = 0;
   out_2653167150204387803[11] = 0;
   out_2653167150204387803[12] = 0;
   out_2653167150204387803[13] = 0;
   out_2653167150204387803[14] = 1;
   out_2653167150204387803[15] = 0;
   out_2653167150204387803[16] = 0;
   out_2653167150204387803[17] = 0;
}
void h_30(double *state, double *unused, double *out_228120081864859671) {
   out_228120081864859671[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7707954994575232479) {
   out_7707954994575232479[0] = 0;
   out_7707954994575232479[1] = 0;
   out_7707954994575232479[2] = 0;
   out_7707954994575232479[3] = 0;
   out_7707954994575232479[4] = 1;
   out_7707954994575232479[5] = 0;
   out_7707954994575232479[6] = 0;
   out_7707954994575232479[7] = 0;
   out_7707954994575232479[8] = 0;
}
void h_26(double *state, double *unused, double *out_8304320119713671674) {
   out_8304320119713671674[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8494148005828784453) {
   out_8494148005828784453[0] = 0;
   out_8494148005828784453[1] = 0;
   out_8494148005828784453[2] = 0;
   out_8494148005828784453[3] = 0;
   out_8494148005828784453[4] = 0;
   out_8494148005828784453[5] = 0;
   out_8494148005828784453[6] = 0;
   out_8494148005828784453[7] = 1;
   out_8494148005828784453[8] = 0;
}
void h_27(double *state, double *unused, double *out_7321481345574699673) {
   out_7321481345574699673[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5533191682774807568) {
   out_5533191682774807568[0] = 0;
   out_5533191682774807568[1] = 0;
   out_5533191682774807568[2] = 0;
   out_5533191682774807568[3] = 1;
   out_5533191682774807568[4] = 0;
   out_5533191682774807568[5] = 0;
   out_5533191682774807568[6] = 0;
   out_5533191682774807568[7] = 0;
   out_5533191682774807568[8] = 0;
}
void h_29(double *state, double *unused, double *out_8177536737779366982) {
   out_8177536737779366982[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8218186338889624663) {
   out_8218186338889624663[0] = 0;
   out_8218186338889624663[1] = 1;
   out_8218186338889624663[2] = 0;
   out_8218186338889624663[3] = 0;
   out_8218186338889624663[4] = 0;
   out_8218186338889624663[5] = 0;
   out_8218186338889624663[6] = 0;
   out_8218186338889624663[7] = 0;
   out_8218186338889624663[8] = 0;
}
void h_28(double *state, double *unused, double *out_3594989154130006304) {
   out_3594989154130006304[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3135787321820094089) {
   out_3135787321820094089[0] = 1;
   out_3135787321820094089[1] = 0;
   out_3135787321820094089[2] = 0;
   out_3135787321820094089[3] = 0;
   out_3135787321820094089[4] = 0;
   out_3135787321820094089[5] = 0;
   out_3135787321820094089[6] = 0;
   out_3135787321820094089[7] = 0;
   out_3135787321820094089[8] = 0;
}
void h_31(double *state, double *unused, double *out_6202521176260306347) {
   out_6202521176260306347[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7867939903595432977) {
   out_7867939903595432977[0] = 0;
   out_7867939903595432977[1] = 0;
   out_7867939903595432977[2] = 0;
   out_7867939903595432977[3] = 0;
   out_7867939903595432977[4] = 0;
   out_7867939903595432977[5] = 0;
   out_7867939903595432977[6] = 0;
   out_7867939903595432977[7] = 0;
   out_7867939903595432977[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_5068820853483992556) {
  err_fun(nom_x, delta_x, out_5068820853483992556);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5097641143412691511) {
  inv_err_fun(nom_x, true_x, out_5097641143412691511);
}
void car_H_mod_fun(double *state, double *out_3574535823991284745) {
  H_mod_fun(state, out_3574535823991284745);
}
void car_f_fun(double *state, double dt, double *out_6415917603272986290) {
  f_fun(state,  dt, out_6415917603272986290);
}
void car_F_fun(double *state, double dt, double *out_3785946309862960090) {
  F_fun(state,  dt, out_3785946309862960090);
}
void car_h_25(double *state, double *unused, double *out_2319808077913854028) {
  h_25(state, unused, out_2319808077913854028);
}
void car_H_25(double *state, double *unused, double *out_6211092749006710939) {
  H_25(state, unused, out_6211092749006710939);
}
void car_h_24(double *state, double *unused, double *out_5316855504508484496) {
  h_24(state, unused, out_5316855504508484496);
}
void car_H_24(double *state, double *unused, double *out_2653167150204387803) {
  H_24(state, unused, out_2653167150204387803);
}
void car_h_30(double *state, double *unused, double *out_228120081864859671) {
  h_30(state, unused, out_228120081864859671);
}
void car_H_30(double *state, double *unused, double *out_7707954994575232479) {
  H_30(state, unused, out_7707954994575232479);
}
void car_h_26(double *state, double *unused, double *out_8304320119713671674) {
  h_26(state, unused, out_8304320119713671674);
}
void car_H_26(double *state, double *unused, double *out_8494148005828784453) {
  H_26(state, unused, out_8494148005828784453);
}
void car_h_27(double *state, double *unused, double *out_7321481345574699673) {
  h_27(state, unused, out_7321481345574699673);
}
void car_H_27(double *state, double *unused, double *out_5533191682774807568) {
  H_27(state, unused, out_5533191682774807568);
}
void car_h_29(double *state, double *unused, double *out_8177536737779366982) {
  h_29(state, unused, out_8177536737779366982);
}
void car_H_29(double *state, double *unused, double *out_8218186338889624663) {
  H_29(state, unused, out_8218186338889624663);
}
void car_h_28(double *state, double *unused, double *out_3594989154130006304) {
  h_28(state, unused, out_3594989154130006304);
}
void car_H_28(double *state, double *unused, double *out_3135787321820094089) {
  H_28(state, unused, out_3135787321820094089);
}
void car_h_31(double *state, double *unused, double *out_6202521176260306347) {
  h_31(state, unused, out_6202521176260306347);
}
void car_H_31(double *state, double *unused, double *out_7867939903595432977) {
  H_31(state, unused, out_7867939903595432977);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
