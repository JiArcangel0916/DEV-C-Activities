#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));

	int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int max = 0, secLarge = 0, i;
	int size = sizeof(arr)/sizeof(arr[0]);
	int min = 100, secSmall = 100;
	
	
	//Randomizing the array
	for (i = 0; i < size; i++){
		arr[i] = rand() % 100 + 1;
	}
	
	//Printing the array
	printf("Array:\n");
	for (i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	
	//Finding the largest and second largest
	for (i = 0; i < size; i++){
		if (arr[i] > max){
			secLarge = max;
			max = arr[i];
		}
		else if (arr[i] > secLarge && arr[i] != max){
			secLarge = arr[i];
		}
	}
	
	//Finding the smallest and second smallest element in the array
	for (i = 0; i < size; i++){
		if (arr[i] < min){
			secSmall = min;
			min = arr[i];
		}
		else if (arr[i] < secSmall && arr[i] != min){
			secSmall = arr[i];
		}
	}
		
	printf("\nLargest element in the array: %d\n", max);
	printf("Second largest element in the array: %d\n", secLarge);
	printf("Smallest element in the array: %d\n", min);
	printf("Second smallest element in the array: %d\n", secSmall);
	
	return 0;
}
