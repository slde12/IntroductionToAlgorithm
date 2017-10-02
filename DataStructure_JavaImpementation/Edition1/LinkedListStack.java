//
//Last modify: Chen, 2017-06-18 14:19:22
/*NOTES

*/
public class LinkedListStack{
	private LNode sentinel;
	private int size;

	public LinkedListStack(){
		size = 0;
		sentinel = new LNode(-1, null);
	}

	public LinkedListStack(int x){
		size = 0;
		sentinel = new LNode(-1, null);
		sentinel.next = new LNode(x, sentinel.next);
		size += 1;
	}

	public void Push(int x){
		sentinel.next = new LNode(x, sentinel.next);
		size += 1;
	}

	public void Clear(){
		sentinel.next = null;
		size = 0;
	}

	public int GetTop(){
		return sentinel.next.value;
	}

	public int Pop(){
		int temp = sentinel.next.value;
		sentinel.next = sentinel.next.next;
		size -= 1;
		return temp;
	}

	public int GetSize(){
		return this.size;
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
		LNode p = sentinel;
		while(p.next != null){
			System.out.print(p.next.value + " ");
			p = p.next;
		}
		System.out.println();
	}



}