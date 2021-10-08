// -------------------------------------
// Robot RF24
// -------------------------------------

#include <Robot.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

const int PIN_CE = 8;
const int PIN_CSN = 10;
const uint64_t PIPE = 0xE8E8F0F0E2LL;

// Objek NRF24L01 
RF24 radio(PIN_CE, PIN_CSN);

char pesan[20]; // Penyangga pesan

Robot bot(3, 5, 6, 9);

char perintah = 'S';

void setup() 
{
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(1, PIPE);
  radio.startListening();
}

void loop() 
{
  if (radio.available()) 
  {
    bool selesai = false;  
      
    while (!selesai) 
    {
      selesai = radio.read(pesan, sizeof(pesan));
      perintah = pesan[0];
      Serial.println(perintah);
    }
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
