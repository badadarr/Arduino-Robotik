// -------------------------------------
// Pengujian XBee
//   untuk menerima kiriman
// -------------------------------------

void setup() 
{
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) 
  {
    String teks = Serial.readString();
    Serial.print(teks);
  }
}

