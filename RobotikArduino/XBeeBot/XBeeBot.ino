// -------------------------------------
// Pengujian XBee
//   untuk menerima kiriman
// -------------------------------------

#include <Robot.h>

Robot bot(3, 5, 6, 9);

char perintah = 'S';

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available()) 
  {
   char kar = Serial.read(); 
   if (! (kar == 'L' || kar == 'F' || 
           kar == 'B' || kar == 'R' || 
           kar == 'S')) 
    {       
      return;
    }
    
    perintah = kar; 
    Serial.println(perintah);
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
