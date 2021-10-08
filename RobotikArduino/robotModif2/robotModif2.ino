// --------------------------------------
// Contoh untuk mencoba robot
//   yang dimodifikasi dari mobil mainan.
//   Remote control asli tetap digunakan.
// --------------------------------------

#include "Robot3.h"

const int PIN_RC_F = 2;
const int PIN_RC_B = 4;
const int PIN_RC_L = 7;
const int PIN_RC_R = 8;

Robot3 bot(3, 5, 6, 9);

void setup() 
{
  pinMode(PIN_RC_L, INPUT);
  pinMode(PIN_RC_R, INPUT);
  pinMode(PIN_RC_B, INPUT);
  pinMode(PIN_RC_F, INPUT);

  Serial.begin(9600);
  bot.aturKecepatan(60);
}

void loop() 
{
  // Baca R/C kiri dan R/C kanan
  int nilai_rc_l = digitalRead(PIN_RC_L);
  int nilai_rc_r = digitalRead(PIN_RC_R);
  
  if (nilai_rc_l == HIGH)
  {
    bot.aturArah('L');
  }  
  else
    if (nilai_rc_r == HIGH)
    {
      bot.aturArah('R');
    }
    else
    {
      bot.aturArah('S');
    }
      
  // Baca R/C ke belakang dan ke depan
  int nilai_rc_b = digitalRead(PIN_RC_B);
  int nilai_rc_f = digitalRead(PIN_RC_F);
  
  if (nilai_rc_b == HIGH)
  {
    bot.mundur(10);
  }  
  else
    if (nilai_rc_f == HIGH)
    {
      bot.maju(100);
    }
    else
    {
      bot.stop(0);
    }

  // Tampilkan informasi tombol
  Serial.print("LRBF: ");
  Serial.print(nilai_rc_l);
  Serial.print(nilai_rc_r);
  Serial.print(nilai_rc_b);
  Serial.println(nilai_rc_f);  
}
