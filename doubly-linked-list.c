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

	printf("\n\n");

	free(curNode);
}


int main()
{
	int newValue;
	int isValid;

	struct Node *tail = malloc(sizeof(struct Node));
	printf("First node value:\n");
	isValid = scanf("%d", &newValue);
	if (isValid)
	{
		tail->value = newValue;
		tail->next = NULL;
		tail->prev = NULL;
	}

	struct Node *head = tail;

	while(isValid){
		printf("\nEnter next value in doubly linked list:\n");
		isValid = scanf("%d", &newValue);
		if (isValid){
			extendNode(&head, newValue);
			printf("\n");
			printDoublyLinkedList(head);
		}
	}

	return 0;
}
