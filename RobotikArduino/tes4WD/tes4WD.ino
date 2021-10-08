// ------------------------------------
// Robot Dalikom
//   yang dikendalikan melalui komputer
// ------------------------------------

#include <Robot.h>
#include <SoftwareSerial.h>

SoftwareSerial bt(7, 8); 
Robot bot(3, 5, 6, 9);

char perintah = 'S';

void setup() 
{ 
  Serial.begin(9600);
  bt.begin(9600);
  bot.aturKecepatan(50);

  bt.println("Siap menerima perintah!");
  bt.println("F, B, L, R, atau S");
}

void loop() 
{
  char dataBt;
  
  if (bt.available()) 
  {
    dataBt = bt.read();
    Serial.println(dataBt);
    if (dataBt == 'F' || dataBt == 'B' ||
        dataBt == 'L' || dataBt == 'R' ||
        dataBt == 'S')
    {
      switch (dataBt)
      {
        case 'F':
          bt.println("Perintah: F - maju");
          break;
        case 'B':
          bt.println("Perintah: B - mundur");
          break;
        case 'L':
          bt.println("Perintah: L - belok kiri");
          break;
        case 'R':
          bt.println("Perintah: R - belok kanan");
          break;
        case 'S':
          bt.println("Perintah: S - stop");
          break;  
      }
      
      perintah = dataBt;      
    }
  }

  tanganiRobot();
}

void tanganiRobot()
{
  Serial.println(perintah);
  switch (perintah)
  {
    case 'S':
      bot.stop(0);
      break;
    case 'F':
      bot.maju(3);
      break;
    case 'B':
      bot.mundur(3);
      break;
    case 'L':
      bot.belokKiri(15);
      bot.maju(3);
      break;
    case 'R':
      bot.belokKanan(15);
      bot.maju(3);
      break;
  } 
}

