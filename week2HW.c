#include<stdio.h>
int main(){
        int i;
        float f;
        char c;
        printf("please enter integer number: ");
        scanf("%d",&i);
        fflush(stdin);
        printf("please enter float number: ");
        scanf("%f",&f);
        fflush(stdin);
        printf("please enter character: ");
        scanf("\n%c",&c);
        fflush(stdin);
        printf("integer number :%d\n",i);
        printf("float number :%f\n",f);
        printf("character :%c\n",c);

        return 0;
}