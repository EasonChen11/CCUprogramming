#include <stdio.h>

void trunk(int h);

void leaf(int h);

int main() {
    printf("please enter the height of the tree=");
    int h;
    scanf("%d",&h);
    int branch_low=2*h-1;
    leaf(h);
    trunk(h);
    return 0;
}

void leaf(int h) {
    printf("\t");
    for (int i = 0; i < h-1; ++i) {
        printf(" ");
    }
    printf("*\n");

    for (int i = 1; i < h-1; ++i) {
        printf("\t");
        for (int j = h; j >i+1; --j) {
            printf(" ");
        }
        printf("*");
        for (int j = 1; j < i*2; j++) {
            printf(" ");
        }
        printf("*\n");
    }
    printf("\t");
    for (int i = 0; i < h*2-1; ++i) {
        printf("*");
    }
    printf("\n");
}

void trunk(int h) {
    for (int i = 0; i < h; ++i) {
        printf("\t");
        for (int j = 0; j < (2*h-1)/2; ++j) {
            printf(" ");
        }
        printf("*\n");
    }
}
