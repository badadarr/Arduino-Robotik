void setup() 
{ 
  Serial.begin(9600);

  String perintah = "Hidupkan LED";

  Serial.print("length(): ");
  Serial.println(perintah.length());

  perintah.toLowerCase();
  Serial.print("toLowerCase(): ");
  Serial.println(perintah);

  perintah.toUpperCase();
  Serial.print("toLowerCase(): ");
  Serial.println(perintah);

  perintah.replace("HIDUPKAN", "MATIKAN");
  Serial.print("replace(): ");
  Serial.println(perintah);

  Serial.print("substring(): ");
  Serial.println(perintah.substring(8));
}

void loop() 
{
  
}


