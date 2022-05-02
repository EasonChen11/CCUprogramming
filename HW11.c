#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
enum {
    push=1,pop,change,Exit
};

void Push(Node ** top, int value);

void print_list(Node * top);

void Pop(Node ** top);

void free_data(Node ** top);

void Change(Node ** top);

int main() {
    Node *top=NULL;
    int value,t=0;
    while (1){
        printf("chose mode: (1)Push, (2)Pop, (3)Change, (4)Exit:");
        int mode;
        scanf("%d",&mode);
        switch (mode) {
            case push:
                printf("input value :");
                scanf("%d",&value);
                Push(&top,value);
                print_list(top);
                break;
            case pop:
                Pop(&top);
                print_list(top);
                break;
            case change:
                Change(&top);
                print_list(top);
                break;
            case Exit:
                free_data(&top);
                t=1;
                break;
        }
        printf("--------------------------------------\n");
        if(t)
            break;
    }
    return 0;
}

void Change(Node ** top) {
    printf("please change the value_1 and value_2 : \n");
    int value[2];
    printf("value_1 = ");
    scanf("%d",&value[0]);
    printf("value_2 = ");
    scanf("%d",&value[1]);
    Node *now_point=*top,*father_point=NULL,*value_point[2][2];
    int have_value=0;
    while (now_point){
        if(have_value==2)
            break;
        if(now_point->data==value[have_value]){
            value_point[have_value][0]=father_point;
            value_point[have_value][1]=now_point;
            have_value++;
        }
        father_point=now_point;
        now_point=now_point->next;
    }
    //print_list(*top);
    if(have_value<2){
        printf("No match\n");
        return;
    }
    Node *ssave=value_point[1][1]->next,*sssave=value_point[0][1]->next;
    if(value_point[0][0]!=NULL){
        if(value_point[0][1]==value_point[1][0]){
            value_point[0][0]->next=value_point[1][1];
            value_point[1][1]->next=value_point[0][1];
            value_point[0][1]->next=ssave;
        }
        else{
            value_point[0][0]->next=value_point[1][1];
            value_point[1][0]->next=value_point[0][1];
            value_point[1][1]->next=sssave;
            value_point[0][1]->next=ssave;
        }
    }else{
        if(value_point[0][1]==value_point[1][0]){
            value_point[1][1]->next=value_point[0][1];
            value_point[0][1]->next=ssave;
        }
        else{
            value_point[1][0]->next=value_point[0][1];
            value_point[1][1]->next=sssave;
            value_point[0][1]->next=ssave;
        }
        *top=value_point[1][1];
    }
    //print_list(*top);
}

void free_data(Node ** top) {
    while (*top){
        Node *save=(*top)->next;
        free(*top);
        *top=save;
    }
}

void Pop(Node ** top) {
    Node *save=(*top)->next;
    printf("remove %d :\n",(*top)->data);
    free(*top);
    *top=save;
}

void print_list(Node * top) {
    int a=1;
    while (top){
        printf("address = %p , data = %d\t,next = %p",top,top->data,top->next);
        if(a){
            printf("   <-----top\n");
            a=0;
        } else printf("\n");
        top=top->next;
        //system("pause");
    }
}

void Push(Node ** top, int value) {
    Node *save= malloc(sizeof (Node));
    save->data=value;
    save->next=*top;
    *top=save;
}
