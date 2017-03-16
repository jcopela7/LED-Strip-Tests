import processing.serial.*;

Serial myPort;
String ledStatus="LED: Off";
int status= 0;
int hue=3;

int r,g,b,r1,g1,b1,r2,g2,b2;

int mode=0;



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
   fill(r,g,b);
   rect(20,10,130,50,10);
   fill(r1,g1,b1);
   rect(160,10,130,50,10);
   fill(r2,g2,b2);
   rect(300,10,130,50,10);
   fill(255);
   
   textSize(32);
   text("ON", 60,135);
   text("OFF",255,135);
   text("Mode1",30,50);
   text("Mode2",170,50);
   text("Mode3",310,50);
   fill(0);
   
   text(ledStatus, 155,240);
   text("Hue: " + hue,175,475);
   
   fill(20,160,133);
   rect(325,325,50,50);
   rect(75,325,50,50);
   
   colorMode(HSB,hue,187,200);
   fill(100,100,100);
   ellipse(225,350,150,150);
   colorMode(RGB,255,255,255,255);
   
   if(mousePressed && mouseX>20 && mouseX<170 && mouseY>10 && mouseY<60){
     r=234;
     g=100;
     b=30;
     r1=20;
     g1=160;
     b1=133;
     r2=20;
     g2=160;
     b2=133;
     mode=1; 
   }
   
   if(mousePressed && mouseX>160 && mouseX<290 && mouseY>10 && mouseY<60){
     r=20;
     g=160;
     b=133;
     r1=234;
     g1=100;
     b1=30;
     r2=20;
     g2=160;
     b2=133;
     mode=2; 
   }
   
   if(mousePressed && mouseX>300 && mouseX<430 && mouseY>10 && mouseY<60){
     r=20;
     g=160;
     b=133;
     r1=20;
     g1=160;
     b1=133;
     r2=234;
     g2=100;
     b2=20;
     mode=3; 
   }
   
   
   if(mousePressed && mouseX>50 && mouseX<200 && mouseY>100 && mouseY<150 && mode==1){
     status=1;
     myPort.write(status);
     stroke(255,0,0);
     strokeWeight(2);
     noFill();
     rect(50,100,150,50,10);
   }
   
   if(mousePressed && mouseX>50 && mouseX<200 && mouseY>100 && mouseY<150 && mode==2){
     status=2;
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
     rect(250,100,150,50,10);     
   } 
   
   if(mousePressed && mouseX>325 && mouseX<375 && mouseY>325 && mouseY<375){
    if(hue<255){
     hue++;
     myPort.write(hue);
     
    }
   } 
   
   if(mousePressed && mouseX>75 && mouseX<125 && mouseY>325 && mouseY<375){
    if(hue>3){
     hue--;
     myPort.write(hue);
    }
   } 
   
   println(status);
   
}