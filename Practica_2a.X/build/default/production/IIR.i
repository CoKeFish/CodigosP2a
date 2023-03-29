# 1 "IIR.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:/Program Files/packs/Microchip/PIC18F-K_DFP/1.7.134/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "IIR.c" 2




# 1 "./Notch 60hzorden4.h" 1
# 23 "./Notch 60hzorden4.h"
const int NL[5] = { 1,3,1,3,1 };
const double NUM[5][3] = {
  {
     0.6891427607528, 0, 0
  },
  {
                   1, 1.419133025919, 1
  },
  {
     0.6891427607528, 0, 0
  },
  {
                   1, 1.419133025919, 1
  },
  {
                   1, 0, 0
  }
};
const int DL[5] = { 1,3,1,3,1 };
const double DEN[5][3] = {
  {
                   1, 0, 0
  },
  {
                   1, 1.500213001995, 0.6615935420864
  },
  {
                   1, 0, 0
  },
  {
                   1, 0.381513719092, 0.3744482215401
  },
  {
                   1, 0, 0
  }
};
# 5 "IIR.c" 2




double IIR_p1(double * Num, double * Den, double input, const double Gain)
{

    static double X[3] = {0};
    static double W[3] = {0};

    static double *X_i = X;
    static double *W_i = W;

    static double Y = 0;

    *X_i = -(Gain) * (float)input;


    for (int i = 0; i < 3; ++i) {
        *W -= ((*Den) * (*W_i));
        Den++;
        W_i++;
    }

    X_i = X;
    W_i = W;

    for (int i = 0; i < 3; ++i) {
        Y += ((*Num) * (*W_i));
        Num++;
        X_i++;
    }

    X_i = X;
    W_i = W;

    W[2] = W[1];
    W[1] = W[0];

    return Y;
}

double IIR_p2(double * Num, double * Den, float input, const double Gain)
{

    static double X[3] = {0};
    static double W[3] = {0};

    static double *X_i = X;
    static double *W_i = W;

    static double Y = 0;

    *X_i = -(Gain) * (float)input;


    for (int i = 0; i < 3; ++i) {
        *W_i -= ((*Den) * (*X_i));
        Den++;
        X_i++;
    }

    X_i = X;
    W_i = W;

    for (int i = 0; i < 3; ++i) {
        Y += ((*Num) * (*W_i));
        Num++;
        X_i++;
    }

    X_i = X;
    W_i = W;

    W[2] = W[1];
    W[1] = W[0];

    return Y;
}
# 104 "IIR.c"
unsigned int FilterIIR(double input)
{

    static double W_1[3] = {0};

    static double W_2[3] = {0};

    double Y[2] = {0};

    W_1[0] = (DEN[1][0] * (NUM[0][0]) * input) - ((DEN[1][1]) * W_1[1]) - ((DEN[1][2]) * W_1[2]);
    Y[0] = ((NUM[1][0]) * W_1[0]) + ((NUM[1][1]) * W_1[1]) + ((NUM[1][2]) * W_1[2]);
    W_1[2] = W_1[1];
    W_1[1] = W_1[0];

    W_2[0] = (DEN[3][0] * Y[0] * NUM[2][0]) - ((DEN[3][1]) * W_2[1]) - ((DEN[3][2]) * W_2[2]);
    Y[1] = ((NUM[3][0]) * W_2[0]) + ((NUM[3][1]) * W_2[1]) + ((NUM[3][2]) * W_2[2]);
    W_2[2] = W_2[1];
    W_2[1] = W_2[0];

    int temp = (int)Y[1];
    if(temp > 4095)
    {
        return 4095;
    }
    if(temp < 0) {
        return 0;
    }
    return (unsigned int)temp;
}
