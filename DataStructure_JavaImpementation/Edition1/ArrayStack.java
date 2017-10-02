//
//Last modify: Chen, 2017-06-18 12:39:22
/*NOTES
 **/
public class ArrayStack{
	/*How to control the type of the stack just like vector<int> in c++*/
	private int stackArray[];
	//Does this syntax do the same thing as "define DEFAULTSIZE 10" in C++?  
	private static final int DEFAULTSIZE = 10;
	private int MaxSize;
	//Is it necessary to make a increasement to stack size when it is full?
	//private int INCREASEMENT = 10;
	private int top;

	//Why do I need to tell the compiler to ignore these kind of warning
	@SuppressWarnings("unchecked")
	ArrayStack(int size){
		MaxSize = size;
		top = 0;
		//Try to make a array of E type
		//Similar to the method in C++, (type*)malloc(sizeof(type)), but
		//not sure about the function of "Object" here.
		stackArray = new int[size];
	}
	/*Make a default size of array*/
	ArrayStack(){
		//ArrayStack(DEFAULTSIZE);
		this(DEFAULTSIZE);
	}

	/*Initialize the array*/
	public void Clear(){
		top = 0;
	}

	/*Push the element to the top of the stack*/
	public boolean Push(int x){
		if(top >= MaxSize){
			return false;
		}
		stackArray[top] = x;
		top ++;
		return true;
	}

	/*Return the top element of the stack*/
	public int GetTop(){
		if(top == 0){
			//The first time I see "return null" syntax in java 
			//return null;
			//Indicate that there is no top element.
			return -9999;
		}
		return stackArray[top - 1];
	}

	/*Pop the top element of the stack*/
	public int Pop(){
		if(top == 0){
			//return null;
			//Indicate that there is no top element.
			return -9999;
		}
		top --;
		return stackArray[top];
		
	}

	/*Check the stack is empty or not*/
	public boolean IsEmpty(){
		if(top == 0){
			return true;
		}
		else{
			return false;
		}
	}

	/*Get the current element numbers of the stack*/
	public int GetSize(){
		return top;
	}

	/*Print the statement of the stack*/
	public void PrintStack(){
		int i = top;
		//Cannot compare i to boolean?
		while(i > 0){
			System.out.print(stackArray[--i] + " ");
		}
		System.out.println();
	}
}