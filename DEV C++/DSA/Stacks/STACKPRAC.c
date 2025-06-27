#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Stack{
	Node *Top;
}Stack;

Node *createNode(int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	
	return newNode;
}

Stack *createStack(){
	Stack *newStack = (Stack*)malloc(sizeof(Stack));
	newStack->Top = NULL;
	
	return newStack;
}

void push(Stack *stack, int data){
	Node *newNode = createNode(data);
	newNode->next = stack->Top;
	stack->Top = newNode;
}

void pop(Stack *stack){
	Node *Temp = stack->Top;
	stack->Top = stack->Top->next;
	Temp->next = NULL;
	free(Temp);
}

void disStack(Stack *stack){
	Node *Current = stack->Top;
	while (Current != NULL){
		printf("%d -> ", Current->data);
		Current = Current->next;
	}
	printf("NULL");
}

int showChoices(){
	int choice;
	
	printf("[1] Create Stack\n");
	printf("[2] Display Stack\n");
	printf("[3] Add Node to Top\n");
	printf("[4] Add Node to Bottom\n");
	printf("[5] Delete Node at Top\n");
	printf("[6] Delete Node at the Bottom\n");
	printf("[7] Exit\n");
	printf("Enter choice => ");
	scanf("%d", &choice);
	
	return choice;
}

int main(){
	int choice;
	do{
		choice = showChoices();
		
		switch(choice){
			case 1:
				createStack();
				
		}
	}
	
	return 0;
}
