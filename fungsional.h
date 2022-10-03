#ifndef FUNGSIONAL_HEADER
#define FUNGSIONAL_HEADER

#include "data_handling/data.h"
#include "opsi.h"

/*      perhitungan harga bensin      */

// menghitung harga bensin berdasarkan data pajak pengguna
unsigned long hitung_hargabensin(data_pajak data_pengguna);

// menampilkan semua opsi yang ada berdasarkan array opsi
void tampilkan_opsi(opsi *opsi_array, int banyak_opsi);

// menampilkan struk harga bensin
void tampilkan_hargabensin(data_pajak data_pengguna, unsigned long harga);


/*      untuk pengurusan data     */

// pengambilan data pajak
void init_datapajak();

// mencari data pajak berdasarkan nik
data_pajak search_datapajak(unsigned long nik);


#endif