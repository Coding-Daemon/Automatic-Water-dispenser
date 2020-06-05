
#include <Servo.h>
Servo myservo; 

int echopin = 8; // connect echopin to pin 8
int trigpin = 7; // connect trigpin to pin 7
long duration;
int distance;



void setup() {
Serial.begin(9600);
myservo.attach(9);  // Servo motor to be connected to pin 9
pinMode (echopin,INPUT);
pinMode (trigpin,OUTPUT);
}

void loop() {

digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite (trigpin, LOW);

duration = pulseIn(echopin, HIGH);

distance= duration*0.034/2;

Serial.println(distance);

 if(distance < 14){
    myservo.write(0);  
    Serial.println("Tap off");    
    delay(1200) ;
 }
 if(distance > 14){
    myservo.write(90);  // change these degrees according to your tap             
    Serial.println("Tap on");
    delay(1200);   


  }
 
  }  
  
