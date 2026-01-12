#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node
{
	int value;
	struct Node* next;
};

struct Node* extendNode(struct Node* node, int newValue)
{	
	struct Node *pNewNode = malloc(sizeof(struct Node));
	pNewNode->value = newValue;
	pNewNode->next = node;

	return pNewNode;
}


void printLinkedList(struct Node* node)
{	
	while (node->next != NULL) {
		printf(" %d ->", (int) node->value);
		node = node->next;
	}
	printf(" NULL");
}


int main()
{
	struct Node *pTAIL = malloc(sizeof(struct Node));
	pTAIL->value = 0;
	pTAIL->next = NULL;

	struct Node *pHEAD = pTAIL;

	int valid_input = 1;	
	while(valid_input){
		printf("\nEnter next value in linked list:\n");
		int newValue;
		valid_input = scanf("%d", &newValue);
		if (valid_input){
			pHEAD = extendNode(pHEAD, newValue);	
			printLinkedList(pHEAD);
		}
	}

	return 0;
}
