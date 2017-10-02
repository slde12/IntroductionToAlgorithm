//Merge sort
//Last modify: Chen, 2017-07-08 18:04:30
/*NOTES
  1. Divide and conquer
  2. Use a auxiliary function merge to merge the two part of array
  3. Time complexity = O(log n) * O(n) = O(nlog n)
  4. log n = times of halving the array(like a binary search)
  5. n = merge the array every time you half the array, easy to prove
  6. Space complexity = O(n), need a temp to store the merged array and recursion(log n), O(n) + O(log n) -> O(n) 
*/

#include <stdlib.h>
#include <stdio.h>

//conquer
//Merge the two part of the array
//Assume two part already ordered
void Merge(int *array, int low, int mid, int high){
	
	int leftSize = mid - low + 1;
	int rightSize = high - mid;
	int tempSize = high - low + 1;
/*
	//left part is from low to mid
	int *left = malloc(leftSize * sizeof(int));
	if(left == NULL) return NULL;
	//right part is from mid+1 to high
	int *right = malloc(rightSize * sizeof(int));
	if(right == NULL) return NULL;
*/
	//Use tempResult to count down the merge array then copy it to the original array
	int *tempResult = malloc(tempSize * sizeof(int));
	//check malloc
	if(tempResult == NULL) exit(1);

	//Merge two array
	int i = 0;
	int j = 0;
	int k = 0;
	while(i != leftSize && j != rightSize){
		if(array[low + i] <= array[mid + 1 + j]){
			tempResult[k] = array[low + i];
			k++;
			i++;
		}else{
			tempResult[k] = array[mid + 1 + j];
			k++;
			j++;
		}
	}
	//Deal with the rest of left or right if it is existed
	while(i != leftSize){
		tempResult[k] = array[low + i];
		k++;
		i++;
	}
	while(j != rightSize){
		tempResult[k] = array[mid + 1 + j];
		k++;
		j++;
	}

	for(k = 0; k!= tempSize; k++){
		array[low + k] = tempResult[k];
	}

	free(tempResult);
}

//Recursion implemention
//divide and conquer
//Half the array every time call the function itself until low == high which means
//only one element in the divided array
void MergeSort(int *array, int low, int high){
	if(low < high){
		int mid = (low + high) / 2;

		//devide
		MergeSort(array, low, mid);
		MergeSort(array, mid + 1, high);
		
		Merge(array, low, mid, high);
		int i;
		for(i = 0; i != 16; i++){
			printf("%d ",array[i]);
		}
		printf("\n");		
	}
}

int main(){
	int a[] = {11,23,43,3,232,4,422,33,323,434,56,7,5,43,5,4};
	int size = 16;
	MergeSort(a,0,size-1);
	printf("\n");
	
	int i;
	for(i = 0; i != size; i++){
		printf("%d ",a[i]);
	}

}