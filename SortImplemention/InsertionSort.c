//Insertion sort
//Last modify: Chen, 2017-07-08 15:49:39
/*NOTES
  1. Start insert from the second num, be careful with the bound.
  2. Compare process has two condition, first, the previous num small(or large) than the key,
     second, the index less than 0, no other num left.
  3. Average time complexity is O(n^2), worst is O(n^2), under the best situation, the num in
     the array is almost ordered, the time complexity will close to O(n).
  4. Space complexity is O(1), no extra space needed.
*/

#include <stdio.h>
#include <stdlib.h>


void InsertionSort(int *array, int arraySize){
	int i;
	int j;
	int k;
	int key;
	//First num doesn't need to compare to itself, start from the second one 
	for(i = 1; i != arraySize; i++){
		key = array[i];
		j = i - 1;
		while(array[j] > key && j >= 0){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;

		//print every sort
		for(k = 0; k != arraySize; k++){
			printf("%d ", array[k]);
		}
		printf("\n");
	}
	/*
	for(i = 0; i != arraySize; i++){
		key = array[i];
		j = i - 1;
		while(j >= 0 && array[j] < key){
			//array[j+1] is key's position
			array[j + 1] = array[j];
			j--
		}
		array[j + 1] = key;
	}
	*/
}

int main(){
	int a[] = {9,8,7,6,5,4,3,2,1};
	int size = 9;
	InsertionSort(a,size);
	/*
	int i;
	for(i = 0; i != size; i++){
		printf("%d ",a[i]);
	}
	8 9 7 6 5 4 3 2 1
	7 8 9 6 5 4 3 2 1
	6 7 8 9 5 4 3 2 1
	5 6 7 8 9 4 3 2 1
	4 5 6 7 8 9 3 2 1
	3 4 5 6 7 8 9 2 1
	2 3 4 5 6 7 8 9 1
	1 2 3 4 5 6 7 8 9
	*/
}