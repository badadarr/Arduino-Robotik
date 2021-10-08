// -----------------------------
// Sketsa untuk remote control 
//    yang berfungsi sebagai
//    pengendali robot XBeeBot
// -----------------------------

const int PIN_TOMBOL = A0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  // Baca sensor Keyes AD Key
  int nilaiPin = analogRead(PIN_TOMBOL);

  if (nilaiPin == 0) 
  {
    // Tombol SW1 ditekan
    Serial.println('L');
    Serial.flush();
  }  
  else if (nilaiPin <= 300) 
  {
    // Tombol SW2 ditekan
    Serial.println('F');
    Serial.flush();
  }
  else if (nilaiPin <= 490) 
  {
    // Tombol SW3 ditekan
    Serial.println('B');
  }
  else if (nilaiPin <= 700) 
  {
    // Tombol SW4 ditekan
    Serial.println('R');
    Serial.flush();
  }
  else if (nilaiPin <= 990) 
  {
    // Tombol SW5 ditekan   
    Serial.println('S');
    Serial.flush();
  }
}

