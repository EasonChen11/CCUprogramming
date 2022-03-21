#include <stdio.h>
const char A_list[][3]={"  ","  ","A=","  ","  "};
const char B_list[][3]={"  ","B=","  "};
const char C_list[][3]={"  ","C=","  "};
void func(const int A[5][5], const int B[3][3],int C[3][3], int row, int colum);

void print_square5(const int A[5][5]);
void print_square3(const int square[3][3],char a) ;
int main() {
    int C[3][3]={0};
    const int A[][5]={{1,1,1,0,0},
                      {0,1,1,1,0},
                      {0,0,1,1,1},
                      {0,0,1,1,0},
                      {0,1,1,0,0}
    };
    const int B[][3]={{1,0,1},
                      {0,1,0},
                      {1,0,1}
    };
    print_square5(A);
    print_square3(B, 'B');
    func(A, B,C, 0, 0);
    print_square3(C, 'C');
    return 0;
}

void print_square5(const int A[5][5]) {
    for (int i = 0; i < 5; ++i) {
        printf("%s",A_list[i]);
        for (int j = 0; j < 5; ++j) {
            printf("%d",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void print_square3(const int square[3][3],char a) {
    for (int i = 0; i < 3; ++i) {
        if(a=='B')
            printf("%s",B_list[i]);
        else
            printf("%s",C_list[i]);
        for (int j = 0; j < 3; ++j) {
            printf("%d",square[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void func(const int A[5][5], const int B[3][3],int C[3][3], int row, int colum) {
    if(row>2 )
        return;
    int a=0,b=0;
    for (int i = row; i < row+3; ++i) {
        for (int j = colum; j < colum+3; ++j) {
            C[row][colum]+=A[i][j]*B[a][b++];
        }
        a++;
        b%=3;
    }
    if(colum==2)
        func(A, B,C, row + 1, 0);
    else
        func(A, B,C, row, colum + 1);
}