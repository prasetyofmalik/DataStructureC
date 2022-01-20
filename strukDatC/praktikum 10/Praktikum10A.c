#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
struct node *newNode(int data){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
};
int max(int a, int b){
    if (a>b) return a;
    else return b;
}
int getHeight(struct node* N){
    if (N==NULL)
        return 0;
    return N->height;
}
int getBalanceFactor(struct node* N){
    if (N==NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}
struct node* rightRotate(struct node* T){
    struct node* new_root = T->left;
    struct node* orphan = new_root->right;

    // rotasi
    new_root->right = T;
    T->left = orphan;
    // update height
    T->height = max(getHeight(T->left), getHeight(T->right))+1;
    new_root->height = max(getHeight(new_root->left),
                           getHeight(new_root->right))+1;
    return new_root;
};
struct node* leftRotate(struct node* T){
    struct node *new_root = T->right;
    struct node *orphan = new_root->left;

    // rotasi
    new_root->left = T;
    T->right = orphan;
    // update height
    T->height = max(getHeight(T->left), getHeight(T->right))+1;
    new_root->height = max(getHeight(new_root->left),
                           getHeight(new_root->right))+1;
    return new_root;
};
struct node* insert(struct node* root, int new_data){
    // 1. BST
    if (root == NULL)
        return(newNode(new_data));
    // asumsi tidak boleh ada nilai yang sama dalam BST
    if (new_data<root->data)
        root->left = insert(root->left, new_data);
    else if (new_data>root->data)
        root->right = insert(root->right, new_data);
    // 2. Update height node baru beserta ancestornya
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));
    // 3. Hitung balance factor untuk menentukan apakah
    // node unbalanced (beserta ancestornya)
    int balance = getBalanceFactor(root);

    // jika tidak seimbang, return hasil rotasi
    // kasus 1: left-left
    if (balance>1 && new_data<root->left->data)
        return rightRotate(root);
    // kasus 2: right-right
    if (balance<-1 && new_data>root->right->data)
        return leftRotate(root);
    // kasus 3: right-left
    if (balance<-1 && new_data<root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // kasus 4: left-right
    if (balance>1 && new_data>root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // return node jika balanced
    return root;
};
struct node* delete_node(struct node* root, int deletedData){
    if(root == NULL)
        return root;
    else{
        struct node* cursor;
        if(deletedData > root->data)
            root->right = delete_node(root->right,deletedData);
        else if(deletedData < root->data)
            root->left = delete_node(root->left, deletedData);
        else{
            //1 CHILD
            if(root->left == NULL){
                cursor = root->right;
                free(root);
                root = cursor;
            }
            else if(root->right == NULL) {
                cursor = root->left;
                free(root);
                root = cursor;
            }
            //2 CHILDREN
            else{
                cursor = root->right;
                while(cursor->left != NULL){
                    cursor = cursor->left;
                }
                root->data = cursor->data;
                root->right = delete_node(root->right, cursor->data);
            }
        }
    }
    // jika setelah dilakukan delete tree kosong, return root
    if (root == NULL)
        return root;
    // update height dari node
    root->height = 1 + max(getHeight(root->left),
                          getHeight(root->right));
    // hitung balance factor
    int balance = getBalanceFactor(root);

    // jika tidak seimbang, return hasil rotasi
    // kasus 1: left-left
    if (balance>1 && getBalanceFactor(root->left)>=0)
        return rightRotate(root);
    // kasus 2: right-right
    if (balance<-1 && getBalanceFactor(root->right)<=0)
        return leftRotate(root);
    // kasus 3: right-left
    if (balance<-1 && getBalanceFactor(root->right)>0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // kasus 4: left-right
    if (balance>1 && getBalanceFactor(root->left)<0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    return root;
};
void displayPreorder(struct node* node){
    if(node == NULL)
        return;
    printf("%d ", node->data); // root
    displayPreorder(node->left); // subtree kiri
    displayPreorder(node->right); // subtree kanan
}
void displayInorder(struct node* node){
    if(node == NULL)
        return;
    displayInorder(node->left); // subtree kiri
    printf("%d ", node->data); // root
    displayInorder(node->right); // subtree kanan
}
void displayPostorder(struct node* node){
    if(node == NULL)
        return;
    displayPostorder(node->left); // subtree kiri
    displayPostorder(node->right); // subtree kanan
    printf("%d ", node->data); // root
}
int main(){
    struct node* root = NULL;

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    printf("Display Pre-Order\t: ");
    displayPreorder(root);
    printf("\nDisplay In-Order\t: ");
    displayInorder(root);
    printf("\nDisplay Post-Order\t: ");
    displayPostorder(root);
    //        9
    //       / \
    //      1   10
    //     / \   \
    //    0   5   11
    //   /   / \
    // -1   2   6

    printf("\n\nSetelah Delete Data\n");
    root = delete_node(root, 10);

    printf("Display Pre-Order\t: ");
    displayPreorder(root);
    printf("\nDisplay In-Order\t: ");
    displayInorder(root);
    printf("\nDisplay Post-Order\t: ");
    displayPostorder(root);
    //       9                        1
    //      / \      kasus 1:        / \
    //     1   11    left-left      0   9
    //    / \         ==>>         /   / \
    //   0   5                   -1   5   11
    //  /   / \                      / \
    //-1   2   6                    2   6

    return 0;
}
