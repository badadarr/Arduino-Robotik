// --------------------------------------------
// Pengujian modul Bluetooth untuk membentuk
//    komunikasi dua arah
// --------------------------------------------                                                                                                                                     

#include <SoftwareSerial.h>

SoftwareSerial bt(7, 8); 

void setup() 
{
  bt.begin(9600);
  bt.println("Ketik F, B, L, R, atau S");
}

void loop() 
{
  char dataBt; // Data dari Bluetooth
  
  if (bt.available()) 
  {
    dataBt = bt.read();
    if (dataBt == 'F' || dataBt == 'B' || 
        dataBt == 'L' || dataBt == 'R' ||
        dataBt == 'S') 
    {   
      bt.print("Anda baru saja menekan tombol ");
      bt.println(dataBt);
    }
  }
}

