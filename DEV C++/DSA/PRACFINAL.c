#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define numProd 5
#define VAT 0.12

void gotoxy(short int x, short int y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef struct{
	int prodNo;
	char prodName[50];
	float prodPrice;
	int prodQuan;
	float totalPrice;
}Product;

typedef struct Node{
	Product prod;
	struct Node* next;
	struct Node* prev;
}Node;

void computeTotPrice(Product* p){
	p->totalPrice = p->prodQuan * p->prodPrice;
}

float arrTotalPriceWithVAT(Product products[]){
	float total = 0.0;
	int i;
	for (i = 0; i < numProd; i++){
		total += products[i].totalPrice;
	}
	
	return total + (total * VAT);
}

void arrDispProd(Product products[]){
	int i;
	printf("%-10s%-15s%-12s%-10s%-12s\n", "Product No.", "Product Name", "Unit Price", "Quantity", "Total Price");
	for (i = 0; i < numProd; i++){
		printf("%-10d%-15s%-12.2f%-10d%-12.2f\n",products[i].prodNo, products[i].prodName, products[i].prodPrice, products[i].prodQuan, products[i].totalPrice);
	}
}

void arrayImp(){
	Product products[numProd] = {
		{1, "Coke", 15.00, 0, 0.0}, 
		{2, "Sprite", 20.00, 0, 0.0}, 
		{3, "Pepsi", 18.00, 0, 0.0}, 
		{4, "Fanta", 22.00, 0, 0.0},
    	{5, "Mountain Dew", 25.00, 0, 0.0}};
    int choice, i, j = 0, prodChoice;
    char resp;
    float total_with_vat;
    for (i = 0; i < numProd; i++){
    	printf("%d. %s\n", products[i].prodNo, products[i].prodName);
	}
	
	do{
		printf("Select the number of the product to add: ");
		scanf("%d", &prodChoice);
		printf("Enter quantity for %s: ", products[prodChoice - 1].prodName);
		scanf("%d", &products[prodChoice - 1].prodQuan);
		computeTotPrice(&products[prodChoice - 1]);
		
		printf("Add another item [Y/N]? ");
		scanf(" %c", &resp);
		
		if (toupper(resp) == 'Y'){
			printf("Select the number of the product to add: ");
			scanf("%d", &prodChoice);
			printf("Enter quantity for %s: ", products[prodChoice - 1].prodName);
			scanf("%d", &products[prodChoice - 1].prodQuan);
			computeTotPrice(&products[prodChoice - 1]);
		}
	} while (j < 5 && toupper(resp) == 'Y');
	
	printf("Array-based Implementation\n");
	arrDispProd(products);
	total_with_vat = arrTotalPriceWithVAT(products);
	printf("with vat: %f", total_with_vat);
}

void dllTotalPriceWithVAT(Node** HEAD){
	float total = 0.0;
    Node *current = *HEAD;
    while (current) {
        total += current->prod.totalPrice;
        current = current->next;
    }
    total + (total * VAT);
    printf("Total Price with VAT: %f", total);
}

void addProd(Node** HEAD, Node** TAIL, int prodNo, char *prodName, float prodPrice, int quan){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->prod.prodNo = prodNo;
	strcpy(newNode->prod.prodName, prodName);
    newNode->prod.prodPrice = prodPrice;
    newNode->prod.prodQuan = quan;
    computeTotPrice(&newNode->prod);
    newNode->next = NULL;
    newNode->prev = *TAIL;
    computeTotPrice(&newNode->prod);
    newNode->next = NULL;
    newNode->prev = *TAIL;
    
    if (*TAIL != NULL) {
        (*TAIL)->next = newNode;
    } 
	else {
        *HEAD = newNode;
    }
    *TAIL = newNode;
}

void disList(Node* HEAD){
	Node* Current = HEAD;
	printf("%-10s%-15s%-12s%-10s%-12s\n", "Product No.", "Product Name", "Unit Price", "Quantity", "Total Price");
	while (Current != NULL){
		printf("%-10d%-15s%-12.2f%-10d%-12.2f\n", Current->prod.prodNo, Current->prod.prodName, Current->prod.prodPrice, Current->prod.prodQuan, Current->prod.totalPrice);
        Current = Current->next;
	}
}

void doubyImp(){
	Node* HEAD = NULL;
	Node* TAIL = NULL;
	int prodChoice;
	int quans[numProd] = {0};
	int j;
	char resp;
	
	Product products[numProd] = {{1, "Coke", 15.00, 0, 0.0}, {2, "Sprite", 20.00, 0, 0.0}, {3, "Pepsi", 18.00, 0, 0.0}, {4, "Fanta", 22.00, 0, 0.0},
        {5, "Mountain Dew", 25.00, 0, 0.0}};
        
    do{
		printf("Select the number of the product to add: ");
		scanf("%d", &prodChoice);
		printf("Enter quantity for %s: ", products[prodChoice - 1].prodName);
		scanf("%d", &products[prodChoice - 1].prodQuan);
		computeTotPrice(&products[prodChoice - 1]);
		
		printf("Add another item [Y/N]? ");
		scanf(" %c", &resp);
		
		if (toupper(resp) == 'Y'){
			printf("Select the number of the product to add: ");
			scanf("%d", &prodChoice);
			printf("Enter quantity for %s: ", products[prodChoice - 1].prodName);
			scanf("%d", &products[prodChoice - 1].prodQuan);
			computeTotPrice(&products[prodChoice - 1]);
		}
	} while (j < 5 && toupper(resp) == 'Y');
	addProd(&HEAD, &TAIL, products[prodChoice - 1].prodNo, products[prodChoice - 1].prodName, products[prodChoice - 1].prodQuan, quans[prodChoice - 1]);
	printf("Doubly linked list Implementation\n");
	disList(HEAD);
	dllTotalPriceWithVAT(&HEAD);
}

int main(){
	int choice;
	printf("Select Implementation\n");
	printf("[1] Array-based Implementation\n");
	printf("[2] Doubly linked list Implementation\n");
	printf("Enter choice => ");
	scanf("%d", &choice);
	scanf("c");
	
	switch(choice){
		case 1:
			arrayImp();
			break;
			
		case 2:
			doubyImp();
			break;
		
		deafult:
			printf("Invalid Choice");
	}
	
	return 0;
}

