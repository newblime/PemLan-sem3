#include "fungsional.h"
#include "opsi.h"
#include "UI.h"

#include "iostream"

using namespace std;

int main(){
  init_datapajak("data_penggunaan.bin");

  loadscreen();

  init_opsi();

  // nggak kepake fungsi nya
  // vector<string> svect;
  // print(svect);

  tampilan_menu();
}