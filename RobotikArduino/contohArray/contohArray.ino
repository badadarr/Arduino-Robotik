void setup() 
{ 
  Serial.begin(9600);

  // Deklarasi array
  int daftarBilangan[5];
  
  // Penugasan elemen-elemen array
  daftarBilangan[0] = 45;
  daftarBilangan[1] = 66;
  daftarBilangan[2] = 11;
  daftarBilangan[3] = 23;
  daftarBilangan[4] = 48;

  // Penampilan isi array
  for (int indeks = 0; indeks < 5; indeks++)
    Serial.println(daftarBilangan[indeks]);
}

void loop() 
{
  
}


