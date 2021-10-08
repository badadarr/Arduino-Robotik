// -----------------------------
// Sketsa untuk remote control 
//    yang berfungsi sebagai
//    pengendali robot RF315
// -----------------------------

#include <RCSwitch.h>

const int PIN_TOMBOL = A0;

RCSwitch rc = RCSwitch();

void setup() 
{
  // Pin untuk mengirim data
  rc.enableTransmit(2);
}

void loop() 
{
  // Baca sensor Keyes AD Key
  int nilaiPin = analogRead(PIN_TOMBOL);
  if (nilaiPin == 0) 
  {
    // Tombol SW1 ditekan
    rc.send('L', 8);
  }  
  else if (nilaiPin <= 300) 
  {
    // Tombol SW2 ditekan
    rc.send('F', 8);
  }
  else if (nilaiPin <= 490) 
  {
    // Tombol SW3 ditekan
    rc.send('B', 8);
  }
  else if (nilaiPin <= 700) 
  {
    // Tombol SW4 ditekan
    rc.send('R', 8);
  }
  else if (nilaiPin <= 990) 
  {
    // Tombol SW5 ditekan    
    rc.send('S', 8);
  }
}

