//Last modify: Chen, 2017-06-18 15:06:33
public class LLStackLauncher{
	//need to test the code everytimes it been changed, cause the suppresswarning
	//can make compiler ignore every warning and error
	@SuppressWarnings("unchecked")
	public static void main(String[] args){
		LNode f = new LNode(1, null);
		LNode b = new LNode(2, f);
		LNode c = new LNode(3, b);
		LNode d = new LNode(4, c);
		LNode e = new LNode(5, d);


		LinkedListStack<LNode> a = new LinkedListStack<LNode>(f);
		//System.out.println(a.GetTop().Get());
		a.Push(b);
		//System.out.println(a.GetTop().Get());
		a.Push(c);
		//System.out.println(a.GetTop().Get());
		//a.PrintStack();
		//System.out.println(a.GetTop());
		a.Push(d);
		a.Push(e);
		//a.PrintStack();

		//Oh no, it seems generic method can only hold different types of data, 
		//but lost the type 
		//LNode p = a.Pop();
		System.out.println(a.Pop().Get());
		System.out.println(a.GetSize());
		System.out.println(a.IsEmpty());
		//a.PrintStack();
		//System.out.println(a.GetTop().Get());
		a.Pop();
		//a.PrintStack();
		//System.out.println(a.GetTop().Get());
		//a.PrintStack();
		a.Pop();
		//System.out.println(a.GetTop().Get());
		a.Pop();
		//a.PrintStack();
		a.Pop();
		System.out.println(a.IsEmpty());
	}
}
