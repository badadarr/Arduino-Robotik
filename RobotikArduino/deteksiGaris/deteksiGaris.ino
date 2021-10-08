//-----------------------------------------
// Contoh pengujian sensor pendeteksi garis
//    YL-54
//-----------------------------------------

const int PIN_SENSOR = 2;

void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_SENSOR, INPUT);
}

void loop() 
{
  int nilaiPin = digitalRead(PIN_SENSOR);
  Serial.println(nilaiPin);
  delay(1000);
}

