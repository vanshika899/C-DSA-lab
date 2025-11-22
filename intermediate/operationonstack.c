#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop(){
    if(top==NULL){ printf("Stack Underflow\n"); return -1; }
    int val = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return val;
}

void displayStack(){
    struct Node *temp = top;
    if(temp==NULL){ printf("Stack empty\n"); return; }
    printf("Stack: ");
    while(temp){ printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}

struct Node *front=NULL, *rear=NULL;

void enqueue(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(rear==NULL){ front=rear=newNode; return; }
    rear->next = newNode;
    rear = newNode;
}

int dequeue(){
    if(front==NULL){ printf("Queue Underflow\n"); return -1; }
    int val = front->data;
    struct Node *temp = front;
    front = front->next;
    if(front==NULL) rear=NULL;
    free(temp);
    return val;
}

void displayQueue(){
    struct Node *temp=front;
    if(temp==NULL){ printf("Queue empty\n"); return; }
    printf("Queue: ");
    while(temp){ printf("%d ", temp->data); temp=temp->next; }
    printf("\n");
}

struct Node *ctail=NULL;

void cEnqueue(int val){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if(ctail==NULL){ newNode->next=newNode; ctail=newNode; return; }
    newNode->next=ctail->next;
    ctail->next=newNode;
    ctail=newNode;
}

int cDequeue(){
    if(ctail==NULL){ printf("Circular Queue Underflow\n"); return -1; }
    struct Node *temp=ctail->next;
    int val=temp->data;
    if(temp==ctail){ free(temp); ctail=NULL; return val; }
    ctail->next=temp->next;
    free(temp);
    return val;
}

void displayCQueue(){
    if(ctail==NULL){ printf("Circular Queue empty\n"); return; }
    struct Node *temp=ctail->next;
    printf("Circular Queue: ");
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp!=ctail->next);
    printf("\n");
}

int main(){
    int choice, op, val;
    while(1){
        printf("\n1.Stack 2.Queue 3.Circular Queue 4.Exit\nChoice: "); scanf("%d",&choice);
        if(choice==4) break;
        printf("1.Insert/Enqueue 2.Delete/Pop 3.Display\nOp: "); scanf("%d",&op);
        if(op==1){ printf("Value: "); scanf("%d",&val); }
        if(choice==1){ if(op==1) push(val); else if(op==2){ int x=pop(); if(x!=-1) printf("Popped: %d\n",x);} else displayStack(); }
        if(choice==2){ if(op==1) enqueue(val); else if(op==2){ int x=dequeue(); if(x!=-1) printf("Dequeued: %d\n",x);} else displayQueue(); }
        if(choice==3){ if(op==1) cEnqueue(val); else if(op==2){ int x=cDequeue(); if(x!=-1) printf("Dequeued: %d\n",x);} else displayCQueue(); }
    }
}
