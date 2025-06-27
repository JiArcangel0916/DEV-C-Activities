#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(short int x, short int y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(){
	//   ****   ****		3 spaces 4 stars 3 spaces 4 stars
	//  ****** ******		2 spaces 6 stars 1 space 6 stars
	// ***************		1 space  15 stars
	//*****************		0 space  17 stars
	// ***************		1 space	 15 stars
	//  *************		2 spaces 13 stars
	//   ***********		3 spaces 11 stars
	//    *********			4 spaces 9 stars
	//     *******			5 spaces 7 stars
	//      *****			6 spaces 5 stars
	//       ***			7 spaces 1 star
	//        *
	
	int i, j, k, stars, spaces, unConnected, lowerHalf;
	unConnected = 2;
	lowerHalf = 8;
	stars = 4;
	spaces = 3;
	
	//Printing the Unconnected parts of the heart
	for (i = 0; i < unConnected; i++){
		for (j = 0; j < unConnected; j++){
			
			//Printing the spaces
			for (k = 0; k < spaces; k++){
				printf(" ");
			}
			
			//Printing the stars
			for (k = 0; k < stars; k++){
				printf("*");
			}

			
		}
		spaces--;
		stars+=2;
		printf("\n");
	}
	
	//Printing the remaining parts of the heart
	stars = 15;
	//Printing the first two lines
	for (i = 0; i < 2; i++){
		//Printing the spaces
		for (j = 0; j < spaces; j++){
			printf(" ");
		}
		
		//Printing the stars
		for (j = 0; j < stars; j++){
			printf("*");
		}
		spaces--;
		stars += 2;
		printf("\n");
	}
	
	//Printing the the remaining parts of the lower part
	spaces++;
	stars -= 2;
	
	for (i = 0; i < 9; i++){
		//Printing the spaces
		for (j = 0; j < spaces; j++){
			printf(" ");
		}
		
		//Printing the stars
		for (j = 0; j < stars; j++){
			printf("*");
		}
		printf("\n");
		spaces++;
		stars-=2;
	}
	
	return 0;
}
