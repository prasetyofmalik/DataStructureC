#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char nama[30];
    struct node *left;
    struct node *right;
    int height;
} mhs;
mhs* newMhs(char nama[]){
    mhs* node = (mhs*)malloc(sizeof(mhs));
    strcpy(node->nama, nama);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
};
int max(int a, int b){
    if (a>b) return a;
    else return b;
}
int getHeight(mhs* N){
    if (N==NULL)
        return 0;
    return N->height;
}
int getBalanceFactor(mhs* N){
    if (N==NULL)
        return 0;
    return (getHeight(N->left) - getHeight(N->right));
}
mhs* rightRotate(mhs* T){
    mhs* new_root = T->left;
    mhs* orphan = new_root->right;

    // rotasi
    new_root->right = T;
    T->left = orphan;
    // update height
    T->height = 1 + max(getHeight(T->left), getHeight(T->right));
    new_root->height = 1 + max(getHeight(new_root->left),
                            getHeight(new_root->right));
    return new_root;
};
mhs* leftRotate(mhs* T){
    mhs *new_root = T->right;
    mhs *orphan = new_root->left;

    // rotasi
    new_root->left = T;
    T->right = orphan;
    // update height
    T->height = 1 + max(getHeight(T->left), getHeight(T->right));
    new_root->height = 1 + max(getHeight(new_root->left),
                            getHeight(new_root->right));
    return new_root;
};
mhs* insert(mhs* root, char n[]){
    // 1. BST
    if (root == NULL)
        return(newMhs(n));
    // asumsi tidak boleh ada nilai yang sama dalam BST
    int z = strcmp(n, root->nama);
    if (z<0)
        root->left = insert(root->left, n);
    else if (z>0)
        root->right = insert(root->right, n);
    // 2. Update height node baru beserta ancestornya
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));
    // 3. Hitung balance factor untuk menentukan apakah
    // node unbalanced (beserta ancestornya)
    int balance = getBalanceFactor(root);

    // jika tidak balanced, return hasil rotation
    int yleft, yright;
    if (root->left->nama!=NULL)
        yleft = strcmp(n, root->left->nama);
    if (root->right->nama!=NULL)
        yright = strcmp(n, root->right->nama);

    // kasus 1: left-left
    if (balance>1 && yleft<0)
        return rightRotate(root);
    // kasus 2: right-right
    if (balance<-1 && yright>0)
        return leftRotate(root);
    // kasus 3: right-left
    if (balance<-1 && yright<0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // kasus 4: left-right
    if (balance>1 && yleft>0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // return node jika balanced
    return root;
};
mhs* delete_node(mhs* root, char deletedNama[]){
    if(root == NULL)
        return root;
    else{
        mhs* cursor;
        int z = strcmp(deletedNama, root->nama);
        if (z>0)
            root->right = delete_node(root->right,deletedNama);
        else if (z<0)
            root->left = delete_node(root->left, deletedNama);
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
                strcpy(root->nama, cursor->nama);
                root->right = delete_node(root->right, cursor->nama);
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
void displayPreorder(mhs* node){
    if (node==NULL)
        return;
    printf("- %s\n", node->nama); // root
    displayPreorder(node->left); // subtree kiri
    displayPreorder(node->right); // subtree kanan

}
void displayInorder(mhs* node){
    if (node==NULL)
        return;
    displayInorder(node->left); // subtree kiri
    printf("- %s\n", node->nama); // root
    displayInorder(node->right); // subtree kanan
}
void displayPostorder(mhs* node){
    if (node==NULL)
        return;
    displayPostorder(node->left); // subtree kiri
    displayPostorder(node->right); // subtree kanan
    printf("- %s\n", node->nama); // root
}
void printCurrentLevel(struct node* root, int level);
int height(struct node* node);
// Print nodes pada level saat ini
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("- %s\n", root->nama); // root
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1); // subtree kiri
        printCurrentLevel(root->right, level - 1); // subtree kanan
    }
}
// Hitung tinggi tree
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        // hitung tinggi tiap subtree
        int lheight = height(node->left);
        int rheight = height(node->right);

        // gunakan yang terbesar
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
// Fungsi untuk menampilkan level order traversal a tree
void printLevelOrder(struct node* root){
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printCurrentLevel(root, i);
}
int main(){
    printf("-----Data Nama Mahasiswa-----\n");
    mhs* root = NULL;

    int i, jml;
    char Inama[30];
    printf("\nMasukkan jumlah mahasiswa: ");
    scanf("%d", &jml);
    for(i=0;i<jml;i++){
        printf("Nama mahasiswa: ");
        scanf("%s", &Inama);
        root = insert(root, Inama);
    }

    int choice = 0;
    do{
        printf("\nMENU\n1. Tambahkan Nama Mahasiswa\n2. Tampilkan"
               " Daftar Mahasiswa\n3. Hapus Nama Mahasiswa\n"
               "4. Keluar\nMasukkan pilihan: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                printf("Masukkan nama mahasiswa: ");
                char add[30];
                scanf("%s", &add);
                root = insert(root, add);
                printf("\n");
                break;
            case 2:
                printf("Display Pre-Order: \n");
                displayPreorder(root);
                printf("\nDisplay In-Order: \n");
                displayInorder(root);
                printf("\nDisplay Post-Order: \n");
                displayPostorder(root);
                printf("\nDisplay Level Order: \n");
                printLevelOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Hapus nama mahasiswa: ");
                char Dnama[30];
                scanf("%s", &Dnama);
                root = delete_node(root, Dnama);
                break;
            case 4:
                printf("\nKELUAR");
                break;
            default:
                printf("Pilihan tidak valid.\n\n");
        }
    }
    while (choice!=4);

    return 0;
}
