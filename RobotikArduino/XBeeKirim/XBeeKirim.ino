// -----------------------------
// Pengiriman data menggunakan 
//   modul XBee 
// -----------------------------

char perintah[5] = {'F', 'B', 'L', 'R', 'S'};

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  // Membangkitkan bilangan acak antara 0 s/d 4
  int bilangan = random(5);

  // Memperoleh karakter di perintah
  char karakter = perintah[bilangan];
  
  Serial.println(karakter);
  Serial.flush();

  delay(1000);
}

