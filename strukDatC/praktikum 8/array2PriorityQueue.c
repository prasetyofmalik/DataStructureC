#include <stdio.h>
#include <stdlib.h>
#define dataMAX 100
#define MAX 6

int intArray[MAX], intData[dataMAX];
int r = -1,f = -1;
void insert(int data,int p){// Enqueue function to insert data and its priority in queue
	int i;
	if((f==0)&&(r==MAX-1)) // Check if Queue is full
		printf("Queue is full");
	else{
		if(f==-1){// if Queue is empty
			f = r = 0;
			intArray[r] = data;
			intData[r] = p;
		} else if(r == MAX-1){// if there there is some elemets in Queue
			for(i=f;i<=r;i++){
                intArray[i-f] = intArray[i];
                intData[i-f] = intData[i];
                r = r-f; f = 0;
                for(i = r;i>f;i--){
					if(p>intData[i]){
						intArray[i+1] = intArray[i];
						intData[i+1] = intData[i];
					}
					else break;

					intArray[i+1] = data;
					intData[i+1] = p;
					r++;
				}
			}
		} else{
			for(i=r; i>=f; i--){
				if(p>intData[i]){
					intArray[i+1] = intArray[i];
					intData[i+1] = intData[i];
				} else break;
			}
			intArray[i+1] = data;
			intData[i+1] = p;
			r++;
		}
	}
}
void display(){ // print the data of Queue
    int i;
	for(i=f;i<=r;i++){
		printf("\nElement = %d\tPriority = %d",intArray[i],intData[i]);
	}
}
int removeData(){ // remove the data from front
	if(f == -1){
		printf("Queue is Empty");
	} else{
		printf("\n\ndeleted Element = %d\tPriority = %d",intArray[f],intData[f]);
		if(f==r)
            f = r = -1;
		else f++;
	}
}
int main(){
    insert(3, 1);
    insert(5, 2);
    insert(9, 3);
    insert(1, 4);
    insert(12, 5);

    printf("Queue: ");
    display();

    removeData();
    printf("\n--------Setelah Remove--------\n");
    printf("Queue: ");
    display();

	removeData();
    printf("\n--------Setelah Remove--------\n");
    printf("Queue: ");
    display();

	return 0;
}
