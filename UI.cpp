#include <bits/stdc++.h>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h>
#include <stdio.h>
#include <conio.h>
#include "opsi.h"
#include "fungsional.h"
#include "input.h"
#include "UI.h"

using namespace std;

string nama_menu;
unsigned long long nik;
COORD coord = {0, 0};


void init_output(){
  SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_OUTPUT | 0x0004);
}

//fungsi gotoxy bisa digunain untuk atur posisi output
void gotoxy(int x, int y){
  printf("\x1b[%d;%dH", x, y);
}

COORD get_cmdsize(){
  CONSOLE_SCREEN_BUFFER_INFO consoleinfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleinfo);

  return consoleinfo.dwSize;
}

void clearScreen(){
  COORD cmdsize = get_cmdsize();
  printf("\x1b[%d;%dH", cmdsize.Y-1, 0);

  for(int i = 0; i < cmdsize.Y; i++){
    printf("\x1b[K");
    printf("\x1b[1A");
  }
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
	clearScreen();
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
    clearScreen();
    system("color 70");
    gotoxy(20,10);
    loadscr();
}

//fungsi loading bisa digunain untuk loadscreen dari fungsi satu ke fungsi lainnya
void loading(){
    system("color 70");
	clearScreen();
	gotoxy(32, 10);

	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int bar1 = 177, bar2 = 219;

	cout << "\n\t\t\t\t\t     L O A D I N G...";
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

void load_struk(){
    system("color 70");
	system("cls");
	gotoxy(32, 10);

	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int bar1 = 177, bar2 = 219;

	cout << "\n\t\t\t\t\t     P E M B U A T A N S T R U K...";
	cout << "\n\n\n\t\t\t\t\t";

	for(int i = 0; i < 25; i++)
		cout << (char)bar1;

	cout << "\r";
	cout << "\t\t\t\t\t";

	for(int i = 0; i < 25; i++){
		cout << (char)bar2;
		Sleep(100);
	}
}

void load_mencari(){
	system("color 70");
	system("cls");
	gotoxy(32, 10);

	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int bar1 = 177, bar2 = 219;

	cout << "\n\t\t\t\t\t     M E N C A R I D A T A...";
	cout << "\n\n\n\t\t\t\t\t";

	for(int i = 0; i < 25; i++)
		cout << (char)bar1;

	cout << "\r";
	cout << "\t\t\t\t\t";

	for(int i = 0; i < 25; i++){
		cout << (char)bar2;
		Sleep(100);
	}
}

void tampilan_menu(){
	system("cls");

	cout << "Program Duplikat MyPertamina" << endl;
	cout << "Masukkan nama anda\t: "; getline(cin, nama_menu);
	cout << "Masukkan nomor NIK anda : "; cin >> nik;

	clearScreen();

	cout << "Selamat datang di aplikasi MyPertamona " << nama_menu << endl;
	cout << "Menu program\t: " << endl;

  	for(int i = 0; i < banyak_opsiarray(); i++)
    	cout << (i+1) << ". " << ambil_opsi(i)->deskripsi_opsi << endl;

  _printf("", 231, 232);

	int index;
  input_opsi(&index);

  	ambil_opsi(index-1)->fungsi();
}

void tampilan_lokasi(){
	loading();
  	buka_lokasi_pom();
}

void harga_bensin(){
	clearScreen();
	gotoxy(30, 14);
	cout << "Nama: " << nama_menu << endl;
	cout << "NIK : " << nik << endl;
	loading();
	unsigned long long hargabensin = hitung_hargabensin(get_datapajak(search_datapajak(nik)), 10000);
	cout << "Pajak Bensin : " << hargabensin << endl;
}

// namanya jangan sama dengan struct data_pajak
void _data_pajak(){
	system("cls");
	gotoxy(30, 14);
	cout << "Nama\t: " << nama_menu << endl;
	cout << "NIK\t: " << nik << endl;
	load_mencari();
	cout << "Harga bensin berdasarkan pajak\t: " << endl;
	search_datapajak(nik);
}

void struk(){
	clearScreen();
	long long uang;
	pembuatan_struk();
	call_border();
	cout << "Nama\t: " << nama_menu << endl;
	cout << "NIK\t: " << nik << endl;
	cout << "Masukkan uang anda\t: "; cin >> uang;
	cout << "Total Pembayaran\t: " << endl;
	cout << "Kembalian\t: " << endl;
}