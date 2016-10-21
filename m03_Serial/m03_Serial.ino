/*
Serial este folosit pentru comunicarea intre placa de dezvoltare Arduino si 
un calculator sau alt dispozitiv. Toate platformele Arduino au cel putin un 
port Serial cunoscut la UART sau USART.
Comunica prin pini digitali RX si TX de pe placa si prin USB pe calculator.
Pentru mai multe informatii http://arduino.cc/en/reference/serial

Dupa rularea programului pentru a putea intra in terminal in programul Arduino
Tools -> Serial Monitor

*/

int number = 0; 

void setup(){
  /*
  begin()
  http://arduino.cc/en/Serial/Begin
  */
  Serial.begin(9600);
  Serial.println("Prima mea interactiune cu serial-ul");
}

void loop(){
  Serial.print("Numar: ");
  Serial.println(number++);
  delay(1000);
}
