#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include "VeKhung.cpp"

using namespace std;

struct kieungaythang{
	int ngay;
	int thang;
	int nam;
};

class sinhvien{
	public:
		string malop;
		string ngaythang;
		string hoten;
		kieungaythang ngaysinh;
		int masv;
		float diemtb;
		
		void nhap_ds(vector<sinhvien> &ds);
		void xoa(vector<sinhvien> &ds);
		void chinhSua(vector<sinhvien> &ds);
		void gi_file_hososinhvien();
		sinhvien doc_thongtin(ifstream &filein);
};

void Menu(vector<sinhvien> ds);
void menutk(vector<sinhvien> ds);
void menusx(vector<sinhvien> ds);
void menutim(vector<sinhvien> ds);
void quay_lai(vector<sinhvien> ds);
void in_ds(vector<sinhvien> ds);
void nhapdssv(vector<sinhvien> &d);
void dientt(vector<sinhvien> &d, sinhvien &sv, int i);
void hotro();

void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}

bool chuanhoaKitu(string name) {
	int kt = 0;
	for (int t = 0; t < name.length() - 1; t++) {
		if ((name[t] >= 65 && name[t] <= 90) || (name[t] >= 97 && name[t] <= 122) || name[t] == 32) {
		}
		else kt++;
	}
	if (kt == 0) return true;
	else return false;
}

void chuanhoaMalop(string &malop){
	for (int i = 0; i < malop.length(); i++){
		while(malop[i] == 32)
			malop.replace(i, 1, "");
		if(malop[i]>=97 && malop[i] <= 122)
			malop[i] = malop[i] - 32;
	}
}

void chuanhoaTen(string &name){
	while(name[0] == 32){
		name.replace(0, 1, "");
	}
	for(int i=0; i < name.length(); i++)
	{
		if(name[i] >= 65 && name[i] <= 90)
			name[i] = name[i] + 32;
	}
	if(name[0] >= 97)
		name[0] = name[0] - 32;
	for(int i = 0; i <name.length() - 1; i++){
		while(name[i] == 32 && name[i+1] == 32)
			name.replace(i, 1, "");
		if(name[i] == 32 && name[i+1] >= 97)
			name[i+1] = name[i+1] - 32;
	}
	if(name[name.length()-1] == 32)
		name.replace(name.length() - 1, 1, "");
}

bool chuanhoaNgaySinh(int d, int m, int y) {
	int k = 0;
	if ( y >= 1900 && y <= 2024){
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d > 31 || d < 0)   k++;
		}
		else
			if (m == 4 || m == 6 || m == 9 || m == 11)
			{
				if (d > 30 || d < 0) k++;
			}
			else
				if (m == 2)
				{
					if (y % 4 == 0)
					{
						if (d > 29 || d < 0) k++;
					}
					else {
						if (d > 28 || d < 0) k++;
					}
				}
				else k++;

				if (k == 0) 
					return true;
				else 
					return false;
	}
}

bool chuanhoaDiem(float x) {
	if (x >= 0 && x <= 10) return true;
	else return false;

}

void sinhvien::gi_file_hososinhvien(){
	ofstream fileout;
	fileout.open("data.txt", ios_base::app);
	fileout<<malop<<", "<<masv<<" "<<hoten<<", "<<diemtb<<" "<<ngaysinh.ngay<<"/"<<ngaysinh.thang<<"/"<<ngaysinh.nam<<endl;
	fileout.close();
}

sinhvien sinhvien::doc_thongtin(ifstream &filein){
	sinhvien a;	
	getline(filein, a.malop, ',');
	filein >> a.masv;
	getline(filein, a.hoten, ',');
	filein >> a.diemtb;
	getline(filein, a.ngaythang);
	return a;
}
void nhapdssv(vector<sinhvien> &d){
	sinhvien sv;
	ifstream filein;
	filein.open("data.txt", ios_base::in);
	while(filein.eof() == false){
			d.push_back(sv.doc_thongtin(filein));
		}
	filein.close();
}

void sx_mssv(vector<sinhvien> &a){
	int n = a.size();
	for(int i = 0; i < n - 2; i++){
		int min = i;
		for(int j = i + 1; j < n -1 ; j++ ){
		if(a[j].masv < a[min].masv)
		min = j;
		}
		if(i != min){
			sinhvien tam = a[i];
			a[i] = a[min];
			a[min] = tam;
		}
	}
}
void sx_diem(vector<sinhvien> &a){
	int n = a.size();
	for(int i = 0; i < n - 2; i++){
		int min = i;
		for(int j = i + 1; j < n -1 ; j++ ){
		if(a[j].diemtb < a[min].diemtb)
		min = j;
		}
		if(i != min){
			sinhvien tam = a[i];
			a[i] = a[min];
			a[min] = tam;
		}
	}
}
string nam(string b){
	string a;
	for(int i = b.length() - 1; i >=0 ; i--)
	if(b[i] >= '0' && b[i] <= '9')
	a.insert(a.begin() + 0, b[i]);
	else
	break;
	return a;
}
string thang(string b){
	string a;
	for(int i = b.length() - 6; i >=0 ; i--)
	if(b[i] >= '0' && b[i] <= '9')
	a.insert(a.begin() + 0, b[i]);
	else
	break;
	return a;
}
string ngay(string b){
	string a;
	for(int i =1; i<3 ; i++)
	if(b[i] >= '0' && b[i] <= '9')
	a.push_back(b[i]);
	else
	break;
	return a;
}
void sx_date(vector<sinhvien> &a){
	int i, min, j, n = a.size();
	for( i = 0; i < n - 2; i++){
		min = i;
		for(j = i + 1; j < n -1 ; j++ ){
			if( nam(a[min].ngaythang) > nam(a[j].ngaythang) )
			min = j;
			else if( nam(a[min].ngaythang) == nam(a[j].ngaythang) ){
				if( thang(a[min].ngaythang) > thang(a[j].ngaythang) )
				min = j;
				else if( thang(a[min].ngaythang) == thang(a[j].ngaythang) ){
				if( ngay(a[min].ngaythang) > ngay(a[j].ngaythang) )
					min = j;
				}
			}
		}
		
		if(i != min){
			sinhvien tam = a[i];
			a[i] = a[min];
			a[min] = tam;
		}
	}
}

string hovaten(string b){
	string a;
	for (int i = 1; i < b.length(); i++)
		a.push_back(b[i]);
	return a;
}

string ten(string b){
	string a;
	for(int i = b.length() - 1; i >=0 ; i--){
		a.insert(a.begin() + 0, b[i]);
		if(b[i-1] == 32 )
		break;
	}
	return a;
}

string ten_c(string b){
	string a;
	for(int i = b.length() - 1; i >=0 ; i--){
		if(b[i-1] == 32 ){
			a.push_back(b[i]);
			break;
		}
	}
	return a;
}

string dem(string f){
	string h;
	int khoangtrong = 0, t = 0;
	for(int i = 1; i < f.length(); i++){
		if(f[i] == 32 )
			khoangtrong = khoangtrong + 1;
	}
	for(int i = 1; i < f.length(); i++)
	{
		if(f[i] == 32)
			t++;
		if (t>0 && t<khoangtrong)
			h.push_back(f[i]);
	}
	h.replace(0, 1, "");
	return h;
}
string dem_c(string f){
	string h;
	for(int i = 1 ; i < f.length() - 1; i++){
		if(f[i] == 32 ){
			h.push_back(f[i+1]);
			break;
		}
	}
	return h;
}
string ho(string f){
	string d;
	for(int i =1; i < 9; i++){
		d.push_back(f[i]);
		if(f[i +1] == 32)
		break;
	}
	return d;
}
string ho_c(string f){
	string h;
	h.push_back(f[1]);
	return h;
}
string lop_c(string a){
	string b;
	b.push_back(a[2]);
	return b;
}
void sx_ten(vector<sinhvien> &d){
	int i, j, min, n = d.size();
	for(i = 0; i < n -2 ; i++){
		min = i;
		for(j = i+1 ; j < n -1 ; j++){
			if(ten(d[min].hoten) > ten(d[j].hoten))
			min = j;
			else if(ten(d[min].hoten) == ten(d[j].hoten)){
				if(dem(d[min].hoten) > dem(d[j].hoten))
				min = j;
				else if( dem(d[min].hoten) == dem(d[j].hoten) ){
					if(ho(d[min].hoten) > ho(d[j].hoten))
					min = j;
				}
			}
		}
		
		if(min != i){
			sinhvien tam = d[i];
			d[i] = d[min];
			d[min] = tam;
		}
	}
}

void sx_malop(vector<sinhvien> &d){
	int i, j, min, n = d.size();
	for(i = 0; i < n -2 ; i++ ){
		min = i;
		for( j = i + 1; j < n -1; j ++){
			if(d[min].malop > d[j].malop)
			min = j;
			else if(d[min].malop == d[j].malop){
				if(ten(d[min].hoten) > ten(d[j].hoten))
				min = j;
				else if(ten(d[min].hoten) == ten(d[j].hoten)){
					if(dem(d[min].hoten) > dem(d[j].hoten))
					min = j;
					else if( dem(d[min].hoten) == dem(d[j].hoten) ){
						if(ho(d[min].hoten) > ho(d[j].hoten))
						min = j;
						else if( ho(d[min].hoten) == ho(d[j].hoten) ){
							if( nam(d[min].ngaythang) > nam(d[j].ngaythang) )
							min = j;
							else if( nam(d[min].ngaythang) == nam(d[j].ngaythang) ){
								if( thang(d[min].ngaythang) > thang(d[j].ngaythang) )
								min = j;
								else if( thang(d[min].ngaythang) == thang(d[j].ngaythang) ){
									if( ngay(d[min].ngaythang) > ngay(d[j].ngaythang) )
									min = j;
								}
							}
						}
					}
				}
			}
		}
		if(min != i){
			sinhvien tam = d[i];
			d[i] = d[min];
			d[min] = tam;
		}
	}
}


int ep_kieu(string s){
	int a = 0, n = s.size();
	int mu = n - 1;
	for(int i = 0; i < n; i++){
		a = a + (s[i] - '0')*pow(10,mu);
		mu--;
	}
	return a;
}

void tim_ten(vector<sinhvien> d){
	system("cls");
	ShowCur(true);
	string t;
	cout<<"\n\t DANH SACH TIM DUOC ";
	ve_khungds(2,3);
	gotoXY(4,4); cout<<"STT";
	gotoXY(10,4); cout<<"Ma lop";
	gotoXY(22,4); cout<<"MSSV";
	gotoXY(35,4); cout<<"Ho va ten";
	gotoXY(53,4); cout<<"Ngay sinh";
	gotoXY(65,4); cout<<"DTBTL";
	gotoXY(80,2); cout<<"Tim kiem theo Ho ten";
	fflush(stdin);
	gotoXY(80,3); cout<<"Nhap vao ho ten can tim: ";
	ve_khung(80,4); 
	gotoXY(81,5); getline(cin,t);
	chuanhoaTen(t);
	int j = 0, n = d.size();
	for(int i =0; i < n-1; i++){
		if(t == hovaten(d[i].hoten) ||t == ten_c(d[i].hoten) || t == dem_c(d[i].hoten) || t == ho_c(d[i].hoten) || t == ten(d[i].hoten) || t == dem(d[i].hoten) || t == ho(d[i].hoten)){
			ve_khungds(2,6+3*j);
			gotoXY(5,7+3*j); cout<<j+1;
			gotoXY(9,7+3*j); cout<<d[i].malop;
			gotoXY(20,7+3*j); cout<<d[i].masv;
			gotoXY(30,7+3*j); cout<<d[i].hoten;
			gotoXY(52,7+3*j); cout<<d[i].ngaythang;
			gotoXY(66,7+3*j); cout<< setprecision(2) << fixed <<d[i].diemtb;
			j++;
		}
	}
	quay_lai(d);
}

void tim_malop(vector<sinhvien> d){
	system("cls");
	ShowCur(true);
	string t;
	cout<<"\n\t DANH SACH TIM DUOC ";
	ve_khungds(2,3);
	gotoXY(4,4); cout<<"STT";
	gotoXY(10,4); cout<<"Ma lop";
	gotoXY(22,4); cout<<"MSSV";
	gotoXY(35,4); cout<<"Ho va ten";
	gotoXY(53,4); cout<<"Ngay sinh";
	gotoXY(65,4); cout<<"DTBTL";
	gotoXY(80,4); cout<<"Tim kiem theo Ma lop";
	fflush(stdin);
	gotoXY(80,3); cout<<"Nhap vao ma lop can tim: ";
	ve_khung(80,4); 
	gotoXY(81,5); getline(cin,t);
	chuanhoaMalop(t);
	int n = d.size();
	int j = 0;
	for(int i =0; i < n -1; i++){
		if(t == d[i].malop || t == lop_c(d[i].malop)){
			ve_khungds(2,6+3*j);
			gotoXY(5,7+3*j); cout<<j+1;
			gotoXY(9,7+3*j); cout<<d[i].malop;
			gotoXY(20,7+3*j); cout<<d[i].masv;
			gotoXY(30,7+3*j); cout<<d[i].hoten;
			gotoXY(52,7+3*j); cout<<d[i].ngaythang;
			gotoXY(66,7+3*j); cout<< setprecision(2) << fixed <<d[i].diemtb;
			j++;
		}
	}
	quay_lai(d);
}

void tim_ngaysinh(vector<sinhvien> d){
	system("cls");
	ShowCur(true);
	string t;
	cout<<"\n\t DANH SACH TIM DUOC ";
	ve_khungds(2,3);
	gotoXY(4,4); cout<<"STT";
	gotoXY(10,4); cout<<"Ma lop";
	gotoXY(22,4); cout<<"MSSV";
	gotoXY(35,4); cout<<"Ho va ten";
	gotoXY(53,4); cout<<"Ngay sinh";
	gotoXY(65,4); cout<<"DTBTL";
	gotoXY(80,2); cout<<"Tim kiem theo Ngay sinh";
	fflush(stdin);
	gotoXY(80,3); cout<<"Nhap vao ngay sinh can tim: ";
	ve_khung(80,4); 
	gotoXY(81,5); getline(cin,t);
	int j = 0, n = d.size();
	for(int i =0; i < n -1; i++){
		if(t == d[i].ngaythang || t == nam(d[i].ngaythang) || t == thang(d[i].ngaythang) || t == ngay(d[i].ngaythang)){
			ve_khungds(2,6+3*j);
			gotoXY(5,7+3*j); cout<<j+1;
			gotoXY(9,7+3*j); cout<<d[i].malop;
			gotoXY(20,7+3*j); cout<<d[i].masv;
			gotoXY(30,7+3*j); cout<<d[i].hoten;
			gotoXY(52,7+3*j); cout<<d[i].ngaythang;
			gotoXY(66,7+3*j); cout<< setprecision(2) << fixed <<d[i].diemtb;
			j++;
		}	
	}
	quay_lai(d);
}

void tim_batky(vector<sinhvien> d){
	system("cls");
	ShowCur(true);
	string t;
	cout<<"\n\t DANH SACH TIM DUOC ";
	ve_khungds(2,3);
	gotoXY(4,4); cout<<"STT";
	gotoXY(10,4); cout<<"Ma lop";
	gotoXY(22,4); cout<<"MSSV";
	gotoXY(35,4); cout<<"Ho va ten";
	gotoXY(53,4); cout<<"Ngay sinh";
	gotoXY(65,4); cout<<"DTBTL";
	
	gotoXY(80,2); cout<<"Tim kiem bat ky";
	fflush(stdin);
	gotoXY(80,3); cout<<"Nhap tu can tim: ";
	ve_khung(80,4); 
	gotoXY(81,5); getline(cin,t);
	
	int j = 0, n = d.size();
	int t1 = ep_kieu(t);
	for(int i =0; i < n -1; i++){
		if(t1 == d[i].diemtb ||t1 == d[i].masv ||t == ten_c(d[i].hoten) || t == dem_c(d[i].hoten) || t == ho_c(d[i].hoten) || t == lop_c(d[i].malop) || t == ten(d[i].hoten) || t == dem(d[i].hoten) || t == ho(d[i].hoten) || t == d[i].malop || t == d[i].hoten || t == d[i].ngaythang || t == nam(d[i].ngaythang) || t == thang(d[i].ngaythang) || t == ngay(d[i].ngaythang)){
			ve_khungds(2,6+3*j);
			gotoXY(5,7+3*j); cout<<j+1;
			gotoXY(9,7+3*j); cout<<d[i].malop;
			gotoXY(20,7+3*j); cout<<d[i].masv;
			gotoXY(30,7+3*j); cout<<d[i].hoten;
			gotoXY(52,7+3*j); cout<<d[i].ngaythang;
			gotoXY(66,7+3*j); cout<< setprecision(2) << fixed <<d[i].diemtb;
			j++;
		}	
	}
	
	quay_lai(d);
}

void tim_mssv(vector<sinhvien> d){
	system("cls");
	ShowCur(true);
	string input;
	int g, t = 0, p = d.size() - 2;
	sx_mssv(d);
	int m;
	cout<<"\n\t DANH SACH TIM DUOC ";
	ve_khungds(2,3);
	gotoXY(4,4); cout<<"STT";
	gotoXY(10,4); cout<<"Ma lop";
	gotoXY(22,4); cout<<"MSSV";
	gotoXY(35,4); cout<<"Ho va ten";
	gotoXY(53,4); cout<<"Ngay sinh";
	gotoXY(65,4); cout<<"DTBTL";
	gotoXY(80,2); cout<<"Tim kiem theo MSSV ";
	gotoXY(80,3); cout<<"Nhap vao MSSV can tim:  ";
	while(1)
	{
		ve_khung(80,4); 
		gotoXY(81,5); cout<<"                    ";
		gotoXY(81,5); getline(cin,input);
				try
				{
					size_t pos;
					stoi(input, addressof(pos));
					if (pos == input.size()) {
						m = stoi(input);
						break;
					}
				}
				catch(const std::exception& e) {}
	}
	while(t <= p){
		g = (t + p)/2;
		if(m < d[g].masv) p = g -1;
		else if(m > d[g].masv) t = g +1;
		else{
			ve_khungds(2,6);
			gotoXY(5,7); cout<<1;
			gotoXY(9,7); cout<<d[g].malop;
			gotoXY(20,7); cout<<d[g].masv;
			gotoXY(30,7); cout<<d[g].hoten;
			gotoXY(52,7); cout<<d[g].ngaythang;
			gotoXY(66,7); cout<<fixed<<setprecision(2)<<d[g].diemtb;
			break;
		}
	}
	quay_lai(d);
}
void tim_diem(vector<sinhvien> d){
	system("cls");
	ShowCur(true);
	string input;
	int g, t = 0, p = d.size() - 2;
	float m;
	sx_diem(d);
	cout<<"\n\t DANH SACH TIM DUOC ";
	ve_khungds(2,3);
	gotoXY(4,4); cout<<"STT";
	gotoXY(10,4); cout<<"Ma lop";
	gotoXY(22,4); cout<<"MSSV";
	gotoXY(35,4); cout<<"Ho va ten";
	gotoXY(53,4); cout<<"Ngay sinh";
	gotoXY(65,4); cout<<"DTBTL";
	gotoXY(80,2); cout<<"Tim kiem theo DTBTL";
	gotoXY(80,3); cout<<"Nhap vao diem can tim: ";
	while(1)
	{
		ve_khung(80,4); 
		gotoXY(81,5); cout<<"                    ";
		gotoXY(81,5); getline(cin,input);
				try
				{
					size_t pos;
					stof(input, addressof(pos));
					if (pos == input.size()) {
						m = stof(input);
						break;
					}
				}
				catch(const std::exception& e) {}
	}
	while(t <= p){
		g = (t + p)/2;
		if(m < d[g].diemtb) p = g -1;
		else if(m > d[g].diemtb) t = g +1;
		else{
			int j = 0, dem = g;
			while(d[g].diemtb == m && g < (d.size() - 1)){
				ve_khungds(2,6+3*j);
				gotoXY(5,7+3*j); cout<<j+1;
				gotoXY(9,7+3*j); cout<<d[g].malop;
				gotoXY(20,7+3*j); cout<<d[g].masv;
				gotoXY(30,7+3*j); cout<<d[g].hoten;
				gotoXY(52,7+3*j); cout<<d[g].ngaythang;
				gotoXY(66,7+3*j); cout<<d[g].diemtb;
				g++;
				j++;
			}
			g = dem -1;
			while(d[g].diemtb == m && g >= 0 ){
				ve_khungds(2,6+3*j);
				gotoXY(5,7+3*j); cout<<j+1;
				gotoXY(9,7+3*j); cout<<d[g].malop;
				gotoXY(20,7+3*j); cout<<d[g].masv;
				gotoXY(30,7+3*j); cout<<d[g].hoten;
				gotoXY(52,7+3*j); cout<<d[g].ngaythang;
				gotoXY(66,7+3*j); cout<<d[g].diemtb;
				g--;
				j++;
			}
			break;
		}
	}
	quay_lai(d);
}

void quay_lai(vector<sinhvien> ds){
	char c;
	TextColor(4);
	gotoXY(90,10);
	cout<<"<< Ve MENU CHINH";
	do{
		c = getch();
		switch(c){
			case 75:
			case 13:
				system("cls");
				Menu(ds);
				break;
		}
	}while(c != 27);
}

void tk_sl_sv(vector<sinhvien> ds){
	int i = 0, j = 0, k = 0, count, n = ds.size() -1;
	vector<int> a, b;
	vector<string> lop;
	for(i = 0; i < n; i++) {
		a.push_back(0);
	}
	for(i = 0; i < n; i++) {
		if (a[i] == 0) {
			count = 1;
			b.push_back(0);
			lop.push_back(ds[i].malop);
			for (j = i+1; j < n; j++)
			{
				if (ds[i].malop == ds[j].malop)
				{
					a[j] = 1;
					count++;
				}
			}
			b[k] = count;
			count = 1;
			k++;
		}
	}
	TextColor(10);
	gotoXY(7,1);
	cout<<"SO LUONG SINH VIEN THEO TUNG LOP";
	ve_khungtk_sl(7,2);
	TextColor(15);
	gotoXY(12,3); cout<<"Ma lop";
	gotoXY(24,3); cout<<"So luong SV";
	k = 0;
	for (i=0; i<lop.size(); i++)
	{
		ve_khungtk_sl(7,5+3*i);
		gotoXY(10,6+3*i); cout<<lop[i];
		gotoXY(28,6+3*i); cout<<b[k];
		k++;
	}
	quay_lai(ds);
}

void tk_kqht_sv(vector<sinhvien> ds){
	int i, j, n = ds.size()-1;
	float tongptxs, tongptgioi, tongptkha, tongpttb, tongptyeu, tongslxs, tongslgioi, tongslkha, tongsltb, tongslyeu;
	vector<int> a;
	vector<float> slxs, slgioi, slkha, sltb, slyeu, ptxs, ptgioi, ptkha, pttb, ptyeu;
	vector<string> lop;
	tongslxs = tongslgioi = tongslkha = tongsltb = tongslyeu = 0;
	tongptxs = tongptgioi = tongptkha = tongpttb = tongptyeu = 0;
	for(i = 0; i < n; i++) {
		a.push_back(0);
	}
	for(i = 0; i < n; i++) {
		if (a[i] == 0) {
			lop.push_back(ds[i].malop);
			for (j = i+1; j < n; j++)
			{
				if (ds[i].malop == ds[j].malop)
					a[j] = 1;
			}
		}
	}
	for(i=0; i < lop.size(); i++)
	{
		slxs.push_back(0);
		slgioi.push_back(0);
		slkha.push_back(0);
		sltb.push_back(0);
		slyeu.push_back(0);
		ptxs.push_back(0);
		ptgioi.push_back(0);
		ptkha.push_back(0);
		pttb.push_back(0);
		ptyeu.push_back(0);
	}
	for(i=0; i < lop.size(); i++)
	{
		for(j=0; j < n; j++)
		{
			if (ds[j].malop == lop[i])
			{
				if (ds[j].diemtb >= 9) {
					slxs[i]++;
					tongslxs++;
				}
				else if (ds[j].diemtb >= 8) {
					slgioi[i]++;
					tongslgioi++;
				}
				else if (ds[j].diemtb >= 6.5) {
					slkha[i]++;
					tongslkha++;
				}
				else if (ds[j].diemtb >= 5) {
					sltb[i]++;
					tongsltb++;
				}
				else {
					slyeu[i]++;
					tongslyeu++;
				}
			}
			ptxs[i] = slxs[i]*100/(slxs[i] + slgioi[i] + slkha[i] + sltb[i] + slyeu[i]);
			ptgioi[i] = slgioi[i]*100/(slxs[i] + slgioi[i] + slkha[i] + sltb[i] + slyeu[i]);
			ptkha[i] = slkha[i]*100/(slxs[i] + slgioi[i] + slkha[i] + sltb[i] + slyeu[i]);
			pttb[i] = sltb[i]*100/(slxs[i] + slgioi[i] + slkha[i] + sltb[i] + slyeu[i]);
			ptyeu[i] = 100 - ptxs[i] - ptgioi[i] - ptkha[i] - pttb[i];
		}
		tongptxs =  tongslxs*100/(tongslxs + tongslgioi + tongslkha + tongsltb + tongslyeu);
		tongptgioi = tongslgioi*100/(tongslxs + tongslgioi + tongslkha + tongsltb + tongslyeu);
		tongptkha = tongslkha*100/(tongslxs + tongslgioi + tongslkha + tongsltb + tongslyeu);
		tongpttb = tongsltb*100/(tongslxs + tongslgioi + tongslkha + tongsltb + tongslyeu);
		tongptyeu = 100 - tongptxs - tongptgioi - tongptkha - tongpttb;
	}
	TextColor(10);
	gotoXY(23,1); cout<<"KET QUA HOC TAP SINH VIEN THEO TUNG LOP";
	TextColor(15);
	ve_khungtk_kqht1(1,2);
	for (i=0; i < lop.size(); i++)
	{
		ve_khungtk_kqht(1,7+3*i);
		cout << setprecision(0);
		gotoXY(4,8+3*i); cout<<lop[i];
		gotoXY(19,8+3*i); cout<<slxs[i];
		gotoXY(33,8+3*i); cout<<slgioi[i];
		gotoXY(47,8+3*i); cout<<slkha[i];
		gotoXY(61,8+3*i); cout<<sltb[i];
		gotoXY(75,8+3*i); cout<<slyeu[i];
		cout << fixed << setprecision(2);
		gotoXY(24,8+3*i); cout<<ptxs[i]<<"%";
		gotoXY(38,8+3*i); cout<<ptgioi[i]<<"%";
		gotoXY(52,8+3*i); cout<<ptkha[i]<<"%";
		gotoXY(66,8+3*i); cout<<pttb[i]<<"%";
		gotoXY(80,8+3*i); cout<<ptyeu[i]<<"%";
	}
	ve_khungtk_kqht(1,7+3*i);
	cout << setprecision(0);
	gotoXY(6,8+3*i); cout<<"TONG";
	gotoXY(19,8+3*i); cout<<tongslxs;
	gotoXY(33,8+3*i); cout<<tongslgioi;
	gotoXY(47,8+3*i); cout<<tongslkha;
	gotoXY(61,8+3*i); cout<<tongsltb;
	gotoXY(75,8+3*i); cout<<tongslyeu;
	cout << fixed << setprecision(2);
	gotoXY(24,8+3*i); cout<<tongptxs<<"%";
	gotoXY(38,8+3*i); cout<<tongptgioi<<"%";
	gotoXY(52,8+3*i); cout<<tongptkha<<"%";
	gotoXY(66,8+3*i); cout<<tongpttb<<"%";
	gotoXY(80,8+3*i); cout<<tongptyeu<<"%";
	quay_lai(ds);
}

void menusx(vector<sinhvien> ds){
	char c;
	int chon = 0;
	string a[10] = {"Theo ma lop        ","Theo MSSV          ","Theo ten           ","Theo ngay sinh     ","Theo diem          "};
	TextColor(15);
	ve_khung(28,5);
	TextColor(10);
	gotoXY(30,6);
	cout<<a[0];
	TextColor(15);
	for(int i = 1; i < 5; i++){
		ve_khung(28,3*i+5);	
		gotoXY(30,3*i+6);
		cout<<a[i];
	}
	do{
		c = getch();
		switch(c){
			case 72:
				TextColor(15);
				gotoXY(30, 3*chon+6);
				cout<<a[chon];
				chon--;
				if(chon < 0) chon = 4;
				TextColor(10);
				gotoXY(30,3*chon+6);
				cout<<a[chon];
				break;
			case 80:
				TextColor(15);
				gotoXY(30, 3*chon+6);
				cout<<a[chon];
				chon++;
				if(chon > 4) chon = 0;
				TextColor(10);
				gotoXY(30,3*chon+6);
				cout<<a[chon];
				break;
			case 75:
				for(int i = 0; i < 15; i++){
					gotoXY(28, i+5);
					cout<<"                       ";	
				}
				Menu(ds);
				break;
			case 77:
			case 13:
				system("cls");
				if (chon==0) sx_malop(ds);
				else if (chon==1) sx_mssv(ds);
				else if (chon==2) sx_ten(ds);
				else if (chon==3) sx_date(ds);
				else if (chon==4) sx_diem(ds);

				ofstream fileout;
				fileout.open("datanew.txt", ios_base::out);
				for (int i = 0; i < ds.size()-1; i++)
				{
					fileout<<ds[i].malop<<", "<<ds[i].masv;
					fileout<<ds[i].hoten<<", "<<ds[i].diemtb<<ds[i].ngaythang<<endl;
				}
				fileout.close();
				remove("data.txt");
				rename("datanew.txt","data.txt");
				ds.resize(0);
				nhapdssv(ds);
				in_ds(ds);
				quay_lai(ds);
				break;
		}
	}while(c != 27);
}

void menutim(vector<sinhvien> ds){
	char c;
	int chon = 0;
	string a[10] = {"Theo ma lop        ","Theo MSSV          ","Theo ten           ","Theo ngay sinh     ","Theo diem          ","Tim kiem bat ky    "};
	TextColor(15);
	ve_khung(28,3);
	TextColor(10);
	gotoXY(30,4);
	cout<<a[0];
	TextColor(15);
	for(int i = 1; i < 6; i++){
		ve_khung(28,3*i+3);	
		gotoXY(30,3*i+4);
		cout<<a[i];
	}
	do{
		c = getch();
		switch(c){
			case 72:
				TextColor(15);
				gotoXY(30, 3*chon+4);
				cout<<a[chon];
				chon--;
				if(chon < 0) chon = 5;
				TextColor(10);
				gotoXY(30,3*chon+4);
				cout<<a[chon];
				break;
			case 80:
				TextColor(15);
				gotoXY(30, 3*chon+4);
				cout<<a[chon];
				chon++;
				if(chon > 5) chon = 0;
				TextColor(10);
				gotoXY(30,3*chon+4);
				cout<<a[chon];
				break;
			case 75:
				for(int i = 0; i < 20; i++){
					gotoXY(28, i+3);
					cout<<"                       ";	
				}
				Menu(ds);
				break;
			case 77:
			case 13:
				if (chon==0) tim_malop(ds);
				else if (chon==1) tim_mssv(ds);
				else if (chon==2) tim_ten(ds);
				else if (chon==3) tim_ngaysinh(ds);
				else if (chon==4) tim_diem(ds);
				else if (chon==5) tim_batky(ds);
				break;
		}
	}while(c != 27);
}

void menutk(vector<sinhvien> ds){
	char c;
	int chon = 0;
	string a[5] = {"So luong sinh vien theo lop","Phan loai ket qua hoc tap"};
	TextColor(15);
	ve_khung1(28,5);
	TextColor(10);
	gotoXY(30,6);
	cout<<a[0];
	TextColor(15);
	for(int i = 1; i < 2; i++){
		ve_khung1(28,3*i+5);	
		gotoXY(30,3*i+6);
		cout<<a[i];
	}
	do{
		c = getch();
		switch(c){
			case 72:
				TextColor(15);
				gotoXY(30, 3*chon+6);
				cout<<a[chon];
				chon--;
				if(chon < 0) chon = 1;
				TextColor(10);
				gotoXY(30,3*chon+6);
				cout<<a[chon];
				break;
			case 80:
				TextColor(15);
				gotoXY(30, 3*chon+6);
				cout<<a[chon];
				chon++;
				if(chon > 1) chon = 0;
				TextColor(10);
				gotoXY(30,3*chon+6);
				cout<<a[chon];
				break;
			case 75:
				for(int i = 0; i < 6; i++){
					gotoXY(28 ,i + 5);
					cout<<"                                 ";
				}
				Menu(ds);
				break;
			case 77:
			case 13:
				system("cls");
				if(chon == 0) tk_sl_sv(ds);
				if(chon == 1) tk_kqht_sv(ds);
				break;
		}
	}while(c != 27);
}

void hotro(){
	TextColor(15);
	gotoXY(1,28); cout<<"Up: Up Arrow || Down: Down Arrow || Select: Enter or Right Arrow || Back: Left Arrow";
}

void Menu(vector<sinhvien> ds){
	ShowCur(false);
	char c;
	sinhvien sv;
	int chon = 0 ;
	string a[10] = {"Them sinh vien  ","Chinh sua SV    " , "Xoa SV          " ,"In danh sach SV ","Sap xep         >","Tim kiem        >", "Thong ke        >", "Thoat       "};
	TextColor(15);
	gotoXY(8,2); cout<<"MENU CHINH";
	hotro();
	TextColor(15);
	ve_khung(3,3);
	TextColor(10);
	gotoXY(6,4);
	cout<<a[0];
	TextColor(15);
	for(int i = 1; i < 8; i++){
		ve_khung(3,3*i+3);	
		gotoXY(6,3*i+4);
		cout<<a[i];
	}	
	do{
		c = getch();
		switch(c){
			case 72:
				TextColor(15);
				gotoXY(6, 3*chon+4);
				cout<<a[chon];
				chon--;
				if(chon < 0) chon = 7;
				TextColor(10);
				gotoXY(6,3*chon+4);
				cout<<a[chon];
				break;
			case 80:
				TextColor(15);
				gotoXY(6, 3*chon+4);
				cout<<a[chon];
				chon++;
				if(chon > 7) chon = 0;
				TextColor(10);
				gotoXY(6,3*chon+4);
				cout<<a[chon];
				break;
			case 77:
			case 13:
				if(chon == 0){
					system("cls");
					sv.nhap_ds(ds);
				}
				if (chon == 1) {
					system("cls");
					sv.chinhSua(ds);
				}
				else if (chon == 2) {
					system("cls");
					sv.xoa(ds);
				}
				else if(chon == 3){
					system("cls");
					in_ds(ds);
				}
				else if(chon == 4) menusx(ds);
				
				else if(chon == 5) menutim(ds);
				
				else if(chon == 6) menutk(ds);
				
				else exit(0);
								
				break;
		}
	}while(c != 27 && c != 13);
}



void in_ds(vector<sinhvien> ds){
	int i;
	gotoXY(26,3);
	TextColor(15);
	ve_khungds(1,2);
	gotoXY(2,3); cout<<"STT";
	gotoXY(9,3); cout<<"Ma lop";
	gotoXY(21,3); cout<<"MSSV";
	gotoXY(34,3); cout<<"Ho va ten";
	gotoXY(52,3); cout<<"Ngay sinh";
	gotoXY(64,3); cout<<"DTBTL";
	for (i=0; i < ds.size()-1; i++)
	{
		ve_khungds(1,5+3*i);	
		gotoXY(4,6+3*i); cout<<i+1;
		gotoXY(8,6+3*i); cout<<ds[i].malop;
		gotoXY(19,6+3*i); cout<<ds[i].masv;
		gotoXY(29,6+3*i); cout<<ds[i].hoten;
		gotoXY(51,6+3*i); cout<<ds[i].ngaythang;
		gotoXY(64,6+3*i); cout<<setprecision(2)<< fixed <<ds[i].diemtb;
	}
	quay_lai(ds);
}

void sinhvien::chinhSua(vector<sinhvien> &ds){
	ShowCur(true);
	int mssv, ms_tontai = 0;
	string input;
	sinhvien sv;
	TextColor(15);
	cout<<"\nNhap MSSV cua sinh vien can chinh sua: ";
	while(1)
	{
		ve_khung(39,0);
		gotoXY(40,1); cout<<"                    ";
		gotoXY(40,1); getline(cin,input);
				try
				{
					size_t pos;
					stoi(input, addressof(pos));
					if (pos == input.size()) {
						mssv = stoi(input);
						for (int i = 0; i < ds.size() - 1; i++)
							if (mssv == ds[i].masv){
								ms_tontai = 1;
							}
						if (ms_tontai) break;
					}
				}
				catch(const std::exception& e) {}
	}
	ve_khungds(1,4);
	gotoXY(2,5); cout<<"STT";
	gotoXY(9,5); cout<<"Ma lop";
	gotoXY(21,5); cout<<"MSSV";
	gotoXY(34,5); cout<<"Ho va ten";
	gotoXY(52,5); cout<<"Ngay sinh";
	gotoXY(64,5); cout<<"DTBTL";
	for (int i=0; i < ds.size()-1; i++)
		if (ds[i].masv == mssv) {
			ve_khungds(1,7);	
			gotoXY(4,8); cout<<1;
			gotoXY(19,8); cout<<ds[i].masv;
			gotoXY(29,8); cout<<ds[i].hoten;
			gotoXY(51,8); cout<<ds[i].ngaythang;
			gotoXY(64,8); cout<<setprecision(2)<< fixed <<ds[i].diemtb;
			break;
		}
	dientt(ds,sv,0);
	sv.gi_file_hososinhvien();
	ds.clear();
	nhapdssv(ds);

	map<int, int> a;
	int n = ds.size() - 1;
	for (int i=0; i < n; i++)
		a[ds[i].masv] = 1;
	a[mssv] = 0;
	ofstream fileout;
	fileout.open("datanew.txt", ios_base::out);
	for (int i=0;i<n;i++) 
		if (a[ds[i].masv]==1)
			{
				fileout<<ds[i].malop<<", "<<ds[i].masv;
				fileout<<ds[i].hoten<<", "<<ds[i].diemtb<<ds[i].ngaythang<<endl;
			}
	fileout.close();
	remove("data.txt");
	rename("datanew.txt","data.txt");
	ds.resize(0);
	nhapdssv(ds);
	quay_lai(ds);
}

void sinhvien::xoa(vector<sinhvien> &ds){
	ShowCur(true);
	map<int, int> a;
	string input;
	int mssv, n = ds.size() - 1;
	for (int i=0; i < n; i++)
		a[ds[i].masv] = 1;
	TextColor(15);
	cout<<"\nNhap MSSV cua sinh vien can xoa: ";
	while(1)
	{
		ve_khung(32,0);
		gotoXY(33,1); cout<<"                    ";
		gotoXY(33,1); getline(cin,input);
				try
				{
					size_t pos;
					stoi(input, addressof(pos));
					if (pos == input.size()) {
						mssv = stoi(input);
						break;
					}
				}
				catch(const std::exception& e) {}
	}
	gotoXY(1,3); cout<<"Xoa sinh vien: ";
	ve_khungds(1,4);
	gotoXY(2,5); cout<<"STT";
	gotoXY(9,5); cout<<"Ma lop";
	gotoXY(21,5); cout<<"MSSV";
	gotoXY(34,5); cout<<"Ho va ten";
	gotoXY(52,5); cout<<"Ngay sinh";
	gotoXY(64,5); cout<<"DTBTL";
	for (int i=0; i < ds.size()-1; i++)
		if (ds[i].masv == mssv) {
			ve_khungds(1,6);	
			gotoXY(4,7); cout<<i+1;
			gotoXY(8,7); cout<<ds[i].malop;
			gotoXY(19,7); cout<<ds[i].masv;
			gotoXY(29,7); cout<<ds[i].hoten;
			gotoXY(51,7); cout<<ds[i].ngaythang;
			gotoXY(64,7); cout<<setprecision(2)<< fixed <<ds[i].diemtb;
			break;
		}
	a[mssv] = 0;
	ofstream fileout;
	fileout.open("datanew.txt", ios_base::out);
	for (int i=0;i<n;i++) 
		if (a[ds[i].masv]==1)
			{
				fileout<<ds[i].malop<<", "<<ds[i].masv;
				fileout<<ds[i].hoten<<", "<<ds[i].diemtb<<ds[i].ngaythang<<endl;
			}
	fileout.close();
	remove("data.txt");
	rename("datanew.txt","data.txt");
	ds.resize(0);
	nhapdssv(ds);
	quay_lai(ds);
}
void dientt(vector<sinhvien> &ds, sinhvien &sv, int i)
{
	string input;
	int dem = 0, loi = 0;
	char c;
	ve_khungds(1,7+3*i);
		gotoXY(8,15); cout<<"                  ";
		gotoXY(4,8+3*i); cout<<i+1;
		gotoXY(7,8+3*i);
		fflush(stdin);
		getline(cin,sv.malop);
		chuanhoaMalop(sv.malop);
		gotoXY(7,8+3*i); cout<<"           ";
		gotoXY(7,8+3*i); cout<<sv.malop;
		sv.masv = 11111111;
		do{
			gotoXY(19,8+3*i); cout<<"         ";
			
			if(sv.masv < 9999999 || sv.masv > 99999999){
				gotoXY(10,20);
				cout<<"Ma sinh vien phai co 8 so, nhap lai !!";	
			}
			
			if(dem > 0){
				gotoXY(10,20);
				cout<<"Ma sinh vien da ton tai, nhap lai ma khac !!";	
			}
			if (loi > 0) {
				gotoXY(10,20);
				cout<<"Nhap sai ma sinh vien, nhap lai !!";
			}
			dem = 0;
			loi = 0;
			gotoXY(19,8+3*i);
			getline(cin,input);
			try
			{
				size_t pos;
                stoi(input, addressof(pos));
				if (pos == input.size())
                    sv.masv = stoi(input);
				else
					loi++;

			}
			catch(const std::exception& e)
			{
				loi++;
			}
			
			gotoXY(10,20); cout<<"                                            ";
			int n = ds.size();
			for(int i = 0; i < n -1 ; i++){
				if(sv.masv == ds[i].masv)
				dem = dem +1;
			}
		}while(dem > 0 || sv.masv < 9999999 || sv.masv > 99999999 || loi > 0);
		fflush(stdin);
		do{
			gotoXY(30,8+3*i); cout<<"                    ";
			gotoXY(30,8+3*i);
			getline(cin,sv.hoten);
			chuanhoaTen(sv.hoten);
			gotoXY(30,8+3*i); cout<<"                    ";
			gotoXY(30,8+3*i); cout<<sv.hoten;
		}while(chuanhoaKitu(sv.hoten) == false );
			do{
				loi = 0;
				gotoXY(52,8+3*i); cout<<"          ";
				gotoXY(54,8+3*i); cout<<"/";
				gotoXY(57,8+3*i); cout<<"/";
				gotoXY(52,8+3*i); cin>>sv.ngaysinh.ngay;
				gotoXY(55,8+3*i); cin>>sv.ngaysinh.thang;
				gotoXY(58,8+3*i); cin>>sv.ngaysinh.nam;
			}while(chuanhoaNgaySinh(sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam) == false);
		do{
			loi = 0;
			gotoXY(64,8+3*i); cout<<"     ";
			gotoXY(64,8+3*i); getline(cin,input);
			try
			{
				size_t pos;
                stof(input, addressof(pos));
				if (pos == input.size())
                    sv.diemtb = stof(input);
				else
					loi++;
			}
			catch(const std::exception& e)
			{
				loi++;
			}
		}while(chuanhoaDiem(sv.diemtb) == false || loi > 0);
}

void sinhvien::nhap_ds(vector<sinhvien> &ds){
	ShowCur(true);
	int t;
	sinhvien sv;
	char c;
	string a[3] = {"Cap nhat", "Huy"};
	TextColor(15);
	cout<<"\nThem moi bao nhieu sinh vien: ";
	TextColor(15);
	ve_khung(32,0);
	gotoXY(33,1); cin>>t;
	TextColor(14);
	ve_khungds(1,4);
	gotoXY(3,5); cout<<"STT";
	gotoXY(9,5); cout<<"Ma lop";
	gotoXY(21,5); cout<<"MSSV";
	gotoXY(34,5); cout<<"Ho va ten";
	gotoXY(51,5); cout<<"Ngay sinh";
	gotoXY(64,5); cout<<"DTBTL";

	for(int i = 0; i < t; i++){
		gotoXY(5,3);
		cout<<"Nhap thong tin sinh vien thu "<<i+1;
		dientt(ds,sv,i);
		ShowCur(false);
		int chon = 0;
		TextColor(10);
		gotoXY(78,15); cout<<a[0];
		TextColor(15);
		gotoXY(90,15); cout<<a[1];
		do{
			c = getch();
			switch(c){
				case 75:
					TextColor(15);
					gotoXY(78 + 12*chon, 15);
					cout<<a[chon];
					chon--;
					if(chon < 0) chon = 1;
					TextColor(10);
					gotoXY(78 +12*chon, 15);
					cout<<a[chon];
					break;
				case 77:
					TextColor(15);
					gotoXY(78 + 12*chon, 15);
					cout<<a[chon];
					chon++;
					if(chon > 1) chon = 0;
					TextColor(10);
					gotoXY(78 + 12*chon, 15);
					cout<<a[chon];
					break;
				case 13:
					if(chon == 0){
						sv.gi_file_hososinhvien();
						ds.clear();
						nhapdssv(ds);
					}
					break;
			}
		}while(c != 13);
	}
	quay_lai(ds);
}

int main(){
	ShowCur(false);
	sinhvien sv;
	vector<sinhvien> ds;
	nhapdssv(ds);
	Menu(ds);
	return 0;
}