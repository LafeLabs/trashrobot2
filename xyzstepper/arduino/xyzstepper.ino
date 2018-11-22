String shape1 = String("hjjjskkkg");
String shape2 = String("1111");
String shape3 = String("22");
String shape4 = String("3jjjdkkk");
String shape5 = String("4444");
String shape6 = String("");
String shape7 = String("");
String shape8 = String("");
String currentGlyph = String("3");

//shapecode 
/*
www.trashrobot.org/xyzstepper 
XYZ Trash Robot with steppers  
using stages from CD/DVD drives 
FREE, PUBLIC DOMAIN
NO COPYRIGHT
*/
int buttonPin = 12;
int stopPin = 3;
boolean buttonState = false;
boolean gostate = false;
int side = 1;
int leftPinArray[] = {8,10,9,11};
int rightPinArray[] = {14,16,15,17};
int zPinArray[] = {4,6,5,7};

int leftPinIndex = 0;
int rightPinIndex = 0;
int zPinIndex = 0;
int pulseTime = 10;//ms

String initGlyph = "kkkkkh";

void setup() {
 // Serial.begin(115200);
  pinMode(leftPinArray[0],OUTPUT);
  pinMode(leftPinArray[1],OUTPUT); 
  pinMode(leftPinArray[2],OUTPUT); 
  pinMode(leftPinArray[3],OUTPUT);
  pinMode(rightPinArray[0],OUTPUT);
  pinMode(rightPinArray[1],OUTPUT); 
  pinMode(rightPinArray[2],OUTPUT); 
  pinMode(rightPinArray[3],OUTPUT);
  pinMode(zPinArray[0],OUTPUT);
  pinMode(zPinArray[1],OUTPUT); 
  pinMode(zPinArray[2],OUTPUT); 
  pinMode(zPinArray[3],OUTPUT);
  
  pinMode(buttonPin,INPUT_PULLUP);//input with pull up resistor
  pinMode(stopPin,INPUT_PULLUP);//input with pull up resistor
  
  digitalWrite(leftPinArray[0],LOW);
  digitalWrite(leftPinArray[1],LOW);
  digitalWrite(leftPinArray[2],LOW);
  digitalWrite(leftPinArray[3],LOW);
  digitalWrite(rightPinArray[0],LOW);
  digitalWrite(rightPinArray[1],LOW);
  digitalWrite(rightPinArray[2],LOW);
  digitalWrite(rightPinArray[3],LOW);
  digitalWrite(zPinArray[0],LOW);
  digitalWrite(zPinArray[1],LOW);
  digitalWrite(zPinArray[2],LOW);
  digitalWrite(zPinArray[3],LOW);
  
  //drawGlyph(initGlyph);
}

void loop() {
  buttonState = !digitalRead(buttonPin);//if grounded set to high
//wire the button to gnd with no external pull up/down 

  if(buttonState){
      side = 1;
      gostate = true;
      drawGlyph(currentGlyph);
      gostate = false;
  }
  
}

void drawGlyph(String localGlyph){

   gostate = digitalRead(stopPin);//if grounded set to false
   //to break out of all loops and stop the whole glyph
//wire the button to gnd with no external pull up/down 

  for(int index = 0;index < localGlyph.length();index++){
      doTheThing(localGlyph.charAt(index));
      if(!gostate){
          break;
      }
  }
}

void doTheThing(char localCommand){

  if(localCommand == 'a'){
    for(int index = 0;index < side;index++){
        leftleft();
        rightleft();
    }
  }
  if(localCommand == 's'){
    for(int index = 0;index < side;index++){
        rightright();
        leftright();
    }
  }
  if(localCommand == 'd'){
    for(int index = 0;index < side;index++){
        leftright();
        rightleft();
    }
  }
  if(localCommand == 'f'){
    for(int index = 0;index < side;index++){
        leftleft();
        rightright();
    }
  }
  
  if(localCommand == 'g'){
    for(int index = 0;index < side;index++){
        inin();
    }
  }
  if(localCommand == 'h'){
    for(int index = 0;index < side;index++){
        outout();
    }
  }
  
  
  if(localCommand == 'j'){
    if(side > 1){
        side /= 2;
    }
  }
  if(localCommand == 'k'){
    side *= 2;
  }
 
  
  
  if(localCommand == '1'){//4
    drawGlyph(shape1);
  }
  if(localCommand == '2'){//16
    drawGlyph(shape2);
  }
  if(localCommand == '3'){//64
    drawGlyph(shape3);
  }
  if(localCommand == '4'){//256
    drawGlyph(shape4);
  }
  if(localCommand == '5'){//1024
    drawGlyph(shape5);
  }
  if(localCommand == '6'){//4096
    drawGlyph(shape6);
  }
  if(localCommand == '7'){//16384
    drawGlyph(shape7);
  }
  if(localCommand == '8'){
    drawGlyph(shape8);
  }
}

void leftleft(){
  leftPinIndex++;
  leftPinIndex = leftPinIndex%4;
  digitalWrite(leftPinArray[leftPinIndex],HIGH);
  delay(pulseTime);
  digitalWrite(leftPinArray[leftPinIndex],LOW);
}
void leftright(){
  leftPinIndex--;
  if(leftPinIndex == -1){
    leftPinIndex = 3; 
  }
  leftPinIndex = leftPinIndex%4;
  digitalWrite(leftPinArray[leftPinIndex],HIGH);
  delay(pulseTime);
  digitalWrite(leftPinArray[leftPinIndex],LOW);


}
void rightright(){
  rightPinIndex++;
  rightPinIndex = rightPinIndex%4;
  digitalWrite(rightPinArray[rightPinIndex],HIGH);
  delay(pulseTime);
  digitalWrite(rightPinArray[rightPinIndex],LOW);
}
void rightleft(){
  rightPinIndex--;
  if(rightPinIndex == -1){
    rightPinIndex = 3; 
  }
  rightPinIndex = abs(rightPinIndex);
  rightPinIndex = rightPinIndex%4;
  digitalWrite(rightPinArray[rightPinIndex],HIGH);
  delay(pulseTime);
  digitalWrite(rightPinArray[rightPinIndex],LOW);
}

void inin(){
  zPinIndex--;
  if(zPinIndex == -1){
    zPinIndex = 3; 
  }
  zPinIndex = abs(zPinIndex);
  zPinIndex = zPinIndex%4;
  digitalWrite(zPinArray[zPinIndex],HIGH);
  delay(pulseTime);
  digitalWrite(zPinArray[zPinIndex],LOW);
}
void outout(){
  zPinIndex++;
  zPinIndex = zPinIndex%4;
  digitalWrite(zPinArray[zPinIndex],HIGH);
  delay(pulseTime);
  digitalWrite(zPinArray[zPinIndex],LOW);
}
