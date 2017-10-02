//Last modify: Chen, 2017-06-18 15:06:33
public class LLStackLauncher{
	public static void main(String[] args){
		LinkedListStack a = new LinkedListStack(5);
		a.Push(1);
		a.Push(2);
		a.PrintStack();
		System.out.println(a.GetTop());
		a.Push(3);
		a.Push(4);
		System.out.println(a.GetTop());
		a.PrintStack();
		System.out.println(a.GetSize());
		System.out.println(a.IsEmpty());
		a.Pop();
		a.Pop();
		a.PrintStack();
		a.Pop();
		a.Pop();
		a.PrintStack();
		a.Pop();
		System.out.println(a.IsEmpty());
	}
}
