#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char s[1000000], int j);

int compare(const void *a, const void *b){
    return *(char*)a>*(char*)b;
}
int main(){
    char s[1000000];
    printf("please enter a string=");
    fgets(s,sizeof (s),stdin);
    for (int i = 0; i < strlen(s)-1; ++i) {
        if(s[i]>96)
            s[i]-=32;
    }
    qsort(s, strlen(s)-1,sizeof (char),compare);
    /*for(int i=1;i< strlen(s)-1;i++){
        int j=i;
        while (s[j]<s[j-1] && j< strlen(s)-1){
            swap(s,j);
            j--;
        }*/
    }
    printf("after sorting=");
    puts(s);
}

void swap(char s[1000000], int j) {
    int x=s[j];
    s[j]=s[j-1];
    s[j-1]=x;
}
