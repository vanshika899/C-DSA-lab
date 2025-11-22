#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){ stack[++top] = c; }
char pop(){ return top==-1 ? '#' : stack[top--]; }
char peek(){ return top==-1 ? '#' : stack[top]; }

int precedence(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    if(c=='^') return 3;
    return 0;
}

int main(){
    char infix[MAX], postfix[MAX], c;
    int k=0;
    printf("Enter Infix expression: ");
    scanf("%s", infix);

    for(int i=0; i<strlen(infix); i++){
        c = infix[i];
        if(isalnum(c)) postfix[k++] = c;
        else if(c=='(') push(c);
        else if(c==')'){
            while(peek()!='#' && peek()!='(') postfix[k++] = pop();
            pop();
        }
        else{
            while(peek()!='#' && precedence(peek())>=precedence(c)) postfix[k++] = pop();
            push(c);
        }
    }
    while(peek()!='#') postfix[k++] = pop();
    postfix[k]='\0';
    printf("Postfix: %s\n", postfix);
    return 0;
}
