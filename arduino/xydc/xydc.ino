String shapeA = String("aw");
String shapeS = String("sw");
String shapeD = String("qeggg");
String shapeF = String("");
String shapez = String("D2A0");//ONE DOT
String shapex = String("D2S0");//TWO DOTS
String shapec = String("qa");//THREE DOTS
String shapev = String("qs");//FOUR DOTS

//shapecode
/*
www.trashrobot.org/xydc 
XY Trash Robot with DC motors 
using drawers from CD/DVD drives 
FREE, PUBLIC DOMAIN
NO COPYRIGHT
*/

boolean loopMode = false;

float scaleFactor = 2;
float unitTriangleOut = 150;//ms
float unitTriangleIn = 150;//ms
float unitSquareOut = 100;//ms
float unitSquareIn = 100;//ms
float unitNull = 100;//ms

float sideTriangleOut = unitTriangleOut;
float sideTriangleIn= unitTriangleIn;
float sideSquareOut = unitSquareOut;
float sideSquareIn = unitSquareIn;
float sideNull = unitNull;

char prevAction = 'w';

int buttonValue = 0;

int triangleOutPin = 10;
int triangleInPin = 11;
int squareOutPin = 8;
int squareInPin = 9;

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
}

void loop() {
  
  buttonValue = analogRead(A4);//or whatever pin the button is on
  
  if(abs(buttonValue - 256) < 100){//z ONE DOT, 1 10k resistor from ground, 3 from 5vdc
    doTheThing('z');
  }
  if(abs(buttonValue - 512) < 100){//x TWO DOTS, two 10k resistors from 5VDC and 2 from ground
    doTheThing('x');
  }
  if(abs(buttonValue - 768) < 100){//c THREE DOTS, one 10k resistor down from 5VDC, three from ground
    doTheThing('c');
  }
  if(abs(buttonValue - 1023) < 100){//v FOUR DOTS, connected to 5VDC
    doTheThing('v');
  }
}

void drawGlyph(String localGlyph){
  for(int index = 0;index < localGlyph.length();index++){
      doTheThing(localGlyph.charAt(index));
  }
}

void doTheThing(char localCommand){
  Serial.print(localCommand);
  /*
    Test if current action is a loop, and if NOT, 
    set the previous action to be this command
    also test if in a loop using loopMode boolean
    terminate all loops with '0', 
  */

  if(!isLoop(localCommand) && !loopMode){
    prevAction = localCommand;
  }
  if(isLoop(localCommand) && !loopMode){
    loopMode = true;
  }
     
  if(localCommand == 'q'){//reset to "unit" value of "side", all in miliseconds
    sideTriangleOut = unitTriangleOut;
    sideTriangleIn= unitTriangleIn;
    sideSquareOut = unitSquareOut;
    sideSquareIn = unitSquareIn;
    sideNull = unitNull;
  }
  if(localCommand == 'w'){
    delay(sideNull);
  }
  if(localCommand == 'e'){
    sideNull /= scaleFactor;
  }
  if(localCommand == 'r'){
    sideNull *= scaleFactor;
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
  }
  if(localCommand == 'h'){
    sideTriangleOut *= scaleFactor;
    sideTriangleIn *= scaleFactor;
  }
  if(localCommand == 'j'){
    sideSquareOut /= scaleFactor;
    sideSquareIn /= scaleFactor;
  }
  if(localCommand == 'k'){
    sideSquareOut *= scaleFactor;    
    sideSquareIn *= scaleFactor;    
  }
  if(localCommand == '0'){
    loopMode = false;//loop terminator 
  }
  if(localCommand == '1'){//4
    doTheThing(prevAction);
    doTheThing(prevAction);
    doTheThing(prevAction);
    doTheThing(prevAction);
  }
  if(localCommand == '2'){//16
    doTheThing('1');
    doTheThing('1');
    doTheThing('1');
    doTheThing('1');    
  }
  if(localCommand == '3'){//64
    doTheThing('2');
    doTheThing('2');
    doTheThing('2');
    doTheThing('2');    
  }
  if(localCommand == '4'){//256
    doTheThing('3');
    doTheThing('3');
    doTheThing('3');
    doTheThing('3');    
  }
  if(localCommand == '5'){//1024
    doTheThing('4');
    doTheThing('4');
    doTheThing('4');
    doTheThing('4');    
  }
  if(localCommand == '6'){//4096
    doTheThing('5');
    doTheThing('5');
    doTheThing('5');
    doTheThing('5');    
  }
  if(localCommand == '7'){//16384
    doTheThing('6');
    doTheThing('6');
    doTheThing('6');
    doTheThing('6');    
  }
  if(localCommand == 'A'){
    drawGlyph(shapeA);
  }
  if(localCommand == 'S'){
    drawGlyph(shapeS);
  }
  if(localCommand == 'D'){
    drawGlyph(shapeD);
  }
  if(localCommand == 'F'){
    drawGlyph(shapeF);
  }
   if(localCommand == 'z'){
    drawGlyph(shapez);
  }
  if(localCommand == 'x'){
    drawGlyph(shapex);
  }
  if(localCommand == 'c'){
    drawGlyph(shapec);
  }
  if(localCommand == 'v'){
    drawGlyph(shapev);
  }

}

bool isLoop(char localCommand){
    if(localCommand == '1' ||
       localCommand == '2' ||
       localCommand == '3' ||
       localCommand == '4' ||
       localCommand == '5' ||
       localCommand == '6' ||
       localCommand == '7'){
           return true;
       }
       else{
           return false;
       }
}
