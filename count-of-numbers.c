#include <stdio.h>
#include <stdlib.h>

int comp (const void *, const void *);

int main() {
    FILE* fin = fopen("input.txt","r");
    FILE* fout = fopen("output.txt","w");
    int N;
    //comment for test 2
    fscanf(fin, "%i", &N);
    int* A;
    A = (int*)calloc(N, sizeof(int));
    for (int k = 0; k < N; ++k){
        fscanf(fin, "%i", &A[k]);
    }
    qsort(A, N, sizeof(int), comp);
    for (int i = 0; i < N; i++) {
        if (A[i] == A[i -1]) {
            continue;
        } else {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (A[i] == A[j]) {
                    count = count + 1;
                }
            }
            fprintf(fout, "%i\t%i\n", A[i], count);
        }
    }
    free(A);
    fclose(fin);
    fclose(fout);
    return 0;
}

int comp(const void *i, const void *j){
    return *(int *) i - *(int *) j;
}
