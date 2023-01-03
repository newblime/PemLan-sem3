#ifndef UI_HEADER
#define UI_HEADER

#include "vector"
#include "string"

void init_output();

void delay();
void loadscr();
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
__declspec(dllimport) void _printf(const char *str, unsigned short fcode, unsigned short bcode, ...);

// fungsi ini digunakan ketika memerlukan menghapus tampilan pada terminal
//
// menggunakan library luar
__declspec(dllimport) void clr_terminal();

// fungsi ini digunakan untuk mengubah posisi cursor
//
// menggunakan library luar
__declspec(dllimport) void set_cursor_pos(int x, int y);

#endif