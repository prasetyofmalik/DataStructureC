#include <stdio.h>

typedef struct data_tanggal{
    int tahun;
    int bulan;
    int tanggal;
} date; // date is a name of new data type

int p33(){
    date ultah;
    //initializing struct ultah elements
    ultah.tanggal = 22;
    ultah.bulan = 9;
    ultah.tahun = 2001;

    //accessing struct ultah elements
    printf("tanggal = %d, bulan = %d, tahun = %d",
           ultah.tanggal, ultah.bulan, ultah.tahun);

    return 0;
}
