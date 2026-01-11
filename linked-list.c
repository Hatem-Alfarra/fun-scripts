#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node
{
	int value;
	struct Node* next;
};

struct Node* extendNode(struct Node* node, int size){
	
	int value = node->value;
	struct Node *pHEAD = node;

	while(size--){
		value++;
		struct Node *pNewNode = malloc(sizeof(struct Node));
		pNewNode->value = value;
		pNewNode->next = node;
		pHEAD = pNewNode;
		node = pNewNode;
	}
	return pHEAD;
}


void printLinkedList(struct Node* node){
	
	printf(" %d ", (int) node->value);
	while (node->next != NULL) {
		node = node->next;
		printf("-> %d ", (int) node->value);
	}
}


int main(){
	
	struct Node *pTAIL = malloc(sizeof(struct Node));
	pTAIL->value = 0;
	pTAIL->next = NULL;
	
	struct Node *pHEAD = extendNode(pTAIL, 5);	
	
	printLinkedList(pHEAD);


	return 0;
}
