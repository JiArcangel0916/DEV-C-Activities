#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(short int x, short int y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printEnds();

int main(){
	// ==========
	// **********
	//  ********
	//   ******
	//    ****
	//    ****
	//   ******
	//  ********
	// **********
	// ==========
	
	int i, j, height, stars, x, y;
	height = 4;
	stars = 10;
	x = 20; y = 5;
	
	gotoxy(x-1, y);
	printEnds();
	for (i = 0; i < height; i++){
		gotoxy(x, y + 1);
		for (j = 0; j < stars; j++){
			printf("*");
		}
		stars -= 2; 
		x++;
		y++;
	}
	x--;
	stars+=2;
	
	for (i = 0; i < height; i++){
		gotoxy(x, y + 1);
		for (j = 0; j < stars; j++){
			printf("*");
		}
		stars += 2;
		y++;
		x--;
	}
	x++;
	y++;
	gotoxy(x-1, y);
	printEnds();
	return 0;
}

void printEnds(){
	int i;
	
	for (i = 0; i < 12; i++){
		printf("=");
	}
}
