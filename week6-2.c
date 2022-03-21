#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *a,const void *b){
    return *(char*)a>*(char*)b;
}
int main(){
    char s[1000000]={""};
    printf("please enter a string=");
    fgets(s,sizeof (s),stdin);
    for (int i = 0; i < strlen(s); ++i) {
        if(s[i]>96)
            s[i]-=32;
    }
    qsort(s, strlen(s)-1,sizeof (char),compare);
    printf("after sorting=");
    puts(s);
}
