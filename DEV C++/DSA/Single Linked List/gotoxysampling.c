#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef struct Stud{
	char studNo[13];
	char name[25];
	char crsYr[10];
	float GWA;
	struct Stud *next; 
}Stud;

void createRec(Stud **Start);
void disRec(Stud *Start);
void freeList(Stud **Start);
void delStud(Stud **Start);
void delAfter(Stud **Start);
int disMenu();

int main(){
	Stud *Start = NULL;
	int choice;
	
	do{
		choice = disMenu();
		switch(choice){
			case 1:
				//Creation of Records
				createRec(&Start);
				disRec(Start);
				break;
			
			case 2:
				//Displaying of Records
				disRec(Start);
			
			case 3:
				//Deletion of Student
				delStud(&Start);
				disRec(Start);
				break;
				
			case 4:
				//Deletion of Student after a Student
				delAfter(&Start);
				disRec(Start);
				break;
				
			case 5:
				//Freeing of Memory
				freeList(&Start);
				break;
				
			default:
				printf("Invalid input");
		}
	} while (choice >= 1 && choice != 5);

	return 0;
}

int disMenu(){
	int choice;
	
	printf("\nEnter action to perform:\n");
	printf("\t[1] Create Student GWA Report\n");
	printf("\t[2] Display Student GWA Report\n");
	printf("\t[3] Delete a Student\n");
	printf("\t[4] Delete Student after a student\n");
	printf("\t[5] Exit\n");
	printf("\t\tEnter choice => ");
	scanf("%d", &choice);
	scanf("%c");

	return choice;
}

void createRec(Stud **Start){
	Stud *newStud;
	char resp;
	
	system("CLS");
	printf("<@@ Creation of Student Records @@>\n");
	newStud = (Stud*)malloc(sizeof(Stud));
	*Start = newStud;
	newStud->next = NULL;
	printf("Answer the ff.:\n");
	
	do{
		printf("\tEnter student no.: ");
		fgets(newStud->studNo, 13, stdin);
		printf("\tEnter student name: ");
		fgets(newStud->name, 25, stdin);
		printf("\tEnter course and year: ");
		fgets(newStud->crsYr, 10, stdin);
		printf("\tEnter GWA: ");
		scanf("%f", &newStud->GWA);
		
		do{
			printf("\nEnter new student?: ");
			scanf(" %c", &resp);
			scanf("%c");
		} while (toupper(resp) != 'Y' && toupper(resp) != 'N');
		
		if (toupper(resp) == 'Y'){
			newStud->next = (Stud*)malloc(sizeof(Stud));
			newStud = newStud->next;
			newStud->next = NULL;
			system("CLS");
		}
	} while (toupper(resp) == 'Y');
	newStud->next = NULL;
	newStud = NULL;
	
	printf("\nPress any key to continue...");
	getch();
}

void disRec(Stud *Start){
	Stud *current;
	int ctr = 5;
	int num = 1;
	
	system("CLS");
	gotoxy(65,2);
	printf("<@@ STUDENT RECORDS @@>");
	
	gotoxy(1, 4);
	printf("STUDENT NO."); // 11 char
	
	gotoxy(20, 4);
	printf("NAME"); // 4 char
	
	gotoxy(50, 4);
	printf("Course & Year"); // 13 char
	
	gotoxy(70, 4);
	printf("GWA"); // 3 char
	
	if (Start == NULL){
		gotoxy(50, 4);
		printf("No students inputted yet!");
	}
	else{
		current = Start;
		
		while (current != NULL){
			gotoxy(1, ctr);
			printf("%d. %s", num, current->studNo);
			
			gotoxy(20, ctr);
			printf("%s", current->name);
			
			gotoxy(50, ctr);
			printf("%s", current->crsYr);
			
			gotoxy(70, ctr);
			printf("%.2f", current->GWA);
			
			current = current->next;
			ctr++;	
			num++;
		}
		current = NULL;
	}
	printf("\n\n");	
}

void delStud(Stud **Start){
	Stud *curr = *Start;
	Stud *prev = NULL;
	char delVal[13];
	
	if (curr == NULL){
		printf("Student Report is already empty!!");
		return;
	}
	
	printf("\n!!Deleting Student!!\n\n");
	printf("Enter student number to delete: ");
	fgets(delVal, 13, stdin);
	
	while (curr != NULL && strcmp(delVal, curr->studNo) != 0){
		prev = curr;
		curr = curr->next;
	}
	
	if (curr != NULL && strcmp(delVal, curr->studNo) == 0){
		printf("Deleting student.... ");
		if (prev == NULL){
			*Start = curr->next;
		}
		else{
			prev->next = curr->next;
		}
		curr->next = NULL;
		free(curr);
		printf("Deletion successful!!\n");
	}
	else{
		printf("student %s does not exist!!\n", delVal);
	}
	curr = prev = NULL;
	printf("Press any key to continue...");
	getch();
}

void delAfter(Stud **Start){
	Stud *curr = *Start, *aft = NULL;
	char delVal[13];
	
	if (curr == NULL){
		printf("Student Report is already empty!!");
		return;
	}
	
	printf("\n!!Deleting Student after a Student!!\n\n");
	printf("Enter student number to delete: ");
	fgets(delVal, 13, stdin);
	
	while (curr != NULL && strcmp(delVal, curr->studNo) != 0){
		curr = curr->next;
	}
	
	if (curr != NULL && strcmp(delVal, curr->studNo) == 0){
		if (curr->next == NULL){
			printf("There is no student after this student!!\n");
		}
		else{
			printf("Deleting student... ");
			aft = curr->next;
			if (aft->next == NULL){
				curr->next = NULL;
			}
			else{
			curr->next = aft->next;
			aft->next = NULL;
			}
			printf("Deletion successful!!\n");
			free(aft);
		}
	}
	else{
		printf("This student does not exist!!\n");
	}
	curr = aft = NULL;
	printf("Press any key to continue...");
	getch();
}

void freeList(Stud **Start){
	Stud *current, *temp;
	
	current = *Start;
	while (current != NULL){
		temp = current;
		current = current->next;
		free(temp);
	}
	current = temp = NULL;
}
