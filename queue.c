#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node
{
	int value;
	struct Node* next;
	struct Node* prev;
};

/* push into a stack a new node with a value
 *
 * parameter pNode is expected to be the head pointer of a linked list.
 * parameter newValue is the desired value of the new node to be pushed.
 *
 * returned is the pointer to the new head pNewNode.
 * */
struct Node* push(struct Node *pNode, int newValue)
{	
	struct Node *pNewNode = malloc(sizeof(struct Node));	
	pNewNode->value = newValue;

	if (pNode != NULL)
	{
		pNode->prev = pNewNode;
	}
	pNewNode->next = pNode;
	pNewNode->prev = NULL;


	return pNewNode;
}

/* pop from a stack (the top element)
 *
 *
 * parameter pNode is expected to be the head pointer of a linked list or a NULL
 * pointer. Null pointers passed in return a Null pointer as well.
 *
 * side effect is freeing of the popped node pointer from heap memory.
 *
 * returned is a pointer to the new head after popping.
 * */
struct Node* pop(struct Node *pNode)
{
	if (pNode == NULL) { return NULL; }

	struct Node *pNextNode = pNode->next;

	if (pNextNode == NULL) { free(pNode); return NULL; }

	pNextNode->prev = NULL;

	free(pNode);
	
	return pNextNode;
}

/*
 * print linked list from Head to Tail.
 *
 * parameter pNode is the head pointer of the linked list.
 * 
 * side effect is printing list from Head to Tail.
 *
 * */
void printLinkedListForwards(struct Node *pNode)
{	
	printf("FORWARDS: ");
	printf("[HEAD]");
	while (pNode != NULL) 
	{
		printf(" %d ->", (int) pNode->value);
		pNode = pNode->next;
	}
	printf(" NULL ");
	printf("[TAIL]\n");
}


/*
 * print linked list from Tail to Head.
 *
 * parameter pNode is the Tail pointer of the linked list.
 *
 * side effect is printing list from Tail to Head.
 *
 * */
void printLinkedListBackwards(struct Node *pNode)
{	
	printf("BACKWARDS: ");
	printf("[TAIL]");
	while (pNode != NULL) 
	{
		printf(" %d ->", (int) pNode->value);
		pNode = pNode->prev;
	}
	printf(" NULL ");
	printf("[HEAD]\n");
}


/*
 * print doubly linked list from Head to Tail.
 * 
 * parameter pNode is the Head pointer of the doubly linked list.
 *
 * side effect is printing list from Head to Tail.
 *
 * */
void printDoublyLinkedList(struct Node* pNode)
{
	printf("Doubly linked list: ");
	while (pNode != NULL) 
	{	
		if (pNode->next != NULL && pNode->prev != NULL)
		{ 
			printf(" %d <-->", (int) pNode->value);
		}
		if (pNode->next == NULL && pNode->prev == NULL)
		{
			printf("NULL <- %d -> NULL", (int) pNode->value);
		} else if (pNode->prev == NULL)
		{
			printf("NULL <- %d ", (int) pNode->value);
			if (pNode->next != NULL) { printf("<-->"); }
		} else if (pNode->next == NULL) 
		{ 
			printf(" %d -> NULL", (int) pNode->value); 
		}

		pNode = pNode->next;
	}

	printf("\n");
}

/*
 * print the stack
 *
 * parameter pNode is a head pointer of the stack 
 *
 * */
void printStack(struct Node* pNode)
{
	printf("Stack: ");
	printf("[TOP]");
	while (pNode != NULL) 
	{
		printf(" %d ", (int) pNode->value);
		pNode = pNode->next;
		if (pNode != NULL) { printf("->"); }
	}
}



void printAll(struct Node *pHEAD, struct Node *pTAIL)
{
	printLinkedListForwards(pHEAD);
	printLinkedListBackwards(pTAIL);
	printDoublyLinkedList(pHEAD);
	printStack(pHEAD);
}



int main()
{
	int newValue;
	int validInput;

	struct Node *pTAIL = NULL;

	printf("First node value:\n");
	validInput = scanf("%d", &newValue);
	if (validInput)
	{
		pTAIL = malloc(sizeof(*pTAIL));
		pTAIL->value = newValue;
		pTAIL->next = NULL;
		pTAIL->prev = NULL;
	}

	struct Node *pHEAD = pTAIL;

	while(validInput){
		char action[10];
		printf("\n\nEnter action:\n");
		scanf("%9s", action);
		if (strcmp(action, "push") == 0)
		{
			printf("\nEnter value to push into stack:\n");
			validInput = scanf("%d", &newValue);
			if (validInput)
			{
				pHEAD = push(pHEAD, newValue);
				// If one element left it is also the tail
				if (pTAIL == NULL) { pTAIL = pHEAD; }
			} 
		} else if (strcmp(action, "pop") == 0) 
		{
			pHEAD = pop(pHEAD);
			if (pHEAD == NULL) { pTAIL = pHEAD; }
		} else 
			printf("Valid actions are: push AND pop\n");
	
		printAll(pHEAD, pTAIL);
	}

	return 0;
}
