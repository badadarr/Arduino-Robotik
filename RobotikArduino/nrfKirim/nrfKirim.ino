// ------------------------------------
// Pengiriman data menggunakan nRF24L01
// ------------------------------------

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

const int PIN_CE = 8;
const int PIN_CSN = 10;
const uint64_t PIPE = 0xE8E8F0F0E2LL;

char perintah[5] = {'F', 'B', 'L', 'R', 'S'};

// Objek NRF24L01
RF24 radio(PIN_CE, PIN_CSN);

char pesan[20]; // penyangga pesan

void setup() 
{
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(PIPE);
}
 
void loop() 
{
  // Membangkitkan bilangan acak antara 0 s/d 4
  int bilangan = random(5);

  // Memperoleh karakter di perintah
  char karakter = perintah[bilangan];

  // Bentuk menjadi string
  sprintf(pesan, "%c", karakter);

  // Kirim ke pemancar  
  radio.write(pesan, strlen(pesan));  
        
  radio.powerDown();  
  delay(1000);
  radio.powerUp();    
}

