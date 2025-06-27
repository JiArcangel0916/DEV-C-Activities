#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

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
    struct Node *prev;
}Node;

int disMenu();
void createList(Node **Start, Node **Tail);
void displayList(Node *Start);
void delNode(Node **Start, Node **Tail);
void delAfter(Node **Start, Node **Tail);
void freeList(Node **Start);

int main(){
    Node *Start = NULL;
    Node *Tail = NULL;
    int choice;
    
    do{
        choice = disMenu();
        switch(choice){
            case 1:
            createList(&Start, &Tail);
            displayList(Start);
            break;
            
            case 2:
            displayList(Start);
            break;
            
            case 3:
            delNode(&Start, &Tail);
            displayList(Start);
            break;
            
            case 4:
            delAfter(&Start, &Tail);
            displayList(Start);
            break;
            
            case 5:
            freeList(&Start);
            break;
            
            default:
            printf("Invalid choice!\n");
        }
    } while (choice >= 1 && choice != 5);
    return 0;
}

int disMenu(){
    int choice;
    
    printf("[1] Create Doubly Linked List\n");
    printf("[2] Display Doubly Linked LIst\n");
    printf("[3] Delete a Node\n");
    printf("[4] Delete a Node after a Node\n");
    printf("[5] Exit\n");
    printf("\tEnter choice => ");
    scanf("%d", &choice);
    getchar();
    
    return choice;
}

void createList(Node **Start, Node **Tail){
    Node *newNode = NULL;
    char resp;
    int ctr = 1;
    
    newNode = (Node*)malloc(sizeof(Node));
    *Start = newNode;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    do{
    	system("CLS");
    	printf("<@@ Creation of Doubly Linked List @@>\n");
        printf("Enter data for student %d:\n", ctr);
        printf("Student Number: ");
        fgets(newNode->StudNo, 13, stdin);
        printf("Name: ");
        fgets(newNode->Name, 25, stdin);
        printf("Course and Year: ");
        fgets(newNode->CrsYr, 10, stdin);
        printf("GWA: ");
        scanf("%f", &newNode->gwa);
        
        printf("Add another student?: ");
        scanf(" %c", &resp);
        scanf("%c");
        
        if (toupper(resp) == 'Y'){
            newNode->next = (Node*)malloc(sizeof(Node));
            newNode->next->prev = newNode;
            newNode = newNode->next;
            *Tail = newNode;
            ctr++;
        }
    } while (toupper(resp) == 'Y');
    newNode->next = NULL;
    newNode = NULL;
    printf("Press ant key to continue...");
    getch();
}

void displayList(Node *Start){
    Node *Current = NULL;
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
		Current = Start;
		
		while (Current != NULL){
			gotoxy(1, ctr);
			printf("%d. %s", num, Current->StudNo);
			
			gotoxy(20, ctr);
			printf("%s", Current->Name);
			
			gotoxy(50, ctr);
			printf("%s", Current->CrsYr);
			
			gotoxy(70, ctr);
			printf("%.2f", Current->gwa);
			
			Current = Current->next;
			ctr++;	
			num++;
		}
		Current = NULL;
	}
	printf("\n\n");	
}

void delNode(Node **Start, Node **Tail){
    int UserResp;
    char DelVal[25], StudVal[25];
    Node *Current = NULL;
    Current = *Start;
    
    if (Current == NULL){
        //This will be displayed if the list is empty
        printf("The list is already empty!!\n");
        printf("Press any key to continue...");
        getchar();
        return;
    }
    //This will be displayed if the list is NOT empty
    printf("Search by: ");
    printf("\n[1] Student Number");
    printf("\n[2] Student Name");
    printf("\nResponse: ");
    scanf("%d", &UserResp);
    getchar();  
    
    //If user chooses 1
    if (UserResp == 1){
        strcpy(StudVal, "Student Number");
    }
    //If user chooses 2
    else if(UserResp == 2){
        strcpy(StudVal, "Student Name");
    }
    
    //Asking user to input the Student number/name of the student to delete
    printf("\n\nDelete which student? [%s]: ", StudVal);
    fgets(DelVal, 25, stdin);
    
    //Finding the student inputted
    while (Current != NULL && strcmp(DelVal, (UserResp == 1 ? Current->StudNo : Current->Name)) != 0){
        Current = Current->next;
    }
    
    //If inputted student is found...
    if (Current != NULL && strcmp(DelVal, (UserResp == 1 ? Current->StudNo : Current->Name)) == 0){
        printf("Deleting Student... ");
        //If Student to be deleted is at the Start
        if (Current->prev == NULL){
            *Start = Current->next;
            if (*Start != NULL){
                (*Start)->prev = NULL;
            }
            else{
                *Tail = NULL;
            }
        }
        //If Student to be deletes is at the End
        else if(Current == *Tail){
            *Tail = Current->prev;
            (*Tail)->next = NULL;
        }
        //If Student to be deleted is at the middle
        else{
            Current->prev->next = Current->next;
            Current->next->prev = Current->prev;
        }
        Current->prev = NULL;
        Current->next = NULL;
        free(Current);
        printf("Deletion Successful!!\n");
    }
    //If inputted student is not found...
    else{
        printf("Student %s does not exist!!\n", DelVal);
    }
    Current = NULL;
    printf("Press any key to continue...");
    getch();
}

void delAfter(Node **Start, Node **Tail){
    int UserResp;
    char DelVal[25], StudVal[25];
    Node *Current = NULL;
    Node *After = NULL;
    Current = *Start;
    
    if (Current == NULL){
        //This will be displayed if the list is empty
        printf("The list is already empty!!\n");
        printf("Press any key to continue...");
        getch();
        return;
    }
    //This will be displayed if the list is NOT empty
    printf("Search by: ");
    printf("\n[1] Student Number");
    printf("\n[2] Student Name");
    printf("\nResponse: ");
    scanf("%d", &UserResp);
    scanf("%c");
    
    //If user chooses 1
    if (UserResp == 1){
        strcpy(StudVal, "Student Number");
    }
    //If user chooses 2
    else if(UserResp == 2){
        strcpy(StudVal, "Student Name");
    }
    
    printf("\n\nEnter student you want to delete the student after [%s]: ", StudVal);
    fgets(DelVal, 25, stdin);
    
    while (Current != NULL && strcmp(DelVal, (UserResp == 1 ? Current->StudNo : Current->Name)) != 0){
        Current = Current->next;
    }
    
    if (Current != NULL && strcmp(DelVal, (UserResp == 1 ? Current->StudNo : Current->Name)) == 0){
        if (Current->next == NULL){
            printf("There is no student after this student!\n");
        }
        else{
            printf("Deleting student...");
            After = Current->next;
            if (After == *Tail){
                *Tail = Current;
                Current->next = NULL;
            }
            else{
                Current->next = After->next;
                Current->next->prev = Current;
            }
            After->prev = NULL;
            After->next = NULL;
            free(After);
            printf("Deletion Successful!!\n");
        }
    }
    else{
        printf("Student %s does not exist!!\n", DelVal);
    }
    printf("Press any key to continue...");
    getch();
    Current = After = NULL;
}

void freeList(Node **Start){
    Node *Current, *Temp;
    
    Current = *Start;
    while (Current != NULL){
        Temp = Current;
        Current = Current->next;
        free(Temp);
    }
    Current = Temp = NULL;
}
