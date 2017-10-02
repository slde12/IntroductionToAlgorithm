//Array implementation of a stack
//Last modify: Chen, 5/23/2017

/*SOME NOTES FOR THE ARRAY IMPLEMENTATION OF A STACK

1. Always check memory after dynamically allocate memory(chech NULL)

2. This ADS is a bad design, a better one is to use &s to pass the address
of stack, so it won't need any return in every function.
---Partly solved, the key is to modify the increasement part, just create a
 temp array free the array which was pointed by s instead of create a 
whole temp stack.

3. For the increasement part, next time I will try realloc() function. 

4. Generally, there are more functions in the stack, but the basic function 
is mostly included in the following code.

*/
#include <stdio.h>
#include <stdlib.h>


#define DATATYPE int
#define STACKSIZE 10
#define INCREASEMENT 10

typedef struct stack_array_implementation{
	DATATYPE *element;//base
	int length;
	int maxsize;
}stack,*Stack;

//prototype
Stack _initalize_stack();
void _increase_stack_size(Stack);
void _push(Stack, DATATYPE);
void _pop(Stack);
DATATYPE _get_top(Stack);
int _get_length(Stack);
int _is_empty(Stack);

int main(){
	Stack s = _initalize_stack();
	int choose;
	DATATYPE parameter;
	while(1){
		printf("This is my first mannul stack: \n");
		printf("So pick a function:\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Get top\n");
		printf("4. Get length\n");
		printf("5. Is stack empty\n");
		printf("6. Quit\n");
		scanf("%d", &choose);

		if(choose == 6) break;

		switch(choose){
			case 1:
				printf("Your value is: \n");
				scanf("%d", &parameter);
				_push(s, parameter);
				break;
			case 2:
				_pop(s);
				break;
			case 3:
				parameter = _get_top(s);
				printf("The top element is: %d\n", parameter);
				break;
			case 4:
				parameter = _get_length(s);
				printf("The length of the stack is: %d\n", parameter);
				break;
			case 5:
				parameter = _is_empty(s);
				printf("%d\n", parameter);
				break;
		}

	}



	return 0;
}

Stack _initalize_stack(){
	Stack s = malloc(sizeof(stack));
	if(s == NULL){
		printf("Error, there is no free memory!\n");
		return 0;
	}
	DATATYPE *array = malloc(STACKSIZE * sizeof(DATATYPE));
	if(array == NULL){
		printf("Error, there is no free memory!\n");
		return 0;
	}
	s -> maxsize = STACKSIZE;
	s -> element = array;
	s -> length = 0;
	return s;
}

void _increase_stack_size(Stack s){
	/*there is a problem, the increase function can only work once, 
	just leave it there and I will find a solution next time

	----this problem has been solved by add an attribution in struct to 
	store the stack size, but another problem came out that if use to function
	to increase the size for stack, it return another stack address, which causes
	some problem when calling this function in the push. Still need to solved.
	*/
	DATATYPE *array = malloc((s -> maxsize + INCREASEMENT) * sizeof(DATATYPE));
	if(array == NULL){
		printf("Error, there is no free memory!\n");
		exit(0);
	}
	int i;
	for(i = 0; i != s -> length; i++){
		array[i] = s -> element[i];
	}
	free(s -> element);
	s -> maxsize = s -> maxsize + INCREASEMENT;
	s -> element = array;	
}

void _push(Stack s, DATATYPE data){
	if(s -> length == s -> maxsize){
		_increase_stack_size(s);
	}
	s -> element[s -> length] = data;
	s -> length += 1;
}

void _pop(Stack s){
	//I didn't do anything to delete a value, not sure it is required to do that.
	s -> length -= 1;
}

DATATYPE _get_top(Stack s){
	return s -> element[s -> length - 1];
}

int _get_length(Stack s){
	return s -> length;
}

int _is_empty(Stack s){
	return s -> length == 0;
}



