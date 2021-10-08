// ---------------------------------------------
// Robot Framera
//   yang dikendalikan oleh remote control
//   inframerah 
// ---------------------------------------------

#include <Robot.h>
#include "IRremote.h"

const int PIN_IR = 2; 

IRrecv penerima(PIN_IR);
decode_results hasil;

Robot bot(10, 5, 6, 9);

char perintah = 'S';

void setup() 
{
  penerima.enableIRIn();
 
  Serial.begin(9600);
  bot.aturKecepatan(60);
}

void loop() 
{
  if (penerima.decode(&hasil)) 
  {
    Serial.println(hasil.value, HEX);

    switch (hasil.value)
    {
      case 0xFF18E7:
        perintah = 'F';
        break;
      case 0xFF10EF:
        perintah = 'L';
        break;        
      case 0xFF38C7:
        perintah = 'S';
        break;      
      case 0xFF5AA5:
        perintah = 'R';
        break;      
      case 0xFF4AB5:
        perintah = 'B';
        break;
    }
    
    // Peroleh nilai berikutnya
    penerima.resume();   
  }   

  tanganiRobot();
}

void tanganiRobot()
{ 
  switch (perintah)
  {
    case 'S':
      bot.stop(0);
      break;
    case 'F':
      bot.maju(1);
      break;
    case 'B':
      bot.mundur(1);
      break;
    case 'L':
      bot.belokKiri(15);
      bot.maju(1);
      break;
    case 'R':
      bot.belokKanan(15);
      bot.maju(1);
      break;
  } 
}

