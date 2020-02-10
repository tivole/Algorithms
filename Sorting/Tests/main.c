// (c) Tivole

#include <stdio.h>
#include <stdlib.h>
#include "../Quick_Sort/quick_sort.h"

void generate(FILE*, int);
int check_sequence(FILE*);
int *read_sequence(FILE*);
void write_sequence(FILE*, int*, int);


int main(void) {

    FILE *f = NULL;
    int result, N, *sequence = NULL;

    /* Checking Quck Sort */

    N = 100;
    generate(f, N);
    sequence = read_sequence(f);
    quick_sort(sequence, 0, N-1);
    write_sequence(f, sequence, N);
    result = check_sequence(f);

    printf("%d\n", result);

    return 0;
}


void generate(FILE *fout, int N) {
    int i;

    fout = fopen("generated_sequence.txt", "w");

    fprintf(fout, "%d\n", N);

    for (i = 0; i < N; i++) {
        if (i % 2) fprintf(fout, "%d\n", i*(-1));
        else fprintf(fout, "%d\n", i);
    }

    fclose(fout);

    return;
}


int check_sequence(FILE *fin) {
    int i, *sequence, N, isSorted = 1;
    
    fin = fopen("sorted.txt", "r");

    fscanf(fin, "%d", &N);

    sequence = (int*)malloc(N * sizeof(int));

    for (i = 0; i < N; i++) fscanf(fin, "%d", &sequence[i]);

    fclose(fin);
    
    for (i = 1; i < N; i++) {
        if (sequence[i-1] > sequence[i])
            isSorted = 0;
    }

    return isSorted;
}


int *read_sequence(FILE *fin) {
    int i, N, *sequence = NULL;

    fin = fopen("generated_sequence.txt", "r");

    fscanf(fin, "%d", &N);

    sequence = (int*)malloc(N * sizeof(int));

    for (i = 0; i < N; i++) fscanf(fin, "%d", &sequence[i]);

    fclose(fin);

    return sequence;
}


void write_sequence(FILE *fout, int *sequence, int N) {
    int i;

    fout = fopen("sorted.txt", "w");

    fprintf(fout, "%d\n", N);
    for (i = 0; i < N; i++) fprintf(fout, "%d\n", sequence[i]);

    fclose(fout);

    return;
}