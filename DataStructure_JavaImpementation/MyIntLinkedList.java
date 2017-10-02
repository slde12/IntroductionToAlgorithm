import java.lang.*;
import java.util.*;

class Node {

  // Constructor.
  public Node(int data) {
    this.data = data;
  }

  public int data;
  public Node next;
}

public class MyIntLinkedList {

    private Node head;
    private Node tail;

    // Insert data in sorted order.
    public void add(int data) {
      Node temp = new Node(data);

      // Base case: The list is empty.
      if(head == null) head = tail = temp;

      // Base case: Element goes in the front.
      else if (data <= head.data) {
        temp.next = this.head;
        this.head = temp;
      }

      // Base case: Element goes in the back.
      else if (tail.data <= data) {
        this.tail.next = temp;
        this.tail = temp;
      }

      // Base case: Element goes in the middle of the list.
      else {
        Node curr = head;
        while(curr.next.data <= data) {
          curr = curr.next;
        }
        temp.next = curr.next;
        curr.next = temp;
      }
    }

    public boolean remove(int data) {

      // Base case: The list is empty.
      if(head == null) return false;

      // Base case: The list has one element.
      if(head == tail && head.data == data) {
        head = tail = null;
        return true;
      }

      // Base case: The element to remove is at the head.
      if(head.data == data) {
        head = head.next;
        return true;
      }

      // The element to remove is anywhere else.
      for(Node curr = head; curr.next != null; curr = curr.next) {
        if(curr.next.data == data) {
          curr.next = curr.next.next;
          return true;
        }
      }

      // The element isn't found.
      return false;
    }

    public void print() {
      // Base case: The list is empty.
      if(head == null) return;

      for(Node curr = head; curr != null; curr = curr.next)
        System.out.print(curr.data + " ");
      System.out.println();
    }

    public static void main(String[] args) {

      MyIntLinkedList list = new MyIntLinkedList();
      list.add(11);
      list.add(7);
      list.add(9);
      list.add(2);
      list.add(32);
      list.add(3);
      list.print();
    }
}
