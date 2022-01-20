/* Aturan Scope pada Bahasa C*/
#include <stdio.h>

int p2_2(){
    {
        int x = 10, y = 20;
        {
            printf("x = %d, y = %d\n", x, y);
            {
                int y = 40;
                x++;
                y++;
                printf("x = %d, y = %d\n", x, y);
            }
            printf("x = %d, y = %d\n", x, y);
        }
    }

    return 0;
}
