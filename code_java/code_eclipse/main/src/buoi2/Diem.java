package buoi2;

import java.util.Scanner;

public class Diem {
	private int x;
	private int y;
	public Diem() {
		x = 0;
		y = 0;
	}
	public Diem(int x1, int y1) {
		x = x1;
		y = y1;
	}
	public void gan(int x1, int y1) {
		x = x1;
		y = y1;
	}
	public void in() {
		System.out.println("("+x+","+y+")");
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap tu ban phim x");
		x = sc.nextInt();
		System.out.println("Nhap tu ban phim y");
		y = sc.nextInt();
	}
	public void ttien(int dx, int dy) {
		x += dx;
		y += dy;
	}
	public int  longX() {
		return x;
	}
	public int  longY() {
		return y;
	}
	public float kcach() {
		return (float) Math.sqrt(x*x + y*y);
	}
	public float Kcach(Diem B) {
		return (float) Math.sqrt(Math.pow(x - B.x, 2)+Math.pow(y-B.y, 2));
	}
	public class SSDiem{
		public static void main(String args[]) {
			Diem a = new Diem(5,3);
			a.in();
			Diem b = new Diem();
			b.nhap();
			b.in();
			System.out.println("Tinh tien b mot khoang (6,9)");
			b.ttien(6, 9);
			b.in();
			System.out.println("Khoang cach B -> 0");
			b.kcach();
			System.out.println("Trung diem AB"+b.kcach());
		}
	}
}
