//
//Last modify: Chen, 2017-06-18 23:39:58
/*NOTES

*/
public class DoubleLinkedList{
	private DLNode sentinel;
	private int size;

	/**Constructor*/
	public DoubleLinkedList(){
		sentinel = new DLNode(null, -1, null);
		size = 0;
	}
	public DoubleLinkedList(int x){
		sentinel = new DLNode(null, -1, null);
		sentinel.next = new DLNode(sentinel, x, sentinel.next);
		size = 1;	
	}

	public int GetSize(){
		return size;
	}

	public void AddFirst(int x){
		sentinel.next = new DLNode(sentinel, x, sentinel.next);
		sentinel.next.next.pre = sentinel.next; 
		size += 1;
	}

	public void AddLast(int x){
		DLNode p = sentinel;
		while(p.next != null){
			p = p.next;
		}
		p.next = new DLNode(p, x, p.next);		
		size += 1;
	}

	public DLNode ReturnNode(int position){
		int i = 0;
		DLNode p = sentinel;
		while(i < position && p != null){
			p = p.next;
			i += 1;
		}
		if(i < position) return null;
		return p;
	}

	/**Remove node by position or node*/
	public boolean Remove(int position){
		DLNode p = ReturnNode(position);
		if(p == null) return false;
		p.pre.next = p.next;
		//Deal with the node if it is the last node
		if(p.next == null) return true;
		p.next.pre = p.pre;
		size -= 1;
		return true;
	}
	public boolean Remove(DLNode p){
		if(p == null) return false;
		p.pre.next = p.next;
		//Deal with the node if it is the last node
		if(p.next == null) return true;
		p.next.pre = p.pre;
		size -= 1;
		return true;
	}

	/**Insert node by position or node*/
	public boolean Insert(int x, int position){
		DLNode p = ReturnNode(position);
		if(p == null) return false;
		p.pre.next = new DLNode(p.pre, x, p);
		p.pre = p.pre.next;
		size += 1;
		return true;
	}
	public boolean Insert(int x, DLNode p){
		if(p == null) return false;
		p.pre.next = new DLNode(p.pre, x, p);
		p.pre = p.pre.next;
		size += 1;
		return true;
	}

	public void PrintList(){
		DLNode p = sentinel;
		while(p.next != null){
			System.out.print(p.next.value + " " + "<->" + " ");
			p = p.next;
		}
		System.out.println("null");
	}	
}