#include <Adafruit_NeoPixel.h>


#define PIN 6
int r=0;
int g=255;
boolean initalize=true;
char  colour;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(30,PIN,NEO_GRB+NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:

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
