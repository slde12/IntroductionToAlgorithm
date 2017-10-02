public class DrawTriangle{
	public static void Draw(int n){
		int i, j;
		for(i = 0; i < n; i++){
			for(j = n - i - 1; j < n; j++){
	 			System.out.print("*");
			}
			System.out.println();
		}		
	}

	public static void main(String[] args){
		DrawTriangle.Draw(10);
	}
}