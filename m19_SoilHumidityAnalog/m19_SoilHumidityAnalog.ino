int pinSoil  = A2;
float sensorValue = 0;
float valMin = 37; // se va schimba in etapa de calibrare
float valMax = 1023; // se va schimba in etapa de calibrare
float total;

void setup(){
  Serial.begin(9600);
}
float procentUmiditate(float x)
{
 float z = valMax - valMin;
 total = (((x-valMin) * 100 )/z ) - 100;
 total = abs(total);
return total;
}
void loop(){
  sensorValue = analogRead(pinSoil);
  //Serial.println(sensorValue);
  Serial.print("Umiditate: ");
  Serial.print((int)procentUmiditate(sensorValue));
  Serial.println(" %");
  delay(1000);
}