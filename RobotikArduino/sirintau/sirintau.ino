// ---------------------------------------------
// Sketsa untuk mengontrol robot Sirintau
//    (Robot pendeteksi rintangan dengan 
//     sensor jarak ultrasonik)
// --------------------------------------------- 

#include <Robot.h>
#include <NewPing.h>
 
const int PIN_TRIG_DEPAN = 7;
const int PIN_ECHO_DEPAN = 8;

const int PIN_TRIG_KIRI = 14;
const int PIN_ECHO_KIRI = 15;

const int PIN_TRIG_KANAN = 16;
const int PIN_ECHO_KANAN = 17;

const int BATAS_JARAK = 25;

Robot bot(3, 5, 6, 9);

NewPing sensorHCKiri(PIN_TRIG_KIRI, 
                     PIN_ECHO_KIRI, 300);
NewPing sensorHCDepan(PIN_TRIG_DEPAN, 
                      PIN_ECHO_DEPAN, 300);
NewPing sensorHCKanan(PIN_TRIG_KANAN, 
                      PIN_ECHO_KANAN, 300);
                      
int jarakKiri;
int jarakDepan;
int jarakKanan;

void setup() 
{
  Serial.begin(9600);
  bot.aturKecepatan(60);
}

void loop() 
{
  // Baca sensor
  jarakKiri = sensorHCKiri.ping_cm();
  jarakDepan = sensorHCDepan.ping_cm(); 
  jarakKanan = sensorHCKanan.ping_cm(); 
  
  Serial.print(jarakKiri);
  Serial.print("\t");
  
  Serial.print(jarakDepan);
  Serial.print("\t");

  Serial.print(jarakKanan);
  Serial.println();
  
  // Pemrosesan gerak robot
  if (jarakDepan <= BATAS_JARAK)
  { 
    // Robot menjumpai penghalang
    if (jarakKiri > jarakKanan)
    {
      Serial.println("Putar kiri");
        
      if (jarakDepan < BATAS_JARAK)
      {
        bot.mundur(15);
        delay(10);
      }
          
      bot.putarKiri(15);
    }
    else 
    {
      Serial.println("Putar Kanan");
      if (jarakDepan < BATAS_JARAK)
      {
        bot.mundur(15);
        delay(10);
      }
        
      bot.putarKanan(15);
    }
  }
  else 
  {
    // Robot bergerak maju
    bot.maju(3);
  }
}

