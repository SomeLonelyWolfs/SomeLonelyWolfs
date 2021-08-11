#include "Servo.h"
char Incoming_value = 0;                //Variable for storing Incoming_value
//
int motor1 = 10; 
int m1DA = 8; 
int m1DB = 9;
int degree=100;
int servopin=12;
Servo myservo;
//
void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  myservo.attach(servopin);
  pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
pinMode(m1DA,OUTPUT);
pinMode(m1DB,OUTPUT);
pinMode(motor1,OUTPUT);
}
void loop()
{
  if(Serial.available() > 0)  {
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    Serial.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    Serial.print("\n");        //New line 
    if(Incoming_value == '1')            //Checks whether value of Incoming_value is equal to 1 
      digitalWrite(13, HIGH);  //If value is 1 then LED turns ON
    else if(Incoming_value == '0')       //Checks whether value of Incoming_value is equal to 0
      digitalWrite(13, LOW);   //If value is 0 then LED turns OFF
  }                            
 //
  switch(digitalRead(13)){
      case HIGH:digitalWrite(m1DA,LOW);digitalWrite(m1DB,HIGH);digitalWrite(motor1,255);analogWrite(motor1,255); break;
      case LOW:digitalWrite(m1DA,LOW);digitalWrite(m1DB,LOW);digitalWrite(motor1,0);analogWrite(motor1,0); break;
      }
     switch(Incoming_value){
     case'l':degree=130; break;
     case'r':degree=70;break;
     case's':degree=100;break;
    }
 myservo.write(degree);
 //
}   
