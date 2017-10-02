//The linked list implementation of queue
//Last modify: Chen, 5/31/2017
/*
1. Something new happened, the first part in a label(the case in switch)
should be a statement and cannot be a declaration.

2.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list{
	int val;
	struct linked_list *next;
}node, *Node;

typedef struct queue_linked_list_implementation{
	Node element;
	Node rear;
	int length;
}queue, *Queue;


Queue _initalize_queue();
int _get_length(Queue);
int _is_empty(Queue);
void _push(Queue, int);
void _pop(Queue);
int _get_head(Queue);
void _print(Queue);
void _delete_queue(Queue);

int main(){
	int choose;
	int parameter;
	while(1){
		printf("The linked list implementation of Queue:\n");
		printf("0. initalize a queue\n");
		printf("1. push\n");
		printf("2. get head\n");
		printf("3. pop\n");
		printf("4. is empty?\n");
		printf("5. get length\n");
		printf("6. print queue\n");
		printf("7. delete queue\n");
		printf("8. exit\n");
		scanf("%d", &choose);
		if(choose == 8) break;
		switch(choose){
			case 0:
				printf("Queue initalization finished.\n");
				Queue q = _initalize_queue();
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
				printf("The queue length is: %d\n", _get_length(q));
				break;
			case 6:
				_print(q);
				break;
			case 7:
				_delete_queue(q);
				break;
		}
	}
	return 0;
}

Queue _initalize_queue(){
	Queue q = malloc(sizeof(queue));
	if(q == NULL) exit(0);
	Node head = malloc(sizeof(node));
	if(head == NULL) exit(0);
	q -> element = head;
	q -> rear = head;
	q -> length = 0;
	head -> next = NULL;
	return q;
}

int _get_length(Queue q){
	return q -> length;
}

int _is_empty(Queue q){
	return q -> length == 0;
}

void _push(Queue q, int value){
	Node temp = malloc(sizeof(node));
	if(temp == NULL) exit(0);
	temp -> val = value;
	temp -> next = NULL;
	q -> rear -> next = temp;
	q -> rear = temp;
	q -> length += 1;
}

int _get_head(Queue q){
	return q -> element -> next -> val;
}

void _pop(Queue q){
	if(_is_empty(q)){
		printf("The queue is empty.\n");
	}
	else{
		Node temp = q -> element -> next;
		q -> element -> next = temp -> next;
		free(temp);
		q -> length --;
	}
}

void _print(Queue q){
	if(_is_empty(q)){
		printf("The queue is empty.\n");
	}
	else{
		Node p = q -> element ->next;
		while(p != q -> rear -> next){
			printf("%d ", p -> val);
			p = p -> next;
		}
		printf("\n");
	}
}

void _delete_queue(Queue q){
	Node p = q -> element -> next;
	while(p != q -> rear -> next){
		Node temp = p;
		p = p -> next;
		free(temp);
	}
	free(q -> element);
	free(q);
}