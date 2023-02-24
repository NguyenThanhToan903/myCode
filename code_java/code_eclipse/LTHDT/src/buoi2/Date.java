package buoi2;

import java.util.Scanner;


public class Date {
	private int d, m, y;
	int max[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	public Date() {
		d=1;
		m=1;
		y=2023;
	}
	public  Date(int d1,int m1, int y1) {
		d = d1;
		m = m1;
		y = y1;
	}
	
	public void nhapDate() {
		Scanner sc = new Scanner(System.in);
		do{
			System.out.println("Nhap ngay:");
			d = sc.nextInt();
			System.out.println("Nhap thang:");
			m = sc.nextInt();
			System.out.println("Nhap nam:");
			y = sc.nextInt();
			
			
		}while (!hople());
	}
	public boolean hople(){
		boolean h = false;
		if(nhuan()){
			max[2] = 29;
		}
		if(y>0 && (m>0 && m<13) && (d>0 && d<= max[m])){
			h = true;
		}
		return h;
	}
	public boolean nhuan() {
		return ((y %4==0)&&(y%100 != 0))||(y%400==0);
	}
	public void hienThi() {
		System.out.println(d+"/"+m+"/"+y);
	}
	public Date ngayHomSau() {
		Date n = new Date(d, m, y);
		n.d++;
		if(n.d>max[n.m]){
			n.d = 1;
			n.m++;
			if(n.m>12){
				n.m = 1;
				n.y++;
				if(n.nhuan())max[2] = 29;
				else max[2]=28;
			}
		}
		return n;
	}
	public Date ngayHomSau(int x) {
		Date n = new Date(d, m ,y);
		for(int i = 0; i<x; i++){
			n = n.ngayHomSau();
		}
		return n;
	}
	
}
