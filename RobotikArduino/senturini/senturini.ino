// ---------------------------------------------
// Sketsa untuk mengontrol robot Senturini
//    (Robot "Sentuh rintangan dan hindari")
// --------------------------------------------- 

#include <Robot.h>
 
const int PIN_SAKLAR_KIRI  = 10;
const int PIN_SAKLAR_KANAN = 11;

Robot bot(3, 5, 6, 9);
                      
int saklarKiri;
int saklarKanan;

void setup() 
{
  pinMode(PIN_SAKLAR_KIRI, INPUT);
  pinMode(PIN_SAKLAR_KANAN, INPUT);
}

void loop() 
{
  // Baca sensor
  saklarKiri = digitalRead(PIN_SAKLAR_KIRI);
  saklarKanan = digitalRead(PIN_SAKLAR_KANAN);
  
  // Pemrosesan gerak robot
  if (saklarKiri)
  { 
     bot.mundur(100);
     delay(10);      
     bot.putarKiri(125);
  }
  else 
    if (saklarKanan) 
    { 
       bot.mundur(100);
       delay(10);      
       bot.putarKanan(125);
    }
    else 
    {
      // Robot bergerak maju
      bot.maju(3);
    }
}

