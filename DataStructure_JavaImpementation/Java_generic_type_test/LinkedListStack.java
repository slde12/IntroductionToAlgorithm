//
//Last modify: Chen, 2017-06-19 19:06:54
/*NOTES

*/

//need to test the code everytimes it been changed, cause the suppresswarning
//can make compiler ignore every warning and error
@SuppressWarnings("unchecked")

public class LinkedListStack<T>{
	private LNode<T> sentinel;
	private int size;

	public LinkedListStack(){
		size = 0;
		sentinel = new LNode<T>(null, null);
	}

	public LinkedListStack(T x){
		size = 0;
		sentinel = new LNode<T>(null, null);
		sentinel.Set(new LNode<T>(x, sentinel.Next()));
		size += 1;
	}

	public void Push(T x){
		sentinel.Set(new LNode<T>(x, sentinel.Next()));
		size += 1;
	}

	public void Clear(){
		sentinel.Set(null, null);
		size = 0;
	}

	public T GetTop(){
		return (T)sentinel.Next().Get();
	}

	public T Pop(){
		T temp = (T)sentinel.Next().Get();
		sentinel.Set(sentinel.Next().Next());
		size -= 1;
		return temp;
	}

	public int GetSize(){
		return size;
	}

	public boolean IsEmpty(){
		if(size == 0){
			return true;
		}
		else{
			return false;
		}
	}

	public void PrintStack(){
		LNode<T> p = sentinel;
		while(p.Next() != null){
			System.out.print((T)p.Next().Get());
			p = p.Next();
		}
		System.out.println();
	}



}