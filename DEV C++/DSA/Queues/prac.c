#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

void createQ(Node **Front, Node **Rear);
void disQ(Node **Front, Node **Rear);
void freeQ(Node **Front);

int main(){
	Node *Front = NULL;
	Node *Rear = NULL;
	
	createQ(&Front, &Rear);
	disQ(&Front, &Rear);
	freeQ(&Front);
}

void createQ(Node **Front, Node **Rear){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	char resp;
	*Front = *Rear = newNode;
	
	printf("<@@ Creation of Queue @@>\n\n");
	
	do{
		printf("Enter data for new node: ");
		scanf("%d", &newNode->data);
		
		printf("Add new node?: ");
		scanf(" %c", &resp);
		
		if (toupper(resp) == 'Y'){
			newNode->next = (Node*)malloc(sizeof(Node));
			newNode = newNode->next;
			*Rear = newNode;
		}
	}while (toupper(resp) == 'Y');
	(*Rear)->next = NULL;
	newNode = NULL;
}

void disQ(Node **Front, Node **Rear){
	int Flag = (*Front)->data;
	Node *travNode = NULL;
	
	if (*Front == NULL){
		printf("Queue is empty");
	}
	else{
		travNode = *Front;
		do{
			printf("%d -> ", travNode->data);
			*Front = travNode->next;
			travNode->next = NULL;
			(*Rear)->next = travNode;
			*Rear = (*Rear)->next;
			travNode = *Front;
		} while (Flag != (*Front)->data);
		travNode = NULL;
		printf("NULL");
	}
}

void freeQ(Node **Front){
	Node *Temp;
	Node *travNode = *Front;
	while (travNode != NULL){
		Temp = travNode;
		travNode = travNode->next;
		free(Temp);
	}
	travNode = Temp = NULL;
}
