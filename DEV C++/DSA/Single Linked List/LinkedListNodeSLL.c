#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

void createList(Node **Start);
void showList(Node *Start);
int showChoices();
void addToStart(Node **Start);
void addToEnd(Node **Start);
void addBeforeNode(Node **Start);
void addAfterNode(Node **Start);
void delStart(Node **Start);
void delEnd(Node **Start);
void delNode(Node **Start);
void freeList(Node *Start);
void delAfter(Node **Start);

int main(){
	Node *Start = NULL;
	int choice;
	
	//Creation of Single/Singly Linked List
	createList(&Start);
	//Traversal of Single/Singly Linked List
	showList(Start);
	
	do{
		choice = showChoices();
		switch(choice){
			case 1:
				//Adding node at the Start
				addToStart(&Start);
				showList(Start);
				break;
		
			case 2:
				//Adding node at the End
				addToEnd(&Start);
				showList(Start);
				break;
			
			case 3:
				//Adding node before a node
				addBeforeNode(&Start);
				showList(Start);
				break;
			
			case 4:
				//Adding node after a node
				addAfterNode(&Start);
				showList(Start);
				break;
			
			case 5:
				//Deleting node at the Start
				delStart(&Start);
				showList(Start);
				break;
			
			case 6:
				//Deleting node at the End
				delEnd(&Start);
				showList(Start);
				break;
			
			case 7:
				//Deleting specific node
				delNode(&Start);
				showList(Start);
				break;
			
			case 8:
				//Deleting node after a node
				delAfter(&Start);
				showList(Start);
				break;
				
			case 9: 
				//Freeing the memory of the list
				freeList(Start);
				break;
					
			default:
				printf("INVALID CHOICE!!!\n\n");
		} 
	}while (choice >= 1 && choice != 9);
	
	return 0;
}

void createList(Node **Start){
	Node *newNode;
	int ctr = 1;
	char resp;
	
	printf("<@@ Creation of Single/Singly Linked List @@>\n");
	newNode = (Node*)malloc(sizeof(Node));
	*Start = newNode;
	newNode->next = NULL;
	
	do{
		printf("Enter data for new node: ");
		scanf("%d", &newNode->data);
	
		do{
			printf("Create new node? [Y/N]: ");
			scanf(" %c", &resp);
		} while (toupper(resp) != 'Y' && toupper(resp) != 'N');
		
		if (toupper(resp) == 'Y'){
			newNode->next = (Node*)malloc(sizeof(Node));
			newNode = newNode->next;
			newNode->next = NULL;
			ctr++;
		}
	} while (toupper(resp) == 'Y');
	newNode->next = NULL;
	newNode = NULL;
	
	printf("\nPress any key to continue...");
	getch();
}

void showList(Node *Start){
	Node *current;
	int ctr = 1;
	
	system("CLS");
	printf("Generating your Single/Singly Linked List... Complete!!!\n\n");
	
	printf("<@@ Traversal of Single/Singly Linked List @@>\n\n");
	if (Start == NULL){
		printf("The list is empty!!");
	}
	else{
		current = Start;
		
		while (current != NULL){
			printf("Node %d content:\n", ctr);
			printf("\tData => %d\n", current->data);
			current = current->next;
			ctr++;
		}
		current = NULL;
	}
	printf("\n\n");
}

int showChoices(){
	int choice;
	
	printf("[1] Add node at the Start\n");
	printf("[2] Add node at the End\n");
	printf("[3] Add node before a node\n");
	printf("[4] Add node after a node\n");
	printf("[5] Delete node at the Start\n");
	printf("[6] Delete node at the End\n");
	printf("[7] Delete a node\n");
	printf("[8] Delete node after a node\n");
	printf("[9] Exit\n");
	printf("\tEnter choice => ");
	scanf("%d", &choice);
	
	return choice;
}

void addToStart(Node **Start){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	
	printf("\n!!Adding new node at the Start!!\n\n");
	printf("Enter data for new node: ");
	scanf("%d", &newNode->data);
	
	if (Start == NULL){
		*Start = newNode;
		newNode->next = NULL;
	}
	else{
		newNode->next = *Start;
		*Start = newNode;
	}
	newNode = NULL;
	printf("\nNode added successfully!\n");
	printf("Press any key to continue...");
	getch();
}

void addToEnd(Node **Start){
	Node *current;
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	
	printf("\nAdding new node at the End!!\n\n");
	printf("Enter data for new node: ");
	scanf("%d", &newNode->data);
	
	current = *Start;
	if (current == NULL){
		current = newNode;
	}
	else{
		while (current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
	
	printf("\nNode added successfully!\n");
	printf("Enter any key to continue...");
	getch();
}

void addBeforeNode(Node **Start){
	int beforeVal, Flag = 0;
	Node *prev = NULL;
	Node *current = *Start;
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	
	printf("\n!!Adding node before a node!!\n\n");
	printf("Enter data for the new node: ");
	scanf("%d", &newNode->data);
	printf("Enter the node you want to new node to preceed: ");
	scanf("%d", &beforeVal);
	
	while (current != NULL && Flag != 1){
		if (beforeVal == current->data){
			Flag = 1;
		}
		else{
			prev = current;
			current = current->next;
		}
	}
	
	if (Flag == 1 && current != NULL){
		if (prev == NULL){
			*Start = newNode;
		}
		else{
		prev->next = newNode;
		}
		newNode->next = current;
		printf("New node added successfully!\n");
		printf("Press any key to continue...");
		getch();
	}
	else{
		printf("This node does not exist!!!\n\n");
		printf("Press any key to continue...");
		getch();
	}
	current = prev = NULL;
}

void addAfterNode(Node **Start){
	int afterVal, Flag = 0;
	Node *current = *Start;
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	
	printf("\n!!Adding node after a node!!\n\n");
	printf("Enter data for new node: ");
	scanf("%d", &newNode->data);
	printf("Enter node you want to add the new node after: ");
	scanf("%d", &afterVal);
	
	while (current != NULL && Flag != 1){
		if (afterVal == current->data){
			Flag = 1;
		}
		else{
			current = current->next;
		}
	}
	
	if (Flag == 1 && current != NULL){
		newNode->next = current->next;
		current->next = newNode;
		printf("New node added successfully!\n");
		printf("Press any key to continue...");
		getch();
	}
	else{
		printf("This node does not exist!!!\n\n");
		printf("Press any key to continue...");
		getch();
	}
	current = newNode = NULL;
}

void delStart(Node **Start){
	Node *current = *Start;
	char resp;
	
	if (current == NULL){
			printf("\nThe list is already empty!!\n");
			return;
		}
	
	printf("\n!!Deleting node at the Start!!\n\n");
	printf("Confirm this action [Y/N]: ");
	scanf(" %c", &resp);
	
	if (toupper(resp) == 'Y'){
		printf("\nDeleting node... ");
		
		*Start = current->next;
		current->next = NULL;
		free(current);
		printf("Deletion success!!\n");
		printf("Press any key to continue...");
		getch();
	}
	else{
		printf("Cancelling deletion...\n");
		printf("Press any key to continue...");
		getch();
	}
	current = NULL;
}

void delEnd(Node **Start){
	Node *prev = NULL;
	Node *current = *Start;
	char resp;
	
	if (current == NULL){
			printf("\nThe list is already empty!!\n");
			return;
	}
	
	printf("\n!!Deleting node at the End!!\n\n");
	printf("Confirm this action [Y/N]: ");
	scanf(" %c", &resp);
	
	if (toupper(resp) == 'Y'){
		printf("Deleting node...");
		
		while (current->next != NULL){
			prev = current;
			current = current->next;
		}
		
		if (prev == NULL){
			*Start = NULL;
		}
		else{
			prev->next = NULL;
		}
		free(current);
		printf("Deletion successful!!\n");
		printf("Press any key to continue...");
		getch();
	}
	else{
		printf("Cancelling deletion...\n\n");
		printf("Press any key to continue...");
		getch();
	}
}

void delNode(Node **Start){
	int delVal, Flag = 0;
	Node *current = *Start;
	Node *prev = NULL;
	
	if (current == NULL){
		printf("\nThis list is already empty!!\n");
		return;
	}
	
	printf("\n!!Deleting specific node!!\n\n");
	printf("Enter data of the node you want to delete: ");
	scanf("%d", &delVal);
	
	while (current != NULL && Flag != 1){
		if (delVal == current->data){
			Flag = 1;
		}
		else{
			prev = current;
			current = current->next;
		}
	}
	
	if (current != NULL && Flag == 1){
		printf("Deleting specified node...");
		
		if (prev == NULL){
			*Start = current->next;
			current->next = NULL;
		}
		else{
			prev->next = current->next;
			current->next = NULL;
		}
		free(current);
		printf("Deletion successfull!!\n");
		printf("Press any key to continue...");
		getch();
	}
	else{
		printf("This node does not exist!!\n");
		printf("Press any key to continue...");
		getch();
	}
}

void delAfter(Node **Start){
	int del_Val;
	Node *Curr = *Start, *Aft = NULL;
	
	if (Curr == NULL){
		printf("\nThis list is already empty!!\n");
		return;
	}
	
	printf("\n!!Deleting node after a node!!\n\n");
	printf("Enter the value of the node you want to delete the node after: ");
	scanf("%d", &del_Val);
	
	while (Curr != NULL && del_Val != Curr->data){
		Curr = Curr->next;
	}
	
	if (Curr != NULL && del_Val && Curr->data){
		if (Curr->next == NULL){
			printf("There is no node after the node!!\n");
		}
		else{
			printf("Deleting node...");
			Aft = Curr->next;
			if (Aft->next == NULL){
				Curr->next = NULL;
			}
			else{
				Curr->next = Aft->next;
				Aft->next = NULL;
			}
			free(Aft);
			printf("Deletion successful!!\n");
		}
	}
	else{
		printf("This node does not exist!!\n");
	}
	Curr = Aft = NULL;
	printf("Press any key to continue...");
	getch();
}

void freeList(Node *Start){
	Node *current = Start;
	Node *temp;
	
	while (current != NULL){
		temp = current;
		current = current->next;
		free(temp);
	} current = temp = NULL;
}
