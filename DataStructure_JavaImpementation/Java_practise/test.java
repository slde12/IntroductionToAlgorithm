import java.util.Scanner;


public class test{
	
	public static void vech(){
		System.out.println("test");
	}

	public static void main(String[] args){
		String str="dsds 213 23.43";
		Scanner sc = new Scanner(str);
		System.out.println(sc.next());
		System.out.println(sc.nextInt());
		System.out.println(sc.nextFloat());
		//test n = new test();
		test.vech();

		abc t = new abc();
		t.print();

	}
}