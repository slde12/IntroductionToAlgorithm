//Binary tree manipulation 
//Last modify: Chen, 2017-06-06 14:56:16
/*NOTES
1. Something for recursion. 1)
*/

#include <iostream>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using std::stack;
using std::queue;
using namespace std;

typedef struct BinaryTree{
	int value;
	BinaryTree *left;
	BinaryTree *right;
}*BiTree,BiTNode;

void CreateBinaryTree(BiTree *);
//Traverse
void PreOrder(BiTree);
void InOrder(BiTree);
void PostOrder(BiTree);
void DLR(BiTree);
void LDR(BiTree);
void LRD(BiTree);
void layerTraverse(BiTree);
//Compute
int sumOfLeftLeaves(BiTree);
int sumOfrightLeaves(BiTree);
int sumOfLeaves(BiTree, int*);
int howManylayers(BiTree);
//Print
void printCompleteTree(BiTree);
//Covert a binary tree to a complete binary tree
//BiTree covertBinaryTree(BiTree);

int main() {
	cout << "Preorder input the numbers" << endl;
	BiTree *T = new BiTree;
	CreateBinaryTree(T);
	
	cout << "Preorder output and DLR:" << endl;
	PreOrder(*T);
	cout << endl;
	DLR(*T);
	cout << endl;
	
	cout << "Inorder output and LDR" << endl;
	InOrder(*T);
	cout << endl;
	LDR(*T);
	cout << endl;
	
	cout << "Postorder output and LRD" << endl;
	PostOrder(*T);
	cout << endl;
	LRD(*T);
	cout << endl;

	cout << "Layer Order" <<endl;
	layerTraverse(*T);
	cout << endl;

	cout << "Sum of the left leaves" << endl;
	int a = sumOfLeftLeaves(*T);
	cout << a << endl;

	cout << "Sum of the right leaves" << endl;
	int b = sumOfrightLeaves(*T);
	cout << b << endl;

	cout << "Sum of all the leaves" << endl;
	int c = 0; 
	sumOfLeaves(*T, &c); 
	cout << c << endl;

	cout << "How many layers in tree" <<endl;
	int d = howManylayers(*T);
	cout << d << endl;

	cout << "Print a complete binary tree" << endl;
	printCompleteTree(*T);
	cout << endl;
	return 0;
}

//create a binary tree with preorder input
void CreateBinaryTree(BiTree *p) {                  
	int x;
	cin >> x;
	if (x == -1) {
		*p = NULL;
	}
	else{
		//p = new BiTree;					             //the difference between new and malloc, and whether the use of "new" is right here?
		*p = (BiTree)malloc(sizeof(BiTNode));			 //----solved, in c++, malloc need to be convert to to variable type pointer (dataType*)malloc(sizeof(dataType)), but c don't.
		(*p) -> value = x;								 //            also, c++ has more simple way, new dataType.
		CreateBinaryTree(&((*p) -> left));
		CreateBinaryTree(&((*p) -> right));	
	}
}

//preorder use recursion
void PreOrder(BiTree p) {
	if (p != NULL) {
		cout << p -> value << " ";
		PreOrder(p -> left);
		PreOrder(p -> right);
	}
}

//inorder use recursion
void InOrder(BiTree p) {
	if (p != NULL) {
		InOrder(p -> left);
		cout << p -> value << " ";
		InOrder(p -> right);
	}
}

//postorder use recursion
void PostOrder(BiTree p) {
	if (p != NULL) {
		PostOrder(p -> left);
		PostOrder(p -> right);
		cout << p -> value << " ";
	}
}

//preorder without iterative
void DLR(BiTree p) {
	stack<BiTree> s;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			s.push(p);
			cout << p -> value << " ";
			p = p -> left;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p -> right;
		}
	}
}

//inorder without iterative
void LDR(BiTree p) {
	stack<BiTree> s;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			s.push(p);
			p = p -> left;
		}
		if (!s.empty()) {
			p = s.top();
			cout << p -> value << " ";
			s.pop();
			p = p -> right;
		}
	}
}

//postorder without iterative
void LRD(BiTree p) {						//The key is:  1.visiting a node when the node doesn't have child or its children were all visited
	stack<BiTree> s;					    //		       2.the right child is pushed into the stack before the left so that when top the stack,
	BiTree curNode;							//               the left child come out first
	BiTree preNode = NULL;					//need to be initialized before loop or it will cause the first if true
	s.push(p);								//input the root before the loop
	while (!s.empty()) {
		curNode = s.top();
		//if (the node doesn't have children) or (it has at least a child as prenode), then print the node value.
		//else beacuse I need a LRD order traverse, so first push the right node into stack so that the right node can come out first as it was pushed later. 
		if ((curNode -> left == NULL && curNode -> right == NULL) || (preNode != NULL && (preNode == curNode -> left || preNode == curNode -> right))) { 		
			cout << curNode -> value << " ";
			s.pop();
			preNode = curNode;
		}
		else {
			if (curNode -> right != NULL) {
				s.push(curNode -> right);
				//cout << "push right" << curNode->right->value << " ";
			}
			if (curNode -> left != NULL) {
				s.push(curNode -> left);
				//cout << "push left" << curNode->left->value << " ";
			}
		}
	}
}
//There is another solution that use a struct to save a value to indicate whether the node has been visited or not

int sumOfLeftLeaves(BiTree p) {
	stack<BiTree> s;
	int sum = 0;
	int tag = 0;
	int leftLeave = 0;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			s.push(p);
			if (p -> left != NULL) {
				leftLeave = p -> left -> value;
				tag = 1;
			}
			p = p -> left;
		}

		if (tag == 1 && s.top() -> right == NULL) sum = sum + leftLeave;
		tag = 0;
		leftLeave = 0;
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p -> right;
		}
	}
	return sum;
}

int sumOfrightLeaves(BiTree p) {
	stack<BiTree> s;
	int sum = 0;
	int tag = 0;
	int rightLeave = 0;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			s.push(p);
			if (p -> right != NULL) {
				rightLeave = p -> right -> value;
				tag = 1;
			}
			p = p -> right;
		}

		if (tag == 1 && s.top() -> left == NULL) sum = sum + rightLeave;
		tag = 0;
		rightLeave = 0;
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p -> left;
		}
	}
	return sum;
}

int sumOfLeaves(BiTree p, int *sum) {
	if (p != NULL) {
		if(p -> left == NULL && p -> right == NULL){
			*sum = *sum + p -> value;
		}
		sumOfLeaves(p -> left, sum);
		sumOfLeaves(p -> right, sum);
	}
}

void layerTraverse(BiTree p){
	queue<BiTree> q;
	q.push(p);
	int layer;
	BiTree temp;
	while(!q.empty()){
		temp = q.front();
		if(temp -> left != NULL) q.push(temp -> left);
		if(temp -> right != NULL) q.push(temp -> right);
		printf("%d ", temp -> value);
		q.pop();
	}
}
//There are two methods to count layers:
//1. Use a counter to count down the nodes number of ecah layer
//2. Use a pointer to point to the last nodes of each layer
int howManylayers(BiTree p){								
	/*
	queue<BiTree> q;										
	q.push(p);
	int layer = 0;
	int counter = 0;
	int currnetLayer = 1;
	int nextLayer = 0;
	BiTree temp;
	while(!q.empty()){
		temp = q.front();
		if(temp -> left != NULL){
			q.push(temp -> left);
			nextLayer++;	
		}
		if(temp -> right != NULL){
			q.push(temp -> right);
			nextLayer++;
		}
		counter++;
		q.pop();
		if(counter == currnetLayer){
			layer++;
			currnetLayer = nextLayer;
			counter = 0;
			nextLayer = 0;
		}
	}
	return layer;
	*/
	///*
	queue<BiTree> q;										
	q.push(p);
	int layer = 0;
	BiTree temp;
	BiTree lastNodeOfCurrentLayer = p;
	BiTree lastNodeOfNextLayer = NULL;
	while(!q.empty()){
		temp = q.front();
		if(temp -> left != NULL){
			q.push(temp -> left);
			lastNodeOfNextLayer = temp -> left;
		}
		if(temp -> right != NULL){
			q.push(temp -> right);
			lastNodeOfNextLayer = temp -> right;
		}
		if(temp == lastNodeOfCurrentLayer){
			layer++;
			lastNodeOfCurrentLayer = lastNodeOfNextLayer;
			lastNodeOfNextLayer = NULL;
		}
		q.pop();
	}
	return layer;
	//*/	
}

//Use layer traverse to print a tree
void printCompleteTree(BiTree p){
	//display control
	int layer = howManylayers(p);
	int width = pow(2, layer) - 1;
	int outsideWidth = (width - 1) / 2;
	int insideWidth = 0;
	int count = 0;
	int layerNode = 1;
	int flag = 0;
	int i;
	int slashControl;

	queue<BiTree> q;
	queue<int> buffer;										

	q.push(p);
	int counter = 0;
	int currnetLayer = 1;
	BiTree temp;
	while(!q.empty()){
		temp = q.front();
		if(temp -> left != NULL){
			q.push(temp -> left);
		}
		if(temp -> right != NULL){
			q.push(temp -> right);
		}
		counter++;
		buffer.push(temp -> value);
		if(counter == currnetLayer){
			currnetLayer = currnetLayer * 2;
			counter = 0;
		}
		q.pop();
	}

	while(!buffer.empty()){
		if(flag == 0){
			for(i = 0; i != outsideWidth; i++){
				cout << "   ";
			}
			flag = 1;
		}

		cout << ' ' << buffer.front() << ' ';
		buffer.pop();
		count++;

		if(count == layerNode){
			for(i = 0; i != outsideWidth; i++){
				cout << "   ";
			}
			insideWidth = outsideWidth;
			outsideWidth = (outsideWidth - 1) / 2;
			layerNode = layerNode * 2;
			count = 0;
			flag = 0;
			cout << endl;
			cout << endl;
		}
		else{
			for(i = 0; i != insideWidth; i++){
				cout << "   ";
			}
		}
	}
}




