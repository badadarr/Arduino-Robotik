// ------------------------------------
// Contoh sketsa untuk menguji Joystick
//   KY-023
// ------------------------------------

const int PIN_VRX = 0;                 
const int PIN_VRY = 1;
const int PIN_SW  = 12;

void setup() 
{
   pinMode(PIN_SW, INPUT_PULLUP);
   
   Serial.begin(9600);
}

void loop() 
{
   // Baca data dari tiga pin 
   int nilaiX = analogRead(PIN_VRX);
   int nilaiY = analogRead(PIN_VRY);
   int nilaiSW = digitalRead(PIN_SW);

   // Kirim ke port serial   
   Serial.print("X: ");
   Serial.print(nilaiX);
   Serial.print(", Y: ");
   Serial.print(nilaiY);
   Serial.print(", SW: ");
   Serial.println(nilaiSW);

   delay(100); // Diperlukan untuk menunda pembacaan berikutnya
}

