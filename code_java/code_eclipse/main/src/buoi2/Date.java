package buoi2;

import java.security.PublicKey;
import java.util.Scanner;

public class Date {
	private int d, m, y;
	public Date() {
		d = 1;
		m = 1;
		y = 2023;
	}
	public int  Date(int d1, int m1, int y1) {
		d = d1;
		m = m1;
		y = y1;
	}
	public void in() {
		System.out.println(d+"/"+m+"/"+y);
	}
	public void nhap() {
		Scanner sc = new Scanner(System.in);
		d = sc.nextInt();
	}
	do {
		System.out.println("Nhap ngay");
		d = sc
	} while(!void hle());
	public boolean hle() {
		int max[] = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
		if(n)
	}
}
