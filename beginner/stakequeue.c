#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;
void push(int x){
    if(top == MAX-1) printf("Stack Overflow\n");
    else stack[++top] = x;
}
int pop(){
    if(top == -1) { printf("Stack Underflow\n"); return -1; }
    return stack[top--];
}
void displayStack(){
    if(top==-1){ printf("Stack empty\n"); return; }
    for(int i=0;i<=top;i++) printf("%d ",stack[i]);
    printf("\n");
}

int queue[MAX], front=-1, rear=-1;
void enqueue(int x){
    if(rear==MAX-1) printf("Queue Overflow\n");
    else{
        if(front==-1) front=0;
        queue[++rear] = x;
    }
}
int dequeue(){
    if(front==-1 || front>rear){ printf("Queue Underflow\n"); return -1; }
    return queue[front++];
}
void displayQueue(){
    if(front==-1 || front>rear){ printf("Queue empty\n"); return; }
    for(int i=front;i<=rear;i++) printf("%d ",queue[i]);
    printf("\n");
}

int cqueue[MAX], cfront=-1, crear=-1;
void cEnqueue(int x){
    if((cfront==0 && crear==MAX-1) || (crear+1==cfront)) { printf("Circular Queue Overflow\n"); return; }
    if(cfront==-1){ cfront=crear=0; cqueue[crear]=x; return; }
    if(crear==MAX-1) crear=0;
    else crear++;
    cqueue[crear]=x;
}
int cDequeue(){
    if(cfront==-1){ printf("Circular Queue Underflow\n"); return -1; }
    int val=cqueue[cfront];
    if(cfront==crear) cfront=crear=-1;
    else if(cfront==MAX-1) cfront=0;
    else cfront++;
    return val;
}
void displayCQueue(){
    if(cfront==-1){ printf("Circular Queue empty\n"); return; }
    int i=cfront;
    while(1){
        printf("%d ", cqueue[i]);
        if(i==crear) break;
        i = (i+1)%MAX;
    }
    printf("\n");
}

int main(){
    int choice, op, val;
    while(1){
        printf("\n--- MENU ---\n1.Stack\n2.Queue\n3.Circular Queue\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("1.Push 2.Pop 3.Display\nEnter operation: ");
                scanf("%d",&op);
                if(op==1){ printf("Enter value: "); scanf("%d",&val); push(val); }
                else if(op==2){ int x=pop(); if(x!=-1) printf("Popped: %d\n",x); }
                else if(op==3) displayStack();
                else printf("Invalid\n");
                break;
            case 2:
                printf("1.Enqueue 2.Dequeue 3.Display\nEnter operation: ");
                scanf("%d",&op);
                if(op==1){ printf("Enter value: "); scanf("%d",&val); enqueue(val); }
                else if(op==2){ int x=dequeue(); if(x!=-1) printf("Dequeued: %d\n",x); }
                else if(op==3) displayQueue();
                else printf("Invalid\n");
                break;
            case 3:
                printf("1.Enqueue 2.Dequeue 3.Display\nEnter operation: ");
                scanf("%d",&op);
                if(op==1){ printf("Enter value: "); scanf("%d",&val); cEnqueue(val); }
                else if(op==2){ int x=cDequeue(); if(x!=-1) printf("Dequeued: %d\n",x); }
                else if(op==3) displayCQueue();
                else printf("Invalid\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
