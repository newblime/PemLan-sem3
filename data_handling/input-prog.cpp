#include "iostream"
#include "conio.h"
#include "file_.h"
#include "data.h"

using namespace std;

void edit_data(data_pajak *dp){
  system("cls");
  cout << "Masukkan NIK: ";
  cin >> dp->nik;
  fflush(stdin);

  unsigned long long gaji;
  cout << "Masukkan penghasilan Tahun ini: Rp.";
  cin >> gaji;
  fflush(stdin);

  int anggota;
  cout << "Berapa anggota keluarga anda? (jawab 0 jika tidak berkeluarga): ";
  cin >> anggota;

  unsigned long long ptkp = 54000000;
  if(anggota > 0)
    ptkp += 4500000 * min(3, anggota);
  
  if(ptkp > gaji){
    dp->pajak_sekarang = 0;
    return;
  }

  unsigned long long pkp = gaji - ptkp;
  int tp = 5;
  if(pkp > 5000000000)
    tp = 50;
  else if(pkp > 250000000)
    tp = 25;
  else if(pkp > 50000000)
    tp = 15;

  dp->pajak_sekarang = (pkp/100)*tp;
}

int main(){
  bool b = true;
  while(b){
    system("cls");
    cout << "Pencet 'g' untuk menggabung data dari kedua file.\nPencet 'e' untuk mengedit salah satu file.\nPencet 'q' untuk keluar dari program." << endl << endl;
    char _c = _getch();
    switch(_c){
      // quit
      break; case 'q':
        b = false;
      
      // gabung
      break; case 'g':{
        cout << "Masukkan file pertama: ";
        string namafile1;
        getline(cin, namafile1);

        cout << "Masukkan file kedua: ";
        string namafile2;
        getline(cin, namafile2);

        file_pajak fp1, fp2;
        if(!open_file(namafile1, &fp1))
          break;

        if(!open_file(namafile2, &fp2)){
          free(fp1.pajak);
          break;
        }

        int idx = fp1.banyak;
        fp1.banyak += fp2.banyak;
        fp1.pajak = (data_pajak*)realloc(fp1.pajak, sizeof(data_pajak)*fp1.banyak);

        for(int i = 0; i < fp2.banyak; i++)
          fp1.pajak[idx+i] = fp2.pajak[i];
        
        save_file(namafile1, &fp1);
        
        free(fp2.pajak);
      }

      // edit file
      break; case 'e':{
        cout << "Masukkan file yang ingin diedit: ";
        string namafile;
        getline(cin, namafile);

        file_pajak fp;
        if(!open_file(namafile, &fp)){
          fp.pajak = (data_pajak*)calloc(1, sizeof(data_pajak));
          fp.banyak = 1;
        }

        int data_idx = 0;

        bool b1 = true;
        while(b1){
          system("cls");
          cout << "Nama file: " << namafile << endl;
          cout << "Data ke-" << data_idx+1 << endl;
          cout << endl;
          cout << "NIK: " << fp.pajak[data_idx].nik << endl;
          cout << "Pajak penghasilan Tahun ini: Rp." << fp.pajak[data_idx].pajak_sekarang << endl;
          cout << endl << endl;
          cout << "Pencet 'n' atau arrow keys kanan atau kiri untuk mengganti index.\nPencet 'e' untuk mengedit data.\nPencet 't' untuk menambahkan data.\nPencet 'h' untuk menghapus data.\nPencet 'f' untuk kembali ke menu awal.\nPencet 'q' untuk keluar dari program." << endl << endl;
          char c = _getch();
          switch(c){
            // quit
            break; case 'q':
              b1 = false;
              b = false;
            
            // ganti fungsi
            break; case 'f':
              b1 = false;
            
            // ganti nomor
            break; case 'n':{
              system("cls");
              cout << "Masukkan angka index: ";
              cin >> data_idx;
              fflush(stdin);
            }

            // edit data
            break; case 'e':{
              edit_data(&fp.pajak[data_idx]);
            }

            // tambah data
            break; case 't':{
              data_pajak d;
              edit_data(&d);

              fp.banyak++;
              realloc(fp.pajak, sizeof(data_pajak)*fp.banyak);

              data_idx = fp.banyak-1;
              fp.pajak[data_idx] = d;
            }

            // menghapus data
            break; case 'h':{
              if(fp.banyak > 1){
                for(int i = data_idx; i < (fp.banyak-1); i++)
                  fp.pajak[i] = fp.pajak[i+1];
                
                fp.banyak--;
                fp.pajak = (data_pajak*)realloc(fp.pajak, sizeof(data_pajak)*fp.banyak);

                if(data_idx >= fp.banyak)
                  data_idx = fp.banyak-1;
              }
              else{
                fp.pajak[0] = data_pajak();
              }
            }

            // ganti index
            break; case 0:{
              char c1 = _getch();
              switch(c1){
                // kanan
                break; case 77:{
                  if(data_idx < (fp.banyak-1))
                    data_idx++;
                }

                // kiri
                break; case 75:{
                  if(data_idx > 0)
                    data_idx--;
                }
              }
            }
          }
        }

        save_file(namafile, &fp);
      }
    }
  }

  system("cls");
}