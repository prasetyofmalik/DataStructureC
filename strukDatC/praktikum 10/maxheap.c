// C program to insert & delete node in max heaps
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 // Max size of Heap

// Function to heapify ith node in a Heap of size n
// following a Bottom-up approach (reheapification upward)
void heapifyInsert(int arr[], int n, int i)
{
    // Find parent
    int parent = (i-1)/2;

    if (arr[parent]>0){
        // For Max-Heap
        // If current node is greater than its parent
        // Swap both of them and call heapify again
        // for the parent
        if (arr[i]>arr[parent]){
            int swap = arr[i];
            arr[i] = arr[parent];
            arr[parent] = swap;

            // Recursively heapify the parent node
            heapifyInsert(arr, n, parent);
        }
    }
}

// Function to insert a new node to the Heap
int insertNode(int arr[], int n, int Key) {
    // Increase the size of Heap by 1
    n = n + 1;

    // Insert the element at end of Heap
    arr[n-1] = Key;

    // Heapify the new node following a
    // Bottom-up approach
    heapifyInsert(arr, n, n-1);

    return n;
}

// To heapify a subtree rooted with node i which is an index
// of arr[] and n is the size of heap (reheapification downward)
void heapifyDelete(int arr[], int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l<n&&arr[l]>arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r<n&&arr[r]>arr[largest])
        largest = r;

    // If largest is not root
    if (largest!=i){
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        // Recursively heapify the affected sub-tree
        heapifyDelete(arr, n, largest);
    }
}

// Function to delete the root from Heap
int deleteRoot(int arr[], int n){
    // Get the last element
    int lastElement = arr[n - 1];

    // Replace root with last element
    arr[0] = lastElement;

    // Decrease size of heap by 1
    n = n - 1;

    // heapify the root node
    heapifyDelete(arr, n, 0);

    return n;
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver Code
int main()
{
    // Array representation of Max-Heap
    //        45
    //      /    \
    //     35     23
    //    /  \   /  \
    //   27  21 22   4
    //  /
    // 19
    int arr[MAX] = {45, 35, 23, 27, 21, 22, 4, 19};

    int n = 8;
    int key = 42;

    n = insertNode(arr, n, key);
    printf("After insert node: ");
    printArray(arr, n);

    //         45
    //       /    \
    //     42      23
    //    /  \    /  \
    //   35  21  22   4
    //  / \
    // 19  27

    n = deleteRoot(arr, n);
    printf("After delete root: ");
    printArray(arr, n);

    //         42
    //       /    \
    //     35      23
    //    /  \    /  \
    //   27  21  22   4
    //  /
    // 19

    return 0;
}
