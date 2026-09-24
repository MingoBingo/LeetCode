#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int value;
    struct Node *next;
};

typedef struct Node Stack;


void push(Stack **top, int value) {
    Stack *newNode = malloc(sizeof(Stack));
    newNode->value = value;
    newNode->next = *top;
    *top = newNode;
}


int pop(Stack **top) {
    if (*top == NULL) return 0;
    
    Stack *aux = *top;
    int poppedValue = aux->value;
    *top = aux->next;
    
    free(aux); 
    return poppedValue;
}

int evalRPN(char** tokens, int tokensSize) {
    Stack *top = NULL;
    
    for(int i = 0; i < tokensSize; ++i) {
        char *token = tokens[i];
        
       
        if(strcmp(token, "+") == 0) {
            int n2 = pop(&top);
            int n1 = pop(&top);
            push(&top, n1 + n2);
        } 
        else if(strcmp(token, "-") == 0) {
            int n2 = pop(&top); 
            int n1 = pop(&top);
            push(&top, n1 - n2);
        } 
        else if(strcmp(token, "*") == 0) {
            int n2 = pop(&top);
            int n1 = pop(&top);
            push(&top, n1 * n2);
        } 
        else if(strcmp(token, "/") == 0) {
            int n2 = pop(&top);
            int n1 = pop(&top);
            push(&top, n1 / n2); 
        } 
        else {
           
            push(&top, atoi(token));
        }
    }
    
    return pop(&top);
}