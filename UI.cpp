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

std::vector<std::pair<const char*, unsigned long long>> _tipebensin = {
  {"Solar", 7000},
  {"Pertalite", 10000},
  {"Dexlite", 13000},
  {"Pertamax", 17000}
};


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

  int len = load.size() + (4 * max((int)load.size()-1, 0));

  COORD sterm = besarTerminal();
  set_cursor_pos((sterm.X-len)/2, sterm.Y/2);

	for(int i = 0; i < load.size(); i++) {
		cout << "    " << load[i];
		delay();
	}
	sleep(2);
}

void loadscreen(){
    _printf("", 232, 15);
    clr_terminal();
    loadscr();
}

void loadingbar(string load){
  SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int bar1 = 177, bar2 = 219;

  COORD sterm = besarTerminal();

  set_cursor_pos((sterm.X-load.length())/2, sterm.Y/2-2);
  cout << load;

  set_cursor_pos((sterm.X-25)/2, sterm.Y/2+2);
  for(int i = 0; i < 25; i++)
    cout << (char)bar1;
  
  set_cursor_pos((sterm.X-25)/2, sterm.Y/2+2);
  for(int i = 0; i < 25; i++){
    cout << (char)bar2;
    Sleep(100);
  }
}

//fungsi loading bisa digunain untuk loadscreen dari fungsi satu ke fungsi lainnya
void loading(){
  _printf("", 232, 15);
	clr_terminal();
	
  loadingbar("L O A D I N G ...");
}

void load_struk(){
    _printf("", 232, 15);
	clr_terminal();

  loadingbar("P E M B U A T A N  S T R U K ...");
}

void load_mencari(){
	_printf("", 232, 15);
	clr_terminal();
	
  loadingbar("M E N C A R I  D A T A ...");
}

void tampilan_menu(){
	clr_terminal();
	set_cursor_pos(35, 0);
	cout << "Program Duplikat MyPertamona" << endl;

  fflush(stdin);

  input_user(&nama_menu);
  input_nik(&nik);

	int idx = search_datapajak(nik);
  if(idx == -1){
    cout << "NIK tidak ditemukan." << endl;
    _getch();
    tampilan_menu();
    return;
  }

	clr_terminal();

	while(true){
		set_cursor_pos(35, 0);
		cout << "Selamat datang di aplikasi MyPertamona " << nama_menu << endl;
		cout << endl;

			cout << "Menu program\t: " << endl;

			for(int i = 0; i < banyak_opsiarray(); i++)
				cout << (i+1) << ". " << ambil_opsi(i)->deskripsi_opsi << endl;
      
      cout << "0. Keluar dari program" << endl;
	    cout << endl;

			int index;
			input_opsi(&index);

			if(index > 0)
        if(index <= banyak_opsiarray())
				  ambil_opsi(index-1)->fungsi();
        else
          continue;
			else{
        _printf("", 231, 0);
        clr_terminal();
        _printf("", 46, 0);
				cout << "Terimakasih sudah memakai MyPertamona " << (char)1 << endl;
        _printf("", 231, 0);
				break;
      }
      
      cout << "Pencet apapun untuk melanjutkan..." << endl;
      _getch();
    
      clr_terminal();
	}
}

void tampilan_lokasi(){
	loading();
  	buka_lokasi_pom();
}

void harga_bensin(){
	clr_terminal();

  cout << "Tipe-Tipe bensin" << endl;
  for(int i = 0; i < _tipebensin.size(); i++)
    cout << i+1 << ". " << _tipebensin[i].first << "\t: Rp." << _tipebensin[i].second << endl;
  
  cout << endl;

  int opsi;
  input_opsi(&opsi);

  if(opsi <= 0 || opsi > _tipebensin.size()){
    cout << "Tipe bensin salah." << endl;
    return;
  }

	loading();

	unsigned long long hargabensin = hitung_hargabensin(get_datapajak(search_datapajak(nik)), _tipebensin[opsi-1].second);
  cout << endl;
	clr_terminal();
	cout << "Nama\t\t\t: " << nama_menu << endl;
	cout << "NIK\t\t\t: " << nik << endl;
	cout << "Harga akhir bensin\t: " << hargabensin << endl;
}

// namanya jangan sama dengan struct data_pajak
void _data_pajak(){
	set_cursor_pos(20, 14);
	load_mencari();
  cout << endl;
	clr_terminal();
	cout << "Nama\t\t: " << nama_menu << endl;
	cout << "NIK\t\t: " << nik << endl;
	cout << "Pajak Gaji\t: ";
	cout << get_datapajak(search_datapajak(nik)).pajak_sekarang << endl;
}

void struk(){
	clr_terminal();
	unsigned long long uang;

  cout << "Tipe-tipe bensin" << endl;
  for(int i = 0; i < _tipebensin.size(); i++)
    cout << i+1 << ". " << _tipebensin[i].first << "\t: Rp." << _tipebensin[i].second << endl;
  
  cout << endl;
  
  int opsi;
  input_opsi(&opsi);

  if(opsi <= 0 || opsi > _tipebensin.size()){
    cout << "Tipe bensin salah." << endl;
    return;
  }

  data_pajak currdp = get_datapajak(search_datapajak(nik));
  unsigned long long harganormal = _tipebensin[opsi].second;
  unsigned long long hargasub = hitung_hargabensin(currdp, harganormal);

	input_bayarbensin(&uang);
	float total = hitung_totalbensin(uang, get_datapajak(search_datapajak(nik)), harganormal);

	load_struk();
	clr_terminal();
	cout << "Nama\t: " << nama_menu << endl;
	cout << "NIK\t: " << nik << endl;
  cout << endl;
  cout << "====================================" << endl;
  cout << "Harga normal bensin\t\t: " << harganormal << endl;
  cout << "Harga perhitungan\t\t: " << hargasub << endl;
  cout << endl;
	cout << "Liter bensin yang dibeli\t: " << total << "L" << endl;
}