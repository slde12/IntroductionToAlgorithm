//Convert infix expression to postfix expression
//Last modify: Chen, 2017-06-04 13:47:58

/*SOME NOTES FOR THE CONVERT
1. Always make mistake, miss some rule to take into consideration

2. Just pass the little bit complex sample, the ((a * b) + (a * b)) sample are not included.  ----Solved, sample passed.

3. String and std input are important and complex in C, need to get used to it.

4. Use file i/o to store the postfix instead of using a variable. ----Solved, use getchar() to handle the input

5. Only works between 0 - 9.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
	char val;
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

void _push(Stack s, char value){
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

char _get_top(Stack s){
	return s -> top -> val;
}


int _compare(char op, char top){
	char operator[5][2] = {{'(', '0'}, {'+', '1'}, {'-', '1'}, {'*', '2'}, {'/', '2'}};
	int i,j;
	for(i = 0; i != 5; i++){
		if(op == operator[i][0]) break;
	}
	for(j = 0; j != 5; j++){
		if(top == operator[j][0]) break;
	}
	return operator[i][1] > operator[j][1];
}

void _convert(FILE *fp){									//just print the postfix expression
	//int i = 0;
	char op;
	//char postfix[100] = ""; 								//suppose it will never over 100
	Stack opStack = _initalize_stack();
	while((op = getchar())!= '\n'){							//operator and operand
		if((op >= '(') && (op <= '/')){						//operator case
			if((_is_empty(opStack) == 1) || (op == '(')){
				_push(opStack, op);
			}
			else if(op == ')'){
				while(_get_top(opStack) != '('){
					//strcat(postfix, _get_top(opStack));
					//printf("%c", _get_top(opStack));
					fprintf(fp, "%c ", _get_top(opStack));
					_pop(opStack);							//pop the operator before '('
				}
				_pop(opStack);								//pop the '('
			}
			else if(_compare(op, _get_top(opStack))){		//if op > top
				_push(opStack, op);
			}
			else{											//if op <= top
				while(_get_top(opStack) != '(' && !_is_empty(opStack) && !_compare(op, _get_top(opStack))){
					//strcat(postfix, _get_top(opStack));
					//printf("%c", _get_top(opStack));
					fprintf(fp, "%c ", _get_top(opStack));
					_pop(opStack);
				}				
				_push(opStack, op);							
			}
		}
		else{												//operand case
			//strcat(postfix, op);
			//printf("%c", op);
			fprintf(fp, "%c ", op);
		}
	}
	while (!_is_empty(opStack)) {
		//printf("%c", _get_top(opStack));
		fprintf(fp, "%c ", _get_top(opStack));
		_pop(opStack);
	}
	//return postfix;
}

int main(){
	printf("This function convert infix to postfix:\n");
	printf("Please enter your infix expression:");
	//char str[100] = "1+2*3+4*5/6*(1+(2*3/4)-5*6)#";
	//scanf("%s", str);
	//printf("The postfix expression is:");
	FILE *fp;
	fp = fopen("record", "w+");
	_convert(fp);
	fclose(fp);

	return 0;
}