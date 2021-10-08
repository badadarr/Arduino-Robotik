// ----------------------------
// Pengujian robot 2WD
// ----------------------------

#include <Robot.h>
 
Robot bot(3, 5, 6, 9);

void setup() 
{ 
  bot.aturKecepatan(60);
}

void loop() 
{
  bot.maju(500);
  bot.stop(2000);

  bot.mundur(500);
  bot.stop(2000);

  bot.belokKanan(150);
  bot.maju(500);

  bot.stop(2000);

  bot.belokKiri(150);
  bot.maju(500);

  bot.stop(2000);
  
  bot.putarKanan(4000);

  bot.stop(2000);
  
  bot.putarKiri(4000);

  bot.stop(2000);
 
}
