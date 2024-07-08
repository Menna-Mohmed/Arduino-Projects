
//Obstacle Avoiding Robot Using Ultrasonic Sensor and Ard

#include<Wire.h>
#define trigPin  9      
#define echoPin 10    

#define int1  11       //REVerse motion of Left motor
#define int2  12       //ForWarD motion of Left motor
#define int3  8      //REVerse motion of Right motor
#define int4  7      //ForWarD motion of Right motor

long duration=0; 
int distance=0;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(int1, OUTPUT);      // set Motor pins as output
  pinMode(int2, OUTPUT);
  pinMode(int3, OUTPUT);
  pinMode(int4, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration*0.034/2;   // convert to distance
  delay(10);
  Serial.println(distance);
    // If you dont get proper movements of your robot then alter the pin numbers
  if (distance > 10)            
  {
    digitalWrite(int1, HIGH);                    // move forward
    digitalWrite(int2, LOW);
    digitalWrite(int3, HIGH);                                
    digitalWrite(int4, LOW);                                                       
  }

  if (distance < 10)
  {
    digitalWrite(int1, LOW);  //Stop                
    digitalWrite(int2, LOW);
    digitalWrite(int3, LOW);                                
    digitalWrite(int4, LOW);
    delay(500);
    digitalWrite(int1, LOW);      //movebackword         
    digitalWrite(int2, HIGH);
    digitalWrite(int3, LOW);                                
    digitalWrite(int4, HIGH);
    delay(500);
    digitalWrite(int1, LOW);  //Stop                
    digitalWrite(int2, LOW);
    digitalWrite(int3, LOW);                                
    digitalWrite(int4, LOW);  
    delay(100);  
    digitalWrite(int1, HIGH);       
    digitalWrite(int2, LOW);   
    digitalWrite(int3, LOW);                                 
    digitalWrite(int4, LOW);  
    delay(500);
  }

}
