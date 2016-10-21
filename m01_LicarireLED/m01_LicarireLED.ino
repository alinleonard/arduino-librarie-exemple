/*
  
  Led BLINK  (Licarire a unui led)
  In acest exemplu vom folosi led-ul de pe placa de dezvoltare

*/

/* 
  Pinul 13 de pe Platforma de dezvoltare Arduino are conectat un led 
  Declaram variabila led cu 13 pentru a folosi mai tarziu in cod ca o initializare
  a pinului 13 de pe Arduino si pentru o modificare mai usoara pe viitor a acestui pin.
*/
int led = 13;

/*
In continuare declaram functia setup
Functia setup ruleaza o singura data la alimentarea placi sau la un anumit restart .
Este folosita pentru a initializa variabile , determinarea pinilor de intrare sau iesire
initializare librarii si altele.
(Pentru mai multe informatii despre functia void cititi documentul .... )
*/
void setup(){
  /*
  Initializam pinul digital ca pin de iesire , aici folosim si variabila declarata la inceputul 
  acestui exemplu si anume variabila led de tip int.
  cu ajutorul functiei pinMode configuram pinul specificat ca pin de intrare sau de iesire.
  ex: pinMode(pin, mode) 
  pin = numarul pinului de pe placa de dezvoltare pe care doriti sa il configurati.
  mode = INPUT (intrare), OUTPUT (iesire) sau INPUT_PULLUP 
  */
  pinMode(led,OUTPUT);
}

//Functia loop este rulata in repetate randuri la nesfarsit.
void loop(){
  //Cu ajutorul functiei digitalWrite ii aplicam o tensiune pe pinul declarat mai sus (led) pentru a aprinde ledul.
  digitalWrite(led, HIGH); 
  /*
  delay este folosit pentru a opri rularea programului pentru un timp specificat de noi in ms 
  ex: 1000 ms = 1 s;
  folosim delay pentru crearea de licarire a ledului
  */
  delay(1000);
  //Ii eliminam tensiunea aplicata pe ledul 13 pentru a stinge ledul
  digitalWrite(led, LOW);
  delay(1000);
}
