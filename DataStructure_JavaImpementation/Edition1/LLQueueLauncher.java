//Last modify: Chen, 2017-06-18 15:41:07
public class LLQueueLauncher{
	public static void main(String[] args){
		LinkedListQueue q = new LinkedListQueue(0);
		q.Enqueue(1);
		q.Enqueue(2);
		q.PrintQueue();
		System.out.println(q.GetTop());
		q.Enqueue(3);
		q.Enqueue(4);
		System.out.println(q.GetTop());
		q.PrintQueue();
		System.out.println(q.GetSize());
		System.out.println(q.IsEmpty());
		q.Dequeue();
		q.Dequeue();
		q.PrintQueue();
		q.Dequeue();
		q.Dequeue();
		q.PrintQueue();
		q.Dequeue();
		System.out.println(q.IsEmpty());
	}
}