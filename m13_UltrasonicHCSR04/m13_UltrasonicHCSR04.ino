/*
  HCSR04      ARDUINO
  -------------------
  VCC         5v
  Trig        D12
  Echo        D11
  GND         GND
  
  Pentru mai multe informatii despre define: http://arduino.cc/en/Reference/Define
  Pentru mai multe informatii despre HCSR04: http://users.ece.utexas.edu/~valvano/Datasheets/HCSR04b.pdf
  
*/

#define trigPin 12
#define echoPin 11

int avarageDistance[10]; 

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
 
  long duration, distance;
  
  for(int i=0;i<10;i++){
    avarageDistance[i] = 0;
  }
  
  for(int y=0;y<10;y++){
    long duration, distance;
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    avarageDistance[y] = distance;
    delay(60);
  }
  
  int x = verify();
  if(x != 0){
    Serial.print(x);
    Serial.println(" cm");
  }

}

int verify(){
   for(int i=0;i<10;i++){
    if(avarageDistance[i] >= 500){
      avarageDistance[i] = 0;
    }
    if(avarageDistance[i] <= 0.2){
      avarageDistance[i] = 0;
    }
    if(avarageDistance[i] != 0){
      return avarageDistance[i];
    }
  }
}