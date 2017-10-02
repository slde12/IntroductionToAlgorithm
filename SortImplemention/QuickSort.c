//Qucik sort
//Last modify: Chen, 2017-07-08 20:23:00
/*NOTES
  1. Divide and conquer
  2. Use Partiton function to find pivot every time separate the array
  3. Average time complexity = O(nlog n)
  4. Worst case = O(n^2), due to the pivot chosen
  5. Space complexity = O(log n), by recursion, call itself log n times
*/

#include <stdlib.h>
#include <stdio.h>

void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Set the array[high] as pivot, the target is to make the 
//partial array become left < pivot < right 
//The pi is the position before the return position
//The pviot position should be pi+1. (which need to be returned)
//The loop in the partition is trying to move the numbers smaller than pivot
//to the pi postion, so the numbers on and after pi+1 position would be bigger
//than pivot  
int Partition(int *array, int low, int high){
	int pivot = array[high];
	
	//Initialize the smaller num position
	int pi = low - 1;
	int j;
	for(j = low; j != high; j++){
		if(array[j] <= pivot){
			pi++;
			Swap(&array[pi], &array[j]);
		}
	}
	Swap(&array[pi + 1], &array[high]);
	return pi + 1;
}

void QuickSort(int *array, int low, int high){
	if(low < high){
		int pivot = Partition(array, low, high);

		QuickSort(array, low, pivot - 1);
		QuickSort(array, pivot + 1, high);
		int k;
		for(k = 0; k != 16; k++){
			printf("%d ",array[k]);
		}
		printf("\n");
	}
}

int main(){
	int a[] = {11,23,43,3,232,4,422,33,323,434,56,7,5,43,5,4};
	int size = 16;
	QuickSort(a,0,size-1);
	printf("\n");
	
	int i;
	for(i = 0; i != size; i++){
		printf("%d ",a[i]);
	}

}