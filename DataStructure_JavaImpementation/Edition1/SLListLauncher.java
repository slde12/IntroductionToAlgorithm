//Last modify: Chen, 2017-06-18 13:24:46
public class SLListLauncher{
	public static void main(String[] args){
		LinkedList a = new LinkedList();
		a.AddFirst(10);
		System.out.println(a.GetSize());
		a.AddFirst(1);
		System.out.println(a.GetSize());
		a.AddLast(20);
		System.out.println(a.GetSize());
		System.out.println(a.GetFirst());
		a.PrintList();
		a.AddLast(12);
		a.AddLast(3);
		a.AddLast(5);
		a.AddLast(7);
		a.PrintList();
		a.DeleteNode(10);
		a.PrintList();
		a.DeleteNode(3);
		a.PrintList();
		a.DeletePosition(3);
		a.PrintList();
		a.InsertPosition(1, 5);
		a.PrintList();


	}
}