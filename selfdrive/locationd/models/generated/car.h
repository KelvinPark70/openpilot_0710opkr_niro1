/******************************************************************************
 *                      Code generated with sympy 1.6.1                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2570753733468156876);
void inv_err_fun(double *nom_x, double *true_x, double *out_1338950635819859059);
void H_mod_fun(double *state, double *out_5501188501219745862);
void f_fun(double *state, double dt, double *out_8505006321756399628);
void F_fun(double *state, double dt, double *out_8682318555600613525);
void h_25(double *state, double *unused, double *out_4407506188367513084);
void H_25(double *state, double *unused, double *out_928015626786622907);
void h_24(double *state, double *unused, double *out_5223788175519076826);
void H_24(double *state, double *unused, double *out_3352019645198312190);
void h_30(double *state, double *unused, double *out_3053052575881375241);
void H_30(double *state, double *unused, double *out_7904829535973745429);
void h_26(double *state, double *unused, double *out_5128370295588372110);
void H_26(double *state, double *unused, double *out_4776577528152586366);
void h_27(double *state, double *unused, double *out_1803100867558815433);
void H_27(double *state, double *unused, double *out_6617247548137120117);
void h_29(double *state, double *unused, double *out_1948620691779470404);
void H_29(double *state, double *unused, double *out_4081030766844913476);
void h_28(double *state, double *unused, double *out_236275267060266537);
void H_28(double *state, double *unused, double *out_8076891950274744560);
#define DIM 8
#define EDIM 8
#define MEDIM 8
typedef void (*Hfun)(double *, double *, double *);

void predict(double *x, double *P, double *Q, double dt);
const static double MAHA_THRESH_25 = 3.841459;
void update_25(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_24 = 5.991465;
void update_24(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_30 = 3.841459;
void update_30(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_26 = 3.841459;
void update_26(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_27 = 3.841459;
void update_27(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_29 = 3.841459;
void update_29(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_28 = 5.991465;
void update_28(double *, double *, double *, double *, double *);
void set_mass(double x);

void set_rotational_inertia(double x);

void set_center_to_front(double x);

void set_center_to_rear(double x);

void set_stiffness_front(double x);

void set_stiffness_rear(double x);
