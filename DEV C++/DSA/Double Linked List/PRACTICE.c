#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
}Node;

int showChoices();
void createList(Node **Head, Node **Tail);
void showList(Node *Head);
void addHead(Node **Head, Node **Tail);
void addTail(Node **Head, Node **Tail);
void delHead(Node **Head, Node **Tail);
void delTail(Node **Head, Node **Tail);
void freeList(Node **Head, Node **Tail);

int main(){
	int choice;
	Node *Head = NULL;
	Node *Tail = NULL;
	
	do{
		choice = showChoices();
		switch(choice){
			case 1:
				createList(&Head, &Tail);
				showList(Head);
				break;
				
			case 2:
				showList(Head);
				break;
				
			case 3:
				addHead(&Head, &Tail);
				showList(Head);
				break;
				
			case 4:
				addTail(&Head, &Tail);
				showList(Head);
				break;
			
			case 5:
				delHead(&Head, &Tail);
				showList(Head);
				break;
			
			case 6:
				delTail(&Head, &Tail);
				showList(Head);
				break;
			
			case 7:
				freeList(&Head, &Tail);
				break;
			
			default:
				printf("Invalid Choice\n");
		}
	} while (choice >= 1 && choice != 6);
}

int showChoices(){
	int choice;
	
	printf("[1] Create List\n");
	printf("[2] Show List\n");
	printf("[3] Add Node at the Head\n");
	printf("[4] Add Node at the Tail\n");
	printf("[5] Delete Node at the Head\n");
	printf("[6] Delete Node at the Tail\n");
	printf("[7] Exit\n");
	printf("Enter choice => ");
	scanf("%d", &choice);
	
	return choice;
}

void createList(Node **Head, Node **Tail){
	char resp;
	Node *newNode = NULL;
	
	system("CLS");
	printf("========== CREATION OF DOUBLE/DOUBLY LINKED LIST ==========\n");
	newNode = (Node*)malloc(sizeof(Node));
	*Head = newNode;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	do {
		printf("Enter data for new node: ");
		scanf("%d", &newNode->data);
		
		printf("Add another node? ");
		scanf(" %c", &resp);
		scanf("%c");
		
		if (toupper(resp) == 'Y'){
			newNode->next = (Node*)malloc(sizeof(Node));
			newNode->next->prev = newNode;
			newNode = newNode->next;
			*Tail = newNode;
			
		}
	} while (toupper(resp) == 'Y');
	newNode->next = NULL;
	newNode = NULL;
	printf("Press any key to continue...");
	getch();
}

void showList(Node *Head){
	Node *Current = Head;
	int ctr = 1;
	
	system("CLS");
	printf("========== TRAVERSAL OF DOUBLE/DOUBLY LINKED LIST ==========\n");
	if (Current == NULL){
		printf("There are no nodes in the list yet\n\n");
	}
	else{
		while (Current != NULL){
			printf("Node %d Data => %d\n", ctr, Current->data);
			ctr++;
			Current = Current->next;			
		}
		Current = NULL;
		printf("\n");
	}
}

void addHead(Node **Head, Node **Tail){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;
	
	printf("\n***** ADDITION OF NODE AT THE HEAD *****\n");
	printf("Enter data for new node: ");
	scanf("%d", &newNode->data);
	printf("Adding new node at the head...");
	
	if (*Head == NULL && *Tail == NULL){
		*Head == newNode;
		*Tail == newNode;
	}
	else{
		newNode->next = *Head;
		*Head = newNode;
	}
	newNode = NULL;
	printf("COMPLETE!!!\n");
	printf("Press any key to continue...");
	getch();
	
}

void addTail(Node **Head, Node **Tail){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;
	
	printf("\n***** ADDTION OF NODE AT THE TAIL *****\n");
	printf("Enter data for new node: ");
	scanf("%d", &newNode->data);
	printf("Adding new node at the tail...");
	
	if (*Head == NULL && *Tail == NULL){
		*Head = newNode;
		*Tail = newNode;
	}
	else{
		newNode->prev = *Tail;
		(*Tail)->next = newNode;
		*Tail = newNode;
	}
	newNode = NULL;
	printf("COMPLETE!!!\n");
	printf("Press any key to continue...");
	getch();
}

void delHead(Node **Head, Node **Tail){
	char resp;
	Node *Temp = NULL;
	
	if (*Head == NULL && *Tail == NULL){
		printf("The list is already empty!\n");
	}
	else{
		printf("***** DELETING NODE AT THE HEAD *****\n");
		printf("Confirm this action [Y/N]: ");
		scanf(" %c", &resp);
	
		if (toupper(resp) == 'Y'){
			printf("Deleting node at head...");
			Temp = *Head;
			*Head = (*Head)->next;
			(*Head)->prev = NULL;
			Temp->next = NULL;
			free(Temp);
			printf("COMPLETE!\n");
			Temp = NULL;
		}
		else{
			printf("Cancelling action...");
		}	
		printf("Press any key to continue...");
		getch();
	}	
}

void delTail(Node **Head, Node **Tail){
	char resp;
	Node *Temp = NULL;
	
	if (*Head == NULL && *Tail == NULL){
		printf("The list is already empty!\n");
	}
	else{
		printf("***** DELETING NODE AT THE TAIL *****\n");
		printf("Confirm this action [Y/N]: ");
		scanf(" %c", &resp);
	
		if (toupper(resp) == 'Y'){
			printf("Deleting node at tail...");
			Temp = *Tail;
			*Tail = (*Tail)->prev;
			(*Tail)->next = NULL;
			free(Temp);
		}
		else{
			printf("Cancelling action...");
		}	
		Temp = NULL;
		printf("Press any key to continue...");
		getch();
	}
}

void freeList(Node **Head, Node **Tail){
	Node *Temp = NULL;
	Node *Current = *Head;
	
	while (Current != NULL){
		Temp = Current;
		Current = Current->next;
		free(Temp);
	}
	
	Current = Temp = NULL;
	*Head = NULL;
	*Tail = NULL;
}
