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
  for(int i = 0; i < pajak->banyak; i++){
    data_pajak *currdp = &pajak->pajak[i];

    int namesize;
    file.read(reinterpret_cast<char*>(&namesize), sizeof(int));

    char nama[namesize+1];
    file.read(nama, namesize);
    nama[namesize] = '\0';

    currdp->nama = string(nama);

    file.read(reinterpret_cast<char*>(&currdp->nik), sizeof(currdp->nik));
    file.read(reinterpret_cast<char*>(&currdp->pajak_sekarang), sizeof(currdp->pajak_sekarang));
  }
  
  return true;
}

void save_file(std::string nama_file, file_pajak *pajak){
  using namespace std;

  ofstream file;
  file.open(nama_file, file.ate);
  
  int code = FILE_CODE;
  file.write(reinterpret_cast<char*>(&code), sizeof(int));
  file.write(reinterpret_cast<char*>(&pajak->banyak), sizeof(int));
  
  for(int i = 0; i < pajak->banyak; i++){
    data_pajak *currdp = &pajak->pajak[i];

    int namelen = currdp->nama.length();
    file.write(reinterpret_cast<char*>(&namelen), sizeof(int));

    file.write(currdp->nama.c_str(), namelen);
    file.write(reinterpret_cast<char*>(&currdp->nik), sizeof(currdp->nik));
    file.write(reinterpret_cast<char*>(&currdp->pajak_sekarang), sizeof(currdp->pajak_sekarang));
  }
  
  free(pajak->pajak);
}

#endif