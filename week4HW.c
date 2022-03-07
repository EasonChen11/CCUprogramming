#include <stdio.h>

void swap(int * a, int * i);

int main() {
    printf("input three numbers: ");
    int list[3]={0};
    for (int i = 0; i < 3; ++i) {
        scanf("%d",&list[i]);
    }
    for (int i = 1; i < 3; ++i) {
        int k=i;
        while (list[k-1]<list[k] && k>0){
            swap(&list[k],&list[k-1]);
            k--;
        }
    }
    for (int i = 0; i < 3; ++i) {
        printf("%d ",list[i]);
    }
    return 0;
}

void swap(int * a, int * i) {
    int x;
    x=*a;
    *a=*i;
    *i=x;
}
