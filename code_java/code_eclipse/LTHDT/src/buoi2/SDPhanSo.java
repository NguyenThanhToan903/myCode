package buoi2;

public class SDPhanSo {

	public static void main(String[] args) {
		PhanSo a = new PhanSo(3,7);
		PhanSo b = new PhanSo(4,9);
		PhanSo x = new PhanSo();
		PhanSo y = new PhanSo();
		PhanSo T = new PhanSo();
		
		a.hienThiPhanSo();
		b.hienThiPhanSo();
		x.nhapPhanSo();
		x.hienThiPhanSo();
		y.nhapPhanSo();
		y.hienThiPhanSo();
		T = x.giaTriNghichDao();
		T.hienThiPhanSo();
		T = x.cong(y);
		T.hienThiPhanSo();
		T = x.tru(y);
		T.hienThiPhanSo();
		

	}

}
