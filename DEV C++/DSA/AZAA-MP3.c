#include <stdio.h>
#include <windows.h>

void gotoxy(short int x, short int y){
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef struct{
	char name[10];
	int precVotes[5];
	int totalVotes ;
}Candidate;

int main(){
	Candidate candidates[4];
	int i, j, y, x = 15;
	int total;
	float half;
	int winner = 1;
	
	//INPUTTING INFO OF CANDIDATES
	for (i = 0; i < 4; i++){
		printf("Enter name of candidate: ");
		fgets(candidates[i].name, 10, stdin);
		candidates[i].totalVotes = 0;
		
		printf("Enter number of votes per precinct:\n");
		for (j = 0; j < 5; j++){
			printf("\tPrecinct %d votes: ", j + 1);
			scanf("%d", &candidates[i].precVotes[j]);
			candidates[i].totalVotes += candidates[i].precVotes[j];
		}
		printf("\n");
		getchar();
	}
	
	//DISPLAY TITLES
	system("CLS");
	gotoxy(20, 2);
	printf("TALLY OF VOTE PER PRECINCT");
	
	
	for (i = 0; i < 4; i++){
		gotoxy(x, 4);
		printf("Candidate");
		x += 15;
	}
	
	y = 6; 
	gotoxy(1, y);
	printf("Precincts");
	x = 17;
	//NAME OF CANDIDATES
	for (i = 0; i < 4; i++){
		gotoxy(x, y);
		printf("%s", candidates[i].name);
		x += 15;
	}
	y++;
	

	//VOTES OF PRECINCTS
	for (i = 0; i < 5; i++){
		x = 17;
		gotoxy(5, y);
		printf("%d", i + 1);
		
		for (j = 0; j < 4; j++){
			gotoxy(x, y);
			printf("%d", candidates[j].precVotes[i]);
			x += 15;
		}
		y++;
	}
	y++;
	
	//PRINT TOTAL VOTES PER CANDIDATE AND PERCENT
	total = 0;
	for (i = 0; i < 4; i++){
		total += candidates[i].totalVotes;
		
	}
	half = total / 2.0;
	
	gotoxy(20, y);
	printf("TOTAL VOTES PER CANDIDATE");
	y++;
	
	for (i = 0; i < 4; i++){	
		gotoxy(1, y);
		printf("%s: %d", candidates[i].name, candidates[i].totalVotes);
		y += 2;
	}
	
	//DISPLAY WINNER
	for (i = 0; i < 4; i++){
		if (candidates[i].totalVotes > half){
			winner = i;
		}
	}
	
	gotoxy(1, 55);
	printf("%s won the election!", candidates[winner].name);
	
	
	
	return 0;
}
