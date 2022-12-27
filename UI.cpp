#include <bits/stdc++.h>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h>
#include <stdio.h>
#include "opsi.h"
#include "fungsional.h"

using namespace std;

void delay(){
	int delay;
	delay=1;
	while(delay<100000000) {
		delay++;
	}
}

void loadscr(){
	vector<char>load = {'M', 'Y', 'P', 'E', 'R', 'T', 'A', 'M', 'O', 'N', 'A'};
	for(int i = 0; i < load.size(); i++) {
		cout << "\t " << load[i];
		delay();
	}
	sleep(2);
}

//fungsi gotoxy bisa digunain untuk atur posisi output
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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
	string nama;
	long long int nik;
	cout << "Program Duplikat MyPertamina" << endl;
	cout << "Masukkan nama anda\t: "; getline(cin, nama);
	cout << "Masukkan nomor NIK anda : "; cin >> nik;

	system("cls");
	cout << "Selamat datang di aplikasi MyPertamona " << nama << endl;
	cout << "Menu program	: " << endl;

  for(int i = 0; i < banyak_opsiarray(); i++)
    cout << (i+1) << ". " << ambil_opsi(i)->deskripsi_opsi << endl;

	int index;
	cout << "Masukkan pilihan : "; cin >> index;

  ambil_opsi(index-1)->fungsi();
}

void tampilan_lokasi(){
	loading();
  
  buka_lokasi_pom();
}

void harga_bensin(){
	long long int a;
	cout << "Masukkan nomor NIK anda : "; cin >> a;
	cout << "Nama\t: " << endl;
	cout << "NIK\t: " << endl;
	cout << "Pajak Bensin\t: " << endl;
}

void data_pajak(){
	cout << "Nama\t" << endl;
	cout << "NIK\t" << endl;
	cout << "Harga bensin berdasarkan pajak\t: " << endl;
}

void struk(){
	cout << "Nama\t" << endl;
	cout << "NIK\t" << endl;
	long long uang;
	cout << "Masukkan uang anda : "; cin >> uang;
	cout << "Total Pembayaran : " << endl;
	cout << "Kembalian : " << endl;
}

void asda(){}
//asdfasdf