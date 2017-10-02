public class BTreeLauncher{
	public static void main(String[] args){
		BinaryTree T = new BinaryTree(1);
		BTNode p = T.AddNode(T.root, 2, 'L');
		BTNode q = T.AddNode(T.root, 3, 'R');
		T.AddNode(p, 4, 'L');
		T.AddNode(p, 5, 'R');
		T.AddNode(q, 6, 'R');
		T.AddNode(q, 6, 'L');


		T.DLR(T.root);
	}
}