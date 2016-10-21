/*
Primul pas pentru a realiza un mod de a da o comanda de pe calculator catre placa.
Dupa rularea programului putem tasta de la tastatura :
a -> Aprindere LED
s -> Stringere LED

Cum putem adauga si alte comenzi ? 
	Pentru a da comenzi (ex: pornire , oprire ) trebuie sa folosim o variabila String.
	In exemplele ce urmeaza voi arata cum se poate realiza acest lucru.

*/
int led = 13;

void setup() {                
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
   /*  Verificam daca au fost trimise date de la calculator */
  if (Serial.available() > 0) {
    //Dorim sa vedem care este primul caracter trimis de la tastatura, dar fara sa il stergem
    //Pentru mai multe informatii despre peek() http://arduino.cc/en/Serial/Peek
    if(Serial.peek() == 'a'){
      digitalWrite(led,HIGH);
      //Pentru a elimina caracterul de pe buffer folosim read(); pentru ca nu mai avem nevoie de el
      Serial.read();
    }else if(Serial.peek() == 's'){
      digitalWrite(led,LOW);
      //Pentru a elimina caracterul de pe buffer folosim read(); pentru ca nu mai avem nevoie de el
      Serial.read();
    }
    /*Pentru a fi siguri ca in buffer nu mai exista alte data folosim o functie de tip while() 
      pentru a elimina orice date de pe serial.
      Pentru informatii despre while() http://arduino.cc/en/Reference/While */
    while(Serial.available()){
      Serial.read();
    }
    
  }
  
}