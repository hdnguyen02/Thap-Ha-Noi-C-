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
const int DINH_COT = 100; // dinh cua cay cot 
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
const int CHIEUCAOCOT = 640;



const int CHIEUCAODIA = 30; // chieu cao cua cai dia 
// tinh ra so dia toi da cua 1 cay chua duoc 
const int TOI_DA_DIA = CHIEUCAOCOT / CHIEUCAODIA; 



// viet ham xoa chan cot



// viet ham hoan doi

void hoanDoiSoNguyen(int &soNguyen1,int &soNguyen2) {
	int intTemp =soNguyen1;// nam du ho vung dia chi 
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

void veCot(int toaDoX,int soDia) {
	setfillstyle(SOLID_FILL, 11); 
	bar(toaDoX,TOADOYCOT - soDia * CHIEUCAODIA,toaDoX + CHIEU_NGANG_COT,DINH_COT); 
}




void veDia(int toaDoX,int toaDoY,int banKinh) {
	setfillstyle(SOLID_FILL, 10); // bo bua.
	bar(toaDoX,toaDoY ,toaDoX + banKinh * 2,toaDoY - CHIEUCAODIA); // ta dan tinh tu duoi nen -> nen phai ve the nay ! 
} 


void xoaDia(int toaDoX,int toaDoY,int banKinh) {
	setfillstyle(SOLID_FILL, COLOR_BACKGROUP); // bo bua.
	bar(toaDoX,toaDoY,toaDoX + banKinh * 2,toaDoY - CHIEUCAODIA); 
}


void diChuyenDia(int toaDoCotDau,int soDiaCotDau,int toaDoCotSau,int soDiaCotSau,int banKinhDiaTrenCung) {
	int toaDoXDiaTrenCung = toaDoCotDau - banKinhDiaTrenCung +10; 
	int i; 
	char c; 
	for (i = soDiaCotDau - 1; i < TOI_DA_DIA;i++) 
	{ 
	veDia(toaDoXDiaTrenCung,TOADOYCOT - i*CHIEUCAODIA,banKinhDiaTrenCung); 
	delay(200);
	xoaDia(toaDoXDiaTrenCung,TOADOYCOT - i*CHIEUCAODIA,banKinhDiaTrenCung );
	veCot(toaDoCotDau,soDiaCotDau - 1); 
	
	if(kbhit()) {
		c = getch();
		cout << c << endl;   
	}
	
	}
	veDia(toaDoXDiaTrenCung,TOADOYCOT - i*CHIEUCAODIA,banKinhDiaTrenCung); 
	if (toaDoCotDau - toaDoCotSau < 0) {   //  chung to 1 dieu cot truoc nam truoc cot sua !
		// tinh ra so lan can phai di chuyen 
		int doDaiDiChuyenDia = toaDoCotSau - toaDoCotDau; 
		int soLanDiChuyen = doDaiDiChuyenDia / (banKinhDiaTrenCung * 2); 
		int j; 
		for (j = 0; j < soLanDiChuyen;j++) {
			veDia(toaDoXDiaTrenCung + j*banKinhDiaTrenCung*2,TOADOYCOT - i*CHIEUCAODIA,banKinhDiaTrenCung); 
			delay(200);
			xoaDia(toaDoXDiaTrenCung + j*banKinhDiaTrenCung*2,TOADOYCOT - i*CHIEUCAODIA,banKinhDiaTrenCung); 
			
			
		}
	}
	else {
		// truong hop nay phai di chuyen nguoc lai 
		// van tinh ra do dai di chuyen dia 
		int doDaiDiChuyenDia = toaDoCotDau - toaDoCotSau;  
		int soLanDiChuyen = doDaiDiChuyenDia / (banKinhDiaTrenCung * 2); 
	
		// tiep theo la di chuyen ->   	
		int j; 
		for (j = 0; j < soLanDiChuyen;j++) {
			// truoc tien can ve lai lai cai luc nay
			veDia(toaDoXDiaTrenCung - j*banKinhDiaTrenCung*2,TOADOYCOT - i*CHIEUCAODIA,banKinhDiaTrenCung); 
			// tiep theo la ve ra cac dia 
			delay(200);
			xoaDia(toaDoXDiaTrenCung - j*banKinhDiaTrenCung*2,TOADOYCOT - i*CHIEUCAODIA,banKinhDiaTrenCung); 
		}
		
		
	}

	int toaDoDiaCotDauSoVoiCotSau = toaDoCotSau - banKinhDiaTrenCung + 10;  
	// thu ve 1 cai xem sao 
	veDia(toaDoDiaCotDauSoVoiCotSau,TOADOYCOT - i*CHIEUCAODIA,banKinhDiaTrenCung); 
	
	
	// tiep tuc qua trinh ha xuong 
	// vi tri bac dau 
	// itnh ra vi tri cua cai dia dau tien 
	int toaDoDiaTrenCungCotSau = TOADOYTHANHXANGANG - (soDiaCotSau * CHIEUCAODIA); 
	int toaDoDiaTrenCungcotTruoc = TOADOYCOT - i*CHIEUCAODIA; 
	int soLanLap = (toaDoDiaTrenCungCotSau - toaDoDiaTrenCungcotTruoc) / CHIEUCAODIA; 
	int k;
	for ( k = 0;k < soLanLap;k++) {
		veDia(toaDoDiaCotDauSoVoiCotSau,toaDoDiaTrenCungcotTruoc + k*CHIEUCAODIA,banKinhDiaTrenCung); 
		delay(200); 
		xoaDia(toaDoDiaCotDauSoVoiCotSau,toaDoDiaTrenCungcotTruoc + k*CHIEUCAODIA,banKinhDiaTrenCung); 
		veCot(toaDoCotSau,soDiaCotSau); 
	}
	veDia(toaDoDiaCotDauSoVoiCotSau,toaDoDiaTrenCungcotTruoc + k*CHIEUCAODIA,banKinhDiaTrenCung); 
}


int A,C; 




void thapHaNoi(int n,int soLuongDia,int toaDoXCotA,int *diaCotA,int toaDoXCotB,int *diaCotB,int toaDoXCotC,int *diaCotC) {
	if (n == 1) {
		sapXepTangDan(diaCotA,soLuongDia);   //  sap xep the nay de dam bao trat tu cua cac dia
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
		thapHaNoi(n - 1,soLuongDia,toaDoXCotA,diaCotA,toaDoXCotC,diaCotC,toaDoXCotB,diaCotB);
		thapHaNoi(1,soLuongDia,toaDoXCotA,diaCotA,toaDoXCotB,diaCotB,toaDoXCotC,diaCotC);
		thapHaNoi(n-1,soLuongDia,toaDoXCotB,diaCotB,toaDoXCotA,diaCotA,toaDoXCotC,diaCotC);
		
	}
}



// viet ham khai bao :  






int main() {
	
	int soDia; 
	do {
		cout << "Nhap vao so dia : "; 
		cin >> soDia; 
		if (soDia <0 || soDia > 8) {
			cout << endl << "So Dia Tu 0 -> 7" << endl; 
		}
		else {
			break; 
		}
	}
	while (true); 
	
	cout << soDia; 
	
	StartBGI start; 
	int *diaCotA = new int[soDia];
	int *diaCotB = new int[soDia]; 
	int *diaCotC = new int[soDia]; 
	

	for (int i = 0; i < soDia;i++) {
		diaCotA[i] = BANKINHDIA * 2 * i + 20; 
		diaCotB[i] = 0; 
		diaCotC[i] = 0;    //  20 la do dai cua cai dia tren cung  
	}
	veThanhNgangVaTieuDe(); 
	int soDiaTam = soDia; 
	for (int i = 0; i < soDia;i++) {
		// tinh ra vi tri x bac dau ve ra 
		int viTriXDia =  TOADOXCOTA - diaCotA[i] + 10; 
		setfillstyle(SOLID_FILL, 10); // bo bua.
	 	bar (viTriXDia,TOADOYCOT - soDiaTam*CHIEUCAODIA + KHOANCACHDIA,viTriXDia + diaCotA[i]*2,TOADOYCOT - soDiaTam*CHIEUCAODIA + CHIEUCAODIA); 
		soDiaTam--;
	}
	
	veCot(TOADOXCOTA,soDia);
	veCot(TOADOXCOTB,0);   
	veCot(TOADOXCOTC,0); 

	thapHaNoi(soDia,soDia,TOADOXCOTA,diaCotA,TOADOXCOTB,diaCotB,TOADOXCOTC,diaCotC); 	
	
	getch(); 
	// tiep tuc ve ra 
	
}
