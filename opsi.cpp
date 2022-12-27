#include "opsi.h"


opsi **_opsi_main = NULL;
int _opsi_main_len = 0;



const opsi *ambil_opsi(int i){
  return _opsi_main[i];
}

int banyak_opsiarray(){
  return _opsi_main_len;
}

void _tambah_opsi(opsi *o){
  if(!_opsi_main)
    _opsi_main = (opsi**)malloc(0);
  
  _opsi_main_len++;
  _opsi_main = (opsi**)realloc(_opsi_main, _opsi_main_len*sizeof(opsi*));

  _opsi_main[_opsi_main_len-1] = o;
}


// deklarasi fungsi luar
void tampilan_lokasi();
void harga_bensin();
void data_pajak();
void struk();

void init_opsi(){
  _tambah_opsi(new opsi{
    .nama_opsi = "Lokasi pom bensin",
    .deskripsi_opsi = "Menunjukkan lokasi pom bensin terdekat",
    .fungsi = tampilan_lokasi
  });

  _tambah_opsi(new opsi{
    .nama_opsi = "Perhitungan harga bensin",
    .deskripsi_opsi = "Perhitungan harga bensin berdasarkan pajak",
    .fungsi = harga_bensin
  });

  _tambah_opsi(new opsi{
    .nama_opsi = "Data pajak user",
    .deskripsi_opsi = "Menampilkan data-data user berdasarkan NIK",
    .fungsi = data_pajak
  });

  _tambah_opsi(new opsi{
    .nama_opsi = "Tampilan struk",
    .deskripsi_opsi = "Menampilkan struk pembelian bensin",
    .fungsi = struk
  });
}