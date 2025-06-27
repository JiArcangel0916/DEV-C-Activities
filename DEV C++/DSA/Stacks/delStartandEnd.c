#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef struct Node{
	char StudNo[13];
    char Name[25];
    char CrsYr[10];
    float gwa;
    struct Node *next;
}Node;

int disMenu();
void createStack(Node **Top);
void disStack(Node **Top);
void delTop(Node **Top);
void delBot(Node **Top);
void freeStack(Node **Top);

int main(){
	Node *Top = NULL;
	int choice;
	
	do{
		choice = disMenu();
		switch(choice){
			case 1:
				createStack(&Top);
				disStack(&Top);
				break;
			
			case 2:
				disStack(&Top);
				break;
			
			case 3:
				delTop(&Top);
				disStack(&Top);
				break;
			
			case 4:
				delBot(&Top);
				disStack(&Top);
				break;
			
			case 5:
				freeStack(&Top);
				break;
			
			default:
				printf("Invalid choice!!\n");
		}
	} while(choice >= 1 && choice != 5);
	
	return 0;
}

int disMenu(){
	int choice;
	printf("\n\n");
	printf("[1] Create Student Report\n");
	printf("[2] Display Student Report\n");
	printf("[3] Delete Student at Top\n");
	printf("[4] Delete Student at Bottom\n");
	printf("[5] Exit\n");
	printf("\tEnter choice => ");
	scanf("%d", &choice);
	scanf("%c");
	
	return choice;
}

void createStack(Node **Top){
	Node *PushNode = NULL;
	char Resp;
	int ctr = 1;
	PushNode = (Node*)malloc(sizeof(Node));
	PushNode->next = NULL;
	*Top = PushNode;
	
	do{
		system("CLS");
		printf("<@@ Creation of Student Records @@>\n");
		printf("Enter data for student %d:\n", ctr);
        printf("Student Number: 	");
        fgets(PushNode->StudNo, 13, stdin);
        printf("Name: 			");
        fgets(PushNode->Name, 25, stdin);
        printf("Course and Year: 	");
        fgets(PushNode->CrsYr, 10, stdin);
        printf("GWA: 			");
        scanf("%f", &PushNode->gwa);
        
        printf("Add another student?: ");
        scanf(" %c", &Resp);
        scanf("%c");
        
        if (toupper(Resp) == 'Y'){
            PushNode = (Node*)malloc(sizeof(Node));
            PushNode->next = *Top;
            *Top = PushNode;
            ctr++;
        }
    } while (toupper(Resp) == 'Y');
    PushNode = NULL;
	printf("Press any key to continue...");
	getch();
}

void disStack(Node **Top){
	Node *PopNode = NULL;
	Node *PushNode = NULL;
	Node *TempTop = NULL;
	int Ctr = 5, Num = 1;
	
	system("CLS");
	
	if (*Top == NULL){
		printf("Student records is empty!\n");
	}
	else{
		gotoxy(65,2);
		printf("<@@ STUDENT RECORDS @@>");
	
		gotoxy(1, 4);
		printf("STUDENT NO."); 
	
		gotoxy(20, 4);
		printf("NAME"); 
	
		gotoxy(50, 4);
		printf("Course & Year");
	
		gotoxy(70, 4);
		printf("GWA"); 
		
		PopNode = *Top;
		while (*Top != NULL){
			gotoxy(1, Ctr);
			printf("%d. %s", Num, PopNode->StudNo);
			
			gotoxy(20, Ctr);
			printf("%s", PopNode->Name);
			
			gotoxy(50, Ctr);
			printf("%s", PopNode->CrsYr);
			
			gotoxy(70, Ctr);
			printf("%.2f", PopNode->gwa);
			
			*Top = (*Top)->next; 
			
			//Putting data into a temporary stack
			if(TempTop == NULL){
				PopNode->next = NULL;
			}
			else{
				PopNode->next = TempTop;
			}
			TempTop = PopNode;
			PopNode = *Top;
			Ctr++;	
			Num++;			
		}
		
		//Returning data to original stack
		PushNode = TempTop;
		while(TempTop != NULL){
			TempTop = PushNode->next;
			if (*Top == NULL){
				PushNode->next = NULL;
			}
			else{
				PushNode->next = *Top;
			}
			*Top = PushNode;
			PushNode = TempTop;
		}
	}
	PopNode = PushNode = TempTop = NULL;
}

void delTop(Node **Top){
	char Resp;
	Node *PopNode = NULL;
	
	if (*Top == NULL){
		printf("List is already empty!\n");
	}
	else{
		PopNode = *Top;
		printf("\n!!Deleting Student at the Start!!\n");
		printf("Confirm this action [Y/N]: ");
		scanf("%c", &Resp);
	
		if (toupper(Resp) == 'Y'){
			printf("Deleting student...");
			*Top = (*Top)->next;
			PopNode->next = NULL;
			free(PopNode);
			printf("Deletion successful!\n");
		}
		else{
			printf("Cancelling deletion...\n");
		}
	}
	PopNode = NULL;
	printf("Press any key to continue...");
	getch();
}

void delBot(Node **Top){
	char Resp;
	Node *PopNode = NULL;
	Node *TempTop = NULL;
	Node *PushNode = NULL;
	
	if (*Top == NULL){
		printf("The list is already empty!\n");
	}
	else{
		PopNode = *Top;
		printf("\nDeleting Student at the End!!\n");
		printf("Confirm this action [Y/N]: ");
		scanf("%c", &Resp);
		
		if (toupper(Resp) == 'Y'){
			printf("Deleting student...");
			
			//Putting data into a temporary stack
			while ((*Top)->next != NULL){
				*Top = (*Top)->next;
				if (TempTop == NULL){
					PopNode->next = NULL;
				}
				else{
					PopNode->next = TempTop;
				}
				TempTop = PopNode;
				PopNode = *Top;
			}
			
			//Deleting student at the bottom
			free(PopNode);
			PopNode = NULL;
			*Top = NULL;
			
			//Returning data into the original stack
			PushNode = TempTop;
			while (TempTop != NULL){
				TempTop = PushNode->next;
				if (*Top == NULL){
					PushNode->next = NULL;
				}
				else{
					PushNode->next = *Top;
				}
				*Top = PushNode;
				PushNode = TempTop;
			}
			
			printf("Deletion successful!\n");
			PushNode = TempTop = NULL;
		}
		else{
			printf("Cancelling deletion...\n");
		}
		printf("Press any key to continue...");
		getch();
	}
}

void freeStack(Node **Top){
	Node *Temp;
	while (*Top != NULL){
		Temp = *Top;
		*Top = (*Top)->next;
		free(Temp);
	}
	Temp = *Top;
	free(Temp);
	
	Temp = NULL;
}
