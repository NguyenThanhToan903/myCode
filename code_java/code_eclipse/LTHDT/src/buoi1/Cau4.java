package buoi1;

import java.util.Scanner;

public class Cau4 {
	Scanner sc = new Scanner(System.in);
	public int nhap() {
		String s= "";
		int  n =0;
		do{
			System.out.println("Nhap:");
			s = sc.nextLine();
			try{
				n = Integer.parseInt(s);
			}
			catch(NumberFormatException x){
				n = Integer.MAX_VALUE;
				System.out.println("Nhap lai:");
			}
		}while(n==Integer.MAX_VALUE);
		return n;
	}
	public static void main(String[] args) {
		Cau4 t = new Cau4();
		int a = t.nhap();
		int b = t.nhap();
		System.out.println("Tong: a+b = "+ (a+b));
	}
}
