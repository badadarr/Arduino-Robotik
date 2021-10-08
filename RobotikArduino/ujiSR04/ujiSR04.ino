// ----------------------------
// Contoh untuk menguji HC-SR04
// ----------------------------

#include <NewPing.h>

const int PIN_TRIG = 7;
const int PIN_ECHO = 8;

NewPing sensorUltra(PIN_TRIG, PIN_ECHO, 300);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  float jarak = sensorUltra.ping_cm(); 
  Serial.println(jarak);

  delay(500);
}
