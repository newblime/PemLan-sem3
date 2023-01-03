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


// fungsi untuk mengamibl size pada terminal
COORD besarTerminal(){
  CONSOLE_SCREEN_BUFFER_INFO consoleinfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleinfo);

  return consoleinfo.dwSize;
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
		set_cursor_pos(i, 0);
		cout << (char)style;
		set_cursor_pos(i, 24);
		cout << (char)style;
	}
	for(i = 0; i <= 24; i++){
		set_cursor_pos(0, i);
		cout << (char)style;
		set_cursor_pos(70, i);
		cout << (char)style;
	}
}

void call_border(){
	clr_terminal();
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
    clr_terminal();
    system("color 70");
    set_cursor_pos(20,10);
    loadscr();
}

//fungsi loading bisa digunain untuk loadscreen dari fungsi satu ke fungsi lainnya
void loading(){
    system("color 70");
	clr_terminal();
	set_cursor_pos(32, 10);

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
	clr_terminal();

	cout << "Program Duplikat MyPertamina" << endl;
  input_user(&nama_menu);
  input_nik(&nik);

	clr_terminal();

	cout << "Selamat datang di aplikasi MyPertamona " << nama_menu << endl;
	cout << "Menu program\t: " << endl;

  	for(int i = 0; i < banyak_opsiarray(); i++)
    	cout << (i+1) << ". " << ambil_opsi(i)->deskripsi_opsi << endl;

	int index;
  input_opsi(&index);

  	ambil_opsi(index-1)->fungsi();
}

void tampilan_lokasi(){
	loading();
  	buka_lokasi_pom();
}

void harga_bensin(){
	clr_terminal();
	set_cursor_pos(30, 14);
	cout << "Nama: " << nama_menu << endl;
	cout << "NIK : " << nik << endl;
	loading();
	unsigned long long hargabensin = hitung_hargabensin(get_datapajak(search_datapajak(nik)), 10000);
	cout << "Pajak Bensin : " << hargabensin << endl;
}

// namanya jangan sama dengan struct data_pajak
void _data_pajak(){
	clr_terminal();
	set_cursor_pos(30, 14);
	cout << "Nama\t: " << nama_menu << endl;
	cout << "NIK\t: " << nik << endl;
	load_mencari();
	cout << "Harga bensin berdasarkan pajak\t: " << endl;
	search_datapajak(nik);
}

void struk(){
	clr_terminal();
	long long uang;
	set_cursor_pos(30, 14);
	call_border();
	cout << "Nama\t: " << nama_menu << endl;
	cout << "NIK\t: " << nik << endl;
	cout << "Masukkan uang anda\t: "; cin >> uang;
	cout << "Total Pembayaran\t: " << endl;
	cout << "Kembalian\t: " << endl;
}