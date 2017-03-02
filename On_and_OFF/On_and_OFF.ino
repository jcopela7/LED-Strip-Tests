#include <Adafruit_NeoPixel.h>


#define PIN 6


boolean initalize=true;
char  colour;
double red=255;
double green=0;
double blue=0;
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
    /*
    //cycling purple, blue, green, yellow
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
    }*/

    //fading transition 

    uint32_t color=strip.Color(red,green,blue);
    for(int i=0;i<NUM_LEDs;i++){
      strip.setPixelColor(i,color);
    }
    red-=1;
    green+=0.5;
    blue+=0.2;
    if(red<0){
      red=255;
    }
    if(blue>244){
      blue=0;
    }
    if(green>244){
      green=0;
    }
    strip.show();
    delay(25);
  /*
  colour=Serial.read();
  
  
  if(colour=='b'){
    for(int i=0; i<6; i++){
      strip.setPixelColor(i,0,10,255);
    }
    strip.show();
    Serial.println("blue");
  }

  if(colour=='g'){
    for(int i=0; i<6; i++){
      strip.setPixelColor(i,0,255,10);
    }
    strip.show();
    Serial.println("green");
  }

  if(colour=='r'){
    for(int i=0; i<6; i++){
      strip.setPixelColor(i,255,0,0);
    }
    strip.show();
  }
    
  if(colour=='n'){
    for(int i=0; i<6; i++){
      strip.setPixelColor(i,0,0,0);
    }
    strip.show();

  }

  Serial.println(colour);*/
}
