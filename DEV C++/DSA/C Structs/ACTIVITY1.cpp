#include <stdio.h>
#include <string.h>

struct STUDREC{
	char studNo[13];
	char studName[25];
	char crsYr[10];
	float GWA;
};

int main(){
	struct STUDREC stud1;
	char acadStatus[20];
	
	printf("Enter Student No.: ");
	scanf("%s", stud1.studNo);
	scanf("%c");
	
	printf("Enter Student Name: ");
	gets(stud1.studName);
	
	printf("Course and Year: ");
	gets(stud1.crsYr);
	
	printf("Enter GWA: ");
	scanf("%f", &stud1.GWA);
	
	if (stud1.GWA <= 2.50){
		strcpy(acadStatus, "Good Standing");
	}
	else if (stud1.GWA > 2.50 && stud1.GWA <= 3.00){
		strcpy(acadStatus, "Probation");
	}
	else{
		strcpy(acadStatus, "Dismissed");
	}
	
	
	printf("\n\n<@@ STUDENT RECORD @@>\n\n");
	printf("Student No.:\t\t%s\n", stud1.studNo);
	printf("Student Name:\t\t%s\n", stud1.studName);
	printf("Course and Year:\t%s\n", stud1.crsYr);
	printf("GWA:\t\t\t%0.2f\n", stud1.GWA);
	printf("Academic Status:\t%s\n", acadStatus);
	
}
