#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node
{
	int value;
	struct Node* next;
	struct Node* prev;
};

struct Node* extendNode(struct Node* node, int newValue)
{	
	struct Node *pNewNode = malloc(sizeof(struct Node));
	pNewNode->value = newValue;
	pNewNode->next = node;
	pNewNode->prev = NULL;

	node->prev = pNewNode;

	return pNewNode;
}


void printLinkedListForwards(struct Node* node)
{	
	printf("[HEAD]");
	while (node != NULL) {
		printf(" %d ->", (int) node->value);
		node = node->next;
	}
	printf(" NULL ");
	printf("[TAIL]");
}



void printLinkedListBackwards(struct Node* node)
{	
	printf("[TAIL]");
	while (node != NULL) {
		printf(" %d ->", (int) node->value);
		node = node->prev;
	}
	printf(" NULL ");
	printf("[HEAD]");
}


int main()
{
	int newValue;
	int validInput;

	struct Node *pTAIL = malloc(sizeof(struct Node));
	printf("First node value:\n");
	validInput = scanf("%d", &newValue);
	if (validInput)
	{
		pTAIL->value = newValue;
		pTAIL->next = NULL;
		pTAIL->prev = NULL;
	}

	struct Node *pHEAD = pTAIL;

	while(validInput){
		printf("\nEnter next value in doubly linked list:\n");
		validInput = scanf("%d", &newValue);
		if (validInput){
			pHEAD = extendNode(pHEAD, newValue);
			printLinkedListForwards(pHEAD);
			printf("\n");
			printLinkedListBackwards(pTAIL);
		}
	}

	return 0;
}
