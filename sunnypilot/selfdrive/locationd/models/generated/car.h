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
void car_err_fun(double *nom_x, double *delta_x, double *out_6562294807386605228);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2873175535680632605);
void car_H_mod_fun(double *state, double *out_7003423076103486201);
void car_f_fun(double *state, double dt, double *out_4874761255145808598);
void car_F_fun(double *state, double dt, double *out_4244621729500222443);
void car_h_25(double *state, double *unused, double *out_6452347059757653782);
void car_H_25(double *state, double *unused, double *out_2250132771693828178);
void car_h_24(double *state, double *unused, double *out_7017419670438019885);
void car_H_24(double *state, double *unused, double *out_4475840555672696740);
void car_h_30(double *state, double *unused, double *out_285233019786519479);
void car_H_30(double *state, double *unused, double *out_9166823113185444933);
void car_h_26(double *state, double *unused, double *out_5247613017467812711);
void car_H_26(double *state, double *unused, double *out_1491370547180228046);
void car_h_27(double *state, double *unused, double *out_6992723746291052189);
void car_H_27(double *state, double *unused, double *out_6992059801385020022);
void car_h_29(double *state, double *unused, double *out_6717529684006546300);
void car_H_29(double *state, double *unused, double *out_8769689616209714499);
void car_h_28(double *state, double *unused, double *out_1766816530455727242);
void car_H_28(double *state, double *unused, double *out_4594655440430306543);
void car_h_31(double *state, double *unused, double *out_2814897531503631432);
void car_H_31(double *state, double *unused, double *out_2280778733570788606);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}