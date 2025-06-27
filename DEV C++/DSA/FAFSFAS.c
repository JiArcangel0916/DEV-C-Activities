#include <stdio.h>
#define NUMPROD 5
#define VAT 0.12

typedef struct{
	int prodNo;
	char prodName[50];
	float prodPrice;
	int prodQuan;
	float prodTotPrice;
}Product;


float compTotWithVal(Product products[]){
	int i; 
	float total = 0.0;
	for (i = 0; i < NUMPROD; i++){
		total += products[i].prodTotPrice;
	}
	return total + (total * VAT);
}

void compTotPrice(Product* p){
	p->prodTotPrice = p->prodQuan * p->prodPrice;
}

void disProds(Product products[]){
	int i;
	printf("ID NAME PRICE QUANTITY TOTAL PRICE\n");
	for (i = 0; i < NUMPROD; i++){
		printf("%d. %s	%f		%d		%f\n", products[i].prodNo, products[i].prodName, products[i].prodPrice, products[i].prodQuan, products[i].prodTotPrice);
	}
}

void arrayImp(){
	Product products[NUMPROD] = {{1, "Coke", 15.00, 0, 0.0}, {2, "Pepsi", 20.00, 0, 0.0}, {3, "Fanta", 10.00, 0, 0.0}, {4, "Water", 15.00, 0, 0.0}, {5, "Coke", 15.00, 0, 0.0}};
	int i, prodChoice;
	float VATval;
	
	for (i = 0; i < NUMPROD; i++){
		printf("%d. %s\n", products[i].prodNo, products[i].prodName);
	}
	for (i = 0; i < 5; i++){
		printf("Enter choice: ");
		scanf("%d", &prodChoice);
		printf("Enter quantity of %s: ", products[prodChoice - 1].prodName);
		scanf("%d", &products[prodChoice - 1].prodQuan);
		compTotPrice(&products[prodChoice - 1]);
	}

	
	printf("YOUR ITEMS:\n");
	disProds(products);
	VATval = compTotWithVal(products);
	printf("Total value with vat %f", VATval);
}


int main(){
	arrayImp();
}
