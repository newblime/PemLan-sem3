#ifndef FUNGSIONAL_HEADER
#define FUNGSIONAL_HEADER

#include "data.h"
#include "opsi.h"

// menghitung harga bensin berdasarkan data pajak pengguna
unsigned long hitung_hargabensin(data_pajak data_pengguna);

// menampilkan semua opsi yang ada berdasarkan array opsi
void tampilkan_opsi(opsi *opsi_array, int banyak_opsi);

// menampilkan struk harga bensin
void tampilkan_hargabensin(data_pajak data_pengguna, unsigned long harga);

#endif