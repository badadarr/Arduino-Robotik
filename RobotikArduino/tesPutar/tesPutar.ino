// ----------------------------
// Pengujian robot 2WD
// ----------------------------

#include <Robot2WD.h>
 
Robot2WD bot(3, 5, 6, 9);

void setup() 
{ 
  bot.aturKecepatan(60);
    bot.putarKanan(1);
    delay(1000);
    bot.putarKanan(1);
    delay(1000);
}

void loop() 
{

}
