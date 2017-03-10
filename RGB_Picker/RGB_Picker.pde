import processing.serial.*;

Serial myPort;
String ledStatus="LED: Off";
int status= 0;

float rX=50;
float gX=50;
float bX=50;

float [] colour= new float[3];

void setup() {
  size(600,700);
  //myPort = new Serial(this,Serial.list()[0],9600);
  //myPort.bufferUntil('\n');
  //println(Serial.list());
}
//void serialEvent (Serial myPort){
  //ledStatus=myPort.readStringUntil('\n');
 
//}

void draw() {
   background(237,240,241);
   
   fill(255,0,0);
   rect(50,350,450,75);
   fill(0,255,0);
   rect(50,450,450,75);
   fill(0,0,255);
   rect(50,550,450,75);
   stroke(0);
   strokeWeight(5);
   fill(230,231,234);
   rect(rX,350,50,75);
   rect(gX,450,50,75);
   rect(bX,550,50,75);
   strokeWeight(1);
   
   if(mousePressed && mouseX>rX && mouseX<rX+50 && mouseY>350 && mouseY<425){
    rX=mouseX-25; 
   }
   colour[0]=map(rX,50,450,0,255);
   fill(0);
   textSize(32);
   text(colour[0],510,395);
   
   if(mousePressed && mouseX>gX && mouseX<gX+50 && mouseY>450 && mouseY<525){
    gX=mouseX-25; 
   }
   colour[1]=map(gX,50,450,0,255);
   fill(0);
   textSize(32);
   text(colour[1],510,495);
   

   if(mousePressed && mouseX>bX && mouseX<bX+50 && mouseY>550 && mouseY<625){
    bX=mouseX-25; 
   }
   colour[2]=map(bX,50,450,0,255);
   fill(0);
   textSize(32);
   text(colour[2],510,595);
   
   fill(colour[0],colour[1],colour[2]);
   rect(50,50,450,200);
   
   
   
}