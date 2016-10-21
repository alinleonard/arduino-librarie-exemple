//Pin Led 
int led = 13; 
//Interval licarire in ms ( 5 secunde )
int interval = 5000; 
//Stare Led ( se schimba dupa rularea programului )
int stareLed = LOW;

void setup(){
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
void loop(){
 if(stareLed == LOW){
  Serial.println("Ledul a fost stins!");
  stareLed = HIGH;
  Serial.print("Aprindem Ledul pentru ");
  Serial.print(interval);
  Serial.println(" ms");
 }
 else{
  Serial.println("Ledul a fost aprins!");  
  stareLed = LOW;
  Serial.print("Stingem ledul pentru ");
  Serial.print(interval);
  Serial.println(" ms");
 }
 digitalWrite(led,stareLed); 
 delay(interval);
}
