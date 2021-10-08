// ---------------------------------------------
// Contoh pengujian saklar sentuh mikro
// --------------------------------------------- 

const int PIN_SAKLAR_KIRI  = 10;
const int PIN_SAKLAR_KANAN = 11;

int saklarKiri;
int saklarKanan;

void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_SAKLAR_KIRI, INPUT);
  pinMode(PIN_SAKLAR_KANAN, INPUT);
}

void loop() 
{
  // Baca sensor
  saklarKiri = digitalRead(PIN_SAKLAR_KIRI);
  saklarKanan = digitalRead(PIN_SAKLAR_KANAN);

  if (saklarKiri == HIGH)
    Serial.println("Saklar kiri ditekan");

  if (saklarKanan == HIGH)
    Serial.println("Saklar kanan ditekan");

  delay(200);  
}

