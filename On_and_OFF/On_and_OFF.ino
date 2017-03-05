#include <Adafruit_NeoPixel.h>


#define PIN 6

int state=0;
int flag=0;
int bluetooth_Data=0;

boolean initalize=true;
char  colour;
double red=255;
double red_Change=1;
double green=0;
double green_Change=0.5;
double blue=0;
double blue_Change=0.2;
const int NUM_LEDs=6;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(30,PIN,NEO_GRB+NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
    //Bluetooth read
    bluetooth_Data=Serial.read();
    if(bluetooth_Data==1){
    state= 1;}
    if(bluetooth_Data==0){
      state=0;}
    flag=0;
 
  if(state==0){
    for (int i=0; i<6;i++){
      strip.setPixelColor(i,0,0,0);
    }
    if(flag==0){
      Serial.println("LED: Off");
      flag=1;
    }
    strip.show();
  }
  if(state ==1){
    for (int i=-1; i<6;i++)
    {
        strip.setPixelColor(i,255,38,131);
        strip.setPixelColor(i+1,0,0,200);
        delay(50);
        strip.show();
        if(i==5){
          for(int i=6;i>=0;i--){
            strip.setPixelColor(i,255,38,131);
            strip.setPixelColor(i+1,0,0,200);
            delay(50);
            strip.show();
          }
        }
    }

    for (int i=-1; i<6;i++)
    {
        strip.setPixelColor(i,38,255,100);
        strip.setPixelColor(i+1,0,0,200);
        delay(50);
        strip.show();
        if(i==5){
          for(int i=6;i>=0;i--){
            strip.setPixelColor(i,28,255,100);
            strip.setPixelColor(i+1,233,248,20);
            delay(50);
            strip.show();
          }
        }
    }

        for (int i=-1; i<6;i++)
    {
        strip.setPixelColor(i,233,248,20);
        strip.setPixelColor(i+1,123,140,200);
        delay(50);
        strip.show();
        if(i==5){
          for(int i=6;i>=0;i--){
            strip.setPixelColor(i,28,255,100);
            strip.setPixelColor(i+1,233,248,20);
            delay(50);
            strip.show();
          }
        }
    }
    if(flag==0){
      Serial.println("LED: On");
      flag=1;
    }
    }
    //cycling purple, blue, green, yellow
    

    //fading transition 
/*
    uint32_t color=strip.Color(red,green,blue);
    for(int i=0;i<NUM_LEDs;i++){
      strip.setPixelColor(i,color);
    }
    red-=red_Change;
    green+=green_Change;
    blue+=blue_Change;
    if(red<=0){
      red_Change=-1;
    }
    if(red>=255){
      red_Change=1;
    }
    if(blue>=255){
      blue_Change=-0.5;
    }
    if(blue<=0){
      blue_Change=0.5;
    }
    if(green>=255){
      green_Change=-0.2;
    }
    if(green<=0){
      green_Change=0.2;
    }
    strip.show();
    delay(10);
  *//*
  colour=Serial.read();
  
//Set Colour Mode
  //BLUE
  if(colour=='b'){
    for(int i=0; i<6; i++){
      strip.setPixelColor(i,0,10,255);
    }
    strip.show();
    Serial.println("blue");
  }
  //GREEN
  if(colour=='g'){
    for(int i=0; i<6; i++){
      strip.setPixelColor(i,0,255,10);
    }
    strip.show();
    Serial.println("green");
  }
  //RED
  if(colour=='r'){
    for(int i=0; i<6; i++){
      strip.setPixelColor(i,255,0,0);
    }
    strip.show();
  }
  //OFF
  if(colour=='n'){
    for(int i=0; i<6; i++){
      strip.setPixelColor(i,0,0,0);
    }
    strip.show();

  }

  Serial.println(colour);*/
}
