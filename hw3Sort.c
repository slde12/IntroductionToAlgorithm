#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 500

typedef struct airPdata{
	char *LocID; //Airport’s ‘‘Short Name’’, ie MCO
	char *fieldName; //Airport Name
	char *city; //Associated City
	float longitude; //Longitude
	float latitude; //latitude
}airPdata;

struct node
{
    airPdata* key;
    struct node *left;
    struct node *right;
    int height;
};

void parseLine(char *line, airPdata *apd);
void printData(int length, airPdata *apd);
void deleteStruct(airPdata *apd);
float sexag2decimal(char *degreeString);
void sortByLocID(airPdata *apd, int low, int high);
int Partition(airPdata *array, int low, int high);
void apdSwap(airPdata *apd1, airPdata *apd2);
void sortBylatitude(airPdata *apd, int size);

int max(int a, int b);
int height(struct node *N);
int max(int a, int b);
struct node* newNode(airPdata *key);
struct node* rightRotate(struct node *y);
struct node* leftRotate(struct node *x);
int getBalance(struct node *N);
struct node* insert(struct node* node, airPdata *key);
void inOrder(struct node *root);

int main (int argc, char *argv[]){

	// Declare input buffer and other parameters
	FILE *fid;
	char buffer[BUFFER_SIZE];
	int count = 0;

	
	// Check for command line input and open input file.
	if(argc==3){
		fid = fopen(argv[1], "r");
		if(fid==NULL){
			printf("hw3Sort ERROR: File \"%s\" not found.\n", argv[1]);
			return 2;
		}
		if(!(argv[2][0] == 'a' || argv[2][0] == 'n')){
			printf("hw3Sort ERROR: valid sort parameters are a or n.\n");
			return 2;
		}
	}
	else{
		printf("Incorect number of input parameters. Please specify the name of the input file and sort parameters.\n");
		printf("Syntax: ./hw3Sort.exe [input file] [sort parameter]\n");
		return 1;
	}
	
	
	// Determine length of the file.
	while(fgets(buffer, BUFFER_SIZE, fid) != NULL){
		count++;
	}
	rewind(fid);
	
	
	// Declare a struct array and allocate memory.
	airPdata *data;

	data = malloc(sizeof(airPdata)*count);
	if(data==NULL){
		printf("Memory allocation for airPdata array failed. Aborting.\n");
		return 2;
	}

	// Read and parse each line of the inputt file.
	for(int i = 0; i<count; i++){
		fgets(buffer, BUFFER_SIZE, fid);
		
		// fgets() includes the New Line delimiter in the output string. 
		// i.e. "This is my string.\n\0"
		// We will truncate the string to drop the '\n' if it is there.
		// Note: There will be no '\n' if the line is longer than the buffer.
		if(buffer[strlen(buffer) - 1] == '\n') buffer[strlen(buffer)-1] = '\0';
		
		parseLine(buffer, data+i);
	}


	// close the input file.
	fclose(fid);

	if(argv[2][0] == 'a'){
		// Sort by LocID using quick sort :)
		sortByLocID(data, 0, count-1);
		printData(count, data);
	}else{
		sortBylatitude(data, count);
	}

	// Free the memory used for fields of the structs.
	for(int i=0; i<count; i++){
		deleteStruct(data+i);
	}

	// Free the memory for the struct array.
	free(data);

	return 0;

}


void parseLine(char *line, airPdata *apd){

	int i=0, j=0, commas=0;
	
	while(commas<15){
		while(*(line+i)!=','){
			i++;
		}
		
		// strncpy does not append a '\0' to the end of the copied sub-string, so we will
		// replace the comma with '\0'. 
		*(line+i) = '\0';

		switch (commas){
		case 1:   //Grab the second "field" - Location ID
			apd->LocID = malloc(sizeof(char)*(i-j+1));
			if(apd->LocID==NULL){
                        	printf("malloc failed to initialize airPdata.LocID.\n");
                                exit(-1);
                        }
                        strncpy(apd->LocID, line+j, i-j+1);
                        break;
		case 2:   //Grab the third "field" - Field Name
			apd->fieldName = malloc(sizeof(char)*(i-j+1));
			if(apd->fieldName==NULL){
				printf("malloc failed to initialize airPdata.fieldName.\n");
				exit(-1);
			}
			strncpy(apd->fieldName, line+j, i-j+1);
			break;
		case 3:   //Grab the fourth "field" - City
			apd->city = malloc(sizeof(char)*(i-j+1));
			if(apd->city==NULL){
				printf("malloc failed to initialize airPdata.city.\n");
				exit(-1);
			}
			strncpy(apd->city, line+j, i-j+1);
			break;
		case 8:   //Grab the ninth "field" - latitude (sexagesimal string)
			apd->latitude = 0;
			char *temp1 = malloc(sizeof(char)*(i-j+1));
			if(temp1==NULL){
				printf("malloc failed to initialize airPdata.latitude.\n");
				exit(-1);
			}
			strncpy(temp1, line+j, i-j+1);
			apd->latitude = sexag2decimal(temp1);
			free(temp1);
			temp1 = NULL;
			break;
		case 9:   //Grab the tenth "field" - Longitude (sexagesimal string)
			apd->longitude = 0;
			char *temp2 = malloc(sizeof(char)*(i-j+1));
			if(temp2==NULL){
				printf("malloc failed to initialize airPdata.longitude.\n");
				exit(-1);
			}
			strncpy(temp2, line+j, i-j+1);
			apd->longitude = sexag2decimal(temp2);
			free(temp2);
			temp2 = NULL;
			break;
		}

		j=++i;
		commas++;
	}
}

void printData(int length, airPdata *data){
	printf("%-11s %-42s %-34s %-15s %-16s\n", "Short Name", "Airport Name", "City", "latitude", "Longitude");
	printf("%-11s %-42s %-34s %-15s %-16s\n", "==========", "============", "====", "========", "=========");
	for(int i=0; i<length; i++){
		//Filter the helipads
		int condition1 = (strlen((data+i)->LocID) == 3) && (((data+i)->LocID[0] <= '9') || ((data+i)->LocID[1] <= '9') || ((data+i)->LocID[2] <= '9'));
		int condition2 = (strlen((data+i)->LocID) == 4) && (((data+i)->LocID[0] <= '9') || ((data+i)->LocID[1] <= '9') || ((data+i)->LocID[2] <= '9') || ((data+i)->LocID[3] <= '9'));
		if(!(condition1 || condition2)){
			printf("%-11s %-42s %-34s %-15.4f %-16.4f\n",(data+i)->LocID, (data+i)->fieldName,
			(data+i)->city, (data+i)->latitude, (data+i)->longitude);
		}
	}
}

void deleteStruct(airPdata *apd){
	free(apd->city);
	free(apd->fieldName);
	free(apd->LocID);
}

float sexag2decimal(char *degreeString){
	if(degreeString == NULL){
		return 0.0;
	}
	int length = strlen(degreeString);
	int i;
	float j = 0.0;
	float temp[3] = {0.0};
	float result = 0;
	int count = 0;

	//Convert each part of degree and store into temporary array
	for(i = length - 2 ; i >= 0; i--){
		if(degreeString[i] != '-' && degreeString[i] != '.' && degreeString[i] >= '0' && degreeString[i] <= '9'){
			temp[count] = temp[count] + (degreeString[i] - '0') * pow(10.0, j);
			j += 1;
		}else if(degreeString[i] == '.'){
			continue;
		}else if(degreeString[i] == '-'){
			count += 1;
			j = 0;
		}else{//Invalid condition
			return 0.0;
		}//end if
	}//end for

	//Invalid degree result
	int invalidCondition = (temp[0] < 0) || (temp[0]>599999) || (temp[1] < 0) || (temp[1] > 59) || (temp[2] < 0 || temp[2] > 180);
	if(invalidCondition == 1){
		return 0.0;
	}

	//Calculate the result
	if(degreeString[length - 1] == 'N' || degreeString[length - 1] == 'E'){
		result = temp[2] + temp[1]/60 + temp[0]/10000/3600;
	}else{
		result = -temp[2] - temp[1]/60 - temp[0]/10000/3600;
	}

	return result;
}

//Using quick sort to accomplish this function
void sortByLocID(airPdata *apd, int low, int high){
	if(low < high){
		int pivot = Partition(apd, low, high);

		sortByLocID(apd, low, pivot - 1);
		sortByLocID(apd, pivot + 1, high);
	}
}

int Partition(airPdata *array, int low, int high){
	char *pivot = (array + high)->LocID;
	
	//Initialize the smaller num position
	int pi = low - 1;
	int j;
	for(j = low; j != high; j++){
		if(strcmp((array + j)->LocID, pivot) <= 0){
			pi++;
			apdSwap(array + pi, array + j);
		}
	}
	apdSwap(array + pi + 1, array + high);
	return pi + 1;
}

void apdSwap(airPdata *apd1, airPdata *apd2){
	char *temp1 = apd1->LocID;
	char *temp2 = apd1->fieldName;
	char *temp3 = apd1->city;
	float temp4 = apd1->longitude;
	float temp5 = apd1->latitude;

	apd1->LocID = apd2->LocID; 
	apd1->fieldName = apd2->fieldName;
	apd1->city = apd2->city;
	apd1->longitude = apd2->longitude;
	apd1->latitude = apd2->latitude;

	apd2->LocID = temp1;
	apd2->fieldName = temp2;
	apd2->city = temp3;
	apd2->longitude = temp4;
	apd2->latitude = temp5;
}

void sortBylatitude(airPdata *apd, int size){
    int i;
    struct node *root = NULL;
    for(i = 0; i != size; i++){
        root = insert(root, apd + i);
    }

    printf("%-11s %-42s %-34s %-15s %-16s\n", "Short Name", "Airport Name", "City", "latitude", "Longitude");
    printf("%-11s %-42s %-34s %-15s %-16s\n", "==========", "============", "====", "========", "=========");

    inOrder(root);
}

int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

struct node* newNode(airPdata *key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  
    return(node);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
struct node* insert(struct node* node, airPdata *key)
{
    if (node == NULL)
        return(newNode(key));
 
    if (key->latitude < node->key->latitude)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    node->height = max(height(node->left), height(node->right)) + 1;
 

    int balance = getBalance(node);

    if (balance > 1 && key->latitude < node->left->key->latitude)
        return rightRotate(node);

    if (balance < -1 && key->latitude > node->right->key->latitude)
        return leftRotate(node);

    if (balance > 1 && key->latitude > node->left->key->latitude)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key->latitude < node->right->key->latitude)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(struct node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        int condition1 = (strlen(root->key->LocID) == 3) && ((root->key->LocID[0] <= '9') || (root->key->LocID[1] <= '9') || (root->key->LocID[2] <= '9'));
		int condition2 = (strlen(root->key->LocID) == 4) && ((root->key->LocID[0] <= '9') || (root->key->LocID[1] <= '9') || (root->key->LocID[2] <= '9') || (root->key->LocID[3] <= '9'));
        if(!(condition1 || condition2) && root->key->latitude <= 31){
       		printf("%-11s %-42s %-34s %-15.4f %-16.4f\n",root->key->LocID, root->key->fieldName,
       		root->key->city, root->key->latitude, root->key->longitude);
        }
        inOrder(root->right);
    }
}
//add
