void setup() 
{ 
  Serial.begin(9600);

  float celsius = 30.5;
  Serial.print("Celsius: ");
  Serial.println(celsius);

  Serial.print("Reaumur: ");
  Serial.println(celsiusKeReaumur(celsius));
}

void loop() 
{
  
}

float celsiusKeReaumur(float celsius)
{
   float reaumur = 4 / 5.0 * celsius;

   return reaumur;
}

