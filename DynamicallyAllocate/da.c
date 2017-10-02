#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct DAS{
	char *name;
	int age;
	int height;
	int weight;
	char *subject;
}STUDENT;

int main(){
	int i, j, k;

	//initalize the age, dynamically allocate memory for an array
	int *ageInfo = malloc(5 * (sizeof(int) + 1));
	for (i = 0; i != 5; i++){
		ageInfo[i] = 10 + i;
	}

	//initalize the name, dynamically allocate memory for an array of an array
	char **nameInfo = malloc(5 * sizeof(char *));
	for (j = 0; j != 5; j++){
		nameInfo[j] = malloc(10 * sizeof(char));
	}
	nameInfo[0] = "Jack";
	nameInfo[1] = "Ada";
	nameInfo[2] = "Berry";
	nameInfo[3] = "Clark";
	nameInfo[4] = "Peter";
/*
	strcpy(nameInfo[0], "Jack");
	strcpy(nameInfo[1], "Ada");
	strcpy(nameInfo[2], "Berry");
	strcpy(nameInfo[3], "Clark");
	strcpy(nameInfo[4], "Peter");
*/
	//initalize the subject
	char *subjectInfo[10] = {"Science", "Math", "Physics", "Chemistry", "Language"};

	//dynamically allocate a struct
	struct DAS *student1 = malloc(sizeof(struct DAS));
	student1->name = nameInfo[3];
	student1->age = ageInfo[3];
	student1->height = 100;
	student1->weight = 100;
	student1->subject = subjectInfo[rand() % 4];

	printf("%s's age is: %d, height is: %d, weight is: %d, subject is: %s ", student1->name, student1->age, student1->height, student1->weight, student1->subject);
	return 0;

}