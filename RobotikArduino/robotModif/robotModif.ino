// -------------------------------------
// Contoh untuk mencoba robot
//   yang dimodifikasi dari mobil mainan
// -------------------------------------

#include "Robot3.h"

Robot3 bot(3, 5, 6, 9);

void setup() 
{
  bot.aturKecepatan(60);

}

void loop() 
{
 
  bot.maju(1000);
  bot.stop(2000);

  bot.mundur(1000);
  bot.stop(2000);
/*
  bot.aturArah('L');
  bot.maju(1000);

  bot.aturArah('S');
  bot.maju(1000);

  bot.aturArah('R');
  bot.maju(1000);

  bot.aturArah('S');
  bot.maju(1000);

  bit.mundur(4000);
  bot.stop(2000);
 */ 
}
