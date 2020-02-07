// (c) Tivole

#include <stdio.h>

#define N 100

int main(void) {

    int i;
    FILE *fout = NULL;

    fout = fopen("generated_sequence.txt", "w");

    fprintf(fout, "%d\n", N);

    for (i = 0; i < N; i++) {
        if (i % 2) fprintf(fout, "%d\n", i*(-1));
        else fprintf(fout, "%d\n", i);
    }

    return 0;
}