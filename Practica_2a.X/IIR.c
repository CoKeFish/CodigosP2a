//
// Created by rrtc2 on 27/03/2023.
//

#include "Notch 60hzorden4.h"
//#include "LowPass 50hzorden4.h"
//#include "HighPass 10hzorden4.h"

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


//double IIR(double input)
//{
//
//    double gain1 = 0.026611328125;
//    double a1[] = {1, 2, 1};
//    double b1[] = {1, -1.65625,  0.765625};
//
//    double gain2 = 0.02294921875;
//    double a2[] = {1, 2, 1};
//    double b2[] = {1, -1.421875,   0.515625};
//
//    double Y[2] = {0};
//
//    Y[0] = IIR_p1(a1, b1, input, gain1);
//    Y[1] = IIR_p2(a2, b2, Y[0], gain2);
//    return Y[1];
//}

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