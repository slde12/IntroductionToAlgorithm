import java.lang.*;
import java.util.*;

class Node<T extends Comparable<T>> {

  // Constructor.
  public Node(T data) {
    this.data = data;
  }

  public T data;
  public Node<T> next;
}

public class GenericLinkedList<T extends Comparable<T>> {

    private Node<T> head;
    private Node<T> tail;

    // Insert data in sorted order.
    public void add(T data) {
      Node<T> temp = new Node<T>(data);

      // Base case: The list is empty.
      if(head == null) head = tail = temp;

      // Base case: Element goes in the front.
      else if (head.data.compareTo(data) >= 0) {
        temp.next = this.head;
        this.head = temp;
      }

      // Base case: Element goes in the back.
      else if (tail.data.compareTo(data) <= 0) {
        this.tail.next = temp;
        this.tail = temp;
      }

      // Base case: Element goes in the middle of the list.
      else {
        Node<T> curr = head;
        while(curr.next.data.compareTo(data) <= 0) {
          curr = curr.next;
        }
        temp.next = curr.next;
        curr.next = temp;
      }
    }

    public T remove(T data) {

      // Base case: The list is empty.
      if(head == null) return null;

      // Base case: The list has one element.
      if(head == tail && head.data.equals(data)) {
        T result = head.data;
        head = tail = null;
        return result;
      }

      // Base case: The element to remove is at the head.
      if(head.data.equals(data)) {
        T result = head.data;
        head = head.next;
        return result;
      }

      // The element to remove is anywhere else.
      for(Node<T> curr = head; curr.next != null; curr = curr.next) {
        if(curr.next.data.equals(data)) {
          T result = curr.next.data;
          curr.next = curr.next.next;
          return result;
        }
      }

      // The element isn't found.
      return null;
    }

    public void print() {
      // Base case: The list is empty.
      if(head == null) return;

      for(Node<T> curr = head; curr != null; curr = curr.next)
        System.out.print(curr.data.toString() + " ");
      System.out.println();
    }

    public static void main(String[] args) {

      // Example: Stronger type checks.
      /*LinkedList ll = new LinkedList();
      ll.add(new Integer(11));
      String eleven = (String) ll.get(0);*/

      // Example: Fewer casts:
      /*LinkedList ll = new LinkedList();
      ll.add("eleven");
      String eleven = (String) ll.get(0);*/

      // Versus:
      /*LinkedList ll = new LinkedList();
      ll.add("eleven");
      String eleven = (String) ll.get(0);*/

      // Example: Inserting & removing Strings.
      GenericLinkedList<String> list = new GenericLinkedList<>();
      list.add("zebra");
      list.add("cow");
      list.add("aardvark");
      list.add("orangutan");
      list.add("elephant");
      list.print();
      list.remove("orangutan");
      list.print();
      list.remove("aardvark");
      list.print();
      list.remove("zebra");
      list.print();
      list.remove("elephant");
      list.print();
    }
}
