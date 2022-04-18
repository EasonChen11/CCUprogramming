#include <stdio.h>
#include <stdlib.h>
enum {
    input_data=1,delete_data,print_all_data,Exit
};
const char takeout[2][9]={"For here","Take out"};
typedef struct food_order_DATA{
    char order;
    int id;
    int price;
    int takeout;
}data;
void print_data(data * pData, int length);

data * add_data(data * pData, int length);

data * remove_data(data * pData, int index, int length);

int main() {
    data *data=NULL;
    int length=0;
    while (1){
        printf("please input a number (1~4)\n");
        printf("(1)input data\n(2)delete data\n(3)print all data\n(4)exit:");
        int step;
        scanf("%d",&step);
        fflush(stdin);
        switch (step) {
            case input_data:
                data=add_data(data,length++);
                if(data==NULL)
                    return 0;
                break;
            case delete_data:
                print_data(data,length);
                int index;
                do{
                    printf("which one you want to delete:");
                    scanf("%d",&index);
                    fflush(stdin);
                } while (index>length);
                data=remove_data(data,index,length--);
                break;
            case print_all_data:
                print_data(data,length);
                break;
            case Exit:
                free(data);
                return 0;
        }
    }
    return 0;
}

data * remove_data(data * pData, int index, int length) {
    data *new_data=malloc(sizeof (data)*(length-1));
    int k=0;
    for(int i=0;i<sizeof (data)*length;i+=sizeof (data)){
        if(i==sizeof (data)*(index-1))
            continue;
        (new_data+k)->takeout=(pData+i)->takeout;
        (new_data+k)->price=(pData+i)->price;
        (new_data+k)->order=(pData+i)->order;
        (new_data+k)->id=(pData+i)->id;
        k+=sizeof (data);
    }
    free(pData);
    return new_data;
}

data * add_data(data * pData, int length) {
    data *new_data=malloc(sizeof (data)*(length+1));
    if(new_data==NULL){
        fprintf(stderr,"Error:unable to allocate required memory");
        return NULL;
    }
    for (int i = 0; i < length*sizeof (data); i+=sizeof (data)) {
        (new_data+i)->takeout=(pData+i)->takeout;
        (new_data+i)->price=(pData+i)->price;
        (new_data+i)->order=(pData+i)->order;
        (new_data+i)->id=(pData+i)->id;
    }
    free(pData);
    printf("enter your order(A,B,C,...)\n");
    scanf(" %c",&(new_data+sizeof (data)*length)->order);
    fflush(stdin);
    printf("enter your ID(0~1000)\n");
    scanf("%d",&(new_data+sizeof (data)*length)->id);
    fflush(stdin);
    printf("enter your price(0~10000)\n");
    scanf("%d",&(new_data+sizeof (data)*length)->price);
    fflush(stdin);
    do{
        printf("enter your For here(0) or Take out(1)\n");
        scanf("%d",&(new_data+sizeof (data)*length)->takeout);
        fflush(stdin);
    } while ((new_data+sizeof (data)*length)->takeout!=0 && (new_data+sizeof (data)*length)->takeout!=1);
    return new_data;
}

void print_data(data * pData, int length) {
    int k=1;
    for (int i = 0; i < length*sizeof (data); i+=sizeof (data)) {
        printf("%d. order=%c id=%-4d price=%-5d \"%s\"\n",k++,(pData+i)->order,(pData+i)->id,(pData+i)->price,takeout[(pData+i)->takeout]);
    }
}
