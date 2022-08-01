#include <Arduino.h>

int blink;
int delaytime;
bool startup = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (startup){
    startup = false;
  }
  
  if(Serial.available()){
    blink = Serial.parseInt();
    Serial.print("LED will blink ");
    Serial.print(blink);
    Serial.println(" time/s per second.");
  } 

  if (blink > 0){
    delaytime = blink*2;
    digitalWrite(2,HIGH);
    delay(1000/delaytime);
    digitalWrite(2,LOW);
    delay(1000/delaytime);
   }
  else{
    digitalWrite(2,HIGH);
   }
}