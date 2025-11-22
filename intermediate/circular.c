#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *tail = NULL;

void insert(){
    int val;
    printf("Enter value to insert: ");
    scanf("%d",&val);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if(tail == NULL){
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void delete(){
    if(tail == NULL){ printf("List is empty\n"); return; }
    int val;
    printf("Enter value to delete: ");
    scanf("%d",&val);
    struct Node *cur = tail->next, *prev = tail;
    do{
        if(cur->data == val){
            if(cur == tail && cur->next == tail){ 
                free(cur); 
                tail = NULL; 
            } else {
                prev->next = cur->next;
                if(cur == tail) tail = prev;
                free(cur);
            }
            printf("Deleted %d\n", val);
            return;
        }
        prev = cur;
        cur = cur->next;
    } while(cur != tail->next);
    printf("Value not found\n");
}

void display(){
    if(tail == NULL){ printf("List is empty\n"); return; }
    struct Node *cur = tail->next;
    printf("List: ");
    do{
        printf("%d ", cur->data);
        cur = cur->next;
    } while(cur != tail->next);
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
