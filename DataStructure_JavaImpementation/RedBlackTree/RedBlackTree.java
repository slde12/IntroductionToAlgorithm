//
//Last modify: Chen, 2017-06-24 16:49:13
/*NOTES

*/
public class RedBlackTree<T>{
	private RBTNode<T> root;
	private RBTNode<T> nil = null;

	public RedBlackTree(){
		root = new RBTNode<T>();
		root.Setparent(this.nil);
		root.Setright(this.nil);
		root.Setleft(this.nil);
	}
	public RedBlackTree(T data){
		root = new RBTNode<T>(data);
		root.Setparent(this.nil);
		root.Setright(this.nil);
		root.Setleft(this.nil);
	}
	public void SetRoot(RBTNode<T> x){
		root.SetData(x.Get());
		root.Setleft(x.Getleft());
		root.Setright(x.Getright());
	}

	public void LeftRotate(RedBlackTree<T> t, RBTNode<T> x){
		RBTNode<T> y = x.Getleft();
		//Deal with the relationship between x and y's subtrees
		x.Setright(y.Getleft()); 
		if(y.Getleft() != t.nil){
			y.Getleft().Setparent(x);
		}
		//Deal with the relationship between y and x's parent
		y.Setparent(x.Getparent());
		if(x.Getparent() == t.nil){
			t.SetRoot(y);
		}
		else if(x == x.Getparent().Getright()){
			x.Getparent().Setright(y);
		}
		else{
			x.Getparent().Setleft(y);
		}
		//Deal with the relationship between x and y
		y.Setleft(x);
		x.Setparent(y);
	}

	public void RightRotate(RedBlackTree<T> t, RBTNode<T> x){
		RBTNode<T> y = x.Getright();
		//Deal with the relationship between x and y's subtrees
		x.Setleft(y.Getright()); 
		if(y.Getright() != t.nil){
			y.Getright().Setparent(x);
		}
		//Deal with the relationship between y and x's parent
		y.Setparent(x.Getparent());
		if(x.Getparent() == t.nil){
			t.SetRoot(y);
		}
		else if(x == x.Getparent().Getleft()){
			x.Getparent().Setleft(y);
		}
		else{
			x.Getparent().Setright(y);
		}
		//Deal with the relationship between x and y
		y.Setright(x);
		x.Setparent(y);
	}

	public void RBInsert(RedBlackTree<T> t, RBTNode<T> z){
		RBTNode<T> y = t.nil;
		RBTNode<T> x = t.root;
		//Move to the position where z is inserted
		while(x != t.nil){
			y = x;
			//Need to define compare function in RBTNode class depends on the type
			//'>' return 1, '<' return 0
			if(x.compareTo(z) == false){
				x = x.Getright();
			}
			else{
				x = x.Getleft();
			}
		}
		//Link z to its parent
		z.Setparent(y);
		//Check whether the y is root or not
		if(y == t.nil){
			t.SetRoot(z);
		}
		//Link y to his child
		//Need to define compare function in RBTNode class depends on the type
		//'>' return 1, '<' return 0
		else if(y.compareTo(z) == true){
			y.Setright(z);
		}
		else{
			y.Setleft(z);
		}
		//Set z's child and color, insert node always be red.
		z.Setleft(t.nil);
		z.Setright(t.nil);
		z.Setcolor("RED");
		RBInsertFixup(t, z);
	}

	public void RBInsertFixup(RedBlackTree<T> t, RBTNode<T> z){
		while(z.Getparent().Getcolor() == "RED"){
			//Condition 1, z's parent is a left child
			if(z.Getparent() == z.Getparent().Getparent().Getleft()){
				RBTNode<T> y = z.Getparent().Getparent().Getright();
				//There are two situations of z's parent's parent's right child
				//red or black(equal to not exist)
				//If it is a red node, lower the black layer makes
				//partly balance, then because the original black node becomes a
				//red node, so reset the z to the parent's parent to check if
				//it obey the red-black rule with its parent
				if(y.Getcolor() == "RED"){
					y.Setcolor("BLACK");
					z.Getparent().Setcolor("BLACK");
					z.Getparent().Getparent().Setcolor("RED");
					z = z.Getparent().Getparent();
				}
				//If it is black, then rotate the subtree of z's parent.
				//if z is a right child, rotate its parent left, 
				//makes z a left child,
				//then, reset the node's color and rotate z's parent's parent 
				//right, make a partly balance.
				else{
					if(z == z.Getparent().Getright()){
						z = z.Getparent();
						LeftRotate(t, z);
					}
					z.Getparent().Setcolor("BLACK");
					z.Getparent().Getparent().Setcolor("RED");
					RightRotate(t, z.Getparent().Getparent());
				}
			}
			//Condition 2, z's parent is a right child, the same as before,
			//just exchange left and right.
			else{
				RBTNode<T> y = z.Getparent().Getparent().Getleft();
				if(y.Getcolor() == "RED"){
					y.Setcolor("BLACK");
					z.Getparent().Setcolor("BLACK");
					z.Getparent().Getparent().Setcolor("RED");
					z = z.Getparent().Getparent();
				}
				else{
					if(z == z.Getparent().Getleft()){
						z = z.Getparent();
						RightRotate(t, z);
					}
					z.Getparent().Setcolor("BLACK");
					z.Getparent().Getparent().Setcolor("RED");
					LeftRotate(t, z.Getparent().Getparent());
				}
			}
		}
		t.root.Setcolor("BLACK");
	}

	public void RBTransplant(RedBlackTree<T> t, RBTNode<T> u, RBTNode<T> v){
		if(u.Getparent() == t.nil){
			t.SetRoot(v);
		}
		else if(u == u.Getparent().Getleft()){
			u.Getparent().Setleft(v);
		}
		else{
			u.Getparent().Setright(v);
		}
		v.Setparent(u.Getparent());
	}

	public RBTNode<T> TreeMinimum(RedBlackTree<T> t, RBTNode<T> x){
		while(x.Getleft() != t.nil){
			x = x.Getleft();
		}
		return x;
	}

	public void RBDelete(RedBlackTree<T> t, RBTNode<T> z){
		RBTNode<T> y = z;
		//Use x to record the subtree node(y's original position) need to be fixed 
		//after delete, if y's original color is black,
		//move y to z means lose a black node on its path.
		RBTNode<T> x;
		String yOriginalColor = y.Getcolor();
		if(z.Getleft() == t.nil){
			x = z.Getright();
			RBTransplant(t, z, z.Getright());
		}
		else if(z.Getright() == t.nil){
			x = z.Getleft();
			RBTransplant(t, z, z.Getleft());
		}
		else{
			y = TreeMinimum(t,  z.Getright());
			yOriginalColor = y.Getcolor();
			x = y.Getright();
			//Is it necessary to discuss y is z's child?
			//the else statement seems include the if statement
			//--I think it is not necessary.
			if(y.Getparent() == z){
				x.Setparent(y);
			}
			else{
				RBTransplant(t, y, y.Getright());
				y.Setright(z.Getright());
				y.Getright().Setparent(y); 
			}
			RBTransplant(t, z, y);
			y.Setleft(z.Getleft());
			y.Getleft().Setparent(y);
			y.Setcolor(z.Getcolor());
		}
		if(yOriginalColor == "BLACK"){
			RBdeleteFixup(t, x);
		}
	}

	public void RBdeleteFixup(RedBlackTree<T> t, RBTNode<T> x){
		//I still worry about if x is a nil node, is this condition statement well satisfied
		while(x != t.root && x.Getcolor() == "BLACK"){
			//x is a left child
			if(x == x.Getparent().Getleft()){
				RBTNode<T> w = x.Getparent().Getright();
				//Case 1, convert it to case 2 or 3 or 4
				if(w.Getcolor() == "RED"){
					x.Getparent().Setcolor("RED");
					w.Setcolor("BLACK");
					LeftRotate(t, x.Getparent());
					w = x.Getparent().Getright();
				}
				//Case 2, both of w's children are black, 
				//lower the black level of w, add another black to x's parent,
				//use the while loop to compare the x's parent and its sibliing
				if(w.Getright().Getcolor() == "BLACK" && w.Getleft().Getcolor() == "BLACK"){
					w.Setcolor("RED");
					x = x.Getparent();
				}
				else{
					//Case 3, w's right child is black, convert it to case 4
					if(w.Getright().Getcolor() == "BLACK"){
						w.Getleft().Setcolor("BLACK");
						w.Setcolor("RED");
						RightRotate(t, w);
						w = x.Getparent().Getright();
					}
					//Case 4, w's right child is red
					w.Setcolor(w.Getparent().Getcolor());
					w.Getright().Setcolor("BLACK");
					x.Getparent().Setcolor("BLACK");
					LeftRotate(t, x.Getparent());
					x = t.root;
				}

			}
			//right child condition, exchange the left and right
			else{
				RBTNode<T> w = x.Getparent().Getleft();
				//Case 1, convert it to case 2 or 3 or 4
				if(w.Getcolor() == "RED"){
					x.Getparent().Setcolor("RED");
					w.Setcolor("BLACK");
					RightRotate(t, x.Getparent());
					w = x.Getparent().Getleft();
				}
				//Case 2, both of w's children are black, 
				//lower the black level of w, add another black to x's parent,
				//use the while loop to compare the x's parent and its sibliing
				if(w.Getleft().Getcolor() == "BLACK" && w.Getright().Getcolor() == "BLACK"){
					w.Setcolor("RED");
					x = x.Getparent();
				}
				else{
					//Case 3, w's right child is black, convert it to case 4
					if(w.Getleft().Getcolor() == "BLACK"){
						w.Getright().Setcolor("BLACK");
						w.Setcolor("RED");
						LeftRotate(t, w);
						w = x.Getparent().Getleft();
					}
					//Case 4, w's right child is red
					w.Setcolor(w.Getparent().Getcolor());
					w.Getleft().Setcolor("BLACK");
					x.Getparent().Setcolor("BLACK");
					RightRotate(t, x.Getparent());
					x = t.root;
				}
			}
		}
		x.Setcolor("BLACK");
	}


}