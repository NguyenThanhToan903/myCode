package buoi2;

public class SDDiem {

	public static void main(String[] args) {
		Diem A = new Diem(3,4);
		A.hienThi();
		Diem B = new Diem();
		B.nhapDiem();
		B.hienThi();
		int x1 = -B.giaTriX();
		int y1 = -B.giaTriY();
		Diem C = new Diem(x1, y1);
		C.hienThi();
		System.out.print("Khoang cach BO la:"); System.out.format("%.2f%n", B.khoangCach());
		System.out.print("Khoang cach AB la:"); System.out.format("%.2f", A.khoangCach(B));
	}
}
