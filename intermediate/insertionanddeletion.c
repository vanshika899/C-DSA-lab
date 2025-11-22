#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val){
    if(root==NULL) return createNode(val);
    if(val < root->data) root->left = insert(root->left, val);
    else if(val > root->data) root->right = insert(root->right, val);
    return root;
}

struct Node* minValueNode(struct Node* node){
    struct Node* current = node;
    while(current && current->left!=NULL) current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int val){
    if(root==NULL) return root;
    if(val < root->data) root->left = deleteNode(root->left, val);
    else if(val > root->data) root->right = deleteNode(root->right, val);
    else{
        if(root->left==NULL){ struct Node* temp = root->right; free(root); return temp; }
        else if(root->right==NULL){ struct Node* temp = root->left; free(root); return temp; }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    struct Node* root = NULL;
    int choice, val;
    while(1){
        printf("\n1.Insert 2.Delete 3.Display(Inorder) 4.Exit\nChoice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter value to insert: "); scanf("%d",&val); root = insert(root, val); break;
            case 2: printf("Enter value to delete: "); scanf("%d",&val); root = deleteNode(root, val); break;
            case 3: printf("BST(Inorder): "); inorder(root); printf("\n"); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
