// ----------------------------
// Pengujian robot 2WD
// ----------------------------

#include <Robot.h>
#include <NewPing.h>

const int PIN_TRIG = 7;
const int PIN_ECHO = 8;

const int BATAS_JARAK = 10;

NewPing sensorUltra(PIN_TRIG, PIN_ECHO, 300);
 
Robot bot(3, 5, 6, 9);

void setup() 
{ 
  Serial.begin(9600);
  bot.aturKecepatan(60);
}

void loop() 
{
  float jarak = sensorUltra.ping_cm();  
  Serial.println(jarak); 
  if (jarak > BATAS_JARAK + 5 && jarak < 50)
  {
    bot.maju(15);
  }

  if (jarak > 0 && jarak < BATAS_JARAK - 5)
  {
    bot.mundur(15);
  }
}
