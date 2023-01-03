#include "data_handling/file_.h"
#include "data_handling/data.h"


file_pajak _file;
bool __sorted = false;

void init_datapajak(std::string namafile){
  if(!__sorted){
    __sorted = true;
    open_file(namafile, &_file);
  }
}

// binary search
int search_datapajak(unsigned long long nik){
  for(int i = 0; i < _file.banyak; i++)
    if(_file.pajak[i].nik == nik)
      return i;
  
  return -1;
}

data_pajak get_datapajak(int idx){
  return _file.pajak[idx];
}