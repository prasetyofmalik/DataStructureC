#include <stdio.h>
#define ROW 2
#define COL 3

int main(void){
    int Matriks_A[ROW][COL]={{5,2,3},{5,7,6}};
    int Matriks_B[ROW][COL]={{2,8,9},{3,5,4}};
    int Matriks_C[ROW][COL];

    printf("Matriks_C adalah : \n");
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            Matriks_C[i][j] = Matriks_A[i][j] * Matriks_B[i][j];
        }
        printf("%d %d %d\n", Matriks_C[i][0], Matriks_C[i][1],Matriks_C[i][2]);
    }

    return 0;
}
