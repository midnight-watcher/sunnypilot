#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_5068820853483992556);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5097641143412691511);
void car_H_mod_fun(double *state, double *out_3574535823991284745);
void car_f_fun(double *state, double dt, double *out_6415917603272986290);
void car_F_fun(double *state, double dt, double *out_3785946309862960090);
void car_h_25(double *state, double *unused, double *out_2319808077913854028);
void car_H_25(double *state, double *unused, double *out_6211092749006710939);
void car_h_24(double *state, double *unused, double *out_5316855504508484496);
void car_H_24(double *state, double *unused, double *out_2653167150204387803);
void car_h_30(double *state, double *unused, double *out_228120081864859671);
void car_H_30(double *state, double *unused, double *out_7707954994575232479);
void car_h_26(double *state, double *unused, double *out_8304320119713671674);
void car_H_26(double *state, double *unused, double *out_8494148005828784453);
void car_h_27(double *state, double *unused, double *out_7321481345574699673);
void car_H_27(double *state, double *unused, double *out_5533191682774807568);
void car_h_29(double *state, double *unused, double *out_8177536737779366982);
void car_H_29(double *state, double *unused, double *out_8218186338889624663);
void car_h_28(double *state, double *unused, double *out_3594989154130006304);
void car_H_28(double *state, double *unused, double *out_3135787321820094089);
void car_h_31(double *state, double *unused, double *out_6202521176260306347);
void car_H_31(double *state, double *unused, double *out_7867939903595432977);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}