#include <stdio.h>
#include <stdlib.h>
FILE *input;
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
    input=fopen("410415069_2.txt","r");
    int index,step;
    int length=0;
    char c;
    while (1){
        fscanf(input,"%d",&step);
        switch (step) {
            case input_data:
                data=add_data(data,length++);
                if(data==NULL){
                    fclose(input);
                    print_data(data,length);
                    return 0;
                    }
                break;
            case delete_data:
                fscanf(input,"%d ",&index);
                data=remove_data(data,index,length--);
                break;
            default:
                fclose(input);
                print_data(data,length);
                free(data);
                return 0;
        }
    }
    return 0;
}

data * remove_data(data * pData, int index, int length) {
    data *new_data=malloc(sizeof (data)*(length-1));
    int k=0;
    for(int i=0;i<length;i++){
        if(i==index-1)
            continue;
        new_data[k++]=pData[i];
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
    for (int i = 0; i < length; i++) {
        new_data[i]=pData[i];
    }
    free(pData);
    char save;
    fscanf(input,"%c",&save);
    fscanf(input,"%c",&(new_data[length].order));
    fscanf(input,"%c",&save);
    fscanf(input,"%d",&(new_data[length].id));
    fscanf(input,"%d",&(new_data[length].price));
    fscanf(input,"%d",&(new_data[length].takeout));
    return new_data;
}

void print_data(data * pData, int length) {
    FILE *output=fopen("410415069_3.txt","w+");
    int k=1;
    for (int i = 0; i < length; i++) {
        fprintf(output,"%d. order=%c id=%-4d price=%-5d \"%s\"\n",k++,(pData+i)->order,(pData+i)->id,(pData+i)->price,takeout[(pData+i)->takeout]);
    }
    fclose(output);
}
