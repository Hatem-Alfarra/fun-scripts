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
 * parameter head is expected to be the head pointer of a linked list.
 * parameter newValue is the desired value of the new node to be pushed.
 *
 * returned is the pointer to the new head newNode.
 * */
struct Node* push(struct Node** head, int newValue)
{	
	struct Node *newNode = malloc(sizeof(struct Node));	
	newNode->value = newValue;

	if (*head != NULL)
	{
		(*head)->prev = newNode;
	}
	newNode->next = *head;
	newNode->prev = NULL;

	*head = newNode;

	return newNode;
}

/* pop from a stack (the top element)
 *
 *
 * parameter headRef is expected to be a pointer of the head pointer of the linked list.
 *
 * side effect is reassigning the head pointer to the next node and freeing of the popped
 *  node (old head) from heap memory.
 *
 * */
void pop(struct Node** headRef)
{	
	// If empty stack, nothing to do and exit function.
	if (*headRef == NULL) { return; }

	struct Node *old = *headRef;
	
	// Next node is the new head
	*headRef = old->next;
	if (*headRef != NULL){
		// Disconnect the stack from old
		(*headRef)->prev = NULL;
	}
	// Free popped node
	free(old);	
}

/*
 * print the stack
 *
 * parameter head is a head pointer of the stack 
 *
 * */
void printStack(struct Node* head)
{
	struct Node* curNode = head;

	printf("\n\n");
	printf("[TOP]");
	while (curNode != NULL) 
	{
		printf(" %d ", (int) curNode->value);
		curNode = curNode->next;
		if (curNode != NULL) { printf("->"); }
	}

	printf("\n");
}


int main()
{
	int newValue;
	int isValid;

	struct Node *tail;

	printf("First node value:\n");
	isValid = scanf("%d", &newValue);
	if (isValid)
	{
		tail = malloc(sizeof(struct Node));
		tail->value = newValue;
		tail->next = NULL;
		tail->prev = NULL;
	}

	struct Node *head = tail;

	while(isValid){
		char action[10];
		printf("\nEnter action:\n");
		scanf("%9s", action);
		if (strcmp(action, "push") == 0)
		{
			printf("\nEnter value to push into stack:\n");
			isValid = scanf("%d", &newValue);
			if (isValid)
			{
				push(&head, newValue);
				// If one element left it is also the tail
				if (head == NULL) { tail = head; }
				printStack(head);
			} 
		} else if (strcmp(action, "pop") == 0) 
		{
			pop(&head);
			if (head == NULL) { tail = head; }
			printStack(head);
		} else printf("Valid actions are: push AND pop\n");
		
		printf("\n");
	}

	return 0;
}
