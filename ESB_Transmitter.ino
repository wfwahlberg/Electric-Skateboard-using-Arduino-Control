#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
float calcmotval;


RF24 transmitter(8,10);// CE and CS Pins

const byte address[6] = {"24"};

int motval;




void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(A1, INPUT);

 transmitter.begin();
 transmitter.openWritingPipe(address);  
 transmitter.setPALevel(RF24_PA_MAX);
 transmitter.stopListening();

}

void loop() {
  // put your main code here, to run repeatedly:

  
  


while(transmitter.isChipConnected () == true){
  
 int motval = analogRead(A1);
 float calcmotval = (motval/1023.)*180.;
  Serial.println(motval);
delay(50);
  
transmitter.write(&calcmotval,sizeof(calcmotval));


  
}
  

}
