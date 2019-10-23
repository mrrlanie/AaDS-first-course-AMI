#include <stdio.h>
FILE *fout;
FILE* fin;
#define N_MAX 10000000
int A[N_MAX];
void exchange(int space);

int main(){
    fin = fopen("input.txt","r");
    fout = fopen("output.txt", "w");
    int N;
    fscanf(fin,"%d\n",&N);
    int K=0;
    for (int i=1;i<=N;i++){
        fscanf(fin,"%d ",&A[i]);
        if (A[i]!=i)
            K++;
        }
    fprintf(fout,"%d\n",K*2);
    for (int i=1;i<=N;i++){
        exchange(i);
    }
    return 0;
}
void exchange(int i){
    int doc = A[i];
    int space = i;
    if (doc == space){
        return;
    }
    fprintf(fout,"-%d %d\n",A[i],i);
    while(doc!=space){
        int right_doc=A[doc];
        fprintf(fout,"-%d %d\n",right_doc,doc);
        fprintf(fout,"%d %d\n",doc,doc);
        A[doc]=doc;
        doc=right_doc;
    }
    fprintf(fout,"%d %d\n",space,doc);
    A[space]=doc;
}