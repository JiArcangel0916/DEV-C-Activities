#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

int disMenu();
void createList(Node **Head, Node **Tail);
void displayList(Node **Head);
void freeList(Node **Head);
void delAfter(Node **Head, Node **Tail);

int main(){
    Node *Head = NULL;
    Node *Tail = NULL;
    int choice;
    
    do{
        choice = disMenu();
        switch (choice){
            case 1: createList(&Head, &Tail); displayList(&Head);
            break;
            
            case 2: displayList(&Head);
            break;
            
            case 3: delAfter(&Head, &Tail); displayList(&Head);
            break;
            
            case 4: freeList(&Head);
        }
    } while (choice >= 1 && choice != 4);
}

int disMenu(){
    int userResp;
    
    printf("\n[1] Create Doubly Linked List\n");
    printf("[2] Display Doubly Linked List\n");
    printf("[3] Delete node after a node\n");
    printf("[4] Exit\n");
    printf("Enter choice => ");
    scanf("%d", &userResp);
    return userResp;
    
}

void createList(Node **Head, Node **Tail){
    int ctr = 1;
    char resp;
    Node *newNode = (Node*)malloc(sizeof(Node));
    *Head = newNode;
    *Tail = newNode;
    newNode->next = NULL;
    newNode->prev = NULL;
    system("CLS");
    
    do{
        printf("Enter data for node %d => ", ctr);
        scanf("%d", &newNode->data);
        
        printf("Add another node?: ");
        scanf(" %c", &resp);
        
        if (toupper(resp) == 'Y'){
            newNode->next = (Node*)malloc(sizeof(Node));
            *Tail = newNode->next;
            newNode = newNode->next;
            ctr++;
        }
    } while (toupper(resp) == 'Y');
    getchar();
    newNode->next = NULL;
    newNode = NULL;
    printf("Press any key...");
    getchar();
}

void displayList(Node **Head){
    int ctr = 1;
    Node *Current = NULL;
    Current = *Head;
    system("CLS");
    if (Current == NULL){
        printf("the list is empty!\n");
    }
    else{
        while (Current != NULL){
            printf("Node %d content:\n", ctr);
            printf("\tData => %d\n", Current->data);
            Current = Current->next;
            ctr++;
        }
    }
}

void delAfter(Node **Head, Node **Tail){
    int delVal;
    Node *Current = NULL;
    Node *After = NULL;
    Current = *Head;
    
    if (Current == NULL){
        printf("The list is already empty!\n");
    }
    else{
        printf("Enter the data of the node you want to delete the node after: ");
        scanf("%d", &delVal);
        getchar();
        
        while(Current != NULL && delVal != Current->data){
            Current = Current->next;
        }
        
        if (Current != NULL && delVal == Current->data){
            if (Current->next == NULL){
                printf("There is no node after this node!\n");
            }
            else{
                printf("Deleting Node... ");
                After = Current->next;
                if (After == *Tail){
                    *Tail = (*Tail)->prev;
                    Current->next = NULL;
                }
                else{
                    Current->next = After->next;
                    After->next->prev = Current;
                }
                After->prev = NULL;
                free(After);
                printf("Deletion successful!\n");
            }
        }
        else{
            printf("This node does not exist!\n");
        }
    }
    printf("Press any key to continue...");
    getchar();
    Current = After = NULL;
}

void freeList(Node **Head){
    Node *Current = NULL;
    Node *Temp = NULL;
    Current = *Head;
    
    while (Current != NULL){
        Temp = Current;
        Current = Current->next;
        free(Temp);
    } 
    Current = Temp = NULL;
}

