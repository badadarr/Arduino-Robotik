// ---------------------------------------------
// Robot RF315
//   yang dikendalikan oleh remote control
//   berfrekuensi radio 315MHz 
// ---------------------------------------------

#include <Robot.h>
#include <RCSwitch.h>

RCSwitch rc = RCSwitch();  
Robot bot(5, 6, 9, 10);

char perintah = 'S';

char perintahSebelum = 'x';

void setup() 
{
  // Penentuan pin untuk menerima data
  // Nilai 1 menyatakan pin #3
  rc.enableReceive(1);
 
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

      if (perintah == perintahSebelum) 
      {
        rc.resetAvailable();
        return;
      }

      // Salin perintah
      perintahSebelum = perintah;   
    
      Serial.print("Data diterima: ");
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

