#pragma once
#include<graphics.h>
#include<iostream>
#include <string>
#include "Constant.h"
#include <windows.h>
using namespace std;
 
class StartBGI
{
public:
	StartBGI()
	{
		initwindow(GetSystemMetrics(SM_CXSCREEN) - 600, GetSystemMetrics(SM_CYSCREEN) - 40);
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



struct NutBam {
	int x,y,w,h,color,colorText;
	string tieuDe; 
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

 


