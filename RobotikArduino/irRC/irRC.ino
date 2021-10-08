// ----------------------------------
// Contoh pengujian IR remote control
// ----------------------------------

#include "IRremote.h"

const int PIN_IR = 2; 

IRrecv penerima(PIN_IR);
decode_results hasil;
  
void setup() 
{
  penerima.enableIRIn();
  
  Serial.begin(9600);
  Serial.println("Siap!");
}

void loop()
{
  if (penerima.decode(&hasil)) 
  {
    Serial.println(hasil.value, HEX);

    // Peroleh nilai berikutnya
    penerima.resume();   
  }
}

