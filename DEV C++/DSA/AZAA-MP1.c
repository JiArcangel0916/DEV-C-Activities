#include <stdio.h>
#include <windows.h>

void gotoxy(short int x, short int y){
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(){
	int size, stars, spaces, i, j, k, x, y;
	
	printf("Enter size of the Triangle [3-12]: ");
	scanf("%d", &size);
	
	stars = 1;
	spaces = size - 1;
	
	x = (80 / 2) - spaces;
	y = (24 / 2) - size;
	
	for (i = 0; i < size; i++){
			//PRINT THE SPACES
			gotoxy(x, y);
			for (k = 0; k < spaces; k++){
				printf(" ");
			}
			
			//PRINT THE STARS
			for (k = 0; k < stars; k++){
				printf("* ");
			}
			printf("\n");
		spaces--;
		stars++;
		y++;
	}
	
	
	return 0;
}
