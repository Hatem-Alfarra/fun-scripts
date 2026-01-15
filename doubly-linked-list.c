#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node
{
	int value;
	struct Node* next;
	struct Node* prev;
};


struct Node* extendNode(struct Node** headRef, int val)
{	
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->value = val;
	newNode->next = *headRef;
	newNode->prev = NULL;
		
	// Set the prev of the old head to newNode.	
       	(*headRef)->prev = newNode;
	// newNode is the new head.
	*headRef = newNode;

	return *headRef;
}

/*
void printdllbackwards(struct Node* tail){	
	struct Node* curNode = tail;
	
	printf("[TAIL]");
	while (curNode != NULL) {
		printf(" %d ->", (int) curNode->value);
		curNode = curNode->prev;
	}
	printf(" NULL ");

	free(curNode);
}
*/


/*
 * print doubly linked list from Head to Tail.
 * 
 * parameter pNode is the Head pointer of the doubly linked list.
 *
 * side effect is printing list from Head to Tail.
 *
 * */
void printDoublyLinkedList(struct Node* head)
{
	struct Node* curNode = head;

	//printf("Doubly linked list: ");
	while (curNode != NULL) 
	{	
		if (curNode->next != NULL && curNode->prev != NULL)
		{ 
			printf(" %d <-->", (int) curNode->value);
		}
		if (curNode->next == NULL && curNode->prev == NULL)
		{
			printf("NULL <- %d -> NULL", (int) curNode->value);
		} else if (curNode->prev == NULL)
		{
			printf("NULL <- %d ", (int) curNode->value);
			if (curNode->next != NULL) { printf("<-->"); }
		} else if (curNode->next == NULL) 
		{ 
			printf(" %d -> NULL", (int) curNode->value); 
		}

		curNode = curNode->next;
	}

	printf("\n");

	free(curNode);
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
			extendNode(&pHEAD, newValue);
			printf("\n");
			printDoublyLinkedList(pHEAD);
		}
	}

	return 0;
}
