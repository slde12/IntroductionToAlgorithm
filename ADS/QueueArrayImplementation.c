//The array implementation of Queue
//Last modify: Chen, 5/30/2017

/*
1. Good job!
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue_array_implementation{
	int head;
	int rear;
	int *element;
	int size;
}queue, *Queue;

Queue _initalize_queue(int);
int _get_head(Queue);
int _get_length(Queue);
int _is_empty(Queue);
int _is_full(Queue);
void _delete_queue(Queue);
void _push(Queue, int);
void _pop(Queue);
void _print(Queue);

int main(){
	int choose;
	int parameter;
	while(1){
		printf("The array implementation of Queue:\n");
		printf("0. initalize a queue\n");
		printf("1. push\n");
		printf("2. get head\n");
		printf("3. pop\n");
		printf("4. is empty?\n");
		printf("5. is full?\n");
		printf("6. get length\n");
		printf("7. print queue\n");
		printf("8. delete queue\n");
		printf("9. exit\n");
		scanf("%d", &choose);
		if(choose == 9) break;
		switch(choose){
			case 0:
				printf("Your circular queue size:\n");
				scanf("%d", &parameter);
				Queue q = _initalize_queue(parameter);
				break;
			case 1:
				printf("Your value: ");
				scanf("%d", &parameter);
				_push(q, parameter);
				break;
			case 2:
				printf("The head value is: %d", _get_head(q));
				break;
			case 3:
				_pop(q);
				break;
			case 4:
				if(_is_empty(q)) printf("The queue is empty\n");
				else printf("The queue is not empty\n");
				break;
			case 5:
				if(_is_full(q))	printf("The queue is full\n");
				else printf("The queue is not full\n");
				break;
			case 6:
				printf("The queue length is: %d\n", _get_length(q));
				break;
			case 7:
				_print(q);
				break;
			case 8:
				_delete_queue(q);
				break;
		}

	}
	return 0;
}

Queue _initalize_queue(int arraySize){
	Queue q = malloc(sizeof(queue));
	if(q == NULL){
		exit(0);
	}
	int *array = malloc((arraySize + 1) * sizeof(int));			// size + 1, make a size + 1 queue which actually can hold element number is size. 
	if(array == NULL){
		exit(0);
	}
	q -> head = -1;
	q -> rear = -1;
	q -> element = array;
	q -> size = arraySize + 1;
}

int _is_empty(Queue q){
	return q -> head == q -> rear ;
}

int _is_full(Queue q){
	if((q -> rear + 1 - q -> head) % q -> size == 0) return 1;
	else return 0;
}

int _get_length(Queue q){
	if(_is_empty(q)) return 0;
	if(q -> head < q ->rear) return q ->rear - q -> head;
	else return q -> rear + q -> size - q -> head;
}

void _delete_queue(Queue q){
	free(q -> element);
	free(q);
}

int _get_head(Queue q){
	return q -> element[q -> head];
} 

void _push(Queue q, int val){
	if(_is_full(q)){
		printf("The queue is full\n");
	}
	else if(q -> head == -1){
		q -> head += 1; 
		q -> rear = q -> head + 1;
		q -> element[q -> head] = val;
	}
	else{
		q -> element[q -> rear] = val;
		q -> rear = (q -> rear + 1) % (q -> size);
	}
}

void _pop(Queue q){
	if(_is_empty(q)) exit(0);
	q -> head = (q -> head + 1) % (q -> size);

}

void _print(Queue q){
	int i = 0;
	for(i = q -> head; i % (q -> size) != q ->rear; i++){
		printf("%d ", q -> element[i]);
	}
	printf("\n");
}