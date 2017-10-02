//Last modify: Chen, 2017-06-18 23:40:17
public class DLNode{
	public int value;
	public DLNode pre;
	public DLNode next;
	public DLNode(DLNode p, int v, DLNode n){
		value = v;
		pre = p;
		next = n;
	}
}