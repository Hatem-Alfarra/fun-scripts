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
struct Node* push(struct Node *head, int newValue)
{	
	struct Node *newNode = malloc(sizeof(struct Node));	
	newNode->value = newValue;

	if (head != NULL)
	{
		head->prev = newNode;
	}
	newNode->next = head;
	newNode->prev = NULL;


	return newNode;
}

/* pop from a stack (the top element)
 *
 *
 * parameter head is expected to be the head pointer of a linked list or a NULL
 * pointer. Null pointers passed in return a Null pointer as well.
 *
 * side effect is freeing of the popped node pointer from heap memory.
 *
 * returned is a pointer to the new head after popping.
 * */
struct Node* pop(struct Node *head)
{
	if (head == NULL) { return NULL; }

	struct Node *pNextNode = head->next;

	if (pNextNode == NULL) { free(head); return NULL; }

	pNextNode->prev = NULL;

	free(head);
	
	return pNextNode;
}

/*
 * print linked list from Head to Tail.
 *
 * parameter head is the head pointer of the linked list.
 * 
 * side effect is printing list from Head to Tail.
 *
 * */
void printLinkedListForwards(struct Node *head)
{	
	struct Node* curNode = head;
	
	printf("FORWARDS: ");
	printf("[HEAD]");
	while (curNode != NULL) 
	{
		printf(" %d ->", (int) curNode->value);
		curNode = curNode->next;
	}
	printf(" NULL ");
	printf("[TAIL]\n");
}


/*
 * print linked list from Tail to Head.
 *
 * parameter head is the Tail pointer of the linked list.
 *
 * side effect is printing list from Tail to Head.
 *
 * */
void printLinkedListBackwards(struct Node *tail)
{	
	struct Node* curNode = tail;
	
	printf("BACKWARDS: ");
	printf("[TAIL]");
	while (curNode != NULL) 
	{
		printf(" %d ->", (int) curNode->value);
		curNode = curNode->prev;
	}
	printf(" NULL ");
	printf("[HEAD]\n");
}


/*
 * print doubly linked list from Head to Tail.
 * 
 * parameter head is the Head pointer of the doubly linked list.
 *
 * side effect is printing list from Head to Tail.
 *
 * */
void printDoublyLinkedList(struct Node* head)
{
	struct Node* curNode = head;

	printf("Doubly linked list: ");
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



void printAll(struct Node *head, struct Node *tail)
{
	//printLinkedListForwards(head);
	//printLinkedListBackwards(tail);
	//printDoublyLinkedList(head);
	printStack(head);
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
				head = push(head, newValue);
				// If one element left it is also the tail
				if (head == NULL) { tail = head; }
				printAll(head, tail);
			} 
		} else if (strcmp(action, "pop") == 0) 
		{
			head = pop(head);
			if (head == NULL) { tail = head; }
			printAll(head, tail);
		} else printf("Valid actions are: push AND pop\n");
		
		printf("\n");
	}

	return 0;
}
