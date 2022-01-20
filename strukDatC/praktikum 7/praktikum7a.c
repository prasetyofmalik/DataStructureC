#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50
#define MAX_CHARS 16
// struktur data array bertipe char
char QUEUE[MAX_CHARS][MAX];
int rear, front;

// fungsi enqueue
void enqueue(char item[]){
    if(rear==MAX-1){
        printf("Antrean penuh\n");
        //return;
        exit(0);
    }
    if(front==-1)
        front = 0;
    rear++;
    // karena antrean bertipe char, maka enqueue tidak bisa
    // dilakukan dengan cara QUEUE[rear] = item
    strcpy(QUEUE[rear], item);
}
// fungsi dequeue
void dequeue(){
    if(rear==-1){
        printf("Antrean kosong\n");
        return;
    }
    if(front==rear)
        front = rear = -1;
    else{
        for(int i=0;i<rear;i++){
            strcpy(QUEUE[i], QUEUE[i+1]);
        }
        rear--;
        front = 0;
    }
}
// fungsi generate bilangan biner
void generateBinaryNumbers(int N){
    char bin[] = "1";
    enqueue(bin);

    for(int i=0;i<N;i++){ // lakukan perulangan dari 0 sampai sebelum N
        // array char kosong untuk persiapan
        char temp[MAX_CHARS] = "";
        char temp2[MAX_CHARS] = "";
        // copy array QUEUE[front] dengan pointer temp dan temp2
        strcpy(temp, QUEUE[front]);
        strcpy(temp2, QUEUE[front]);
        // tampilkan array temp dan hapus elemen pertama
        printf("%s ", temp);
        dequeue();
        // tambahkan 0 ke array temp dan masukkan elemen baru
        strcat(temp, "0");
        enqueue(temp);
        // tambahkan 1 ke array temp2 dan masukkan elemen baru
        strcat(temp2, "1");
        enqueue(temp2);
    }
}

int main(){
    rear = -1;
    front = -1;

    int n;
    printf("Masukkan sebuah bilangan: ");
    scanf("%d", &n);
    generateBinaryNumbers(n);

    return 0;
}
