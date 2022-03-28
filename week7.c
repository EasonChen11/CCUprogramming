#include <stdio.h>

void Game(int attacker, int target, int **formPtr);
int main() {
    int chart[3][3]={{70,30,40},{40,15,30},{20,60,40}};
    char tital[][4]={"job","HP","DEF","ATK"};
    char name[][8]={{"Warrior"},{"Wizard"},{"Archer"}};
    do{
        for (int i = 0; i < 4; ++i) {
            if(i==0)
                printf("%- 9s",tital[i]);
            else
                printf("%- 4s",tital[i]);
        }
        printf("\n");
        for (int i = 0; i < 3; ++i) {
            printf("%- 8s",name[i]);
            for (int j = 0; j < 3; ++j) {
                if(j==0)
                    printf("%- 4d",chart[i][j]);
                else
                    printf("% 4d",chart[i][j]);
            }
            printf("\n");
        }
        int attacker,target;
        do{
        printf("Please select an attacker:(1)Warrior (2)Wizard (3)Archer: ");
        scanf("%d",&attacker);
        printf("Please select an target:(1)Warrior (2)Wizard (3)Archer: ");
        scanf("%d",&target);
        if(attacker==target)
            printf("You can not select same player!!!\n");
        }while(attacker==target);
        int *chart_ptr[]={chart[0],chart[1],chart[2]};
        int **chart_pp=chart_ptr;
        Game(attacker,target,chart_pp);
    }    while(chart[0][0]>0 && chart[1][0]>0 && chart[2][0]>0);
        for (int i = 0; i < 3; ++i) {
        if(chart[i][0]<=0){
            printf("%s Died! Game over!\n",name[i]);
            break;
        }
    }
    return 0;
}
void Game(int attacker, int target, int **formPtr){
    attacker-=1;
    target-=1;
    int ATK=*(*(formPtr+attacker)+2);
    if(*(*(formPtr+target)+1)<ATK){
        *(*(formPtr+target)+1)=0;
        *(*(formPtr+target)+0)-=(ATK-*(*(formPtr+target)+1));
    }else{
        *(*(formPtr+target)+1)-=ATK;
    }
    if(*(*(formPtr+target)+0)<=0){
        *(*(formPtr+target)+0)=0;
        *(*(formPtr+target)+1)=0;
        *(*(formPtr+target)+2)=0;

    }
}