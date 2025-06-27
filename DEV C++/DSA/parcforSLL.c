#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

void gotoxy(short int x, short int y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

typedef struct Node{
	char name[25];
	int age;
	char address[100];
	struct Node *next;
}Node;

void createList(Node **Head);
void disList(Node *Head);
void addStart(Node **Head);
void addEnd(Node **Head);
void addBefore(Node **Head);
void addAfter(Node **Head);
void delStart(Node **Head);
void delEnd(Node **Head);
void delNode(Node **Head);
void delBefore(Node **Head);
void delAfter(Node **Head);
void freeList(Node **Head);
int disMenu();

int main(){
	Node *Head = NULL;
	int ans;
	
	do{
		ans = disMenu();
		switch(ans){
			case 1:
				createList(&Head);
				disList(Head);
				break;
				
			case 2:
				disList(Head);
				break;
				
			case 3:
				addStart(&Head);
				disList(Head);
				break;
				
			case 4:
				addEnd(&Head);
				disList(Head);
				break;
			
			case 5:
				addBefore(&Head);
				disList(Head);
				break;
				
			case 6:
				addAfter(&Head);
				disList(Head);
				break;
			
			case 7:
				delStart(&Head);
				disList(Head);
				break;
				
			case 8:
				delEnd(&Head);
				disList(Head);
				break;
				
			case 9:
				delNode(&Head);
				disList(Head);
				break;
				
			case 10:
				delBefore(&Head);
				disList(Head);
				break;
				
			case 11:
				delAfter(&Head);
				disList(Head);
				break;
			
			case 12:
				freeList(&Head);
				break;
				
			default:
				printf("Invalid Choice!\n");
		}	
	} while (ans >= 1 && ans != 12);
}

int disMenu(){
	int ans;
	printf("[1] Create List\n");
	printf("[2] Display List\n");
	printf("[3] Add to Start of the List\n");
	printf("[4] Add to End of the List\n");
	printf("[5] Add node before a node\n");
	printf("[6] Add node after a node\n");
	printf("[7] Delete Start of the List\n");
	printf("[8] Delete End of the List\n");
	printf("[9] Delete Node\n");
	printf("[10] Delete before a node in the List\n");
	printf("[11] Delete after a node in the List\n");
	printf("[12] Exit\n");
	printf("\tEnter choice => ");
	scanf("%d", &ans);
	scanf("%c");
	
	return ans;
}

void createList(Node **Head){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	*Head = newNode;
	char resp;
	
	do{
		system("CLS");
		printf("Enter the following the information\n");
		printf("\tName: ");
		fgets(newNode->name, 25, stdin);
		printf("\tAge: ");
		scanf("%d", &newNode->age);
		scanf("%c");
		printf("\tAddress: ");
		fgets(newNode->address, 100, stdin);
		
		printf("\nEnter new person? ");
		scanf("%c", &resp);
		scanf("%c");
		
		if (toupper(resp) == 'Y'){
			newNode->next = (Node*)malloc(sizeof(Node));
			newNode = newNode->next;
		}
	} while (toupper(resp) == 'Y');
	newNode->next = NULL;
	newNode = NULL;
	
	printf("Press any key to continue...");
	getch();
}

void disList(Node *Head){
	Node *Current = Head;
	system("CLS");
	int ctr = 1;
	int num = 5;
	
	if (Current == NULL){
		printf("No inputted person yet!!\n");
	}
	else{
		gotoxy(65, 2);
		printf("<@@ PERSON RECORD @@>");
		
		gotoxy(1, 4);
		printf("Name");
		
		gotoxy(30, 4);
		printf("Age");
		
		gotoxy(45, 4);
		printf("Address");
		
		while (Current != NULL){
			gotoxy(1, num);
			printf("%d. %s", ctr, Current->name);
			
			gotoxy(30, num);
			printf("%d", Current->age);
			
			gotoxy(45, num);
			printf("%s", Current->address);
			Current = Current->next;
			num++;
			ctr++;
		}
		Current = NULL;
	}
	printf("\n\n");	
}

void addStart(Node **Head){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	
	system("CLS");
	printf("Enter the following the information\n");
	printf("\tName: ");
	fgets(newNode->name, 25, stdin);
	printf("\tAge: ");
	scanf("%d", &newNode->age);
	scanf("%c");
	printf("\tAddress: ");
	fgets(newNode->address, 100, stdin);
	
	if (*Head == NULL){
		*Head = newNode;
	}
	else{
		newNode->next = *Head;
		*Head = newNode;
	}
	newNode = NULL;
	printf("Press any key to continue...");
	getch();
}

void addEnd(Node **Head){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	Node *Current = NULL;
	
	system("CLS");
	printf("Enter the following the information\n");
	printf("\tName: ");
	fgets(newNode->name, 25, stdin);
	printf("\tAge: ");
	scanf("%d", &newNode->age);
	scanf("%c");
	printf("\tAddress: ");
	fgets(newNode->address, 100, stdin);
	
	if (*Head == NULL){
		*Head = newNode;
	}
	else{
		Current = *Head;
		while (Current->next != NULL){
			Current = Current->next;
		}
		Current->next = newNode;
	}
	Current = newNode = NULL;
	printf("Press any key to continue...");
	getch();
}

void addBefore(Node **Head){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	Node *Current = *Head;
	Node *Prev = NULL;
	char val[25];
	
	system("CLS");
	printf("Enter the following the information\n");
	printf("\tName: ");
	fgets(newNode->name, 25, stdin);
	printf("\tAge: ");
	scanf("%d", &newNode->age);
	scanf("%c");
	printf("\tAddress: ");
	fgets(newNode->address, 100, stdin);
	
	printf("Enter the name you want to add the person before: ");
	fgets(val, 25, stdin);
	
	while (Current != NULL && strcmp(val, Current->name) != 0){
		Prev = Current;
		Current = Current->next;
	}
	
	if (Current != NULL && strcmp(val, Current->name) == 0){
		if (Current == *Head){
			newNode->next = *Head;
			*Head = newNode;
		}
		else{
		newNode->next = Current;
		Prev->next = newNode;	
		}
	}
	else{
		printf("%s Does not exist\n", val);
	}
	Current = Prev = newNode = NULL;
	printf("Press any key to continue...");
	getch();
}

void addAfter(Node **Head){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	Node *Current = NULL;
	Current = *Head;
	char val[25];
	
	system("CLS");
	printf("Enter the following the information\n");
	printf("\tName: ");
	fgets(newNode->name, 25, stdin);
	printf("\tAge: ");
	scanf("%d", &newNode->age);
	scanf("%c");
	printf("\tAddress: ");
	fgets(newNode->address, 100, stdin);
	
	printf("Enter the name you want to add the person before: ");
	fgets(val, 25, stdin);
	
	while (Current != NULL && strcmp(val, Current->name) != 0){
		Current = Current->next;
	}
	
	if (Current != NULL && strcmp(val, Current->name) == 0){
		if (Current->next == NULL){
			Current->next = newNode;
		}
		else{
			newNode->next = Current->next;
			Current->next = newNode;
		}
	}
	else{
		printf("%s does not exist\n", val);
	}
	Current = newNode = NULL;
	printf("Press any key to continue...");
	getch();
}

void delStart(Node **Head){
	Node *Current = *Head;
	if (Current == NULL){
		printf("List is already empty!\n");
	}
	else{
		*Head = Current->next;
		Current->next = NULL;
		free(Current);
	}
	Current = NULL;
	printf("Press any key to continue...");
	getch();
}

void delEnd(Node **Head){
	Node *Current = *Head;
	Node *Prev = NULL;
	
	if (Current == NULL){
		printf("List is already empty!");
	}
	else{
		while (Current->next != NULL){
			Prev = Current;
			Current = Current->next;
		}
		
		if (Prev == NULL){
			free(*Head);
			*Head = NULL;
		}
		else{
			Prev->next = NULL;
			free(Current);	
		}
	}
	Current = Prev = NULL;
	printf("Press any key to continue...");
	getch();
}

void delNode(Node **Head){
	char val[25];
	Node *Current = *Head;
	Node *Prev = NULL;
	
	printf("Enter the name of the person you want to delete: ");
	fgets(val, 25, stdin);
	
	if (Current == NULL){
		printf("List is already empty!\n");
	}
	else{
		while(Current != NULL && strcmp(Current->name, val) != 0){
			Prev = Current;
			Current = Current->next;
		}
		
		if (Current != NULL && strcmp(Current->name, val) == 0){
			if (Current == *Head){
				*Head = Current->next;
				Current->next = NULL;
			}
			else if(Current->next == NULL){
				Prev->next = NULL;
			}
			else{
				Prev->next = Current->next;
				Current->next = NULL;
			}
			free(Current);
		}
		else{
			printf("%s does not exist\n", val);
		}
	}
	Current = Prev = NULL;
	printf("Press any key to continue...");
	getch();
}

void delBefore(Node **Head){
	char val[25];
	Node *Current = *Head;
	Node *Prev = NULL;
	
	if (Current == NULL){
		printf("The list is already empty");
		printf("\nPress any key to continue...");
		getch();
		return;
	}
	else{
		printf("Enter the name you want to delete the person before: ");
		fgets(val, 25, stdin);
		
		if (strcmp(Current->name, val) == 0){
			printf("There is no person before this person\n");
		}
		else{
			while (Current != NULL && strcmp(Current->next->name, val) != 0){
				Prev = Current;
				Current = Current->next;
			}
			
			if (Current != NULL && strcmp(Current->next->name, val) == 0){
				if (Prev == NULL){
					*Head = Current->next;
					Current->next = NULL;
					free(Current);
				}
				else{
					Prev->next = Current->next;
					Current->next = NULL;
					free(Current);
				}
			}
			else{
				printf("%s does not exist\n", val);
			}
		}
	}
	Current = Prev = NULL;
	printf("Press any key to continue...");
	getch();
}

void delAfter(Node **Head){
	Node *Current = *Head;
	Node *Aft = NULL;
	char val[25];
	
	if (Current == NULL){
		printf("List is already empty\n");
		printf("Press any key to continue...");
		getch();
		return;
	}
	
	printf("Enter the name of the person you want to delete after: ");
	fgets(val, 25, stdin);
	
	while (Current != NULL && strcmp(Current->name, val) != 0){
		Current = Current->next;
	}
	
	if (Current != NULL && strcmp(Current->name, val) == 0){
		if (Current->next == NULL){
			printf("There is no person after this person\n");
		}
		else{
			Aft = Current->next;
			Current->next = Aft->next;
			Aft->next = NULL;
			free(Aft);
		}
	}
	else{
		printf("%s does not exist", val);
	}
	Current = Aft = NULL;
	printf("Press any key to continue...");
	getch();
}

void freeList(Node **Head){
	Node *Current = *Head;
	Node *Temp = NULL;
	
	while (Current != NULL){
		Temp = Current;
		Current = Current->next;
		free(Temp);
	}
	Current = Temp = NULL;
}































