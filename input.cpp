#include<iostream>
#include "string"
#include "UI.h"

using namespace std;

void input_user(string *user){
    cout<<"Masukkan Username\t: ";
    getline(cin, *user);
}

void input_nik(unsigned long long *nik){
    cout<<"Masukkan NIK anda\t: ";
    cin>> *nik;
}

void input_bayarbensin(unsigned long long *bensin){
    cout<< "Masukkan berapa rupiah bensin yang akan dibayar\t: ";
    cin>> *bensin;
}

void input_bayarliter(float *liter){
    cout<< "Masukkan berapa liter bensin\t: ";
    cin>> *liter;
}
void input_opsi(int *opsi){
    cout<<"Masukkan Opsi yang akan di pilih : ";
    cin>> *opsi;
}