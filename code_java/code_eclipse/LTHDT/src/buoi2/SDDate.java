package buoi2;

import java.util.Scanner;

public class SDDate {

	public static void main(String[] args) {
		Date day = new Date();
		Scanner sc = new Scanner(System.in);
		day.nhapDate();
		day.hienThi();
		day=day.ngayHomSau();
		day.hienThi();
		int x;
		System.out.println("Nhap so ngay:");
		x = sc.nextInt();
		day=day.ngayHomSau(x);
		day.hienThi();

	}

}
