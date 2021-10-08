// -----------------------------
// Pengiriman data menggunakan 
//   modul pengirim RF 315MHz 
// -----------------------------

#include <RCSwitch.h>

RCSwitch rc = RCSwitch();

char perintah[5] = {'F', 'B', 'L', 'R', 'S'};

void setup() 
{
  Serial.begin(9600);
  // Pin untuk mengirim data
  rc.enableTransmit(2);
}

void loop() 
{
  // Membangkitkan bilangan acak antara 0 s/d 4
  int bilangan = random(5);

  // Memperoleh karakter di perintah
  char karakter = perintah[bilangan];
  
  rc.send(karakter, 8);

  delay(1000);
}

