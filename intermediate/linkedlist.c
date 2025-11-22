#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(){
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void delete(){
    if(head == NULL){ printf("List is empty\n"); return; }
    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);
    struct Node *temp = head, *prev = NULL;
    while(temp != NULL && temp->data != val){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){ printf("Value not found\n"); return; }
    if(prev == NULL) head = head->next;
    else prev->next = temp->next;
    free(temp);
    printf("Deleted %d\n", val);
}

void display(){
    if(head == NULL){ printf("List is empty\n"); return; }
    struct Node *temp = head;
    printf("List: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\nEnter choice: ");
        scanf("%d", &choice);
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
