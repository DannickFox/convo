// convoSig.h
// Discrete signals for testing.
#include <math.h>

double amp = 1;
double angspd = 1;
double phi = 0;

double sigSen (double t) {
    return amp * sin(t * angspd + phi);
}

double sigSqr (double t) {
    double s = sigSen(t);
    return amp * s > 0 ? 1 : s < 0 ? -1 : 0;
}

double *sample (int N, double T, double (*fcn)(double)) {
    double *d_sig = malloc(sizeof(double) * N);
    for (int k = 0; k < N; k++) {
        d_sig[k] = fcn((double)k * T);
    }
    return d_sig;
}

double *hannWindow (int N) {
    double *hann = (double *) malloc(N * sizeof(double));
    for (int n = 0; n < N; n++) {
        hann[n] = 0.5 * (1 - cos(
            (2 * M_PI * n) / (N - 1)
        ));
    }
    
    return hann;
}