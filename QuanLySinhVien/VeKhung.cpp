#include <iostream>
#include "console.h"

using namespace std;

void ve_khungds(int x, int y){
	gotoXY(x,y);
	TextColor(15);
	cout<<(char)218;
	for(int i = 0; i < 63; i++){
		if(i == 4) cout<<(char)194;
		if(i == 15) cout<<(char)194;
		if(i == 24) cout<<(char)194;
		if(i == 45) cout<<(char)194;
		if(i == 57) cout<<(char)194;
		else cout<<(char)196;
	}	
	cout<<(char)191;
	gotoXY(x,y+1);
	cout<<(char)179;
	gotoXY(x+5,y+1);
	cout<<(char)179;
	gotoXY(x+17,y+1);
	cout<<(char)179;
	gotoXY(x+27,y+1);
	cout<<(char)179;
	gotoXY(x+49,y+1);
	cout<<(char)179;
	gotoXY(x+62,y+1);
	cout<<(char)179;
	gotoXY(x+68,y+1);
	cout<<(char)179;	
	gotoXY(x,y+2);
	cout<<(char)192;
	for(int i = 0; i < 63; i++){
		if(i == 4) cout<<(char)193;
		if(i == 15) cout<<(char)193;
		if(i == 24) cout<<(char)193;
		if(i == 45) cout<<(char)193;
		if(i == 57) cout<<(char)193;
		else cout<<(char)196;
	}
	cout<<(char)217;
}


void ve_khung(int x, int y){
	gotoXY(x,y);
	cout<<(char)218;
	for(int i = 0; i < 20; i++)	cout<<(char)196;
	cout<<(char)191;
	gotoXY(x,y+1);
	cout<<(char)179;
	gotoXY(x+21,y+1);
	cout<<(char)179;	
	gotoXY(x,y+2);
	cout<<(char)192;
	for(int i = 0; i < 20; i++) cout<<(char)196;
	cout<<(char)217;
}

void ve_khungtk_sl(int x, int y)
{
	gotoXY(x,y);
	TextColor(15);
	cout<<(char)218;
	for(int i = 0; i < 29; i++){
		if(i == 14) cout<<(char)194;
		else cout<<(char)196;
	}	
	cout<<(char)191;
	gotoXY(x,y+1);
	cout<<(char)179;
	gotoXY(x+15,y+1);
	cout<<(char)179;
	gotoXY(x+30,y+1);	
	cout<<(char)179;
	gotoXY(x,y+2);
	cout<<(char)192;
	for(int i = 0; i < 29; i++){
		if(i == 14) cout<<(char)193;
		else cout<<(char)196;
	}
	cout<<(char)217;
}

void ve_khung1(int x, int y){
	gotoXY(x,y);
	cout<<(char)218;
	for(int i = 0; i < 30; i++)	cout<<(char)196;
	cout<<(char)191;
	gotoXY(x,y+1);
	cout<<(char)179;
	gotoXY(x+31,y+1);
	cout<<(char)179;	
	gotoXY(x,y+2);
	cout<<(char)192;
	for(int i = 0; i < 30; i++) cout<<(char)196;
	cout<<(char)217;
}

void ve_khungtk_kqht(int x, int y)
{
	gotoXY(x,y);
	TextColor(15);
	cout<<(char)218;
	for(int i = 0; i < 75; i++){
		if(i == 14) cout<<(char)194;
		if (i == 20) cout<<(char)194;
		if (i == 26) cout<<(char)194;
		if (i == 32) cout<<(char)194;
		if (i == 38) cout<<(char)194;
		if (i == 44) cout<<(char)194;
		if (i == 50) cout<<(char)194;
		if (i == 56) cout<<(char)194;
		if (i == 62) cout<<(char)194;
		if (i == 68) cout<<(char)194;
		else cout<<(char)196;
	}	
	cout<<(char)191;
	gotoXY(x,y+1);
	cout<<(char)179;
	gotoXY(x+15,y+1);
	cout<<(char)179;
	gotoXY(x+22,y+1);	
	cout<<(char)179;
	gotoXY(x+29,y+1);
	cout<<(char)179;
	gotoXY(x+36,y+1);
	cout<<(char)179;
	gotoXY(x+43,y+1);
	cout<<(char)179;
	gotoXY(x+50,y+1);
	cout<<(char)179;
	gotoXY(x+57,y+1);
	cout<<(char)179;
	gotoXY(x+64,y+1);
	cout<<(char)179;
	gotoXY(x+71,y+1);
	cout<<(char)179;
	gotoXY(x+78,y+1);
	cout<<(char)179;
	gotoXY(x+85,y+1);
	cout<<(char)179;
	gotoXY(x,y+2);
	cout<<(char)192;
	for(int i = 0; i < 75; i++){
		if(i == 14) cout<<(char)193;
		if (i == 20) cout<<(char)193;
		if (i == 26) cout<<(char)193;
		if (i == 32) cout<<(char)193;
		if (i == 38) cout<<(char)193;
		if (i == 44) cout<<(char)193;
		if (i == 50) cout<<(char)193;
		if (i == 56) cout<<(char)193;
		if (i == 62) cout<<(char)193;
		if (i == 68) cout<<(char)193;
		else cout<<(char)196;
	}
	cout<<(char)217;
}

void ve_khungtk_kqht1(int x, int y)
{
	gotoXY(x,y);
	TextColor(15);
	cout<<(char)218;
	for(int i = 0; i < 80; i++){
		if (i == 14) cout<<(char)194;
		if (i == 27) cout<<(char)194;
		if (i == 40) cout<<(char)194;
		if (i == 53) cout<<(char)194;
		if (i == 66) cout<<(char)194;
		else cout<<(char)196;
	}	
	cout<<(char)191;
	gotoXY(x,y+1);
	cout<<(char)179;
	gotoXY(x+15,y+1);
	cout<<(char)179;
	gotoXY(x+29,y+1);
	cout<<(char)179;
	gotoXY(x+43,y+1);
	cout<<(char)179;
	gotoXY(x+57,y+1);
	cout<<(char)179;
	gotoXY(x+71,y+1);
	cout<<(char)179;
	gotoXY(x+85,y+1);
	cout<<(char)179;
	gotoXY(x,y+2);
	cout<<(char)179;
	for(int i = 0; i < 84; i++){
		if(i == 14) cout<<(char)195;
		else if (i == 21) cout<<(char)194;
		else if (i == 28) cout<<(char)197;
		else if (i == 35) cout<<(char)194;
		else if (i == 42) cout<<(char)197;
		else if (i == 49) cout<<(char)194;
		else if (i == 56) cout<<(char)197;
		else if (i == 63) cout<<(char)194;
		else if (i == 70) cout<<(char)197;
		else if (i == 77) cout<<(char)194;
		else if (i < 14) cout<<' ';
		else cout<<(char)196;
	}
	cout<<(char)180;
	gotoXY(x,y+3);
	cout<<(char)179;
	gotoXY(x+15,y+3);
	cout<<(char)179;
	gotoXY(x+22,y+3);	
	cout<<(char)179;
	gotoXY(x+29,y+3);
	cout<<(char)179;
	gotoXY(x+36,y+3);
	cout<<(char)179;
	gotoXY(x+43,y+3);
	cout<<(char)179;
	gotoXY(x+50,y+3);
	cout<<(char)179;
	gotoXY(x+57,y+3);
	cout<<(char)179;
	gotoXY(x+64,y+3);
	cout<<(char)179;
	gotoXY(x+71,y+3);
	cout<<(char)179;
	gotoXY(x+78,y+3);
	cout<<(char)179;
	gotoXY(x+85,y+3);
	cout<<(char)179;
	gotoXY(x,y+4);
	cout<<(char)192;
	for(int i = 0; i < 75; i++){
		if(i == 14) cout<<(char)193;
		if (i == 20) cout<<(char)193;
		if (i == 26) cout<<(char)193;
		if (i == 32) cout<<(char)193;
		if (i == 38) cout<<(char)193;
		if (i == 44) cout<<(char)193;
		if (i == 50) cout<<(char)193;
		if (i == 56) cout<<(char)193;
		if (i == 62) cout<<(char)193;
		if (i == 68) cout<<(char)193;
		else cout<<(char)196;
	}
	cout<<(char)217;
	gotoXY(x+5,y+2); cout<<"Ma lop";
	gotoXY(x+19,y+1); cout<<"Xuat sac";
	gotoXY(x+34,y+1); cout<<"Gioi";
	gotoXY(x+49,y+1); cout<<"Kha";
	gotoXY(x+59,y+1); cout<<"Trung binh";
	gotoXY(x+77,y+1); cout<<"Yeu";
	gotoXY(x+18,y+3); cout<<"SL";
	gotoXY(x+26,y+3); cout<<"%";
	gotoXY(x+32,y+3); cout<<"SL";
	gotoXY(x+40,y+3); cout<<"%";
	gotoXY(x+46,y+3); cout<<"SL";
	gotoXY(x+54,y+3); cout<<"%";
	gotoXY(x+60,y+3); cout<<"SL";
	gotoXY(x+68,y+3); cout<<"%";
	gotoXY(x+74,y+3); cout<<"SL";
	gotoXY(x+82,y+3); cout<<"%";
}

