#include<stdio.h>

int main()
{
    char vokal[5];
    int i;
    vokal[0]='A';
    vokal[1]='I';
    vokal[2]='U';
    vokal[3]='E';
    vokal[4]='O';

    for(i=0;i<5;i++){
        printf("%c\n", vokal[i]);
    }

    return 0;
}
