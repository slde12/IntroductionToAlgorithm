public class LNode<T>{
	private T data;
	private LNode next;
	//@SuppressWarnings("Unchecked")
	
	public LNode(T d, LNode n){
		this.data = d;
		this.next = n;
	} 

	/**Return the data through a function*/
	public T Get(){
		return this.data;
	}

	/**Set the node, data, next or data and next*/
	public void Set(T d){
		this.data = d;
	}
	public void Set(LNode n){
		this.next = n;
	}
	public void Set(T d, LNode n){
		this.data = d;
		this.next = n;
	}

	public LNode Next(){
		return next;
	}
}