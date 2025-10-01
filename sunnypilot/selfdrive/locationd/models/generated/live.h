#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_11550028942566401);
void live_err_fun(double *nom_x, double *delta_x, double *out_9184767064344944388);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_6119341299857655338);
void live_H_mod_fun(double *state, double *out_2423349688366534848);
void live_f_fun(double *state, double dt, double *out_3286974643845487244);
void live_F_fun(double *state, double dt, double *out_3900617724921068927);
void live_h_4(double *state, double *unused, double *out_5594199428645316670);
void live_H_4(double *state, double *unused, double *out_2295401826439358034);
void live_h_9(double *state, double *unused, double *out_6244923351303820998);
void live_H_9(double *state, double *unused, double *out_2536591473068948679);
void live_h_10(double *state, double *unused, double *out_6519334956050940943);
void live_H_10(double *state, double *unused, double *out_85009065529868653);
void live_h_12(double *state, double *unused, double *out_5817048618006658828);
void live_H_12(double *state, double *unused, double *out_7314858234471319829);
void live_h_35(double *state, double *unused, double *out_2328325805861695636);
void live_H_35(double *state, double *unused, double *out_8386322806913218078);
void live_h_32(double *state, double *unused, double *out_2964925050445193380);
void live_H_32(double *state, double *unused, double *out_1443364646140056340);
void live_h_13(double *state, double *unused, double *out_6804217202458125360);
void live_H_13(double *state, double *unused, double *out_6244979346460613005);
void live_h_14(double *state, double *unused, double *out_6244923351303820998);
void live_H_14(double *state, double *unused, double *out_2536591473068948679);
void live_h_33(double *state, double *unused, double *out_1151613323620641099);
void live_H_33(double *state, double *unused, double *out_8812620888450823014);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}