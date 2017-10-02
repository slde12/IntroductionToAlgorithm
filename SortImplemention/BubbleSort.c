//Bubble sort implemention
//Last modify: Chen, 2017-07-08 12:19:16
/*NOTES
  1. Every loop start from the begin position, looping n times to bubble every n numbers, time complexity: O(n^2)
  2. Be careful with the bound of the embedded loop, in case of the index over the array size
  3. Worst Case = Average Case = O(n^2) 
  4. Best Case = O(n), actually, according to the basic algorithm, all the case would be O(n^2). 
     Optimizing algorithm by adding a control in the loop, if the first time loop doesn't exchange any
     position of the array, then the following loop will not be executed the performance for best case to be O(n) 
  5. Space Complexity: O(1), no extra memory space(temp are not included)
*/
#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int *array, int arraySize){
	int i;
	int j;
	int k;
	int temp;
	//Every time from the begin to bubble
	//
	int control = 0;
	for(i = 0; i != arraySize && control == 0; i++){
		control = 1;
		for(j = 1; j != arraySize; j++){
			if(array[j - 1] > array[j]){
				Swap(&array[j - 1], &array[j]);
				control = 0;
			}
		}

		//print every sort
		for(k = 0; k != arraySize; k++){
			printf("%d ", array[k]);
		}
		printf("\n");
	}
}

int main(){
	int a[] = {9,8,7,6,5,4,3,2,1};
	int size = 9;
	BubbleSort(a,size);
	/*
	int i;
	for(i = 0; i != size; i++){
		printf("%d ",a[i]);
	}
	8 7 6 5 4 3 2 1 9
	7 6 5 4 3 2 1 8 9
	6 5 4 3 2 1 7 8 9
	5 4 3 2 1 6 7 8 9
	4 3 2 1 5 6 7 8 9
	3 2 1 4 5 6 7 8 9
	2 1 3 4 5 6 7 8 9
	1 2 3 4 5 6 7 8 9
	1 2 3 4 5 6 7 8 9
	*/
}