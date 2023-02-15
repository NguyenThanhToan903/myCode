package buoi1;

import java.util.Scanner;

public class Cau8 {
	Scanner sc = new Scanner(System.in);
	int ds[];
	public void nhapDS() {
		int i, n;
		System.out.println("Nhap so phan tu:");
		n = sc.nextInt();
		ds = new int[n];
		for(i = 0; i < n; i++){
			System.out.println("Nhap phan tu thu ("+ i +"): ");
			ds[i] = sc.nextInt();
		}
	}
	public void in() {
		for(int i: ds){
			System.out.print(i +" ");
		}
		System.out.println("");
	}
	public int kiemtra(int k) {
		int count=0, i;
		for(i=0; i<ds.length; i++){
			if(ds[i] == k){
				count++;
			}
		}
		return count;
	}
	public void sort() {
		int i, j, tmp;
		for(i=0; i<ds.length-1; i++){
			for(j=i+1; j<ds.length; j++){
				if(ds[i]>ds[j]){
					tmp = ds[j];
					ds[j]=ds[i];
					ds[i]=tmp;
				}
			}
		}
	}
	public static void main(String[] args) {
		Cau8 danh_sach = new Cau8();
		danh_sach.nhapDS();
		
		Scanner sc = new Scanner(System.in);
		int x;
		x = sc.nextInt();
		System.out.println("Danh sach co "+danh_sach.kiemtra(x)+" phan tu " + x);
		danh_sach.sort();
		System.out.println("Danh sach da sap xep: ");
		danh_sach.in();
	}
}
