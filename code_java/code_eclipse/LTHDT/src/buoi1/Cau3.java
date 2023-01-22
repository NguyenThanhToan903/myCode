package buoi1;

public class Cau3 {
	public static void main(String[] args) {
		double s=0, n, max = Float.MIN_VALUE;
		for(String e: args){
			try{n = Float.parseFloat(e);}
			catch(NumberFormatException x){
				n=0.0;
			}
			s+=n;
			if(n>max){
				max = n;
			}
		}
		System.out.println("Tong: "+ s);
		System.out.println("max = " + max);
	}
}
