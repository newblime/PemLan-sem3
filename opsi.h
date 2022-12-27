#ifndef OPSI_HEADER
#define OPSI_HEADER

#include "string"

// tipe data fungsi (fungsi disimpan dalam bentuk pointer, dan dapat langsung dipakai sebagai fungsi biasa)
typedef void(*FungsiOpsi)();

struct opsi{
  std::string nama_opsi;
  std::string deskripsi_opsi;

  // cara penggunaan, opsi.fungsi(); atau opsi[n].fungsi();
  FungsiOpsi fungsi;
};

// pembuatan opsi array
void init_opsi();

// pengambilan opsi array yang dibuat diawal
const opsi *ambil_opsiarray();

// panjang dari opsi array
int banyak_opsiarray();

void delay();
void loadscr();
void gotoxy();
void loadscreen();
void loading();
void tampilan_menu();
void tampilan_lokasi();
void harga_bensin();
void data_pajak();
void struk();

void tambah_opsi(opsi o);

void init_opsi(){
  tambah_opsi(opsi{
		.nama_opsi = "Delay",
		.deskripsi_opsi = "Menyela waktu sebelum ke kode berikutnya",
		.fungsi = delay
	});

	tambah_opsi(opsi{
		.nama_opsi = "Load screen array",
		.deskripsi_opsi = "Perulangan loadscreen untuk awal program",
		.fungsi = loadscr
	});

	tambah_opsi(opsi{
		.nama_opsi = "Loading screen awal program",
		.deskripsi_opsi = "Menampilkan loading screen",
		.fungsi = loadscreen
	});

	tambah_opsi(opsi{
		.nama_opsi = "Loading bar",
		.deskripsi_opsi = "Menampilkan progress loading bar",
		.fungsi = loading
	});

	tambah_opsi(opsi{
		.nama_opsi = "Tampilan menu",
		.deskripsi_opsi = "Menampilkan list menu program", 
		.fungsi = tampilan_menu
	});

  tambah_opsi(opsi{
    .nama_opsi = "Lokasi pom bensin",
    .deskripsi_opsi = "Menunjukkan lokasi pom bensin lewat web",
    .fungsi = tampilan_lokasi
  });

  tambah_opsi(opsi{
    .nama_opsi = "Perhitungan harga bensin",
    .deskripsi_opsi = "Menghitungan harga bensin user berdasarkan NIK",
    .fungsi = harga_bensin
  });

  tambah_opsi(opsi{
    .nama_opsi = "Data pajak user",
    .deskripsi_opsi = "Menampilkan data-data user",
    .fungsi = data_pajak
  });

  tambah_opsi(opsi{
    .nama_opsi = "Tampilan struk",
    .deskripsi_opsi = "Menampilkan struk pembelian bensin",
    .fungsi = struk
  });
}

//asdasda
#endif