#include "fungsional.h"
#include "opsi.h"

#include "iostream"

using namespace std;

int main(){
  init_opsi();

  const opsi *_o = ambil_opsiarray();
  for(int i = 0; i < banyak_opsiarray(); i++){
    cout << i+1 << ". " << _o[i].nama_opsi << endl;

    /*
    1. Perhitungan harga bensin
        Memperhitungkan total bensin berdasarkan pajak gaji.

    2. ....
        ....
    */
  }

  cout << "Pilih mana?";

  int pilih;

  _o[pilih-1].fungsi();
  /*
  test
  */
}