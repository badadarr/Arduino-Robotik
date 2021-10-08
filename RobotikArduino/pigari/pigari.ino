// ---------------------------------------------
// Sketsa untuk mengontrol robot Pigari
//    (Robot pengikut garis)
// --------------------------------------------- 

#include <Robot.h>
 
const int PIN_L = 10;
const int PIN_C = 11;
const int PIN_R = 12;

Robot bot(3, 5, 6, 9);

void setup() 
{
  pinMode(PIN_L, INPUT);
  pinMode(PIN_C, INPUT);
  pinMode(PIN_R, INPUT);

  bot.aturKecepatan(60);
}

void loop() 
{

  int nilaiPinL = digitalRead(PIN_L);
  int nilaiPinC = digitalRead(PIN_C);
  int nilaiPinR = digitalRead(PIN_R);

  if (nilaiPinL == 1 && nilaiPinR == 0)
  {
    // Sensor kiri di luar garis hitam
    bot.belokKanan(2);
  }
  else if (nilaiPinR == 1 && nilaiPinL == 0)
  {
    // Sensor kanan di luar garis hitam
    bot.belokKiri(2);
  }
  else if (nilaiPinL + nilaiPinC + nilaiPinR == 0)
  {    
    // Semua sensor berada pada garis hitam
    bot.maju(6);
  }
  else if (nilaiPinL + nilaiPinC + nilaiPinR == 3)
  {
    // Semua sensor berada di luar garis hitam
    bot.mundur(2);
  }
}

