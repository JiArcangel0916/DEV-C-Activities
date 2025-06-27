#include <stdio.h>
#include <string.h>

struct STUDREC{
	char studNo[13];
	char studName[25];
	char crsYr[10];
	float SGrade[5];
};

int main(){
	struct STUDREC stud1;
	char acadStatus[20];
	int i;
	float sum = 0, ave;
	
	printf("Enter Student No.: ");
	scanf("%s", stud1.studNo);
	scanf("%c");
	
	printf("Enter Student Name: ");
	gets(stud1.studName);
	
	printf("Course and Year: ");
	gets(stud1.crsYr);
	
	printf("Enter Subject Grades:\n ");
	for (i = 0; i < 5; i++){
		printf("\tEnter Grade %d: ", i + 1);
		scanf("%f", &stud1.SGrade[i]);
		sum += stud1.SGrade[i];
	}
	
	ave = sum / 5.0;
	
	
	if (ave <= 2.50){
		strcpy(acadStatus, "Good Standing");
	}
	else if (ave > 2.50 && ave <= 3.00){
		strcpy(acadStatus, "Probation");
	}
	else{
		strcpy(acadStatus, "Dismissed");
	}
	
	
	printf("\n\n<@@ STUDENT RECORD @@>\n\n");
	printf("Student No.:\t\t%s\n", stud1.studNo);
	printf("Student Name:\t\t%s\n", stud1.studName);
	printf("Course and Year:\t%s\n", stud1.crsYr);
	printf("GWA:\t\t\t%0.2f\n", ave);
	printf("Academic Status:\t%s\n", acadStatus);
	
	return 0;
	
}
