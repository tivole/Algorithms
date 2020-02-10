// (c) Tivole

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Quick_Sort/quick_sort.h"
#include "../Heap_Sort/heap_sort.h"

void generate(FILE*, int);
int check_sequence(FILE*);
int *read_sequence(FILE*);
void write_sequence(FILE*, int*, int);


int main(void) {

    FILE *f = NULL;
    int result, N, *sequence = NULL;
    clock_t begin_time, end_time;
    double time_spent;


    /* Checking Quck Sort */

    N = 1000000;
    generate(f, N);
    sequence = read_sequence(f);
    begin_time = clock();
    quick_sort(sequence, 0, N-1);
    end_time = clock();
    time_spent = (double)(end_time - begin_time) / CLOCKS_PER_SEC;
    write_sequence(f, sequence, N);
    result = check_sequence(f);

    printf("*********\n");
    printf("Quick Sort Test Results:\n");
    printf("time_spent = %.10lf\n%d\n\n", time_spent, result);


    /* Checking Heap Sort */

    N = 1000000;
    generate(f, N);
    sequence = read_sequence(f);
    begin_time = clock();
    heap_sort(sequence, N);
    end_time = clock();
    time_spent = (double)(end_time - begin_time) / CLOCKS_PER_SEC;
    write_sequence(f, sequence, N);
    result = check_sequence(f);

    printf("*********\n");
    printf("Heap Sort Test Results:\n");
    printf("time_spent = %.10lf\n%d\n\n", time_spent, result);

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