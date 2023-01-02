#ifndef UI_HEADER
#define UI_HEADER

#include "vector"
#include "string"

void init_output();

void delay();
void loadscr();
void gotoxy();
void loadscreen();
void loading();
void tampilan_menu();
void tampilan_lokasi();
void harga_bensin();
void _data_pajak();
void struk();
void print(std::vector<std::string>&);
void border();
void call_border();
void load_struk();
void load_mencari();

// pemanggilan fungsi sama seperti printf, namun dengan tambahan code pewarnaan
// parameter paling akhir sama seperti parameter yang dikasih para printf
//
// menggunakan library luar
void _printf(const char *str, short fcode, short bcode);

#endif