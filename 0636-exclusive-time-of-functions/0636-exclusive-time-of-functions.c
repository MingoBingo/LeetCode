/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <strings.h>

struct Stack
{
    char *command;
    int cmdID;
    int timestamp;
    struct Stack *next;
};

typedef struct Stack Stack;

void pop(Stack **top)
{
    if((*top) == NULL)
        return;
    Stack *aux = (*top);
    (*top) = (*top)->next;
    free(aux);
}

void push(Stack **top, char *command)
{
    Stack *aux = malloc(sizeof(Stack));
    aux->command = malloc(sizeof(char) * (strlen(command) + 1));

    strcpy(aux->command, command);
    
    aux->next = (*top);
    (*top) = aux;

    char *belle = malloc(sizeof(char) * (strlen(command) + 1));

    strcpy(belle, command);

    char *p = strtok(belle, ":");

    aux->cmdID = atoi(p);

    p = strtok(NULL, ":");
    p = strtok(NULL, ":");
    
    aux->timestamp = atoi(p);

    free(belle);
}

int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) 
{
    int *result = calloc(n, sizeof(int));
    (*returnSize) = n;

    int i = 0;

    Stack *top = NULL;

    while(i < logsSize)
    {
        char *command = malloc(sizeof(char) * (strlen(logs[i]) + 1));
        strcpy(command, logs[i]);

        char *auxCMD = malloc(sizeof(char) * (strlen(command) + 1));
        strcpy(auxCMD, logs[i]);

        if(strstr(command, "start"))
        {
            char *k = strtok(auxCMD, ":");
            int ID = atoi(k);
            k = strtok(NULL, ":");
            k = strtok(NULL, ":");
            int tmstp = atoi(k);

            if(top!=NULL)
            {
                result[top->cmdID] += (tmstp - top->timestamp);
            }
            push(&top, command);
        }
        else
        {
            char *p = strtok(auxCMD, ":");
            p = strtok(NULL, ":");
            p = strtok(NULL, ":");
            result[top->cmdID] += ((atoi(p)) - top->timestamp + 1);
            int tptmp = atoi(p) + 1;
            pop(&top);

            if(top!=NULL)
                top->timestamp = tptmp;
            free(command);

        }
        free(auxCMD);
        i++;
    }
    
    return result;
}