#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX], top=-1;

void push(int x){ stack[++top]=x; }
int pop(){ return stack[top--]; }

int main(){
    char exp[MAX];
    printf("Enter Postfix expression: ");
    scanf("%s", exp);
    for(int i=0; i<strlen(exp); i++){
        char c = exp[i];
        if(isdigit(c)) push(c-'0');
        else{
            int b = pop();
            int a = pop();
            switch(c){
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b); break;
            }
        }
    }
    printf("Result: %d\n", pop());
    return 0;
}
