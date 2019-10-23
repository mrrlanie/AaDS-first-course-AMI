#include <stdio.h>
int main() {
    FILE*fin=fopen("input.txt","r");
    FILE*fout=fopen("output.txt","w");
    int d;
    int N;
    int x;
    fscanf(fin,"%d%d",&N,&d);
    int A[d];
    for (int i = 0; i <= d-1; i++) {
        fscanf(fin,"%i",&A[i]);
    }
    int max=0;
    int sum=0;
    int i=0;
    for (int j = d; j <= N-1; j++) {
        fscanf(fin,"%i",&x);
        if (A[i]>max){
            max=A[i];
        }if ((max+x)>sum){
            sum=max+x;
        }
        A[i]=x;
        i=(i+1)%d;
    }
    fprintf(fout,"%i",sum);
    fclose(fin);
    fclose(fout);
    return 0;
}