//
//Last modify: Chen, 2017-06-24 15:13:41
/*NOTES

*/
public class RBTNode<T>{
	private T data;
	//"RED" represent red, "BLACK" represent black
	private String color;
	private RBTNode parent;
	private RBTNode lchild;
	private RBTNode rchild;

	public RBTNode(T d, RBTNode p, RBTNode l, RBTNode r){
		this.data = d;
		this.parent = p;
		this.lchild = l;
		this.rchild = r;
	}
	//Set root node
	public RBTNode(T d){
		this.data = d;
		this.parent = null;
		this.lchild = null;
		this.rchild = null;
	}
	public RBTNode(){
		this.data = null;
		this.parent = null;
		this.lchild = null;
		this.rchild = null;
	}

	public void SetData(T d){
		this.data = d;
	}

	public void Setparent(RBTNode p){
		this.parent = p;
	}

	public void Setleft(RBTNode l){
		this.lchild = l;
	}

	public void Setright(RBTNode r){
		this.rchild = r;
	}

	public void Setcolor(String c){
		this.color = c;
	}
	public T Get(){
		return this.data;
	}

	public RBTNode Getleft(){
		return this.lchild;
	}

	public RBTNode Getright(){
		return this.rchild;
	}

	public RBTNode Getparent(){
		return this.parent;
	}

	//'>' return true, else return false
	public boolean compareTo(RBTNode<T> x){
		return true;
	}

	public String Getcolor(){
		return this.color;
	}
}