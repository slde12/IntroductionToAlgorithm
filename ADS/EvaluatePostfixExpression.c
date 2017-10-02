//Evaluate postifx expression
//Last modify: Chen, 5/31/2017

/*SOME NOTES FOR THE CONVERT
1. The input problem not solved ----solved

2. the result is int, shoud be double so that can show decimal fraction.

3. the order of operand matters, especially in divide (op1 / op2).

4. 
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

Stack _initalize_stack(){
	Stack s = malloc(sizeof(stack));
	Linkedlist head = malloc(sizeof(LNode));		//set the head node as length counter
	s -> element = head;
	s -> element -> val = 0; 						//length!!!
	s -> top = s -> element;
	return s;
}

void _push(Stack s, int value){
	Linkedlist temp = malloc(sizeof(LNode));
	temp -> val = value;
	s -> top -> next = temp;
	s -> top = s -> top -> next;
	s -> element -> val += 1;						//upload length!
}

int _is_empty(Stack s){
	return s -> element -> val == 0;
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

int main(){
	//int buffer[10];
	//FILE *fp;
	//fp = fopen("result", "r+");
	//char str[100] = "123*+45*6/123*4/+56*-*+#";
	//int i = 0;
	Stack s = _initalize_stack();
	char op;
	int operand1, operand2;
	FILE *fp;
	fp = fopen("record", "r+");
	while(fscanf(fp, "%c", &op) == 1){
		if(op >= '0' && op <= '9'){
			_push(s, op - '0');
		}
		else{
			switch(op){
				case '+':
					operand2 = _get_top(s);
					_pop(s);
					operand1 = _get_top(s);
					_pop(s);
					_push(s, operand1 + operand2);
					break;
				case '-':
					operand2 = _get_top(s);
					_pop(s);
					operand1 = _get_top(s);
					_pop(s);
					_push(s, operand1 - operand2);
					break;
				case '*':
					operand2 = _get_top(s);
					_pop(s);
					operand1 = _get_top(s);
					_pop(s);
					_push(s, operand1 * operand2);
					break;
				case '/':
					operand2 = _get_top(s);
					_pop(s);
					operand1 = _get_top(s);
					_pop(s);
					_push(s, operand1 / operand2);
					break;
			}
		}
	}
	fclose(fp);
	int result = _get_top(s);
	printf("The result of the postfix is: %d", result);
	return 0;
}