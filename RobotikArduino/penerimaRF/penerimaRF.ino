// ---------------------------------------------
// Penerimaan data menggunakan 
//    modul penerima RF 315MHz 
// ---------------------------------------------

#include <RCSwitch.h>

RCSwitch rc = RCSwitch();  

void setup() 
{
  // Penentuan pin untuk menerima data
  // Nilai 0 menyatakan pin #2
  rc.enableReceive(0);
 
  Serial.begin(9600);
  Serial.println("Siap menerima data!");
}
    
void loop() 
{
  if (rc.available()) 
  {
    char kar = rc.getReceivedValue();
    
    if (kar != 0) 
    {
      Serial.print("Data diterima: ");
      Serial.println(kar);
    }

    rc.resetAvailable();
  }    
}

