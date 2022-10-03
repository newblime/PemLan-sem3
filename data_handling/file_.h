#ifndef FILE_P_HEADER
#define FILE_P_HEADER

#include "fstream"
#include "string"

#include "data.h"

#define FILE_CODE 0x12345678

struct file_pajak{
  int banyak;
  data_pajak *pajak;
};

// kalau true, file nya bisa dibuka
// kalau false, file nya tidak bisa dibuka
bool open_file(std::string nama_file, file_pajak *pajak){
  using namespace std;

  ifstream file;
  file.open(nama_file);

  if(!file.is_open())
    return false;
  
  int code;
  file.read(reinterpret_cast<char*>(&code), sizeof(int));

  if(code != FILE_CODE)
    return false;
  
  file.read(reinterpret_cast<char*>(&pajak->banyak), sizeof(int));

  pajak->pajak = (data_pajak*)malloc(sizeof(data_pajak)*pajak->banyak);
  for(int i = 0; i < pajak->banyak; i++)
    file.read(reinterpret_cast<char*>(&pajak->pajak[i]), sizeof(data_pajak));
  
  return true;
}

void save_file(std::string nama_file, file_pajak *pajak){
  using namespace std;

  ofstream file;
  file.open(nama_file, file.ate);
  
  int code = FILE_CODE;
  file.write(reinterpret_cast<char*>(&code), sizeof(int));
  file.write(reinterpret_cast<char*>(&pajak->banyak), sizeof(int));
  
  for(int i = 0; i < pajak->banyak; i++)
    file.write(reinterpret_cast<char*>(&pajak->pajak[i]), sizeof(data_pajak));
  
  free(pajak->pajak);
}

#endif