// ---------------------------------------
// Contoh untuk menguji modul Keyes AD Key
// ---------------------------------------

const int PIN_TOMBOL = A0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int nilaiPin = analogRead(PIN_TOMBOL);
  if (nilaiPin == 0) 
  {
    Serial.print(nilaiPin);
    Serial.println(" - SW1 ditekan");
    delay(200);
  }  
  else if (nilaiPin <= 300) 
  {
    Serial.print(nilaiPin);
    Serial.println(" - SW2 ditekan");
    delay(200);
  }
  else if (nilaiPin <= 490) 
  {
    Serial.print(nilaiPin);
    Serial.println(" - SW3 ditekan");
    delay(200);
  }
  else if (nilaiPin <= 700) 
  {
    Serial.print(nilaiPin);
    Serial.println(" - SW4 ditekan");
    delay(200);
  }
  else if (nilaiPin <= 990) 
  {
    Serial.print(nilaiPin);
    Serial.println(" - SW5 ditekan");    
    delay(200);
  }
}


