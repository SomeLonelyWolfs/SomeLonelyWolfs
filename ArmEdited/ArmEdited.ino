/** Servo Attachments
 *  Yellow = pin 8
 *  Brown= pin Ground
 *  Red= pin 5v
 *  --------------------------------------------------------
 *  
 *  
 *  
 *  
 */









const int buttonPin = 2;     
int On=0;
int buttonState = 0;
#include <Servo.h>
Servo myservo;
int val;
void setup() {
  // initialize the LED pin as an output:
  myservo.attach(8);
  // initialize the pushbutton pin as an input:
}
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    //checks if this is first time pressing the button or the second
    if(On==0){
    On=1;
    }else{
      On=0;
    }
  } else {
  }
//checks and run code is it's on or off.
if(On==1){
  //if the code is on, make it so that it retracts
myservo.write(map(0,0,1023,0,180));
delay(15);
}else{
 //if the code is false, make it so that it is default
myservo.write(map(1023,0,1023,0,180));
delay(15);
}
delay(180);//5 seconds untill next use
}
