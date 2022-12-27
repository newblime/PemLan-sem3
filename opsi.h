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
opsi *ambil_opsiarray();

// panjang dari opsi array
int banyak_opsiarray();

#endif