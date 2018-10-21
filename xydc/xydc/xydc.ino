String shape1 = String("asdf");
String shape2 = String("hh1g 1g 1g 1");
String shape3 = String("");
String shape4 = String("");
String shape5 = String("");
String shape6 = String("");
String shape7 = String("");
String shape8 = String("");
String currentGlyph = String("2");

//shapecode 
/*
www.trashrobot.org/xydc 
XY Trash Robot with DC motors 
using drawers from CD/DVD drives 
FREE, PUBLIC DOMAIN
NO COPYRIGHT
*/

String currentGlyph = String("5678");
float scaleFactor = 2;
float unitTriangleOut = 100;//ms
float unitTriangleIn = 100;//ms
float unitSquareOut = 100;//ms
float unitSquareIn = 100;//ms
float unitNull = 100;//ms

float sideTriangleOut = unitTriangleOut;
float sideTriangleIn= unitTriangleIn;
float sideSquareOut = unitSquareOut;
float sideSquareIn = unitSquareIn;
float sideNull = unitNull;

int triangleOutPin = 12;
int triangleInPin = 13;
int squareOutPin = 10;
int squareInPin = 11;

void setup() {
  Serial.begin(115200);
  pinMode(triangleOutPin,OUTPUT);
  pinMode(triangleInPin,OUTPUT); 
  pinMode(squareOutPin,OUTPUT); 
  pinMode(squareInPin,OUTPUT);
  digitalWrite(triangleOutPin,LOW);
  digitalWrite(triangleInPin,LOW);
  digitalWrite(squareOutPin,LOW);
  digitalWrite(squareInPin,LOW);
  
  drawGlyph(currentGlyph);
  
}

void loop() {
  
  
}

void drawGlyph(String localGlyph){
  for(int index = 0;index < localGlyph.length();index++){
      doTheThing(localGlyph.charAt(index));
  }
}

void doTheThing(char localCommand){
  if(localCommand == ' '){
    delay(sideNull);
  }
  if(localCommand == 'a'){
    //turn on output to triangle out pin, should be pin 13
    digitalWrite(triangleOutPin,HIGH);
    delay(sideTriangleOut);
    //turn off output to triangle out pin, should be pin 13
    digitalWrite(triangleOutPin,LOW);
  }
  if(localCommand == 's'){
    //turn on output to triangle in pin, should be pin 12
    digitalWrite(triangleInPin,HIGH);
    delay(sideTriangleIn);
    //turn off output to triangle in pin, should be pin 12
    digitalWrite(triangleInPin,LOW);    
  }
  if(localCommand == 'd'){
    //turn on output to square out pin, should be pin 11
    digitalWrite(squareOutPin,HIGH);
    delay(sideSquareOut);
    //turn off output to square out pin, should be pin 11
    digitalWrite(squareOutPin,LOW);
  }
  if(localCommand == 'f'){
    //turn on output to square in pin, should be pin 10
    digitalWrite(squareInPin,HIGH);
    delay(sideSquareIn);
    //turn off output to square in pin, should be pin 10
    digitalWrite(squareInPin,LOW);
  }
  if(localCommand == 'g'){
    sideTriangleOut /= scaleFactor;
    sideTriangleIn /= scaleFactor;
    sideSquareOut /= scaleFactor;
    sideSquareIn /= scaleFactor;
    sideNull /= scaleFactor;
  }
  if(localCommand == 'h'){
    sideTriangleOut *= scaleFactor;
    sideTriangleIn *= scaleFactor;
    sideSquareOut *= scaleFactor;    
    sideSquareIn *= scaleFactor;    
    sideNull *= scaleFactor;
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
