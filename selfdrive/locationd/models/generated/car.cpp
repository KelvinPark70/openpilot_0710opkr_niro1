
extern "C"{

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

}
extern "C" {
#include <math.h>
/******************************************************************************
 *                      Code generated with sympy 1.6.1                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2570753733468156876) {
   out_2570753733468156876[0] = delta_x[0] + nom_x[0];
   out_2570753733468156876[1] = delta_x[1] + nom_x[1];
   out_2570753733468156876[2] = delta_x[2] + nom_x[2];
   out_2570753733468156876[3] = delta_x[3] + nom_x[3];
   out_2570753733468156876[4] = delta_x[4] + nom_x[4];
   out_2570753733468156876[5] = delta_x[5] + nom_x[5];
   out_2570753733468156876[6] = delta_x[6] + nom_x[6];
   out_2570753733468156876[7] = delta_x[7] + nom_x[7];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1338950635819859059) {
   out_1338950635819859059[0] = -nom_x[0] + true_x[0];
   out_1338950635819859059[1] = -nom_x[1] + true_x[1];
   out_1338950635819859059[2] = -nom_x[2] + true_x[2];
   out_1338950635819859059[3] = -nom_x[3] + true_x[3];
   out_1338950635819859059[4] = -nom_x[4] + true_x[4];
   out_1338950635819859059[5] = -nom_x[5] + true_x[5];
   out_1338950635819859059[6] = -nom_x[6] + true_x[6];
   out_1338950635819859059[7] = -nom_x[7] + true_x[7];
}
void H_mod_fun(double *state, double *out_5501188501219745862) {
   out_5501188501219745862[0] = 1.0;
   out_5501188501219745862[1] = 0.0;
   out_5501188501219745862[2] = 0.0;
   out_5501188501219745862[3] = 0.0;
   out_5501188501219745862[4] = 0.0;
   out_5501188501219745862[5] = 0.0;
   out_5501188501219745862[6] = 0.0;
   out_5501188501219745862[7] = 0.0;
   out_5501188501219745862[8] = 0.0;
   out_5501188501219745862[9] = 1.0;
   out_5501188501219745862[10] = 0.0;
   out_5501188501219745862[11] = 0.0;
   out_5501188501219745862[12] = 0.0;
   out_5501188501219745862[13] = 0.0;
   out_5501188501219745862[14] = 0.0;
   out_5501188501219745862[15] = 0.0;
   out_5501188501219745862[16] = 0.0;
   out_5501188501219745862[17] = 0.0;
   out_5501188501219745862[18] = 1.0;
   out_5501188501219745862[19] = 0.0;
   out_5501188501219745862[20] = 0.0;
   out_5501188501219745862[21] = 0.0;
   out_5501188501219745862[22] = 0.0;
   out_5501188501219745862[23] = 0.0;
   out_5501188501219745862[24] = 0.0;
   out_5501188501219745862[25] = 0.0;
   out_5501188501219745862[26] = 0.0;
   out_5501188501219745862[27] = 1.0;
   out_5501188501219745862[28] = 0.0;
   out_5501188501219745862[29] = 0.0;
   out_5501188501219745862[30] = 0.0;
   out_5501188501219745862[31] = 0.0;
   out_5501188501219745862[32] = 0.0;
   out_5501188501219745862[33] = 0.0;
   out_5501188501219745862[34] = 0.0;
   out_5501188501219745862[35] = 0.0;
   out_5501188501219745862[36] = 1.0;
   out_5501188501219745862[37] = 0.0;
   out_5501188501219745862[38] = 0.0;
   out_5501188501219745862[39] = 0.0;
   out_5501188501219745862[40] = 0.0;
   out_5501188501219745862[41] = 0.0;
   out_5501188501219745862[42] = 0.0;
   out_5501188501219745862[43] = 0.0;
   out_5501188501219745862[44] = 0.0;
   out_5501188501219745862[45] = 1.0;
   out_5501188501219745862[46] = 0.0;
   out_5501188501219745862[47] = 0.0;
   out_5501188501219745862[48] = 0.0;
   out_5501188501219745862[49] = 0.0;
   out_5501188501219745862[50] = 0.0;
   out_5501188501219745862[51] = 0.0;
   out_5501188501219745862[52] = 0.0;
   out_5501188501219745862[53] = 0.0;
   out_5501188501219745862[54] = 1.0;
   out_5501188501219745862[55] = 0.0;
   out_5501188501219745862[56] = 0.0;
   out_5501188501219745862[57] = 0.0;
   out_5501188501219745862[58] = 0.0;
   out_5501188501219745862[59] = 0.0;
   out_5501188501219745862[60] = 0.0;
   out_5501188501219745862[61] = 0.0;
   out_5501188501219745862[62] = 0.0;
   out_5501188501219745862[63] = 1.0;
}
void f_fun(double *state, double dt, double *out_8505006321756399628) {
   out_8505006321756399628[0] = state[0];
   out_8505006321756399628[1] = state[1];
   out_8505006321756399628[2] = state[2];
   out_8505006321756399628[3] = state[3];
   out_8505006321756399628[4] = state[4];
   out_8505006321756399628[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8505006321756399628[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8505006321756399628[7] = state[7];
}
void F_fun(double *state, double dt, double *out_8682318555600613525) {
   out_8682318555600613525[0] = 1;
   out_8682318555600613525[1] = 0;
   out_8682318555600613525[2] = 0;
   out_8682318555600613525[3] = 0;
   out_8682318555600613525[4] = 0;
   out_8682318555600613525[5] = 0;
   out_8682318555600613525[6] = 0;
   out_8682318555600613525[7] = 0;
   out_8682318555600613525[8] = 0;
   out_8682318555600613525[9] = 1;
   out_8682318555600613525[10] = 0;
   out_8682318555600613525[11] = 0;
   out_8682318555600613525[12] = 0;
   out_8682318555600613525[13] = 0;
   out_8682318555600613525[14] = 0;
   out_8682318555600613525[15] = 0;
   out_8682318555600613525[16] = 0;
   out_8682318555600613525[17] = 0;
   out_8682318555600613525[18] = 1;
   out_8682318555600613525[19] = 0;
   out_8682318555600613525[20] = 0;
   out_8682318555600613525[21] = 0;
   out_8682318555600613525[22] = 0;
   out_8682318555600613525[23] = 0;
   out_8682318555600613525[24] = 0;
   out_8682318555600613525[25] = 0;
   out_8682318555600613525[26] = 0;
   out_8682318555600613525[27] = 1;
   out_8682318555600613525[28] = 0;
   out_8682318555600613525[29] = 0;
   out_8682318555600613525[30] = 0;
   out_8682318555600613525[31] = 0;
   out_8682318555600613525[32] = 0;
   out_8682318555600613525[33] = 0;
   out_8682318555600613525[34] = 0;
   out_8682318555600613525[35] = 0;
   out_8682318555600613525[36] = 1;
   out_8682318555600613525[37] = 0;
   out_8682318555600613525[38] = 0;
   out_8682318555600613525[39] = 0;
   out_8682318555600613525[40] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8682318555600613525[41] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8682318555600613525[42] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8682318555600613525[43] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8682318555600613525[44] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8682318555600613525[45] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8682318555600613525[46] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8682318555600613525[47] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8682318555600613525[48] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8682318555600613525[49] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8682318555600613525[50] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8682318555600613525[51] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8682318555600613525[52] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8682318555600613525[53] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8682318555600613525[54] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8682318555600613525[55] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8682318555600613525[56] = 0;
   out_8682318555600613525[57] = 0;
   out_8682318555600613525[58] = 0;
   out_8682318555600613525[59] = 0;
   out_8682318555600613525[60] = 0;
   out_8682318555600613525[61] = 0;
   out_8682318555600613525[62] = 0;
   out_8682318555600613525[63] = 1;
}
void h_25(double *state, double *unused, double *out_4407506188367513084) {
   out_4407506188367513084[0] = state[6];
}
void H_25(double *state, double *unused, double *out_928015626786622907) {
   out_928015626786622907[0] = 0;
   out_928015626786622907[1] = 0;
   out_928015626786622907[2] = 0;
   out_928015626786622907[3] = 0;
   out_928015626786622907[4] = 0;
   out_928015626786622907[5] = 0;
   out_928015626786622907[6] = 1;
   out_928015626786622907[7] = 0;
}
void h_24(double *state, double *unused, double *out_5223788175519076826) {
   out_5223788175519076826[0] = state[4];
   out_5223788175519076826[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3352019645198312190) {
   out_3352019645198312190[0] = 0;
   out_3352019645198312190[1] = 0;
   out_3352019645198312190[2] = 0;
   out_3352019645198312190[3] = 0;
   out_3352019645198312190[4] = 1;
   out_3352019645198312190[5] = 0;
   out_3352019645198312190[6] = 0;
   out_3352019645198312190[7] = 0;
   out_3352019645198312190[8] = 0;
   out_3352019645198312190[9] = 0;
   out_3352019645198312190[10] = 0;
   out_3352019645198312190[11] = 0;
   out_3352019645198312190[12] = 0;
   out_3352019645198312190[13] = 1;
   out_3352019645198312190[14] = 0;
   out_3352019645198312190[15] = 0;
}
void h_30(double *state, double *unused, double *out_3053052575881375241) {
   out_3053052575881375241[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7904829535973745429) {
   out_7904829535973745429[0] = 0;
   out_7904829535973745429[1] = 0;
   out_7904829535973745429[2] = 0;
   out_7904829535973745429[3] = 0;
   out_7904829535973745429[4] = 1;
   out_7904829535973745429[5] = 0;
   out_7904829535973745429[6] = 0;
   out_7904829535973745429[7] = 0;
}
void h_26(double *state, double *unused, double *out_5128370295588372110) {
   out_5128370295588372110[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4776577528152586366) {
   out_4776577528152586366[0] = 0;
   out_4776577528152586366[1] = 0;
   out_4776577528152586366[2] = 0;
   out_4776577528152586366[3] = 0;
   out_4776577528152586366[4] = 0;
   out_4776577528152586366[5] = 0;
   out_4776577528152586366[6] = 0;
   out_4776577528152586366[7] = 1;
}
void h_27(double *state, double *unused, double *out_1803100867558815433) {
   out_1803100867558815433[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6617247548137120117) {
   out_6617247548137120117[0] = 0;
   out_6617247548137120117[1] = 0;
   out_6617247548137120117[2] = 0;
   out_6617247548137120117[3] = 1;
   out_6617247548137120117[4] = 0;
   out_6617247548137120117[5] = 0;
   out_6617247548137120117[6] = 0;
   out_6617247548137120117[7] = 0;
}
void h_29(double *state, double *unused, double *out_1948620691779470404) {
   out_1948620691779470404[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4081030766844913476) {
   out_4081030766844913476[0] = 0;
   out_4081030766844913476[1] = 1;
   out_4081030766844913476[2] = 0;
   out_4081030766844913476[3] = 0;
   out_4081030766844913476[4] = 0;
   out_4081030766844913476[5] = 0;
   out_4081030766844913476[6] = 0;
   out_4081030766844913476[7] = 0;
}
void h_28(double *state, double *unused, double *out_236275267060266537) {
   out_236275267060266537[0] = state[5];
   out_236275267060266537[1] = state[6];
}
void H_28(double *state, double *unused, double *out_8076891950274744560) {
   out_8076891950274744560[0] = 0;
   out_8076891950274744560[1] = 0;
   out_8076891950274744560[2] = 0;
   out_8076891950274744560[3] = 0;
   out_8076891950274744560[4] = 0;
   out_8076891950274744560[5] = 1;
   out_8076891950274744560[6] = 0;
   out_8076891950274744560[7] = 0;
   out_8076891950274744560[8] = 0;
   out_8076891950274744560[9] = 0;
   out_8076891950274744560[10] = 0;
   out_8076891950274744560[11] = 0;
   out_8076891950274744560[12] = 0;
   out_8076891950274744560[13] = 0;
   out_8076891950274744560[14] = 1;
   out_8076891950274744560[15] = 0;
}
}

extern "C"{
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



extern "C"{

      void update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<1,3,0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
      }
    
      void update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<2,3,0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
      }
    
      void update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<1,3,0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
      }
    
      void update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<1,3,0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
      }
    
      void update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<1,3,0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
      }
    
      void update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<1,3,0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
      }
    
      void update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<2,3,0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
      }
    
}
