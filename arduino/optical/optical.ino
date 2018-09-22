int x0 = 0;
int x1 = 0;
int x2 = 0;
int x3 = 0;

int pin1 = 8;
int pin2 = 9;
int pin3 = 10;
int pin4 = 11;

int threshold = 1000;

void setup() {
  Serial.begin(115200);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
}

void loop() {
    x0 = analogRead(A0);
    x1 = analogRead(A1);
    x2 = analogRead(A2);
    x3 = analogRead(A3);
    Serial.print(x0-1010);    
    Serial.print(",");
    Serial.print(x1-1010);    
    Serial.print(",");
    Serial.print(x2-1010);    
    Serial.print(",");
    Serial.println(x3-1010);    
    if(x0 < threshold){
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,LOW);
      digitalWrite(pin4,HIGH);
    }
    else{
      digitalWrite(pin1,LOW);
    }
    delay(1);
    if(x1 < threshold){
      digitalWrite(pin4,LOW);
      digitalWrite(pin3,LOW);
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,HIGH);
    }
    else{
      digitalWrite(pin2,LOW);
    }
delay(1);
    if(x2 < threshold){
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin4,LOW);
      digitalWrite(pin3,HIGH);
    }
    else{
      digitalWrite(pin3,LOW);
    }
delay(1);
    if(x3 < threshold){
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,LOW);
      digitalWrite(pin4,HIGH);
    }
    else{
      digitalWrite(pin4,LOW);
    }

delay(1);

}
