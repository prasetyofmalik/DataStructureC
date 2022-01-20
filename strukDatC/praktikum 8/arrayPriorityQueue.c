#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 6

int intArray[MAX];
int itemCount = 0;
int peek(){
    return intArray[0];
}
bool isEmpty(){
    return itemCount == 0;
}
bool isFull(){
    return itemCount == MAX;
}
int size(){
    return itemCount;
}
void display(){
    for(int i=0; i<itemCount; i++){
        printf("%d ", intArray[i]);
    }
}
// operasi insert atau enqueue
// asumsi data lebih besar memiliki prioritas lebih tinggi
void insert(int data){
    int i = 0;
    if(!isFull()){
        if(itemCount==0){
            intArray[itemCount] = data;
        } else{
            for(i=itemCount-1; i>=0; i--){
                if(data>intArray[i]){ // prioritas lebih tinggi
                    intArray[i+1] = intArray[i];
                } else break;
            }
            // masukkan data
            intArray[i+1] = data;
        }
        itemCount++;
    }
}
// operasi remove atau dequeue
// menghapus elemen di indeks ke-0 dengan menggeser tiap2 elemen
void removeData(){
    for(int i=0; i<itemCount; i++){
        intArray[i] = intArray[i+1];
    }
    itemCount--;
}

int main(){
    insert(3);
    insert(5);
    insert(4);
    insert(1);
    insert(2);

    printf("Queue: ");
    display();

    printf("\nElement at front: %d\n", peek());

    removeData();

    printf("\n--------Setelah Remove--------\n");
    printf("Queue: ");

    display();
}
