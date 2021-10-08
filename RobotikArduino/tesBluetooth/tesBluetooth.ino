// --------------------------------------------
// Pengujian untuk mengirim teks
//    melalui modul HC-06
// --------------------------------------------                                                                                                                                     

#include <SoftwareSerial.h>

SoftwareSerial bt(7, 8); 

void setup() 
{
  // Atur laju bit komunikasi Bluetooth
  bt.begin(9600);
}

void loop() 
{
  bt.println("Tes..");

  delay(1000); 
}

