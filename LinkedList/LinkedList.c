//Function of Linked list
//Last modify: Chen 5/21/2017

/*SOME NOTES FOR THE LINKED LIST
1. Different list structures result in different manipulation designs, 
a list with an empty head node is much more clear and easy in delete and insert a node,
especially in the first node.          

head node -> first_node -> second_node -> ... -> NULL

2. In a linked list without a empty head node, manipulation need to be careful 
if the first node has chance to be modified, because the head node is a pointer, 
we need to pass the address of the pointer, which is double pointer, 
or we return the modified head at the end of the function. 

3. The priority of operator, -> is higher than *, be careful when use (*p) -> next
and "*p -> next" equals "*(p -> next)"

4. Manipulation on the liinked list is not the end, the control, the logic of the
main function is also important so that I need to improve my understand of it.

5. This program is still NOT FINISHED, some logic problem still in the last 4 function
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int val;
	struct list *next;
}LNode, *Linklist;

void _create_linkedlist(Linklist);
void _print_list(Linklist);
void _insert_by_value(Linklist, int, int);
void _insert_by_key(Linklist, int, int);
void _insert_last(Linklist, int);
void _delete_by_value(Linklist *, int);
void _delete_by_key(Linklist *, int);
void _iteration_manipulation(Linklist);
int _recursion_manipulation(Linklist);

int main(){
	//initalize list
	Linklist head = malloc(sizeof(LNode));
	if(head == NULL){
		return -1;
	}
	head -> next = NULL;
	//check NULL
	if(head == NULL){
		printf("Error, there is no free memory");
		return 0;
	}
	_create_linkedlist(head);
	_print_list(head);

	//user choice
	while(1){
		int choose;
		int parameter1, parameter2;
		printf("Select your function:\n");
		printf("1. Insert a node by value\n");		
		printf("2. Insert a node by key\n");	
		printf("3. Delete a node by value\n");		
		printf("4. Delete a node by key\n");
		printf("8. Insert a node at last\n");		
		printf("5. Iteration (not finished)\n");
		printf("6. Recurstion (not finished)\n");		
		printf("7. End the fucntion\n");	
		scanf("%d", &choose);
		if(choose == 7){
			break;
		}
		switch(choose){
			case 1:
				printf("Please enter target value and your node value:\n");
				scanf("%d%d",&parameter1, &parameter2);
				_insert_by_value(head, parameter1, parameter2);
				_print_list(head);
				printf("\n");
				break;
			case 2:
				printf("Please enter key position and your node value:\n");
				scanf("%d%d",&parameter1, &parameter2);
				_insert_by_key(head, parameter1, parameter2);
				_print_list(head);
				printf("\n");
				break;
			case 3:
				printf("Please enter target value:\n");
				scanf("%d", &parameter1);
				_delete_by_value(&head, parameter1);
				_print_list(head);
				printf("\n");
				break;
			case 4:
				printf("Please enter key position:\n");
				scanf("%d", &parameter1);
				_delete_by_key(&head, parameter1);
				//printf("%p %d", head, head -> val);
				//printf("check\n");
				_print_list(head);
				printf("\n");
				break;
			case 8:
				printf("Please enter value you want to insert in the end:\n");
				scanf("%d", &parameter1);
				_insert_last(head, parameter1);
				//printf("%p %d", head, head -> val);
				//printf("check\n");
				_print_list(head);
				printf("\n");
				break;
		}
	}
	return 0;
}

//create list without empty head node, awful!!!
void _create_linkedlist(Linklist head){
	Linklist p = head;
	int value;
	
	printf("Enter your node value, -1 is the end: \n");
	scanf("%d", &value);
	while(value != -1){
		p -> val = value;
		Linklist q = malloc(sizeof(LNode));
		//check NULL
		if(head == NULL){
			printf("Error, there is no free memory");
			break;
		}
		p -> next = q;
		p = p -> next;
		p -> next = NULL;
		printf("Enter your node value, -1 is the end: \n");
		scanf("%d", &value);
	}
}

void _print_list(Linklist head){
	Linklist p = head;
	printf("Your linked list is: ");
	while(p -> next -> next != NULL){
		printf("%d -> ", p -> val );
		p = p -> next;
	}
	// deal with the last one, because I don't want to print a "->"
	printf("%d", p -> val);
}

//insert a node after the first match value
void _insert_by_value(Linklist head, int target_value, int value){
	Linklist p = head;
	while(p -> val != target_value){
		p = p -> next;
	}
	Linklist q = malloc(sizeof(LNode));
	//check NULL
	if(head == NULL){
		printf("Error, there is no free memory");
	}
	else{
		q -> val = value;
		q -> next = p -> next;
		p -> next = q;
	}
	
}

//insert a node after the key position
void _insert_by_key(Linklist head, int position, int value){
	Linklist p = head;
	int count = position - 1;

	while(count){//consider the first position, awful code without empty head node, lol.
		p = p -> next;
		count--;
	}
	Linklist q = malloc(sizeof(LNode));
	if(head == NULL){
		printf("Error, there is no free memory");
	}
	else{
		q -> val = value;
		q -> next = p -> next;
		p -> next = q;
	}
}

//again, it is awful to manipulate a linked list without a empty node head
//still have some problem, following manipulation and such things.
void _delete_by_value(Linklist *head, int value){
	Linklist *p = head;
	if((*head) -> val == value){
		Linklist *q = p;
		(*head) = (*p) -> next;
		free(q);
	}
	else{
		while((*p) -> next -> val != value){
			(*p) = (*p) ->next;
		}
		if((*p) -> next -> val == value){
			Linklist *q = p;
			*q = (*p) -> next;
			(*p) -> next = (*p) -> next -> next;
			free(q);
		}
		else printf("Error, no match node!\n");
	}
}

//again, again and again, an empty head node can avoid all of these stupid things.
//still have some problem, the out of range is not accomplished.
void _delete_by_key(Linklist *head, int key){
	Linklist *p = head;
	int count = key;
	if(count = 1){
		Linklist *q = p;
		*head = (*p) -> next;
		free(q);
	}
	else{
		while(count - 2){
			*p = (*p) ->next;
			count--;	
		}
		if((*p) -> next != NULL){
			Linklist *q;
			*q = (*p) -> next; 
			(*p) -> next = (*p) -> next -> next;
			free(q);
		}
		else printf("Error, out of range!");
	}
}

//trace a linked list
void _iteration_manipulation(Linklist head){
	Linklist p = head;
	while(p -> next != NULL){
		//manipulation
		p = p -> next;
	}
}

int _recursion_manipulation(Linklist node){
	if(node = NULL){
		return 0;
	}
	return 1 + _recursion_manipulation(node -> next);
}

void _insert_last(Linklist head, int x){
	Linklist p = head;
	while(p -> next != NULL){
		p = p -> next;
	}
	Linklist temp = malloc(sizeof(LNode));
	temp -> val = x;
	temp -> next = NULL;
	p -> next = temp;

}
