// -------------------------------------
// Robot hasil modifikasi dari mainan
//   yang dikendalikan dengan R/C
//   yang menggunakan Joystick dan
//   nRF24L01
// -------------------------------------

#include <Robot3.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

const int PIN_CE = 8;
const int PIN_CSN = 10;
const uint64_t PIPE = 0xE8E8F0F0E2LL;

// Objek NRF24L01 
RF24 radio(PIN_CE, PIN_CSN);

char pesan[20]; // Penyangga pesan

Robot3 bot(3, 5, 6, 9);

char perintah1 = 'S';
char perintah2 = 'F';

void setup() 
{
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(1, PIPE);
  radio.startListening();

  bot.aturKecepatan(80);
}

void loop() 
{
  if (radio.available()) 
  {
    bool selesai = false;  
      
    while (!selesai) 
    {
      selesai = radio.read(pesan, sizeof(pesan));
      char perintah = pesan[0];
      Serial.println(perintah);

      if (perintah == 'L' || perintah == 'S' ||
          perintah == 'R')
        perintah1 = perintah;
      else
        if (perintah == 'F' || perintah == 'B' ||
            perintah == 'H')
          perintah2 = perintah;
    }
  }
  
  tanganiRobot();
}

void tanganiRobot()
{ 
  switch (perintah1)
  {
    case 'L':
    case 'S':
    case 'R':
      bot.aturArah(perintah1);
      break;
  }
  
  switch (perintah2)
  {
    case 'H':
      bot.stop(0);
      break;
    case 'F':
      bot.maju(1);
      break;
    case 'B':
      bot.mundur(1);
      break;
  } 
}
