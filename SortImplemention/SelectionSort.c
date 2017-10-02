//Selection Sort
//Last modify: Chen, 2017-07-08 16:20:07
/*NOTES
  1. Every time find a max(or min) num in the range and swap it to its position
  2. Best case = Worst case = O(n^2)
  3. Space complexity is O(1)
  4. Better than Bubble sort based on T(n)
*/
#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int *array, int arraySize){
	int i;
	int j;
	int k;
	//the index of the max num
	int max;
	for(i = arraySize - 1; i >= 0; i--){
		//find the max element in the range
		max = i;
		for(j = 0; j != i; j++){
			if(array[j] > array[max]){
				max = j;
			}
		}
		Swap(&array[max], &array[i]);

		//print every sort
		for(k = 0; k != arraySize; k++){
			printf("%d ", array[k]);
		}
		printf("\n");

	}
}


int main(){
	int a[] = {19,18,17,16,15,14,13,12,11};
	int size = 9;
	int i;
	printf("Input:");
	for(i = 0; i != size; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	SelectionSort(a,size);
	/*
	11 18 17 16 15 14 13 12 19
	11 12 17 16 15 14 13 18 19
	11 12 13 16 15 14 17 18 19
	11 12 13 14 15 16 17 18 19
	11 12 13 14 15 16 17 18 19
	11 12 13 14 15 16 17 18 19
	11 12 13 14 15 16 17 18 19
	11 12 13 14 15 16 17 18 19
	11 12 13 14 15 16 17 18 19
	*/
	
}
