package buoi1;

import java.util.Scanner;

public class Cau5 {
	
	public static void Ptbac1() {
		Scanner sc = new Scanner(System.in);
		double a, b, x;
		System.out.println("Nhap 2 tham so a va b:");
		a = sc.nextDouble();
		b = sc.nextDouble();
		if(a == 0){
			System.out.println("Phuong tring vo nghiem.");
		}
		else{
			x = -b/a;
			System.out.println("Phuong tring co nghiem x ="+x);	
		}
		
		
	}
	public static void Ptbac2() {
		Scanner sc = new Scanner(System.in);
		double a, b, c, delta, x;
		System.out.println("Nhap tham so a, b va c:");
		a = sc.nextDouble();
		b = sc.nextDouble();
		c = sc.nextDouble();
		if(a == 0){
			x = -c/b;
		}
		else{
			delta  = b*b - 4*a*c;
			if(delta==0){
				System.out.println("Phuong trinh co nghiem: "+ (-b/(2*a)));
			}
			else if(delta>0){
				System.out.println("Phuong trinh co 2 nghiem: " + "\nx1 = "+ ((-b+Math.sqrt(delta))/(2*a)) + "\nx2 =" + ((-b-Math.sqrt(delta))/(2*a)));
			}
			else{
				System.out.println("Phuong trinh vo nghiem");
			}
		}
		
		
	}
	public static void main(String[] args) {
		Cau5 giaipt = new Cau5();
		giaipt.Ptbac1();
		giaipt.Ptbac2();
	}
}
