#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct Node
{
	int value;
	struct Node* next;
};

struct Node* extendNode(struct Node** headRef, int newValue)
{	
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->value = newValue;
	newNode->next = *headRef;

	*headRef = newNode;

	return newNode;
}

void printLinkedList(struct Node* head)
{	
	struct Node* curNode = head;
	
	printf("[HEAD]");
	while (curNode != NULL) {
		printf(" %d ->", (int) curNode->value);
		curNode = curNode->next;
	}
	printf(" NULL ");
}


int main()
{
	struct Node *tail = malloc(sizeof(struct Node));
	struct Node *head;
	int newValue;
	int isValid;


	printf("\nEnter the first value of your linked list:\n");
	isValid = scanf("%d", &newValue);
	if (isValid){
		tail->value = newValue;
		tail->next = NULL;
	}

	head = tail;

	while(isValid){
		printf("\nEnter next value in linked list:\n");
		int newValue;
		isValid = scanf("%d", &newValue);
		if (isValid){
			extendNode(&head, newValue);	
			printLinkedList(head);
		}
	}

	return 0;
}
