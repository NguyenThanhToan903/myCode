package buoi2;

import java.util.Scanner;

public class PhanSo{
	private int x, y;
	public PhanSo() {
		x = 0;
		y = 1;
	}
	public PhanSo(int tu, int mau) {
		x = tu;
		y = mau;
	}
	public void nhapPhanSo() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap x:");
		x = sc.nextInt();
		do{
		System.out.println("Nhap y:");
		y = sc.nextInt();
		}while(y==0);
		if(y<0){ x = -x; y = - y;}
	}
	public void hienThiPhanSo() {
		if(x==0)System.out.println("0");
		else if(y==1)System.out.println(x);
		else System.out.println(+x+"/"+y);
	}
	public void nghichDao() {
		int temp;
		if(x!=0){
			temp = x;
			x = y;
			y = temp;
		} else {
			System.out.println("X = 0 : Khong nghich dao duoc!!");
		}
	}
	public PhanSo giaTriNghichDao() {
		PhanSo T = new PhanSo();
		if(x!=0){
			T.y = x;
			T.x = y;
		} else {
			System.out.println("X = 0 : Khong nghich dao duoc!!");
		}
		return T;
	}
	public float giaTriThuc() {
		return (float) x/y;
	}
	public boolean lonHon(PhanSo a) {
		return (x/y)>(a.x/a.y);
	}
	public int UCLN(int a, int b) {
		if(a<0)a-=a;
		while(a!=b){
			if(a>b) a-=b;
			else b-=a;
		}
		return a;
	}
	public PhanSo phanSoToiGian(PhanSo T) {
		int ucln = UCLN(T.x, T.y);
		T.x /= ucln;
		T.y /= ucln;
		return T;
	}
	
	public PhanSo cong(PhanSo a) {
		int tuSo, mauSo;
		tuSo = x*a.y+y*a.x;
		mauSo = y*a.y;
		PhanSo Tong = new PhanSo(tuSo, mauSo);
		Tong = phanSoToiGian(Tong);
		System.out.println("Tong hai phan so = "+Tong.x+"/"+Tong.y);
		return Tong;
	}
	public PhanSo tru(PhanSo a) {
		int tuSo, mauSo;
		tuSo = x*a.y-y*a.x;
		mauSo = y*a.y;
		PhanSo Hieu = new PhanSo(tuSo, mauSo);
		Hieu = phanSoToiGian(Hieu);
		System.out.println("Hieu hai phan so = "+Hieu.x+"/"+Hieu.y);
		return Hieu;
	}
	public PhanSo nhan(PhanSo a) {
		int tuSo, mauSo;
		tuSo = x*a.x;
		mauSo = y*a.y;
		PhanSo Tong = new PhanSo(tuSo, mauSo);
		Tong = phanSoToiGian(Tong);
		System.out.println("Tich hai phan so = "+Tong.x+"/"+Tong.y);
		return Tong;
	}
	public PhanSo chia(PhanSo a) {
		int tuSo, mauSo;
		tuSo = x*a.y;
		mauSo = y*a.x;
		PhanSo Tong = new PhanSo(tuSo, mauSo);
		Tong = phanSoToiGian(Tong);
		System.out.println("Thuong hai phan so = "+Tong.x+"/"+Tong.y);
		return Tong;
	}
	
	
}
