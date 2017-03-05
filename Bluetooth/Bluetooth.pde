import processing.serial.*;

Serial myPort;
String ledStatus="LED: Off";
int status= 0;




void setup() {
  size(450,500);
  myPort = new Serial(this,Serial.list()[0],9600);
  myPort.bufferUntil('\n');
  println(Serial.list());
}
void serialEvent (Serial myPort){
  ledStatus=myPort.readStringUntil('\n');
 
}

void draw() {
   background(237,240,241);
   fill(20,160,133);
   stroke(33);
   strokeWeight(1);
   rect(50,100,150,50,10);
   rect(250,100,150,50,10);
   fill(255);
   
   textSize(32);
   text("ON", 60,135);
   text("OFF",255,135);
   fill(0);
   
   text(ledStatus, 155,240);
   
   if(mousePressed && mouseX>50 && mouseX<200 && mouseY>100 && mouseY<150){
     status=1;
     myPort.write(status);
     stroke(255,0,0);
     strokeWeight(2);
     noFill();
     rect(50,100,150,50,10);
   }
   
   if(mousePressed && mouseX>250 && mouseX<400 && mouseY>100 && mouseY<150){
     status=0;
     myPort.write(status);
     stroke(255,0,0);
     strokeWeight(2);
     noFill();
     rect(250,150,50,100);     
   } 
   
   println(status);
   
}