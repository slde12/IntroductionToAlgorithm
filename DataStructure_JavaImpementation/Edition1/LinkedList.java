/**/
/*Last modify: Chen, 2017-06-17 15:59:54*/
/**NOTES
  *The first data structure written in Java, using "Pass by value" is really interesting,
  *still having some problems about "this" and the recursion manipulation, such as using
  *recursion to get list size.
  *
  **/

public class LinkedList{
	
	private LNode sentinel;
	private int size;

	public LinkedList(){
		size = 0;
		sentinel = new LNode(-1, null);
	}
	
	public LinkedList(int x){
		size = 0;
		sentinel = new LNode(-1, null);
		sentinel.next = new LNode(x ,sentinel.next);
		size += 1;
	}

	/**Add a node in the head*/
	public void AddFirst(int x){
		sentinel.next = new LNode(x, sentinel.next);
		size += 1;
	}

	/**Add a node in the last*/
	public void AddLast(int x){
		LNode p = sentinel;
		while(p.next != null){
			p = p.next;
		}
		p.next = new LNode(x, p.next);
		size += 1;
	}

	/**Get size of the list*/
	public int GetSize(){
		/*Have no idea the difference between this.size and size*/
		return this.size;
	}

	public int GetFirst(){
		return sentinel.next.value;
	}

	/**Delete the first matching node by key*/
	public boolean DeleteNode(int x){
		LNode p = sentinel;
		while(p.next.value != x){
			p = p.next;
		}
		if(p.next.value == x){
			p.next = p.next.next;
			return true;
		}
		/*return delete fail information*/
		else{
			return false;
		}
	}

	/**Delete the node by position*/
	public boolean DeletePosition(int x){
		LNode p = sentinel;
		/*Pay attention to the position, the first node is a sentinel*/
		int i = 1;
		while(i < x){
			p = p.next;
			i += 1;
		}
		/*Delete success*/
		if(p.next != null){
			p.next = p.next.next;
			return true;
		}
		/*Delete fail*/
		else{
			return false;
		}
	}

	/**Insert the node by position*/
	public void InsertPosition(int position, int x){
		LNode p = sentinel;
		/*Pay attention to the position, the first node is a sentinel*/
		int i = 1;
		while(i < position){
			p = p.next;
			i += 1;
		}
		p.next = new LNode(x, p.next);
	}

	/**Iteration manipultaion*/
	public int GetSize_iteration(){
		LNode p = sentinel;
		int size = 0;
		while(p.next != null){
			size += 1;
		}
		return size;
	}
	/**Iteration manipulation*/
	public void PrintList(){
		LNode p = sentinel;
		while(p.next != null){
			System.out.print(p.next.value + " " + "->" + " ");
			p = p.next;
		}
		System.out.println("null");
	}

	/*Recursion manipulation
	public int GetSize_recursion(){
		if(sentinel.next == null){
			return 0;
		}
		else{
			
		}
	}
	*/

}