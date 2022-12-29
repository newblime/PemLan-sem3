#ifndef FUNGSIONAL_HEADER
#define FUNGSIONAL_HEADER

#include "data_handling/data.h"
#include "opsi.h"

/*      perhitungan harga bensin      */

// menghitung harga bensin berdasarkan data pajak pengguna
unsigned long long hitung_hargabensin(data_pajak data_pengguna, long long harga_bensin);

// menhitung total harga bensin dengan jumlah liter
unsigned long long hitung_literbensin(float liter, data_pajak dp, unsigned long long hargabensin);

// menghitung liter bensin yang dibeli
float hitung_totalbensin(unsigned long long uang, data_pajak dp, unsigned long long hargabensin)

/*      untuk pengurusan data     */

// pengambilan data pajak
void init_datapajak();

// mencari index data pajak berdasarkan nik
// fungsi ini akan return -1 jika tidak ada nik yang cocok di database
int search_datapajak(unsigned long long nik);

// mengambil data pajak berdasarkan index
data_pajak get_datapajak(int idx);


void buka_lokasi_pom();


#endif