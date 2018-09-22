//oscillator code
//trash robot
//FREE
//NO COPYRIGHT
//NO PATENTS
//NO IP


int x = 0;
int x0 = 512;//this should range from 0 to 1023
int deltax = 200; //this should range from 0 to 512

int outPin = 6;

void setup() {
  Serial.begin(115200);
  pinMode(outPin, OUTPUT);
  digitalWrite(outPin,LOW);
}

void loop() {
  x0 = analogRead(A2);
  deltax = analogRead(A3)/2;
  x = analogRead(A0);
  
  if(x < x0 - deltax || x < 10){
     digitalWrite(outPin,HIGH);  
  }
  if(x > x0 + deltax || x > 1013){
     digitalWrite(outPin,LOW);  
  }
  Serial.println(x);
}
