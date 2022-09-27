#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

#include <Servo.h>

RF24 receiver(9,10);// CE and CS Pins

Servo motor;

const byte address[6] = {"24"};

float calcmotval;



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  motor.attach(3);

 receiver.begin();
 receiver.openReadingPipe(0,address);
 receiver.setPALevel(RF24_PA_MAX);
 receiver.startListening();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);

while(receiver.available()){

receiver.read(&calcmotval,sizeof(calcmotval));
motor.write(calcmotval);
Serial.println(calcmotval);
  Serial.println("available!");
  delay(50);
}
  

}
