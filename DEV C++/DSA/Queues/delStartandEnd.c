#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>

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
void createQ(Node **Front, Node **Rear);
void disQ(Node **Front, Node **Rear);
void delStart(Node **Front, Node **Rear);
void delEnd(Node **Front, Node **Rear);
void freeQ(Node **Front, Node **Rear);

int main(){
	Node *Front = NULL;
	Node *Rear = NULL;
	int choice;
	
	do{
		choice = disMenu();
		switch (choice){
			case 1:
				createQ(&Front, &Rear);
				disQ(&Front, &Rear);
				break;
			
			case 2:
				disQ(&Front, &Rear);
				break;
			
			case 3:
				delStart(&Front, &Rear);
				disQ(&Front, &Rear);
				break;
			
			case 4:
				delEnd(&Front, &Rear);
				disQ(&Front, &Rear);
				break;
			
			case 5:
				freeQ(&Front, &Rear);
				break;
			
			default:
				printf("Invalid choice!!\n");
		}
	} while (choice >= 1 && choice != 5);
	
	return 0;
}

int disMenu(){
	int choice;
	printf("\n\n[1] Create Student Records\n");
	printf("[2] Display Student Records\n");
	printf("[3] Delete Student at the Start\n");
	printf("[4] Delete Student at the End\n");
	printf("[5] Exit\n");
	printf("\tEnter choice => ");
	scanf("%d", &choice);
	scanf("%c");
	
	return choice;
}

void createQ(Node **Front, Node **Rear){
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->next = NULL;
	char Resp;
	int Ctr = 1;
	*Front = *Rear = NewNode;
	
	do{
		system("CLS");
		printf("<@@ Creation of Student Records @@>\n");
		printf("Enter data for student %d:\n", Ctr);
        printf("Student Number: 	");
        fgets(NewNode->StudNo, 13, stdin);
        printf("Name: 			");
        fgets(NewNode->Name, 25, stdin);
        printf("Course and Year: 	");
        fgets(NewNode->CrsYr, 10, stdin);
        printf("GWA: 			");
        scanf("%f", &NewNode->gwa);
        
        printf("Add another student?: ");
        scanf(" %c", &Resp);
        scanf("%c");
        
        if (toupper(Resp) == 'Y'){
            NewNode->next = (Node*)malloc(sizeof(Node));
            *Rear = NewNode->next;
            NewNode = NewNode->next;
            Ctr++;
        }
	} while (toupper(Resp) == 'Y');
	(*Rear)->next = NULL;
	NewNode = NULL;
	printf("Press any key to continue...");
	getch();
}

void disQ(Node **Front, Node **Rear){
	Node *TempFront = NULL;
	Node *TempRear = NULL;
	Node *TravNode = *Front;
	int Ctr = 5, Num = 1;
	
	system("CLS");
	
	if (TravNode == NULL){
		printf("No students inputted yet\n");
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
		
		while (*Front != NULL){
			gotoxy(1, Ctr);
			printf("%d. %s", Num, TravNode->StudNo);
			
			gotoxy(20, Ctr);
			printf("%s", TravNode->Name);
			
			gotoxy(50, Ctr);
			printf("%s", TravNode->CrsYr);
			
			gotoxy(70, Ctr);
			printf("%.2f", TravNode->gwa);
			
			//Adding data into temporary queue
			*Front = TravNode->next;
			if (*Front == NULL){
				*Rear = NULL;
			}
			TravNode->next = NULL;
			if (TempFront == NULL){
				TempFront = TravNode;
			}
			else{
				TempRear->next = TravNode;
			}
			TempRear = TravNode;
			TravNode = *Front;
			Ctr++;
			Num++;
		}
		*Front = *Rear = NULL;
		
		//Returning data into original queue
		*Front = TempFront;
		*Rear = TempFront;
	}
	TravNode = TempFront = TempRear = NULL;
}

void delStart(Node **Front, Node **Rear){
	Node *DelNode = *Front;
	char Resp;
	
	if (DelNode == NULL){
		printf("No students inputted yet\n");
	}
	else{
		printf("Confirm this action [Y/N]: ");
		scanf("%c", &Resp);
		
		if (toupper(Resp) == 'Y'){
			printf("Deleting student at the Start...");
			*Front = (*Front)->next;
			DelNode->next = NULL;
			if (*Front == NULL){
				*Rear = NULL;
			}
			free(DelNode);
			DelNode = NULL;
			printf("Deletion successful!\n");	
		}
		else{
			printf("Cancelling Deletion...\n");
		}
	}
	printf("Press any key to continue...");
	getch();
}

void delEnd(Node **Front, Node **Rear){
	Node *DelNode = NULL;
	Node *TempFront = NULL;
	Node *TempRear = NULL;
	char Resp;
	
	if (*Front == NULL){
		printf("No students inputted yet\n");
	}
	else{
		printf("Confirm this action [Y/N]: ");
		scanf(" %c", &Resp);
		
		if (toupper(Resp) == 'Y'){
			printf("Deleting student at the End...");
			DelNode = *Front;
			//Traversing for the Rear and putting the data into a temporary queue
			while (DelNode->next != NULL){
				*Front = (*Front)->next;
				if (TempFront == NULL){
					TempFront = DelNode;
				}
				else{
					TempRear->next = DelNode;
				}
				TempRear = DelNode;
				DelNode = *Front;
				TempRear->next = NULL;
			}
			
			free(DelNode);
			DelNode = NULL;
			
			//Returning the data into the original queue
			*Front = TempFront;
			*Rear = TempRear;
			printf("Deletion successful!\n");
		}
		else{
			printf("Cancelling deletion...\n");
		}
	}
	TempFront = TempRear = NULL;
	printf("Press any key to continue...");
	getch();
}

void freeQ(Node **Front, Node **Rear){
	Node *TravNode = *Front;
	Node *Temp = NULL;
	while (TravNode != NULL){
		Temp = TravNode;
		TravNode = TravNode->next;
		free(Temp);
	}
	*Front = *Rear = NULL;
}
