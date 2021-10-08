// ---------------------------------------------
// Sketsa untuk menguji 
//    dua sensor HC-SR06
// --------------------------------------------- 

#include <NewPing.h>
 
const int PIN_TRIG_DEPAN = 7;
const int PIN_ECHO_DEPAN = 8;

const int PIN_TRIG_KIRI = 14;
const int PIN_ECHO_KIRI = 15;

NewPing sensorHCKiri(PIN_TRIG_KIRI, 
                     PIN_ECHO_KIRI, 300);
NewPing sensorHCDepan(PIN_TRIG_DEPAN, 
                      PIN_ECHO_DEPAN, 300);
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  float jarakDepan = sensorHCDepan.ping_cm();  
  float jarakKiri = sensorHCKiri.ping_cm();  
  
  Serial.print("Jarak Depan: ");
  Serial.print(jarakDepan);
  Serial.print(", jarak Kiri: ");
  Serial.println(jarakKiri);

  delay(500);
  
  
}


