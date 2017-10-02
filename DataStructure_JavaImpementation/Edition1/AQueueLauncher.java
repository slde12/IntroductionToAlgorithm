//Last modify: Chen, 2017-06-18 19:14:37
public class AQueueLauncher{
	public static void main(String[] args){
		ArrayQueue q = new ArrayQueue(5);
		System.out.println(q.IsFull());
		System.out.println(q.IsEmpty());
		q.Enqueue(1);
		q.Enqueue(2);
		q.Enqueue(3);
		q.Enqueue(4);
		q.Enqueue(5);
		q.PrintQueue();
		System.out.println(q.IsEmpty());
		System.out.println(q.IsFull());
		System.out.println(q.GetFront());
		System.out.println(q.Enqueue(6));
		System.out.println(q.GetSize());
		q.Dequeue();
		System.out.println(q.GetSize());
		System.out.println(q.Enqueue(6));
		System.out.println(q.GetFront());
		q.PrintQueue();
		q.Dequeue();
		q.Dequeue();
		q.Dequeue();
		q.Dequeue();
		q.Dequeue();
		q.PrintQueue();
		System.out.println(q.Dequeue());
		System.out.println(q.GetSize());
	}
}