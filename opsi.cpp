#include "opsi.h"


opsi *_opsi_main = NULL;
int _opsi_main_len = 0;



const opsi *ambil_opsiarray(){
  return _opsi_main;
}

int banyak_opsiarray(){
  return _opsi_main_len;
}

void _tambah_opsi(opsi o){
  if(!_opsi_main)
    _opsi_main = (opsi*)malloc(0);
  
  _opsi_main_len++;
  _opsi_main = (opsi*)realloc(_opsi_main, _opsi_main_len*sizeof(opsi));

  _opsi_main[_opsi_main_len] = o;
}

void init_opsi(){
  
}