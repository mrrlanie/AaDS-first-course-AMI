#include <stdio.h>

int main() {
    FILE*fin=fopen("input.txt","r");
    FILE*fout=fopen("output.txt","w");
    int N ,l,M,r,sum=0;
    fscanf(fin,"%d",&N);
    int A[N+1];
    A[0]=0;
    for (int i = 1; i <=N ; ++i) {
        fscanf(fin,"%d",&A[i]);
    }
    for (int j = 1; j <=N ; ++j) {
        A[j]=A[j-1]+A[j];
    }
    fscanf(fin,"%d",&M);
    for (int k = 0; k < M; ++k) {
        fscanf(fin,"%d%d",&l,&r);
        fprintf(fout,"%d ",A[r]-A[l-1]);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}