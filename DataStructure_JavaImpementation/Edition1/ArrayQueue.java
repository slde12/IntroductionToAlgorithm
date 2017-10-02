//
//Last modify: Chen, 2017-06-18 17:29:47
/**NOTES
 *
 **/
public class ArrayQueue{
	private int QueueArray[];
	private static final int DEFAULTSIZE = 10;
	private int MaxSize;
	private int front;
	private int rear;

	public ArrayQueue(int size){
		MaxSize = size + 1;
		QueueArray = new int[MaxSize];
		front = -1;
		rear = -1;
	}

	public ArrayQueue(){
		this(DEFAULTSIZE);
	}

	public boolean IsEmpty(){
		return(front == rear);
	}

	public boolean IsFull(){
		if((rear + 1 - front) % MaxSize == 0) return true;
		else return false;
	}

	public int GetSize(){
		if(this.IsEmpty() == true) return 0;
		if(front < rear) return rear - front;
		else return rear + MaxSize - front;
	}

	public int GetFront(){
		return QueueArray[front];
	}
	
	public void Clear(){
		front = -1;
		rear = -1;
	}

	public boolean Enqueue(int x){
		if(this.IsFull() == true){
			return false;
		}
		else if(front == -1){
			front += 1;
			rear = front + 1;
			QueueArray[front] = x;
			return true;
		}
		else{
			QueueArray[rear] = x;
			rear = (rear + 1) % (MaxSize);
			return true;
		}
	}

	public boolean Dequeue(){
		if(this.IsEmpty() == true){
			return false;
		}
		else{
			front = (front + 1) % MaxSize;
			return true;
		}
	}

	public void PrintQueue(){
		int i;
		for(i = front; i % MaxSize != rear; i++){
			System.out.print(QueueArray[i]);
		}
		System.out.println();
	}

}