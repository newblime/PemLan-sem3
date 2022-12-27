#include "opsi.h"


opsi *_opsi_main = NULL;


void perhitungan_bensin(){
  cout << "test" << endl;
}

void pilihan_identitas(){
  tampil_identitas(nama, nik, gaji);
}


void _tambah_opsi(opsi o){

}

void init_opsi(){
  _tambah_opsi(opsi{
    .nama_opsi = "Perhitungan harga bensin",
    .deskripsi_opsi = "Memperhitungkan total bensin berdasarkan pajak gaji.",
    .fungsi = perhitungan_bensin
  });

  _tambah_opsi(opsi{....});
}