#include "Windows.h"
#include "string"

void buka_lokasi_pom(){
  ShellExecute(NULL, "open", "https://www.google.com/maps/dir//spbu+terdekat", NULL, NULL, SW_SHOWNORMAL);
}