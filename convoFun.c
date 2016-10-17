// convoFun.c
// Main convolution function.
double c_sum (int n, int len_x, int len_h, double *x, double *h) {
    // convolution (summation loop)
    double sum = 0;
    for (int k = 0; k <= n; k++) {
        if (n - k < len_x && k < len_h) {
            sum += x[n - k] * h[k];
        }
    }
    return sum;
}

double *conv (int len_x, int len_h, double *x, double *h, int len_y) {
    // convolution (main loop)
    double *y = malloc(sizeof(double) * len_y);

    for (int n = 0; n < len_y; n++) {
        y[n] = c_sum(n, len_x, len_h, x, h);
    }
    return y;
}