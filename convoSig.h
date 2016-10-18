// convoSig.h
// Discrete signals for testing.
#include <math.h>

double amp = 1;
double frec = 10;
double phi = 0;

double sigSen (double t) {
    // sine function
    return amp * sin(t * frec * 2 * M_PI + phi);
}

double *sample (int N, double T, double (*fcn)(double)) {
    // waveform function sampler for simulating
    double *d_sig = malloc(sizeof(double) * N);
    for (int k = 0; k < N; k++) {
        d_sig[k] = fcn((double)k * T);
    }
    return d_sig;
}

double *hannWindow (int N) {
    // Discrete hann window function
    double *hann = (double *) malloc(N * sizeof(double));
    for (int n = 0; n < N; n++) {
        hann[n] = 0.5 * (1 - cos(
            (2 * M_PI * n) / (N - 1)
        ));
    }
    
    return hann;
}