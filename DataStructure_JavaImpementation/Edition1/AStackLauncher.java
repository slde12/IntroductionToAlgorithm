//Last modify: Chen, 2017-06-18 13:24:51
public class AStackLauncher{
	public static void main(String[] args){
		ArrayStack a = new ArrayStack(5);
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
		System.out.println(a.IsEmpty());
	}
}
