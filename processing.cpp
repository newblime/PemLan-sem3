#include "fungsional.h"

// menghitung harga bensin berdasarkan pajak pengguna
unsigned long long hitung_hargabensin(data_pajak dp, long long bensin){
    float ratio;
    if(dp.pajak_sekarang <= 5000000)
    {
        ratio = (dp.pajak_sekarang-0)/(5000000-0);
        
        return (bensin/2 * ratio)+  bensin/2;
    }
    else if(dp.pajak_sekarang > 5000000 )
    {
        if (dp.pajak_sekarang > 12000000)
        {
            dp.pajak_sekarang = 12000000;
        }
        ratio = (dp.pajak_sekarang-5000000)/(12000000-5000000);
        return (bensin * ratio)+  bensin;
    }
}
// menghitung total harga bensin dengan jumlah liter
unsigned long long hitung_literbensin(float liter, data_pajak dp, unsigned long long hargabensin){
    return hitung_hargabensin(dp, hargabensin) * liter;
}
// menghitung liter dari bensin yang dibeli
float hitung_totalbensin(unsigned long long uang, data_pajak dp, unsigned long long hargabensin)
{
    return ((float)uang/1000000) / ((float)hitung_hargabensin(dp, hargabensin)/1000000);
}