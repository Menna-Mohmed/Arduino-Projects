
//using bluetooth module we entere data by mobile application to control moving robot car
char data;
int motorAP=9;
int motorAN=10;
int motorBP=11;
int motorBN=12;



void setup() {
  pinMode(motorAP,OUTPUT);
  pinMode(motorAN,OUTPUT);
  pinMode(motorBP,OUTPUT);
  pinMode(motorBN,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()>0){
    data=Serial.read();
    if(data=='1'){
      digitalWrite(motorAP,HIGH);
      digitalWrite(motorAN,LOW);
      digitalWrite(motorBP,HIGH);
      digitalWrite(motorBN,LOW);
      
      
      
      }
    
    else if(data=='2'){
      digitalWrite(motorAP,LOW);
      digitalWrite(motorAN,HIGH);
      digitalWrite(motorBP,LOW);
      digitalWrite(motorBN,HIGH);
      }
      else if(data=='3'){
      digitalWrite(motorAP,LOW);
      digitalWrite(motorAN,HIGH);
      digitalWrite(motorBP,HIGH);
      digitalWrite(motorBN,LOW);
      }
      else if(data=='4'){
      digitalWrite(motorAP,HIGH);
      digitalWrite(motorAN,LOW);
      digitalWrite(motorBP,LOW);
      digitalWrite(motorBN,HIGH);
      }
    else if(data=='0'){
      digitalWrite(motorAP,LOW);
      digitalWrite(motorAN,LOW);
      digitalWrite(motorBP,LOW);
      digitalWrite(motorBN,LOW);
      }
    
    
    
    }
}
