#include "data_handling/file_.h"
#include "data_handling/data.h"


file_pajak _file;
bool __sorted = false;

// bubble sort
void _sorting_dp(){
  bool _sort = true;
  while(_sort){
    _sort = false;
    for(int i = 0; i < (_file.banyak-1); i++){
      if(_file.pajak[i].nik > _file.pajak[i=1].nik){
        auto _p = _file.pajak[i];
        _file.pajak[i] = _file.pajak[i+1];
        _file.pajak[i+1] = _p;

        _sort = true;
      }
    }
  }
}

void init_datapajak(){
  if(!__sorted){
    __sorted = true;
    open_file("data.bin", &_file);

    _sorting_dp();
  }
}

// binary search
int search_datapajak(unsigned long long nik){
  int i = -1;
  int l = 0, r = _file.banyak-1;

  do{
    if(l >= r)
      break;

    int idx = (l+r)/2;
    unsigned long long _nik = _file.pajak[idx].nik;
    if(_nik == nik)
      i = idx;
    else if(_nik > nik)
      l = idx+1;
    else if(_nik < nik)
      r = idx;
  }
  while(i >= 0);

  return i;
}

data_pajak get_datapajak(int idx){
  return _file.pajak[idx];
}