public class Dog{
	public int weight;
	public Dog(int w){
		weight = w;
	}
	public void makeNoise(){
		if(weight < 10){
			System.out.println("aoaoaoaoaooooo!");
		}
		if(weight < 20){
			System.out.println("wowowowwooooo");
		}
		else{
			System.out.println("BARK BAAAAAARK!");
		}
	}
}