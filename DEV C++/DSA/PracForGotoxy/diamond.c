#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(short int x, short int y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(){
	//   *			3 spaces	1 star
	//  ***   		2 spaces	3 stars
	// *****		1 space		5 stars
	//*******					7 stars
	// *****		1 space		5 stars
	//  ***			2 spaces	3 stars
	//   *			3 spaces	1 star
	
	int i,j, stars, longest, height, rows;
	longest = 4;
	stars = 1;
	height = 1;
	rows = 12;
	
	for (i = 5; i > longest; i++){
		gotoxy(rows-i, height);
		for (j = 0; j < stars; j++){
			printf("Error ");
		}
		stars+=2;
		height++;
	}
	stars-=2;
	
	for (i = 0; i < longest - 1; i++){
		gotoxy((rows-2)+i,height);
		for(j = 0; j < stars - 2; j++){
			 printf("*");
		}
		stars-=2;
		height++;
	}
	return 0;
}
