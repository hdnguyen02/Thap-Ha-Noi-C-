#pragma once
#include<graphics.h>
#include<iostream>
#include <string>
#include "Constant.h"
#include <windows.h>
using namespace std;
 

//   khai bao ra struct ONhap => dung de nhap xuat tren man hinh BGI 



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



void nhapDia(int &soDia) 
{
	do
	{
		cout<<"Nhap Vao So Dia : ";
		cin>>soDia;
		if(soDia<=0) 
		{
			MessageBox(NULL, "So Dia Khong The <= 0", "Thong Bao!", MB_ICONINFORMATION | MB_OK);
		}
	}while(soDia<=0);
}


void khoiTaoBanKinhDiaCotACotBCotC(int *diaCotA,int *diaCotB,int *diaCotC,int &soDia) 
{
	for (int i = 0; i < soDia;i++) {
		diaCotA[i] = BAN_KINH_DIA * 2 * i + 20;  
		diaCotB[i] = diaCotC[i] = 0; 
	}
	
}

void setText(int bkColor,int colorText,int typeFont,int size) {
	setbkcolor(bkColor); 
	setcolor(colorText); 
	settextstyle(typeFont,0,size);
}



struct NutBam {
	// bao gom cac thong so sau 
	int x,y,w,h,color,colorText;
	string tieuDe; 
	// ve ham ve 
	// viet ham   bao 
	void set(int x,int y,int w,int h,int color,int colorText,string tieuDe) {
		this->x = x;
		this->y = y; 
		this->w = w; 
		this->h = h; 
		this->colorText = colorText; 
		this->color = color; 
		this->tieuDe = tieuDe;
	}
	NutBam(int x,int y,int w,int h,int color,int colorText,string tieuDe) {
		this->set(x,y,w,h,color,colorText,tieuDe); 
	}
	NutBam(){}; 
	// ham ve  
	bool isMouseHover(int mx, int my)
	{
		if (mx >= x && mx <= x + w && my >= y && my <= y + h)
		{
			return true;
		}
		return false;
	}

	void veNut()
	{
		char arr[70];
		strcpy(arr, tieuDe.c_str());
		setfillstyle(SOLID_FILL, color); // bo bua.
		bar(x, y, x + w, y + h);
		settextstyle(10, 0, 1);  
		int text_w = textwidth(arr);
		int text_h = textheight(arr);
		int toaDoTextX = x + (w - text_w) / 2;
		int toaDoTextY = y + (h - text_h) / 2;
		setcolor(colorText);
		setbkcolor(color); 
		outtextxy(toaDoTextX, toaDoTextY, arr);
	}
};

 


