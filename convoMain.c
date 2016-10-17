// convoMain.c
// Entry point.
#include <stdio.h>
#include <stdlib.h>

#include "convoSig.h"
#include "convoFun.c"
#include "file_gen.c"

#define ERR_MSG printf("Memory Error!\n")

int main (void) {
    angspd = 10;

    int S_N = 100;
    int H_N = 20;
    int C_N = S_N + H_N - 1;
    double S_T = 0.01;
    double *y;
    double *x = sample(S_N, S_T, sigSen);
    double *h = hannWindow(H_N);

    if (x) {
        file_gen("sigOut.txt", S_N, x);

        if (h) {
            file_gen("hannOut.txt", H_N, h);
            
            if (y = conv(S_N, H_N, x, h, C_N)) {
                file_gen("convOut.txt", C_N, y);
                free(y);
            } else ERR_MSG;
            free(h);
        } else ERR_MSG;
        free(x);
    } else ERR_MSG;

    return 0;
}