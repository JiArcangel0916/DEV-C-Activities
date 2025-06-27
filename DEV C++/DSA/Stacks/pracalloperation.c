#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

void createStack (Node **TOP);
void disStack (Node **TOP);
void freeStack (Node **TOP);
void delTop (Node **TOP);
void addTop (Node **TOP);
int Menu();

int main(){
	Node *TOP = NULL;
	int choice;
	
	do {
		choice = Menu();
		switch(choice){
			case 1:
				createStack(&TOP);
				disStack(&TOP);
				break;
				
			case 2:
				disStack(&TOP);
				break;
			
			case 3:
				addTop(&TOP);
				disStack(&TOP);
				break;
			
			case 4:
				delTop(&TOP);
				disStack(&TOP);
				break;
				
			case 5:
				freeStack(&TOP);
				
			default:
				printf("Invalid choice\n");
		}
	} while (choice >= 1 && choice != 5);
}

int Menu(){
	int choice;
	
	printf("[1] Create Stack\n");
	printf("[2] Display Stack\n");
	printf("[3] Add node to Top\n");
	printf("[4] Delete node at Top\n");
	printf("[5] Exit\n");
	printf("\tEnter choice => ");
	scanf("%d", &choice);
	
	return choice;
}

void createStack(Node **TOP){
	Node *pushNode = (Node*)malloc(sizeof(Node));
	pushNode->next = NULL;
	*TOP = pushNode;
	char resp;
	
	system("CLS");
	printf("<@@ Creation of Stack @@>\n\n");
	do{
		printf("Enter data for node: ");
		scanf("%d", &pushNode->data);
		
		printf("Enter new node?: ");
		scanf(" %c", &resp);
		
		if (toupper(resp) == 'Y'){
			pushNode = (Node*)malloc(sizeof(Node));
			pushNode->next = *TOP;
			*TOP = pushNode;
		}	
	} while (toupper(resp) == 'Y');
	printf("Press any key to continue...");
	getch();
	pushNode = NULL;
}

void disStack(Node **TOP){
	Node *popNode = NULL;
	Node *tempTOP = NULL;
	Node *pushNode = NULL;
	int ctr = 1;
	
	system("CLS");
	if (*TOP == NULL){
		printf("Stack is empty!!\n");
		return;
	}
	
	popNode = *TOP;
	while (*TOP != NULL){
		printf("Node %d content:\n", ctr);
		printf("\tData => %d\n", popNode->data);
		*TOP = (*TOP)->next;
		
		//Putting data into a temporary stack
		if (tempTOP == NULL){
			popNode->next = NULL;
		}
		else{
			popNode->next = tempTOP;
		}
		tempTOP = popNode;
		popNode = *TOP;
		ctr++;
	}
	
	//returning nodes from temporary stack to original stack
	pushNode = tempTOP;
	while (tempTOP != NULL){
		tempTOP = tempTOP->next;
		if (*TOP == NULL){
			pushNode->next = NULL;
		}
		else{
			pushNode->next = *TOP;
		}
		*TOP = pushNode;
		pushNode = tempTOP;
	}
}

void addTop(Node **TOP){
	Node *pushNode = (Node*)malloc(sizeof(Node));
	pushNode->next = NULL;
	
	printf("\n!!Adding of node at the top!!\n");
	printf("Enter data for new node: ");
	scanf("%d", &pushNode->data);
	
	printf("Adding node...");
	if(*TOP != NULL){
		pushNode->next = *TOP;
		*TOP = pushNode;
	}
	else{
		*TOP = pushNode;
	}
	printf("Adding successful!\n");
	printf("Press any key to continue...");
	getch();
	pushNode = NULL;
}

void delTop(Node **TOP){
	Node *popNode = *TOP;
	char resp;
	
	printf("!!Deleting node at the Top!!\n");
	printf("Confirm this action: ");
	scanf(" %c", &resp);
	
	printf("Deleting top...");
	if (toupper(resp) == 'Y'){
		*TOP = (*TOP)->next;
		popNode->next = NULL;
		free(popNode);	
		printf("Deletion successful!!\n");
	}
	else{
		printf("Cancelling deletion\n");
	}
	printf("Press any key to continue...");
	getch();
	popNode = NULL;
}

void freeStack(Node **TOP){
	Node *temp;
	Node *current = *TOP;
	
	while (current != NULL){
		temp = current;
		current = current->next;
		free(temp);
	}
	current = temp = NULL;
}
