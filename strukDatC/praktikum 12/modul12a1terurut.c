#include <stdio.h>
#define MAX 100 // ukuran maksimum array

void fill_data(int data[], int size)
{
    printf("Input ukuran array (max 100): ");
    scanf("%d", &size);
    for(int i=0; i<size; i++)
    {
        printf("input data ke-%d :",i+1);
        scanf("%d",&data[i]);
        if (i>0) //urut secara ascending
        {
            int a=i-1;
            int c=i;
            while(a>=0 && data[c] < data[a])
            {
                int temp[1];
                temp[1]=data[c];
                data[c]=data[a];
                data[a]=temp[1];
                c--;
                a--;
            }
        }
    }
    for(int i=0; i<size; i++) printf("%d ",data[i]);
 }
int seq_search(int data[], int size, int x){
    for (int i=0; i<size; i++){
        if (data[i]==x) return i;
        if (data[i]>x) return -1; // ascending
        //if (data[i]<x) return -1; // descending
    }
    return -1;
}
void main(){
    int data[MAX];
    int size; // ukuran array
    int x;
    fill_data(data, &size);
    printf("\n\nNilai yang ingin dicari: ");
    scanf("%d", &x);
    if (seq_search(data,size,x)==-1)
        printf("tidak ditemukan.");
    else
        printf("ditemukan pada indeks ke-%d.", seq_search(data,size,x));
}
