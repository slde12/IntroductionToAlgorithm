//
//Last modify: Chen, 2017-06-18 15:26:41
/*NOTES

*/
public class LinkedListQueue{

	private LNode sentinel;
	private int size;

	public LinkedListQueue(){
		size = 0;
		sentinel = new LNode(-1, null);
	}

	public LinkedListQueue(int x){
		size = 0;
		sentinel = new LNode(-1, null);
		sentinel.next = new LNode(x, sentinel.next);
		size += 1;
	}

	public void Enqueue(int x){
		LNode p = sentinel;
		while(p.next != null){
			p = p.next;
		}
		p.next = new LNode(x, p.next);
		size += 1;
	}

	public void Clear(){
		sentinel.next = null;
		size = 0;
	}

	public int GetTop(){
		return sentinel.next.value;
	}

	public int Dequeue(){
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

	public void PrintQueue(){
		LNode p = sentinel;
		while(p.next != null){
			System.out.print(p.next.value + " ");
			p = p.next;
		}
		System.out.println();
	}



}