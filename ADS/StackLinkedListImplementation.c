//The linked list implementation of stack
//Last modify: Chen, 5/26/2017

/*SOME NOTES FOR THE LINKED LIST IMPLEMENTATION OF STACK

0. Actually, I made a stupid design, a stack can be just a simple linked list
which has its first head to take the length(if necessary) and adds a top pointer 
to point to the last node, so the stack struct is actually useless or not 
essential.

1. Linked list implementation stack is much easiler than array implementation.

2. There are some functions are not added, such as clear stack, destroy stack.

3. I am getting more used to code, LOL.

4. Set a empty head node DO solve a lot of stupid questions.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int val;
	struct list *next;
}LNode, *Linkedlist;

typedef struct stack_linked_list_implementation{
	Linkedlist element;
	Linkedlist top;
}stack,*Stack;

Stack _initalize_stack();
void _push(Stack, int);
void _pop(Stack);
int _get_lenght(Stack);
int _get_top(Stack);
int _is_empty(Stack);

int main(){
	printf("The linked list implementation of stack:\n");
	int choose;
	int parameter;
	Stack s = _initalize_stack();
	while(1){
		printf("Please pick a function:\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. get top\n");
		printf("4. get length\n");
		printf("5. is empty\n");
		printf("6. exit\n");
		scanf("%d", &choose);
		if (choose == 6) break;
		switch(choose){
			case 1:
				printf("Enter your value: ");
				scanf("%d", &parameter);
				_push(s, parameter);
				break;
			case 2:
				_pop(s);
				break;
			case 3:
				parameter = _get_top(s);
				printf("The top value is: %d\n", parameter);
				break;
			case 4:
				parameter = _get_lenght(s);
				printf("The stack length is: %d\n", parameter);
				break;
			case 5:
				if(_is_empty(s) == 1) printf("The stack is empty.\n");
				else printf("The stack is not empty\n");
				break;
		}
	}
	return 0;
}

Stack _initalize_stack(){
	Stack s = malloc(sizeof(stack));
	Linkedlist head = malloc(sizeof(LNode));		//set the head node as length counter
	s -> element = head;
	s -> element -> val = 0; 						//length!!!
	s -> top = s -> element;
}

void _push(Stack s, int value){
	Linkedlist temp = malloc(sizeof(LNode));
	temp -> val = value;
	s -> top -> next = temp;
	s -> top = s -> top -> next;
	s -> element -> val += 1;						//upload length!
}

void _pop(Stack s){
	if(_is_empty(s) == 1) exit(EXIT_FAILURE);
	free(s -> top);
	s -> top = s -> element;
	s -> element -> val -= 1;
	int num = s -> element -> val;
	while(num){										//reset the top
		s -> top = s -> top -> next;
		num--;
	}
}

int _get_lenght(Stack s){
	return s -> element -> val;
}

int _get_top(Stack s){
	return s -> top -> val;
}

int _is_empty(Stack s){
	return s -> element -> val == 0;
}