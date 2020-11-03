/******************************************************************************
 *                      Code generated with sympy 1.6.1                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7987571560497852780);
void inv_err_fun(double *nom_x, double *true_x, double *out_7706086563173484994);
void H_mod_fun(double *state, double *out_2893869075774502199);
void f_fun(double *state, double dt, double *out_86260775881187040);
void F_fun(double *state, double dt, double *out_337404223910972012);
void h_3(double *state, double *unused, double *out_3519710842356305611);
void H_3(double *state, double *unused, double *out_2243908009057849174);
void h_4(double *state, double *unused, double *out_7089510001439135527);
void H_4(double *state, double *unused, double *out_8565614729940893238);
void h_9(double *state, double *unused, double *out_6921300668919697688);
void H_9(double *state, double *unused, double *out_802920102564819557);
void h_10(double *state, double *unused, double *out_6973949860981814163);
void H_10(double *state, double *unused, double *out_5134959026630482915);
void h_12(double *state, double *unused, double *out_979603663173378879);
void H_12(double *state, double *unused, double *out_6459059218201683669);
void h_31(double *state, double *unused, double *out_1694469178338575531);
void H_31(double *state, double *unused, double *out_9134148993345103490);
void h_32(double *state, double *unused, double *out_1530795806609552829);
void H_32(double *state, double *unused, double *out_3012229336104046940);
void h_13(double *state, double *unused, double *out_6850962748823605531);
void H_13(double *state, double *unused, double *out_1922234406631776705);
void h_14(double *state, double *unused, double *out_6921300668919697688);
void H_14(double *state, double *unused, double *out_802920102564819557);
void h_19(double *state, double *unused, double *out_7795486367036127457);
void H_19(double *state, double *unused, double *out_5235599953667250738);
#define DIM 23
#define EDIM 22
#define MEDIM 22
typedef void (*Hfun)(double *, double *, double *);

void predict(double *x, double *P, double *Q, double dt);
const static double MAHA_THRESH_3 = 3.841459;
void update_3(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814728;
void update_4(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_9 = 7.814728;
void update_9(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_10 = 7.814728;
void update_10(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_12 = 7.814728;
void update_12(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_31 = 7.814728;
void update_31(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_32 = 9.487729;
void update_32(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_13 = 7.814728;
void update_13(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_14 = 7.814728;
void update_14(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_19 = 7.814728;
void update_19(double *, double *, double *, double *, double *);