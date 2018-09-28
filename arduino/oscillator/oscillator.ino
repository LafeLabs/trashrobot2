//oscillator code
//trash robot
//FREE
//NO COPYRIGHT
//NO PATENTS
//NO IP


int x = 0;
int x0 = 0;

boolean enable = false;

int enablePin = 10;
int drivePin1 = 5;
int drivePin2 = 6;

void setup() {
  Serial.begin(115200);
  pinMode(enablePin, INPUT);
  pinMode(drivePin1, OUTPUT);
  pinMode(drivePin2, OUTPUT);
  digitalWrite(drivePin1,LOW);
  digitalWrite(drivePin2,LOW);
  x0 = analogRead(A0);
}

void loop() {
    enable = digitalRead(enablePin);
    x = analogRead(A0) - x0;
    if(enable && x > 0){
        digitalWrite(drivePin2,HIGH);
        digitalWrite(drivePin1,LOW);
    }
    if(enable && x < 0){
        digitalWrite(drivePin1,HIGH);
        digitalWrite(drivePin2,LOW);      
    }
    if(!enable){
        digitalWrite(drivePin2,LOW);
        digitalWrite(drivePin1,LOW);
    }

    delay(1);
}
