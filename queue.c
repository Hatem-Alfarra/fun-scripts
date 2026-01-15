#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int value;
    struct Node* behind;
};

struct queue {
    struct Node *pFront;
    struct Node *pBack;
    int size;
};

void initQueue(struct queue *pQ){
    pQ->size = 0;
    pQ->pBack = NULL;
    pQ->pFront = NULL;
}

void enqueue(struct queue* pQ, int newValue){
    struct Node* pNewNode = malloc(sizeof(struct Node));
    pNewNode->value = newValue;

    int size = pQ->size;
    if (size <= 0) {
        pNewNode->behind = NULL;
        pQ->pBack = pNewNode;
        pQ->pFront = pNewNode;
        pQ->size += 1;
    } else {
        pNewNode->behind = NULL;
//        pNewNode->next = pQ->behind;
        pQ->pBack->behind = pNewNode;
        pQ->pBack = pNewNode;
        pQ->size += 1;
    }
}

void dequeue(struct queue* pQ){
    if (pQ->pFront == NULL) {return;}
    struct Node* oldFront = pQ->pFront;
    struct Node* newFront = oldFront->behind;
    free(oldFront);
    pQ->pFront = newFront;
//    newFront->next = NULL;
}

void printQueue(struct queue *pQ){
    struct Node* curNode = pQ->pFront;
    printf("[Front]");

    while(curNode != NULL){
        printf(" %d " ,curNode->value);
        if (curNode->behind != NULL){
            printf("<-");
        }
        curNode = curNode->behind;
    }

}

int main(){
    int newValue;
    int isValid;
    struct queue *Q1 = malloc(sizeof(struct Node));


    printf("First queue value:\n");
    isValid = scanf("%d", &newValue);
    if (isValid)
    {
        initQueue(Q1);
        enqueue(Q1, newValue);
    }

    while(isValid){
        char action[10];
        printf("\nEnter action:\n");
        scanf("%9s", action);
        if (strcmp(action, "enqueue") == 0 || strcmp(action, "E") == 0)
        {
            printf("\nEnter value to insert into queue:\n");
            isValid = scanf("%d", &newValue);
            if (isValid)
            {
                enqueue(Q1, newValue);
                printQueue(Q1);
            }
        } else if (strcmp(action, "dequeue") == 0 || strcmp(action, "D") == 0) {
            dequeue(Q1);
            printQueue(Q1);
        } else printf("Valid actions are: enqueue (E) AND dequeue (D)\n");

        printf("\n");
    }

    return 0;
}
