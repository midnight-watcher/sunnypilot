#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5883224282319393425);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_266692242281043755);
void pose_H_mod_fun(double *state, double *out_157508777103841027);
void pose_f_fun(double *state, double dt, double *out_488772806955075569);
void pose_F_fun(double *state, double dt, double *out_4053952474543882038);
void pose_h_4(double *state, double *unused, double *out_3761869252140862000);
void pose_H_4(double *state, double *unused, double *out_2736167434181912294);
void pose_h_10(double *state, double *unused, double *out_5019928406836969817);
void pose_H_10(double *state, double *unused, double *out_2772140546624323337);
void pose_h_13(double *state, double *unused, double *out_1798578478729464014);
void pose_H_13(double *state, double *unused, double *out_1097588029120611730);
void pose_h_14(double *state, double *unused, double *out_1188008182786197296);
void pose_H_14(double *state, double *unused, double *out_4744978381097828130);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}