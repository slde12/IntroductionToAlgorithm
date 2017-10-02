 //Last modify: Chen, 2017-06-18 23:39:50
 public class DLListLauncher{
 	public static void main(String[] args){
 		DoubleLinkedList a = new DoubleLinkedList();
 		a.AddLast(1);
 		a.AddFirst(2);
 		a.AddLast(3);
 		a.PrintList();
 		DLNode p = a.ReturnNode(2);
 		System.out.println(p.value);
 		System.out.println(a.GetSize());
 		a.Insert(10, p);
 		System.out.println(a.GetSize());
 		a.PrintList();
 		a.Insert(4, 1);
 		a.PrintList();
 		System.out.println(a.GetSize());
 		System.out.println(p.value);
 		a.Remove(p);
 		a.PrintList();
 		p = a.ReturnNode(2);
 		System.out.println(p.value);
 		p = p.next;
 		System.out.println(p.value);
 		a.Remove(p);
 		a.PrintList();
 		System.out.println(a.GetSize());
 		p = a.ReturnNode(3);
 		System.out.println(p.value);
 		a.Remove(3);
 		a.PrintList();

 	}
 }