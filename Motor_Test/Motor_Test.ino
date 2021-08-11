int motor1 = 10; 
int m1DA = 9; 
int m1DB = 8;
// motor two
int motor2 = 5; 
int m2DA = 6; 
int m2DB = 7;
int echopin=2;
int trigpin=3;
long duration, cm, inches;
int runni=0;
char getstr;
void setup(){
Serial.begin(9600);
pinMode(motor1,OUTPUT) ;  
pinMode(m1DA,OUTPUT) ; 
pinMode(m1DB,OUTPUT) ;
pinMode(motor2,OUTPUT) ;  
pinMode(m2DB,OUTPUT) ;
pinMode(m2DA,OUTPUT) ; 
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
}
void scanner(){
  digitalWrite(trigpin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echopin, INPUT);
  duration = pulseIn(echopin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  //Serial.print(inches);
  //Serial.print("in, ");
 //Serial.print(cm);
  //Serial.print("cm");
  //Serial.println();
  
  delay(250);
}

void forward(){
if(runni==1){
//Right Motor(This is reversed.)
digitalWrite(m2DA,LOW);//Controls input of Electricity(LOW==On//HIGH==Off);
digitalWrite(m2DB,HIGH);// Controls input of electricity (LOW==On//HIGH==Off)
analogWrite(motor2,255);//speed
//Left Motor(This is reversed.)
digitalWrite(m1DA,HIGH);//Controls input of Electricity(LOW==On//HIGH==Off);
digitalWrite(m1DB,LOW);// Controls input of electricity (LOW==On//HIGH==Off)
analogWrite(motor1,255);//speed
}else{
  
}
}
void loop(){
   scanner();
  getstr=Serial.read();
   if(inches>20){
   switch(getstr){
     case 'f': runni=1; forward(); break;
    // case 'b':runni=1; back();   break;
    // case 'l':runni=1; left();   break;
    // case 'r':runni=1; right();  break;
     case 's': runni=0;   break;
    // case 'a': stateChange(); break;
   default:  break;
   }
   }else{
   runni=0;
   if(getstr=='s'){
  runni=0;
   }
 }
}
