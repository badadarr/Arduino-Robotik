// --------------------------------
// Sketsa untuk remote control 
//    yang berfungsi sebagai
//    pengendali robot yang berasal
//    dari mobil mainan yang R/C-nya
//    tidak digunakan.
//    Joystick digunakan sebagai
//    pengendali.
// --------------------------------

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

const int PIN_CE = 8;
const int PIN_CSN = 10;
const uint64_t PIPE = 0xE8E8F0F0E2LL;

const int PIN_TOMBOL = A0;

// Objek NRF24L01
RF24 radio(PIN_CE, PIN_CSN);

const int PIN_VRX = 0;                 
const int PIN_VRY = 1;
const int PIN_SW  = 2;

char pesan[20]; // penyangga pesan

void setup() 
{
  pinMode(PIN_SW, INPUT_PULLUP);
  
  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(PIPE);
}

void loop() 
{
  // Baca data dari tiga pin 
  int nilaiX = analogRead(PIN_VRX);
  int nilaiY = analogRead(PIN_VRY);
  int nilaiSW = digitalRead(PIN_SW);

  bool belokKiri = nilaiX < 340;
  bool belokKanan = nilaiX > 684;
  if (belokKiri) 
    kirim('L'); // Belok kiri
  else 
    if (belokKanan)
      kirim('R'); // Belok kanan
    else    
      kirim('S'); // Lurus

  bool keDepan = nilaiY < 340;
  bool keBelakang = nilaiY > 684;
  if (keDepan)
    kirim('F');  // Ke depan
  else
    if (keBelakang)
      kirim('B'); // Ke belakang
    else
      kirim('H'); // Berhenti   
}

void kirim(char karakter)
{
  sprintf(pesan, "%c", karakter);
  
  // Kirim ke pemancar  
  radio.write(pesan, strlen(pesan));  
        
  radio.powerDown();  
  delay(30);
  radio.powerUp();   
}
