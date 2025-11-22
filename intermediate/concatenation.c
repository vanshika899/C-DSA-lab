#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head){
    if(head==NULL){ printf("List is empty\n"); return; }
    struct Node *temp = head;
    while(temp){ printf("%d ", temp->data); temp=temp->next; }
    printf("\n");
}

struct Node* concatenate(struct Node *head1, struct Node *head2){
    if(head1==NULL) return head2;
    struct Node *temp = head1;
    while(temp->next) temp = temp->next;
    temp->next = head2;
    return head1;
}

struct Node* createList(int n){
    struct Node *head=NULL, *temp;
    int val;
    for(int i=0;i<n;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &val);
        struct Node *newNode = createNode(val);
        if(head==NULL) head=temp=newNode;
        else { temp->next=newNode; temp=newNode; }
    }
    return head;
}

int main(){
    int n1,n2;
    printf("Enter number of elements in first list: ");
    scanf("%d",&n1);
    struct Node *head1 = createList(n1);

    printf("Enter number of elements in second list: ");
    scanf("%d",&n2);
    struct Node *head2 = createList(n2);

    head1 = concatenate(head1, head2);
    printf("Concatenated List: ");
    display(head1);
    return 0;
}
