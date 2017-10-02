//Counting Sort
//Last modify: Chen, 2017-07-09 18:40:58
/*NOTES
  1. Five ''for'' loop to accomplish the counting sort
  2. Using count array to count down the number's order by using original
     number as the index of the count array, which make number ordered
  3. Space complexity is terrible in the worst case, depending on the range of the sorted number
  4. Time complexity = O(n+k), n is the amount of the numbers, k is the range of the numbers
  5. Space complexity is O(n+k), need to create a count array and temp array to count down the sorted
     numbers as auxiliary array
*/
#include <stdio.h>
#include <stdlib.h>

void CountingSort(int *array, int arraySize, int arrayRange){
	int *count = malloc(arrayRange * sizeof(int));
	if(count == NULL) exit(-1);
	int *tempResult = malloc(arraySize * sizeof(int));
	if(tempResult == NULL) exit(-1);

	int i;
	int j;
	for(i = 0; i != arrayRange; i++){
		count[i] = 0;
	}

	for(i = 0; i != arraySize; i++){
		count[array[i]]++;
	}

	for(i = 1; i != arrayRange; i++){
		count[i] = count[i] + count[i - 1];
	}

	for(i = 0; i != arraySize; i++){
		count[array[i]]--;
		tempResult[count[array[i]]] = array[i];
	}
	
	for(i = 0; i != arraySize; i++){
		array[i] = tempResult[i];
	}
}

int main(){
	int a[] = {1,2,4,5,7,5,4,3,5,7,8,1};
	int size = 12;
	CountingSort(a, 12, 9);
	printf("\n");
	
	int i;
	for(i = 0; i != size; i++){
		printf("%d ",a[i]);
	}
}