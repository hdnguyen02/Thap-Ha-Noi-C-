#include<graphics.h>

#include<iostream>
#include<sstream>
#include <string>
using namespace std; 


string intToString(int n) {
	stringstream ss; 
	ss << n; 
	string s; 
	ss >> s; 
	return s; 
}


using namespace std; 

class StartBGI
{
public:
	StartBGI()
	{
		int y = GetSystemMetrics(SM_CYSCREEN);
		int x = GetSystemMetrics(SM_CXSCREEN);
		initwindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) - 40);
	}
	~StartBGI()
	{
		closegraph();
	}
};


// dinh nghia 1 vai bien sau
// bien ve thoi gian
const int THOIGIAN = 100;  // tinh theo ms giay 
const int CHIEUCAOCOT = 500; // chieu cao cua cay cot 
const int TOADOYCOT = 690;  
// tiep theo khai bao ra nhung toa do cua chiec cot  
const int TOADOXCOTA = 300; 
const int TOADOXCOTB = 760;
const int TOADOXCOTC = 1200; 


// dinh nghia 1 vai key 
const int KEYUP = 72; 
const int KEYDOWN = 80; 
const int ESC = 27; 


const int COLOR_BACKGROUP = 0; 

const int BANKINHDIA = 10; 
// viet ham ve ra cai cot ne ! 

// dat ra toa do nen  
const int TOADOXTHANHXANGANG = 156; 
const int TOADOYTHANHXANGANG = 700;
const int CHIEUCAOTHANHXANGANG = 16; 
const int CHIEUDAITHANHXANGANG = 1200; 
const int KHOANCACHDIA = 2; // khoan cach giua cac dia 
const int CHIEU_NGANG_COT = 20; 

// viet ham ve ra cai dang cot 


const int soDia = 5; // gia su co 4 dia di

const int CHIEUCAODIA = 30; // chieu cao cua cai dia 
// tinh ra so dia toi da cua 1 cay chua duoc 
const int TOI_DA_DIA = CHIEUCAOCOT / CHIEUCAODIA; 



// viet ham xoa chan cot

void xoaChanCot(int x,int soDia) {
	int chieuCaoXoa = soDia*CHIEUCAODIA + soDia * KHOANCACHDIA;
	setfillstyle(SOLID_FILL, COLOR_BACKGROUP); // bo bua
	bar (x - 10,TOADOYCOT,x + CHIEU_NGANG_COT,TOADOYCOT - soDia * CHIEUCAODIA); 
	
}


// viet ham hoan doi

void hoanDoiSoNguyen(int soNguyen1,int soNguyen2) {
	int intTemp =soNguyen1;; // nam du ho vung dia chi 
	soNguyen1 = soNguyen2;
	soNguyen2 = intTemp;
}

// viet ham so sanh giam gian 
void sapXepTangDan(int *arr,int soLuongPhanTu) {
	for (int i = 0; i < soLuongPhanTu - 1;i++) {
		for (int j = i + 1;j < soLuongPhanTu;j++) {
			if (arr[i] > arr[j]) {
				// hoan doi tai cho nay 
				hoanDoiSoNguyen(arr[i],arr[j]); 
			}
			
		}
	}
}


void sapXepGiamDan(int *arr,int soLuongPhanTu) {
	for (int i = 0; i < soLuongPhanTu - 1;i++) {
		for (int j = i + 1;j < soLuongPhanTu;j++) {
			if (arr[i] < arr[j]) {
				// hoan doi tai cho nay 
				hoanDoiSoNguyen(arr[i],arr[j]); 
			}
			
		}
	}
}

// viet them ham dem so luong 0 

int soPhanTuKhacKhong(int *arr,int soLuongPhanTu) 
{
	// dem xem
	int demSoLuongPhanTuKhacKhong = 0; 
	for (int i = 0; i < soLuongPhanTu;i++) {
		if (arr[i] != 0) {
			demSoLuongPhanTuKhacKhong++; 
		}
	}
	return demSoLuongPhanTuKhacKhong; 
}




void veThanhNgangVaTieuDe() {
	setfillstyle(SOLID_FILL, 14); // bo bua.
	bar(TOADOXTHANHXANGANG, TOADOYTHANHXANGANG, TOADOXTHANHXANGANG + CHIEUDAITHANHXANGANG, TOADOYTHANHXANGANG + CHIEUCAOTHANHXANGANG);
	setbkcolor(COLOR_BACKGROUP); 
	//settextstyle(10,0,2); 
	outtextxy(TOADOXCOTA,TOADOYTHANHXANGANG + 30,(char*)"COT A"); 
	outtextxy(TOADOXCOTA + 600,TOADOYTHANHXANGANG + 30,(char*)"COT B"); 
	outtextxy(TOADOXCOTA + 1000,TOADOYTHANHXANGANG + 30,(char*)"COT C"); 
}


// ve ham in cot 

void veCotThayThe() {
	
}

void veCot(int toaDoXCot,int toaDoYCot) {
	setfillstyle(SOLID_FILL, 11); // bo bua.
	bar(toaDoXCot, toaDoYCot, toaDoXCot + CHIEU_NGANG_COT,CHIEUCAOCOT - toaDoYCot); // thong so thu 3 la thong so chieu cao -> ta ve chieu cao tuy thuoc 
	// tiep tuc hien thi ra -> 
	
}

// toa do X la noi se ve ra cai dia -> 
//toa do Y la dung tinh theo 

void veDia(int toaDoX,int toaDoY,int banKinh) {
	setfillstyle(SOLID_FILL, 14); // bo bua.
	bar(toaDoX,toaDoY ,toaDoX + banKinh * 2,toaDoY - CHIEUCAODIA); // ta dan tinh tu duoi nen -> nen phai ve the nay ! 
} 


void xoaDia(int toaDoX,int toaDoY,int banKinh) {
	setfillstyle(SOLID_FILL, COLOR_BACKGROUP); // bo bua.
	bar(toaDoX,toaDoY,toaDoX + banKinh * 2,toaDoY - CHIEUCAODIA); 
}


void diChuyenDia(int toaDoCotDau,int soDiaCotDau,int toaDoCotSau,int soDiaCotSau,int banKinhDiaTrenCung) {
	int toaDoXDiaTrenCung = toaDoCotDau - banKinhDiaTrenCung +10; 
	
	
	int i; 
	// ve lai cai cot dau tien ne 
	// veCot(toaDoCotDau,TOADOYCOT); 
	
	// chung bi du 
	
	
	// cai ham nay dung de di chuyen tu cot cai dia tren cung cua cot dau tien sang cot phia sau 
	// so dia cot dau tuc la vi tri cai dia tren cung ay. banKinhCotDau chinh la cai ban kinh cua cai 
	
	// cho cai dia duy chuyen nhe 
	
	// vong lap nay dung de lap cai chi ! 
	
	// dung de ve ra cai nat dia -> dua vao chieu cao tinh tu cai cot kie tro di 
	
	// tinh bang cach nao => chi can biet duoc -> so dia tren cung lay chieu cao * so Dia  
	
	// tinh ra so dia toi da tren cot 
	
	// tinh nhu sau : vi tri bac dau ve se la vi tri 
	
	
	for (i = soDiaCotDau; i < TOI_DA_DIA;i++) 
	{
	veDia(toaDoXDiaTrenCung,TOADOYCOT - i*CHIEUCAODIA,banKinhDiaTrenCung); 
	
	// sau khi ve song xoa di dia truoc do 
	delay(200);
	// sau khi ve thi xoa de len cai dia -> thuat toan xoa dia nhu sau 
	// ta dung chieu cao lam 1 don vi
	// tiep theo la  
	xoaDia(toaDoXDiaTrenCung,TOADOYCOT - i*CHIEUCAODIA,banKinhDiaTrenCung );
	// ve lai cai cot 
	veCot(toaDoCotDau,TOADOYCOT - soDiaCotDau * CHIEUCAODIA); 
	
	
	}
	
	
}



int main() {
	StartBGI start; 
	
	// khai bao ra 3 cai mang chua dia chi cua tui no  
	int *diaCotA = new int[soDia];
	int *diaCotB = new int[soDia]; 
	int *diaCotC = new int[soDia]; 
	

	for (int i = 0; i < soDia;i++) {
		diaCotB[i] = 0; 
		diaCotC[i] = 0; 
		diaCotA[i] = BANKINHDIA * 2 * i + 20;    //  20 la do dai cua cai dia tren cung  
	}
	veThanhNgangVaTieuDe(); 
	
	
	int soDiaTam = soDia; 
	
		veCot(TOADOXCOTA,TOADOYCOT);   // ve ra cai true A  
		
		xoaChanCot(TOADOXCOTA,soDia); // ve ra va xoa chan tru di so voi so dia 
		 
		
	// ve ra so dia cua cot A  
	// ve ra so dia =>> nen viet 1 ham ve dia ra 
	
	for (int i = 0; i < soDia;i++) {
		// tinh ra vi tri x bac dau ve ra 
		int viTriXDia =  TOADOXCOTA - diaCotA[i] + 10; 
		setfillstyle(SOLID_FILL, 10); // bo bua.
	 	bar (viTriXDia,TOADOYCOT - soDiaTam*CHIEUCAODIA + KHOANCACHDIA,viTriXDia + diaCotA[i]*2,TOADOYCOT - soDiaTam*CHIEUCAODIA + CHIEUCAODIA); 
		soDiaTam--;
	}
	
	
	// ve ra tru A va tru B 
	veCot(TOADOXCOTB,TOADOYCOT);   
	veCot(TOADOXCOTC,TOADOYCOT); 
	
	// dem ra so luong dia cua cot A  
	int soDiaCotA = soPhanTuKhacKhong(diaCotA,soDia); 
	
	 diChuyenDia(TOADOXCOTA,soDiaCotA,TOADOXCOTC,0,diaCotA[0]);  // a[0] la dia tren cung  
	 
	
	
	
	// giai phong di
	delete []diaCotA; 
	delete []diaCotB;
	delete []diaCotC; 
	
	
	
	getch(); 
	// tiep tuc ve ra 
	
}
