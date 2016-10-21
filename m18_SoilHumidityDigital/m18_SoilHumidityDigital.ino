int pinSoil  = 2;

void setup(){
  Serial.begin(9600);
  pinMode(pinSoil,INPUT_PULLUP);
  pinMode(13, OUTPUT);
}
void loop(){
  int humidityState = digitalRead(pinSoil);
  if(humidityState == LOW){
    Serial.println("Water system Enabled");
    digitalWrite(13, HIGH);
  }
  if(humidityState == HIGH){
    digitalWrite(13, LOW);
  }
}
