// (c) Tivole

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int i, *sequence, N, isSorted = 1;
    FILE *fin = NULL;

    fin = fopen("sorted.txt", "r");

    fscanf(fin, "%d", &N);

    sequence = (int*)malloc(N * sizeof(int));

    for (i = 0; i < N; i++) fscanf(fin, "%d", &sequence[i]);
    
    for (i = 1; i < N; i++) {
        if (sequence[i-1] > sequence[i])
            isSorted = 0;
    }

    printf("%d\n", isSorted);

    return 0;
}