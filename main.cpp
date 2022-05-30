#include "DoHoa.h"
#include "Constant.h"
#include "sstream"
using namespace std; 




int thoiGian = 200;   //  thoi gian chay 
void hoanDoiSoNguyen(int &soNguyen1,int &soNguyen2); 
void sapXepTangDan(int *arr,int soLuongPhanTu);
void sapXepGiamDan(int *arr,int soLuongPhanTu);
int soPhanTuKhacKhong(int *arr,int soLuongPhanTu);
void veXaNgang();
void veNhieuDia(int *diaCotX,int toaDoXCot,int soDia);
void veCot(int toaDoX,int soDia);
void khoiTaoGiaoDien(int *diaCotA,int toaDoXCotA,int toaDoXCotB,int toaDoXCotC,int soDia);
void veDia(int toaDoX,int toaDoY,int banKinh);
void xoaDia(int toaDoX,int toaDoY,int banKinh);
void diChuyenDia(int toaDoCotDau,int soDiaCotDau,int toaDoCotSau,int soDiaCotSau,int banKinhDiaTrenCung);
int A,C; 
void thapHaNoi(int n,int soLuongDia,int toaDoXCotA,int *diaCotA,int toaDoXCotB,int *diaCotB,int toaDoXCotC,int *diaCotC, string strA,string strB, string strC); 
string intToString(int n); 

int main() 
{
	int soDia; 
	nhapDia(soDia);	
	StartBGI start; 
	settextstyle(10,0,1); 
	string strsoDia = "So Dia : " + intToString(soDia); 
	outtextxy(410,30,(char*)strsoDia.c_str()); 
	int *diaCotA = new int[soDia];
	int *diaCotB = new int[soDia]; 
	int *diaCotC = new int[soDia]; 
	khoiTaoBanKinhDiaCotACotBCotC(diaCotA,diaCotB,diaCotC,soDia);
	khoiTaoGiaoDien(diaCotA,TOADO_X_COT_A,TOADO_X_COT_B,TOADO_X_COT_C,soDia);
	thapHaNoi(soDia,soDia,TOADO_X_COT_A,diaCotA,TOADO_X_COT_B,diaCotB,TOADO_X_COT_C,diaCotC,"A","B","C"); 	
	delete []diaCotA;delete[]diaCotB;delete []diaCotC; 
	MessageBox(NULL, "Hoan Thanh", "Thong Bao!", MB_ICONINFORMATION | MB_OK);
	getch(); 
	closegraph();
	return 0; 
}

string intToString(int n) 
{
	stringstream ss; 
	ss << n; 
	string s; 
	ss >> s; 
	return s;
}


void hoanDoiSoNguyen(int &soNguyen1,int &soNguyen2) {
	int intTemp =soNguyen1;
	soNguyen1 = soNguyen2;
	soNguyen2 = intTemp;
}

void sapXepTangDan(int *arr,int soLuongPhanTu) {
	for (int i = 0; i < soLuongPhanTu - 1;i++) {
		for (int j = i + 1;j < soLuongPhanTu;j++) {
			if (arr[i] > arr[j]) {
				hoanDoiSoNguyen(arr[i],arr[j]); 
			}
			
		}
	}
}


void sapXepGiamDan(int *arr,int soLuongPhanTu) {
	for (int i = 0; i < soLuongPhanTu - 1;i++) {
		for (int j = i + 1;j < soLuongPhanTu;j++) {
			if (arr[i] < arr[j]) {
				hoanDoiSoNguyen(arr[i],arr[j]); 
			}
			
		}
	}
}



int soPhanTuKhacKhong(int *arr,int soLuongPhanTu) 
{
	int demSoLuongPhanTuKhacKhong = 0; 
	for (int i = 0; i < soLuongPhanTu;i++) {
		if (arr[i] != 0) {
			demSoLuongPhanTuKhacKhong++; 
		}
	}
	return demSoLuongPhanTuKhacKhong; 
}




void veXaNgang() {
	setfillstyle(SOLID_FILL, COLOR_XA_NGANG); 
	bar(TOADO_X_THANH_XA_NGANG, TOADO_Y_THANH_XA_NGANG, TOADO_X_THANH_XA_NGANG + CHIEU_DAI_THANH_XA_NGANG, 
	TOADO_Y_THANH_XA_NGANG + CHIEU_CAO_THANH_XA_NGANG);
	setbkcolor(COLOR_BACKGROUP); 
	settextstyle(10,0,2); 
	setcolor(14);
	outtextxy(TOADO_X_COT_A - 20,TOADO_Y_THANH_XA_NGANG + 30,(char*)"COT A"); 
	outtextxy(TOADO_X_COT_B -20,TOADO_Y_THANH_XA_NGANG + 30,(char*)"COT B"); 
	outtextxy(TOADO_X_COT_C - 20,TOADO_Y_THANH_XA_NGANG + 30,(char*)"COT C"); 
}


void veNhieuDia(int *diaCotX,int toaDoXCot,int soDia) 
{
	int temp = soDia;
	for (int i = 0; i < soDia;i++) {
		int viTriXDia =  toaDoXCot - diaCotX[i] + 10;   
		setfillstyle(SOLID_FILL, COLOR_DIA); 
	 	bar (viTriXDia,TOA_DO_Y_COT - temp*CHIEU_CAO_DIA + KHOAN_CACH_DIA,viTriXDia + diaCotX[i]*2,TOA_DO_Y_COT - temp*CHIEU_CAO_DIA + CHIEU_CAO_DIA); 
		temp--;
	}
}


void veCot(int toaDoX,int soDia) {
	setfillstyle(SOLID_FILL, COLOR_COT); 
	bar(toaDoX,TOA_DO_Y_COT - soDia * CHIEU_CAO_DIA,toaDoX + CHIEU_NGANG_COT,DINH_COT); 
}


void khoiTaoGiaoDien(int *diaCotA,int toaDoXCotA,int toaDoXCotB,int toaDoXCotC,int soDia) {
	veXaNgang();   
	veNhieuDia(diaCotA,toaDoXCotA,soDia); 
	veCot(toaDoXCotA,soDia);
	veCot(toaDoXCotB,0);   
	veCot(toaDoXCotC,0); 
}




void veDia(int toaDoX,int toaDoY,int banKinh) {
	setfillstyle(SOLID_FILL, COLOR_DIA); // bo bua.
	bar(toaDoX,toaDoY ,toaDoX + banKinh * 2,toaDoY - CHIEU_CAO_DIA + KHOAN_CACH_DIA); // ta dan tinh tu duoi nen -> nen phai ve the nay ! 
} 


void xoaDia(int toaDoX,int toaDoY,int banKinh) {
	setfillstyle(SOLID_FILL, COLOR_BACKGROUP); // bo bua.
	bar(toaDoX,toaDoY,toaDoX + banKinh * 2,toaDoY - CHIEU_CAO_DIA - KHOAN_CACH_DIA); 
}



// toi uu hoa ham di chuyen... 
// viet ham su ly trung tam dieu khien 
void dieuKhienTocDo(NutBam &tangThoiGian,NutBam &giamThoiGian)
{
	int xclick,yclick; 
	if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (tangThoiGian.isMouseHover(xclick,yclick)) {
				if (thoiGian > 10) {  // tang thoi gian len -> mieng la 
					thoiGian = thoiGian - 50; 
				}
			}
			else if (giamThoiGian.isMouseHover(xclick,yclick)) {
				if (thoiGian <= 300) {
					thoiGian = thoiGian + 50; // g
				}
			}
		}
}

void diChuyenDia(int toaDoCotDau,int soDiaCotDau,int toaDoCotSau,int soDiaCotSau,int banKinhDiaTrenCung) {
	NutBam tieuDe(368,50,200,40,COLOR_BACKGROUP,14,"DIEU KHIEN TOC DO"); 
	tieuDe.veNut(); 
	NutBam tangThoiGian(356 + 144,100,100,40,15,0,"TANG"); 
	tangThoiGian.veNut(); 
	NutBam giamThoiGian(340 ,100,100,40,15,0,"GIAM"); 
	giamThoiGian.veNut();
	int toaDoXDiaTrenCung = toaDoCotDau - banKinhDiaTrenCung +10;    //   lay ra toa do X cua dia tren cung cua cot dau 
	int i; 
	for (i = soDiaCotDau - 1; i < TOI_DA_DIA;i++) 
	{ 
	veDia(toaDoXDiaTrenCung,TOA_DO_Y_COT - i*CHIEU_CAO_DIA,banKinhDiaTrenCung); 
	delay(thoiGian);
	xoaDia(toaDoXDiaTrenCung,TOA_DO_Y_COT - i*CHIEU_CAO_DIA,banKinhDiaTrenCung );
	veCot(toaDoCotDau,soDiaCotDau - 1);   //  ve lai tru sau khi xoa khi vua xoa dia
	dieuKhienTocDo(tangThoiGian,giamThoiGian);

	}
	veDia(toaDoXDiaTrenCung,TOA_DO_Y_COT - i*CHIEU_CAO_DIA,banKinhDiaTrenCung); 
	if (toaDoCotDau - toaDoCotSau < 0) {   //  chung to 1 dieu cot truoc nam truoc cot sua !
		int doDaiDiChuyenDia = toaDoCotSau - toaDoCotDau; 
		int soLanDiChuyen = doDaiDiChuyenDia / (banKinhDiaTrenCung * 2); 
		int j; 
		for (j = 0; j < soLanDiChuyen;j++) {
			veDia(toaDoXDiaTrenCung + j*banKinhDiaTrenCung*2,TOA_DO_Y_COT - i*CHIEU_CAO_DIA,banKinhDiaTrenCung); 
			delay(thoiGian);
			xoaDia(toaDoXDiaTrenCung + j*banKinhDiaTrenCung*2,TOA_DO_Y_COT - i*CHIEU_CAO_DIA,banKinhDiaTrenCung); 
			dieuKhienTocDo(tangThoiGian,giamThoiGian);
		}
	}
	else {
		int doDaiDiChuyenDia = toaDoCotDau - toaDoCotSau;  
		int soLanDiChuyen = doDaiDiChuyenDia / (banKinhDiaTrenCung * 2); 	
		int j; 
		for (j = 0; j < soLanDiChuyen;j++) {
			veDia(toaDoXDiaTrenCung - j*banKinhDiaTrenCung*2,TOA_DO_Y_COT - i*CHIEU_CAO_DIA,banKinhDiaTrenCung); 
			delay(thoiGian);
			xoaDia(toaDoXDiaTrenCung - j*banKinhDiaTrenCung*2,TOA_DO_Y_COT - i*CHIEU_CAO_DIA,banKinhDiaTrenCung); 
			dieuKhienTocDo(tangThoiGian,giamThoiGian);
		}
	}

	int toaDoDiaCotDauSoVoiCotSau = toaDoCotSau - banKinhDiaTrenCung + 10;  
	veDia(toaDoDiaCotDauSoVoiCotSau,TOA_DO_Y_COT - i*CHIEU_CAO_DIA,banKinhDiaTrenCung); 
	int toaDoDiaTrenCungCotSau = TOADO_Y_THANH_XA_NGANG - (soDiaCotSau * CHIEU_CAO_DIA); 
	int toaDoDiaTrenCungcotTruoc = TOA_DO_Y_COT - i*CHIEU_CAO_DIA; 
	int soLanLap = (toaDoDiaTrenCungCotSau - toaDoDiaTrenCungcotTruoc) / CHIEU_CAO_DIA; 
	int k;
	for ( k = 0;k < soLanLap;k++) 
	{
		veDia(toaDoDiaCotDauSoVoiCotSau,toaDoDiaTrenCungcotTruoc + k*CHIEU_CAO_DIA,banKinhDiaTrenCung); 
		delay(thoiGian); 
		xoaDia(toaDoDiaCotDauSoVoiCotSau,toaDoDiaTrenCungcotTruoc + k*CHIEU_CAO_DIA + KHOAN_CACH_DIA,banKinhDiaTrenCung); 
	 	veCot(toaDoCotSau,soDiaCotSau); 
	 	dieuKhienTocDo(tangThoiGian,giamThoiGian);
	}
	xoaDia(toaDoDiaCotDauSoVoiCotSau,toaDoDiaTrenCungcotTruoc + k*CHIEU_CAO_DIA + KHOAN_CACH_DIA,banKinhDiaTrenCung); 
	veDia(toaDoDiaCotDauSoVoiCotSau,toaDoDiaTrenCungcotTruoc + k*CHIEU_CAO_DIA,banKinhDiaTrenCung); 
}

void thapHaNoi(int n,int soLuongDia,int toaDoXCotA,int *diaCotA,int toaDoXCotB,int *diaCotB,int toaDoXCotC,int *diaCotC, string strA,string strB, string strC) {
	if (n == 1) {
		cout << strA << "->" << strC << endl; 
		sapXepTangDan(diaCotA,soLuongDia);  
		sapXepGiamDan(diaCotC,soLuongDia);   
		for (int i = 0;i < soLuongDia;i++) {  // vong lap dung de lay ra cai dia nao do khac 0
			if (diaCotA[i] != 0) {
				A = i; 
				break; 
			}
			A = 0;    // dia nay con khong con gi ca !
		}

		// di chuyen luon dia so 0 
		for(int i = 0;i < soLuongDia;i++) {
			if (diaCotC[i] != 0) {
				C = i; 
				break;
			}
			C = 0; 
		}
		
		// lay ra dia tren cung cua no 
		int soDiaCotA = soPhanTuKhacKhong(diaCotA,soLuongDia); 
		int soDiaCotC = soPhanTuKhacKhong(diaCotC,soLuongDia); 

		diChuyenDia(toaDoXCotA,soDiaCotA,toaDoXCotC,soDiaCotC,diaCotA[A]);   // bo vao A vi no la cai dia tren cung 
	
		for (int i = C; i < soLuongDia;i++)
		{
			if (diaCotC[i] == 0) {
				hoanDoiSoNguyen(diaCotA[A],diaCotC[i]); 
				break; 
			}
		}
		diaCotA[A] = 0; 
	}
	else {
		thapHaNoi(n-1,soLuongDia,toaDoXCotA,diaCotA,toaDoXCotC,diaCotC,toaDoXCotB,diaCotB,strA,strC,strB);
		thapHaNoi(1,soLuongDia,toaDoXCotA,diaCotA,toaDoXCotB,diaCotB,toaDoXCotC,diaCotC,strA,strB,strC);
		thapHaNoi(n-1,soLuongDia,toaDoXCotB,diaCotB,toaDoXCotA,diaCotA,toaDoXCotC,diaCotC,strB,strA,strC);
		
	}
}
