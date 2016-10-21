/*
  Led BLINK  (Licarire a unui led) fara delay
  In acest exemplu vom folosi led-ul de pe placa de dezvoltare pentru a crea un efect de licarire fara ajutorul 
  delay-ului . 
*/

int led = 13;

/*
Declaram variabile care se vor schimba dupa rularea programului sursa.
*/
int stareLed = LOW;
long timpAnterior = 0;


//Interval licarire
long interval = 1000;

void setup(){
  pinMode(led,OUTPUT);
}

void loop(){
  
  unsigned long timpCurent = millis();
  if(timpCurent - timpAnterior > interval){
    timpAnterior = timpCurent;
    
    if(stareLed == LOW)
      stareLed = HIGH;
    else
      stareLed = LOW;
    
    digitalWrite(led,stareLed);
  }
  
}
