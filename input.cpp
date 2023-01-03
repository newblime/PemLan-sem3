#include<iostream>
#include "string"

using namespace std;

void input_nik(unsigned long long *nik){
    cout<<"Masukkan NIK anda\n";
    cin>> *nik;
}

void input_bayarbensin(unsigned long long *bensin){
    cout<< "Masukkan berapa rupiah bensin yang akan dibayar\n";
    cin>> *bensin;
}

void input_bayarliter(float *liter){
    cout<< "Masukkan berapa liter bensin\n";
    cin>> *liter;
}
void input_opsi(int *opsi){
    cout<<"Masukkan Opsi yang akan di pilih\n";
    cin>> *opsi;
}