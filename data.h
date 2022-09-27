#ifndef DATA_HEADER
#define DATA_HEADER

struct data_pajak{
  unsigned long nik;
  unsigned long pajak_sekarang;
};

// pengambilan data pajak
void init_datapajak();

// mencari data pajak berdasarkan nik
data_pajak search_datapajak(unsigned long nik);


#endif