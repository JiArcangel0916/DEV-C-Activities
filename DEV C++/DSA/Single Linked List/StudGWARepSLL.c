#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
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
void addStart(Stud **Start);
void addEnd(Stud **Start);
void addBefore(Stud **Start);
void addAfter(Stud **Start);
void delStart(Stud **Start);
void delEnd(Stud **Start);
void delStud(Stud **Start);
void delBefore(Stud **Start);
void delAfter(Stud **Start);
int disMenu();

int main(){
	Stud *Start = NULL;
	int choice;
	
	do{
		choice = disMenu();
		switch (choice){
			case 1:
				//Creation of Student Record
				createRec(&Start);
				disRec(Start);
				break;
			
			case 2:
				//Displaying of Student Record
				disRec(Start);
				break;
				
			case 3:
				//Adding Student at the Start
				addStart(&Start);
				disRec(Start);
				break;
			
			case 4:
				//Adding Student at the End
				addEnd(&Start);
				disRec(Start);
				break;
				
			case 5:
				//Adding Student Before a Student
				addBefore(&Start);
				disRec(Start);
				break;
				
			case 6:
				//Adding Student After a Student
				addAfter(&Start);
				disRec(Start);
				break;
				
			case 7:
				//Deleting Student at the Start
				delStart(&Start);
				disRec(Start);
				break;
			
			case 8:
				//Deleting Student at the End
				delEnd(&Start);
				disRec(Start);
				break;
				
			case 9: 
				//Deleting a Student
				delStud(&Start);
				disRec(Start);
				break;
				
			case 10:
				//Deleting a Student Before a Student
				delBefore(&Start);
				disRec(Start);
				break;
			
			case 11:
				//Deleting a Student After a Student
				delAfter(&Start);
				disRec(Start);
				break;
			
			case 12:
				//Freeing List
				freeList(&Start);
				break;
				
			default:
				printf("Invalid response!");
		}
	} while (choice >= 1 && choice < 12);
	
	return 0;
}

int disMenu(){
	int choice;
	
	printf("\nEnter action to perform:\n");
	printf("\t[1] Create Student GWA Report\n");
	printf("\t[2] Display Student GWA Report\n");
	printf("\t[3] Add Student to Start\n");
	printf("\t[4] Add Student to End\n");
	printf("\t[5] Add Student before a student\n");
	printf("\t[6] Add Student after a student\n");
	printf("\t[7] Delete Student at Start\n");
	printf("\t[8] Delete Student at End\n");
	printf("\t[9] Delete a Student\n");
	printf("\t[10] Delete Student before a student\n");
	printf("\t[11] Delete Student after a student\n");
	printf("\t[12] Exit\n");
	printf("\t\tEnter choice => ");
	scanf("%d", &choice);
	scanf("%c");

	return choice;
}

void createRec(Stud **Start){
	Stud *newStud;
	char resp;
	int i;
	
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
		
		for (i = 0; i < strlen(newStud->name); i++){
			newStud->name[i] = toupper(newStud->name[i]);
		}
		
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
	Stud *current = NULL;
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
		gotoxy(25, 5);
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

void addStart(Stud **Start){
	Stud *newStud = (Stud*)malloc(sizeof(Stud));
	newStud->next = NULL;
	int i;
	
	system("CLS");
	printf("!! Adding new Student at the Start !!\n\n");
	printf("Answer the ff.:\n");
	
	printf("\tEnter student no.: ");
	fgets(newStud->studNo, 13, stdin);
	printf("\tEnter student name: ");
	fgets(newStud->name, 25, stdin);
	for (i = 0; i < strlen(newStud->name); i++){
			newStud->name[i] = toupper(newStud->name[i]);
		}
	printf("\tEnter course and year: ");
	fgets(newStud->crsYr, 10, stdin);
	printf("\tEnter GWA: ");
	scanf("%f", &newStud->GWA);
	
	if (Start == NULL){
		*Start = newStud;
	}
	else{
		newStud->next = *Start;
		*Start = newStud;
	}
	newStud = NULL;
	
	printf("\nStudent addedd successfully!\n");
	printf("Press any key to continue...");
	getch();
}

void addEnd(Stud **Start){
	Stud *newStud, *current;
	int i;
	newStud = (Stud*)malloc(sizeof(Stud));
	newStud->next = NULL;
	
	system("CLS");
	printf("!! Adding new Student at the End !!\n\n");
	printf("Answer the ff.:\n");
	
	printf("\tEnter student no.: ");
	fgets(newStud->studNo, 13, stdin);
	printf("\tEnter student name: ");
	fgets(newStud->name, 25, stdin);
	for (i = 0; i < strlen(newStud->name); i++){
			newStud->name[i] = toupper(newStud->name[i]);
		}
	printf("\tEnter course and year: ");
	fgets(newStud->crsYr, 10, stdin);
	printf("\tEnter GWA: ");
	scanf("%f", &newStud->GWA);
	
	if (Start == NULL){
		*Start = newStud;
	}
	else{
		current = *Start;
		while (current->next != NULL){
			current = current->next;
		}
		current->next = newStud;
	}
	
	newStud = NULL;
	printf("\nStudent added successfully!\n");
	printf("Press any key to continue...");
	getch();
}

void addBefore(Stud **Start){
	Stud *newStud, *prev = NULL;
	Stud *current = *Start;
	int Flag = 0, i;
	char nameBefore[25];
	newStud = (Stud*)malloc(sizeof(Stud));
	newStud->next = NULL;
	
	printf("\n!! Adding new Student Before a Student !!\n\n");
	printf("Answer the ff.:\n");
	
	printf("\tEnter student no.: ");
	fgets(newStud->studNo, 13, stdin);
	printf("\tEnter student name: ");
	fgets(newStud->name, 25, stdin);
	for (i = 0; i < strlen(newStud->name); i++){
			newStud->name[i] = toupper(newStud->name[i]);
		}
	printf("\tEnter course and year: ");
	fgets(newStud->crsYr, 10, stdin);
	printf("\tEnter GWA: ");
	scanf("%f", &newStud->GWA);
	scanf("%c");
	printf("Enter the name of the Student you want to add the new Student before: ");
	fgets(nameBefore, 25, stdin);
	for (i = 0; i < strlen(nameBefore); i++){
			nameBefore[i] = toupper(nameBefore[i]);
		}
	
	while (current != NULL && Flag != 1){
		if (nameBefore == current->name){
			Flag = 1;
		}
		else{
			prev = current;
			current = current->next;
		}
	}
	
	if (current != NULL && Flag == 1){
		if (prev == NULL){
			*Start = newStud;
		}
		else{
			prev->next = newStud;
		}
		newStud->next = current;
		
		printf("\nStudent added successfully!\n");
	}
	else{
		printf("Student does not exist!!\n");
	}
	
	printf("Press any key to continue...");
	getch();
	current = prev = NULL;
}

void addAfter(Stud **Start){
	int Flag = 0, i;
	char nameAfter[25];
	Stud *current = *Start;
	Stud *newStud = (Stud*)malloc(sizeof(Stud));
	newStud->next = NULL;
	
	printf("\n!! Adding Student after a Student !!\n");
	printf("Answer the ff.:\n");
	
	printf("\tEnter student no.: ");
	fgets(newStud->studNo, 13, stdin);
	printf("\tEnter student name: ");
	fgets(newStud->name, 25, stdin);
	for (i = 0; i < strlen(newStud->name); i++){
			newStud->name[i] = toupper(newStud->name[i]);
		}
	printf("\tEnter course and year: ");
	fgets(newStud->crsYr, 10, stdin);
	printf("\tEnter GWA: ");
	scanf("%c");
	
	printf("Enter the name of the Student you want to add the new Student after: ");
	fgets(nameAfter, 25, stdin);
	for (i = 0; i < strlen(nameAfter); i++){
			nameAfter[i] = toupper(nameAfter[i]);
		}
	
	while (current != NULL && Flag != 1){
		if (nameAfter == current->name){
			Flag = 1;
		}
		else{
			current = current->next;
		}
	}
	
	if (current != NULL && Flag == 1){
		newStud->next = current->next;
		current->next = newStud;
		
		printf("Student addedd successfully!\n");
	}
	else{
		printf("Student does not exist!!\n");
	}
	
	current = newStud = NULL;
	printf("Press any key to continue...");
	getch();
}

void delStud(Stud **Start){
	Stud *current = *Start, *prev = NULL;
	int Flag = 0, i;
	char nameDel[25];
	
	if (current = NULL){
		printf("Student Records is already empty!!\n\n");
		printf("Press any key to continue...");
		getch();
		return;
	}
	
	printf("\n!! Deleting a Student !!\n\n");
	printf("Enter the name of the student you want to delete: ");
	fgets(nameDel, 25, stdin);
	for (i = 0; i < strlen(nameDel); i++){
		nameDel[i] = toupper(nameDel[i]);
	}
	
	while (current != NULL && Flag != 1){
		if (nameDel == current->name){
			Flag = 1;
		}
		else{
			prev = current;
			current = current->next;
		}
	}
	
	if (current != NULL && Flag == 1){
		printf("\nDeleting Student... ");
		
		if (prev == NULL){
			*Start = current->next;
		}
		else{
			prev->next = current->next;
		}
		current->next = NULL;
		free(current);
		printf("Deletion successful!!\n");
	}
	else{
		printf("This student does not exist!!\n");
	}
	printf("Press any key to continue...");
	getch();
	current = prev = NULL;
}

void delStart(Stud **Start){
	char resp;
	Stud *current = *Start;
	
	if (current == NULL){
		printf("Student Records is already empty!!\n\n");
		printf("Press any key to continue...");
		getch();
		return;
	}
	
	printf("\n!! Deleting Student at the Start !!\n");
	printf("Confirm this action? [Y/N]: ");
	scanf("%c", &resp);
	
	if (toupper(resp) == 'Y'){
		printf("Deleting Student... ");
		*Start = current->next;
		current->next = NULL;
		free(current);
		printf("Deletion successful!!\n");
	}
	else{
		printf("Cancelling deletion...");
	}
	printf("Press any key to continue...");
	getch();
	current = NULL;
}

void delEnd(Stud **Start){
	char resp;
	Stud *current = *Start;
	Stud *prev;
	
	if (current == NULL){
		printf("Student Records is already empty!!\n\n");
		printf("Press any key to continue...");
		getch();
		return;
	}
	
	printf("\n!! Deleting Student at the End !!\n");
	printf("Confirm this action? [Y/N]: ");
	scanf("%c", &resp);
	
	if (toupper(resp) == 'Y'){
		printf("Deleting Student... ");
		while (current->next != NULL){
			prev = current;
			current = current->next;
		}
		
		if (prev == NULL){
			free(current);
		}
		else{
			prev->next = NULL;
			free(current);
		}
		printf("Deletion successful!!\n");
	}
	else{
		printf("Cancelling deletion...\n");
	}
	current = prev = NULL;
	printf("Press any key to continue...");
	getch();
}

void delBefore(Stud **Start){
	Stud* current = *Start, *prev = NULL;
	char nameBefore[25];
	int i, Flag = 0;

	if (current == NULL){
		printf("Student Records is already empty!!\n\n");
		printf("Press any key to continue...");
		getch();
		return;
	}
	
	printf("\n!! Deleting Student before a Student !!\n\n");
	printf("Enter the name you want to delete the Student before: ");
	fgets(nameBefore, 25, stdin);
	for (i = 0; i < strlen(nameBefore); i++){
		nameBefore[i] = toupper(nameBefore[i]);
	}
	
	while (current != NULL && Flag != 1){
		if (nameBefore == current->name){
			Flag = 1;
		}
		else{
			prev = current;
			current = current->next;
		}
	}
	
	if (current != NULL && Flag == 1){
		printf("Deleting student... ");
		if (prev == NULL){
			*Start = current->next;
		}
		else{
			prev->next = current->next;
		}
		current->next = NULL;
		free(current);
		printf("Deletion successful!!\n");
	}
	else{
		printf("Student does not exist!\n");
	}
	printf("Press any key to continue...");
	getch();
	current = prev = NULL;
}

void delAfter(Stud **Start){
	Stud *current = *Start;
	Stud *aft = NULL;
	char nameAfter[25];
	int i, Flag = 0;
	
	if (current == NULL){
		printf("Student Records is already empty!!\n\n");
		printf("Press any key to continue...");
		getch();
		return;
	}
	
	printf("\n!! Deleting Student before a Student !!\n\n");
	printf("Enter the name you want to delete the Student after: ");
	fgets(nameAfter, 25, stdin);
	for (i = 0; i < strlen(nameAfter); i++){
		nameAfter[i] = toupper(nameAfter[i]);
	}
	
	while (current != NULL && Flag != 1){
		if (nameAfter == current->name){
			Flag = 1;
		}
		else{
			current = current->next;
			aft = current->next;
		}
	}
	
	if (current != NULL && Flag == 1){
		printf("Deleting Student... ");
		current->next = aft->next;
		aft->next = NULL;
		free(aft);
		printf("Deletion successful!!\n");
	}
	else{
		printf("Student does not exist!\n");
	}
	printf("Press any key to continue...");
	getch();
	current = aft = NULL;
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
