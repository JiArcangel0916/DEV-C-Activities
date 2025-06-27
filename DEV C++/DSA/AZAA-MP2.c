#include <stdio.h>

void searchArr(int arr[], int search);

int main(){
	int arr[10];
	int i, search;
	
	//ACCEPT INTEGER VALUES
	printf("Enter 10 Integer Values:\n");
	for (i = 0; i < 10; i++){
		printf("\tInteger Value No. %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	//ACCEPT YUNG SEARCH
	printf("\nEnter integer value to be searched: ");
	scanf("%d", &search);
	
	searchArr(arr, search);
	
	return 0;
}

void searchArr(int arr[], int search){
	int i;
	int firstOc = 1000, lastOc = 1000; 
	
	for (i = 0; i < 10; i++){
		if (search == arr[i]){
			if (firstOc == 1000){
				firstOc = i;
			}
			lastOc = i;
		}
	}
	
	if (firstOc != 1000 && lastOc != 1000){
		printf("The First Occurrence of No. %d is in Array index %d\n", search, firstOc);
		printf("The Last Occurrence of No. %d is in Array index %d\n", search, lastOc);
	}
	else{
		printf("Integer value to be searched is not found!");
	}
	
}
