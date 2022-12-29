#include <bits/stdc++.h>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h>
#include <stdio.h>
#include <conio.h>
#include "opsi.h"
#include "fungsional.h"

using namespace std;

string nama;
long long int nik;
COORD coord = {0, 0};

//fungsi gotoxy bisa digunain untuk atur posisi output
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(){
	int delay;
	delay=1;
	while(delay<100000000) {
		delay++;
	}
}

void border(){
	int i, style = 178;
	for(i = 0; i <= 70; i++){
		gotoxy(i, 0);
		cout << (char)style;
		gotoxy(i, 24);
		cout << (char)style;
	}
	for(i = 0; i <= 24; i++){
		gotoxy(0, i);
		cout << (char)style;
		gotoxy(70, i);
		cout << (char)style;
	}
}

void call_border(){
	system("cls");
	border();
	getch();
}

void print(vector<string>&stringVec){
    cout << setfill( '*' ) << setw( 40 ) << '*' <<  endl;
    for( int i=0; i< stringVec.size(); i++ ) {
        cout << '*' << left << setfill(' ' ) << setw( 40 - 2 ) << stringVec[i] << '*'<< endl;
    }
    cout << setfill( '*' ) << setw( 40 ) << '*' <<  endl;
}

void loadscr(){
	vector<char>load = {'M', 'Y', 'P', 'E', 'R', 'T', 'A', 'M', 'O', 'N', 'A'};
	for(int i = 0; i < load.size(); i++) {
		cout << "\t " << load[i];
		delay();
	}
	sleep(2);
}

void loadscreen(){
    system("cls");
    system("color 70");
    gotoxy(20,10);
    loadscr();
}

//fungsi loading bisa digunain untuk loadscreen dari fungsi satu ke fungsi lainnya
void loading(){
    system("color 70");
	system("cls");
	gotoxy(32, 10);

	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int bar1 = 177, bar2 = 219;

	cout << "\n\t\t\t\t\t    L O A D I N G...";
	cout << "\n\n\n\t\t\t\t\t";

	for(int i = 0; i < 25; i++)
		cout << (char)bar1;

	cout << "\r";
	cout << "\t\t\t\t\t";

	for(int i = 0; i < 25; i++){
		cout << (char)bar2;
		Sleep(100);
	}

	//cout << "\n\n\t\t\t\t\t" << (char)1 << "!";
	//system("pause");
}

void tampilan_menu(){
	system("cls");
	gotoxy(100, 14);
	cout << "Program Duplikat MyPertamina" << endl;
	cout << "Masukkan nama anda\t: "; getline(cin, nama);
	cout << "Masukkan nomor NIK anda : "; cin >> nik;

	cout << "Selamat datang di aplikasi MyPertamona" << nama << endl;
	cout << "Menu program\t: " << endl;

  	for(int i = 0; i < banyak_opsiarray(); i++)
    	cout << (i+1) << ". " << ambil_opsi(i)->deskripsi_opsi << endl;

	int index;

	cout << "Masukkan pilihan\t: "; cin >> index;

  	ambil_opsi(index-1)->fungsi();
}

void tampilan_lokasi(){
	loading();
  	buka_lokasi_pom();
}

void harga_bensin(){
	cout << "Nama: " << nama << endl;
	cout << "NIK : " << nik << endl;
	loading();
	cout << "Pajak Bensin : " << endl;
	unsigned long long hargabensin = hitung_hargabensin(get_datapajak(search_datapajak(nik)), 10000);
}

// namanya jangan sama dengan struct data_pajak
void _data_pajak(){
	gotoxy(30, 14);
	cout << "Nama\t: " << nama << endl;
	cout << "NIK\t: " << nik << endl;
	cout << "Harga bensin berdasarkan pajak\t: " << endl;
}

void struk(){
	cout << "Nama\t: " << nama << endl;
	cout << "NIK\t: " << nik << endl;
	long long uang;
	cout << "Masukkan uang anda\t: "; cin >> uang;
	cout << "Total Pembayaran\t: " << endl;
	cout << "Kembalian\t: " << endl;
}
