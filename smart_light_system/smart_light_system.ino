#define led 5
#define button 10
#define switch 9
#define ldr A0
int val;

void setup() {
 pinMode(button,INPUT);
 pinMode(switch,INPUT);
 pinMode(ldr,INPUT);
 pinMode(led,OUTPUT);
 

}

void loop() {
  val=analogRead(ldr);
  val=map(val,0,1023,255,0);
  if(!digitalRead(switch)){
    analogWrite(led,val);
  }
  else{
    if(digitalRead(button)){
      digitalWrite(led,HIGH);
      }
      else{
        
      digitalWrite(led,LOW);
        }
    }

}
