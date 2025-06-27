#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

void disStack(Node **TOP, Node **tempTOP);
void retrieve (Node **TOP, Node **tempTOP);

int main(){
	Node *TOP = NULL;
	Node *pushNode = (Node*)malloc(sizeof(Node));
	TOP = pushNode;
	pushNode->next = NULL;
	Node *tempTOP = NULL;
	char resp;
	printf("<@@ Creation of Stacks @@>\n\n");
	
	do{
		printf("Enter data for new node: ");
		scanf("%d", &pushNode->data);
		
		printf("Enter new node?: ");
		scanf(" %c", &resp);
		
		if (toupper(resp) == 'Y'){
			pushNode = (Node*)malloc(sizeof(Node));
			pushNode->next = TOP;
			TOP = pushNode;
		}
	} while (toupper(resp) == 'Y');
	pushNode = NULL;
	
	printf("Press any key to continue...");
	getch();
	
	disStack(&TOP, &tempTOP);
	retrieve(&TOP, &tempTOP);
	
}

void disStack(Node **TOP, Node **tempTOP){
	system("CLS");
	Node *popNode = NULL;
	int ctr = 1;
	
	if (*TOP == NULL){
		printf("The stack is empty\n");
		return;
	}
	
	popNode = *TOP;
	while (*TOP != NULL){
		printf("Node %d content\n", ctr);
		printf("\tData => %d\n", popNode->data);
		
		*TOP = (*TOP)->next;
		if (*tempTOP == NULL){
			popNode->next = NULL;
			*tempTOP = popNode;
		}
		else{
			popNode->next = *tempTOP;
			*tempTOP = popNode;
		}
		popNode = *TOP;
		ctr++;
	}
}

void retrieve (Node **TOP, Node **tempTOP){
	Node *pushNode = *tempTOP;
	
	while (pushNode != NULL){
		if (*TOP == NULL){
			*tempTOP = pushNode->next;
			pushNode->next = NULL;
			*TOP = pushNode;
		}
		else{
			*tempTOP = pushNode->next;
			pushNode->next = *TOP;
			*TOP = pushNode;
		}
		pushNode = *tempTOP;
	}

}
