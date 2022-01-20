#include <stdio.h>

int p2_3(){
    int matriks[3][4];
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            printf("masukkan nilai matriks matriks[%d][%d]: ", i, j);
            scanf("%d", &matriks[i][j]);
        }
    }
    printf("\n");
    for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            printf("%d ", matriks[i][j]);
            if(j==3){
                printf("\n");
            }
        }
    }

    return 0;
}
