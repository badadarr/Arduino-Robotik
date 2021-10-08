// ---------------------------------------------
// Robot RF315
//   yang dikendalikan oleh remote control
//   berfrekuensi radio 315MHz 
// ---------------------------------------------

#include <Robot.h>
#include <RCSwitch.h>

RCSwitch rc = RCSwitch();  
Robot bot(3, 5, 6, 9);

char perintah = 'S';

void setup() 
{
  // Penentuan pin untuk menerima data
  // Nilai 0 menyatakan pin #2
  rc.enableReceive(0);
 
  Serial.begin(9600);
  bot.aturKecepatan(50);
}

void loop() 
{
  if (rc.available()) 
  {
    char kar = rc.getReceivedValue();
    
    if (kar != 0) 
    { 
      perintah = kar;
    
      Serial.println(perintah);
    }

    rc.resetAvailable();
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

