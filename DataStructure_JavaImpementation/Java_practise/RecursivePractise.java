public class RecursivePractise{
	public static class Node{
		private int data;
		private Node next;
		public Node(int d, Node n){
			this.data = d;
			this.next = n;
		}
	}

	public static int Recursive(Node head){
		int sum;
		if(head == null){
			return 0;
		}
		sum = Recursive(head.next);
		
		if(sum == -1 || head.data == sum){
			return -1;
		}else{
			return head.data + sum;
		}
	}

	public static void main(String[] args){
		/*
		Node a = new Node(1, null);
		Node b = new Node(1, null);
		Node c = new Node(1, null);
		Node d = new Node(1, null);
		Node e = new Node(1, null);
		*/
		Node f = new Node(1, null);
		Node g = new Node(2, f);
		Node h = new Node(1, g);
		Node i = new Node(4, h);
		Node j = new Node(1, i);
		Node k = new Node(3, j);
		Node l = new Node(20, k);

		int result = Recursive(l);
		System.out.println(result);


	}
}