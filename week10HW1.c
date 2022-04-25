#include <stdio.h>
#include <stdlib.h>
int compare(const int *a,const int *b){
    return *a-*b;
}
int main(){
    FILE *input= fopen("410415069_1.txt","r");
    int save,list[1000],i=0;
    while ( fscanf(input,"%d",&save)!=EOF){
        list[i++]=save;
    }
    fclose(input);

    FILE *output=fopen("410415069_1.txt","w");
    qsort(list,i,sizeof (int),compare);
        for (int j = 0; j < i; ++j) {
        printf("%d ",list[j]);
    }
    for (int j = 0; j < i; ++j) {
        fprintf(input,"%d ",list[j]);
    }
    fclose(output);
}
