// ---------------------------------------------
// Sketsa untuk mengontrol 
//    Robot pengikut garis yang dapat 
//    menghindari rintangan
// --------------------------------------------- 

#include <Robot.h>
#include <NewPing.h>
 
const int PIN_L = 10;
const int PIN_C = 11;
const int PIN_R = 12;

const int PIN_LED = 19;

const int PIN_TRIG_DEPAN = 7;
const int PIN_ECHO_DEPAN = 8;

const int PIN_TRIG_KIRI = 14;
const int PIN_ECHO_KIRI = 15;

const int BATAS_JARAK = 20;

int nilaiPinL;
int nilaiPinC;
int nilaiPinR;

float jarakDepan, jarakKiri;
  
NewPing sensorHCKiri(PIN_TRIG_KIRI, 
                     PIN_ECHO_KIRI, 300);
NewPing sensorHCDepan(PIN_TRIG_DEPAN, 
                      PIN_ECHO_DEPAN, 300);

Robot bot(3, 5, 6, 9);

void setup() 
{
  pinMode(PIN_L, INPUT);
  pinMode(PIN_C, INPUT);
  pinMode(PIN_R, INPUT);
  pinMode(PIN_LED, OUTPUT);
  
  bot.aturKecepatan(70);
}

void loop() 
{
  // Pemeriksa rintangan
  jarakDepan = sensorHCDepan.ping_cm();  
  if (jarakDepan != 0  && jarakDepan <= BATAS_JARAK)
     hindariRintangan();

  // Bagian penangan lintasan 
  //   (sama seperti pada robot Pigari)
  
  nilaiPinL = digitalRead(PIN_L);
  nilaiPinC = digitalRead(PIN_C);
  nilaiPinR = digitalRead(PIN_R);

  // Ikuti lintasan
  if (nilaiPinL == 1 && nilaiPinR == 0)
  {
    // Sensor kiri di luar garis hitam
    bot.belokKanan(2);
  }
  else if (nilaiPinR == 1 && nilaiPinL == 0)
  {
    // Sensor kanan di luar garis hitam
    bot.belokKiri(2);
  }
  else if (nilaiPinL + nilaiPinC + nilaiPinR == 0)
  {    
    // Semua sensor berada pada garis hitam
    bot.maju(6);
  }
  else if (nilaiPinL + nilaiPinC + nilaiPinR == 3)
  {
    // Semua sensor berada di luar garis hitam
    bot.mundur(2);
  }
}

void hindariRintangan()
{
  digitalWrite(PIN_LED, HIGH); // Hidupkan LED

  // TAHAP 1
  // Belokkan robot ke kanan sampai sensor HC-SR04 kiri
  //   mendeteksi objek dengan jarak kurang dari atau
  //   sama dengan BATAS_JARAK
  jarakKiri = sensorHCKiri.ping_cm();
  while (jarakKiri == 0 || jarakKiri >= BATAS_JARAK)
  {
     bot.belokKanan(2);
     jarakKiri = sensorHCKiri.ping_cm();
  }

  // TAHAP 2
  // Putari objek sampai salah satu pendeteksi garis
  //   menjumpai garis hitam
  nilaiPinL = digitalRead(PIN_L);
  nilaiPinC = digitalRead(PIN_C);
  nilaiPinR = digitalRead(PIN_R);
  int totalLCR = nilaiPinL + nilaiPinC + nilaiPinR;

  while (totalLCR == 3)
  {
    jarakKiri = sensorHCKiri.ping_cm();
    if (jarakKiri == 0 || 
        jarakKiri >= BATAS_JARAK + 5)
    {
      bot.belokKiri(4);
    }
    else if (jarakKiri > 0 && 
             jarakKiri <= BATAS_JARAK - 5)
    {
      bot.belokKanan(4);
    }
    else
    {
      bot.maju(2);
    }
    
    // ---- Baca kembali sensor pendeteksi garis
    nilaiPinL = digitalRead(PIN_L);
    nilaiPinC = digitalRead(PIN_C);
    nilaiPinR = digitalRead(PIN_R);
    totalLCR = nilaiPinL + nilaiPinC + nilaiPinR;
  }

  // TAHAP 3
  // Putar robot ke kanan sehingga 
  //   pendeteksi garis R (kanan) berada di warna putih
  while (nilaiPinR == 0)
  {
    bot.putarKanan(12);
    
    nilaiPinR = digitalRead(PIN_R);
    nilaiPinL = digitalRead(PIN_L);

    delay(30);
  }

  // Matikan LED
  digitalWrite(PIN_LED, LOW);
}

