public class BinaryTree{
	public class Node{
		public BTNode data;
		public Node next;
		public Node(BTNode d, Node n){
			data = d;
			next = n;
		} 
	}
	public class LLStack{
		private Node sentinel;
		private int size;

		public LLStack(){
			size = 0;
			sentinel = new Node(null, null);
		}

		public LLStack(BTNode x){
			size = 0;
			sentinel = new Node(null, null);
			sentinel.next = new Node(x, sentinel.next);
			size += 1;
		}

		public void Push(BTNode x){
			sentinel.next = new Node(x, sentinel.next);
			size += 1;
		}

		public void Clear(){
			sentinel.next = null;
			size = 0;
		}

		public BTNode GetTop(){
			return sentinel.next.data;
		}

		public BTNode Pop(){
			BTNode temp = sentinel.next.data;
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
	}
	//Not a good idea to make a public root, just accomplish the function first
	public BTNode root;
	//Constructor
	public BinaryTree(int data){
		root = new BTNode(null, data, null);
	}
	
	public BTNode AddNode(BTNode parent, int data, char LeftOrRight){
		if(LeftOrRight == 'L'){
			parent.left = new BTNode(null, data, null);
			return parent.left;
		}
		if(LeftOrRight == 'R'){
			parent.right = new BTNode(null, data, null);
			return parent.right;
		}
		return null;
	}

	/*Preorder use recursion*/
	public void PreOrder(BTNode p){
		if(p != null){
			//manipulation on the current node
			System.out.print(p.data + " ");
			PreOrder(p.left);
			PreOrder(p.right);
		}
	}

	/*Pnorder use recursion*/
	public void InOrder(BTNode p) {
		if (p != null) {
			InOrder(p.left);
			System.out.print(p.data + " ");
			InOrder(p.right);
		}
	}
	
	/*Postorder use recursion*/
	public void PostOrder(BTNode p) {
		if (p != null) {
			PostOrder(p.left);
			PostOrder(p.right);
			System.out.print(p.data + " ");
		}
	}

	//preorder without recursion
	void DLR(BTNode p) {
		LLStack s = new LLStack();
		while (p != null || !s.IsEmpty()) {
			while (p != null) {
				s.Push(p);
				System.out.print(p.data + " ");
				p = p.left;
			}
			if (!s.IsEmpty()) {
				//p = s.GetTop();
				p = s.Pop();
				p = p.right;
			}
		}
	}

	//inorder without recursion
	void LDR(BTNode p) {
		LLStack s = new LLStack();
		while (p != null || !s.IsEmpty()) {
			while (p != null) {
				s.Push(p);
				p = p.left;
			}
			if (!s.IsEmpty()) {
				p = s.GetTop();
				System.out.print(p.data + " ");
				s.Pop();
				p = p.right;
			}
		}
	}

	/*postorder without recursion*/
	/**The key is:  1.visiting a node when the node doesn't have child or its children were
	  *               all visited.
	  *		        2.the right child is pushed into the stack before the left so that when
	  *               top the stack, the left child come out first.*/
	void LRD(BTNode p) {									
		LLStack s = new LLStack();			
		BTNode curNode;										
		//need to be initialized before loop or it will cause the first if true
		BTNode preNode = null;								
		//input the root before the loop
		s.Push(p);											
		while (!s.IsEmpty()) {
			curNode = s.GetTop();
			//if (the node doesn't have children) or (it has at least a child as prenode), then print the node value.
			//else beacuse I need a LRD order traverse, so first push the right node into stack so that the right node can come out first as it was pushed later. 
			if ((curNode.left == null && curNode.right == null) || (preNode != null && (preNode == curNode.left || preNode == curNode.right))) { 		
				System.out.print(curNode.data + " ");
				s.Pop();
				preNode = curNode;
			}
			else {
				if (curNode.right != null) {
					s.Push(curNode.right);
					//cout << "push right" << curNode->right->value << " ";
				}
				if (curNode.left != null) {
					s.Push(curNode.left);
					//cout << "push left" << curNode->left->value << " ";
				}
			}
		}
	}


}