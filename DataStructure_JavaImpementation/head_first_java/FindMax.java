public class FindMax{
	public static int max(int[] n){
		int size = n.length;
		int bigger = -1;
		int i;
		for(i = 0; i < size; i++){
			if(n[i] >= bigger){
				bigger = n[i];
			}
		}
		return bigger;
	}

	public static void main(String[] args){
		int[] numbers = new int[]{4, 3, 2, 4, 5, 76, 87, 6, 5, 45, 4};
		System.out.println(FindMax.max(numbers));
	}
}