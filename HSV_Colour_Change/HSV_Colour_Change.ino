#include <FastLED.h>

#define NUM_LEDS 25
#define DATA_PIN 6

//Bluetooth Comunication Variables
int state=0;
int bluetooth_Data=0;

//Colour Variables
int hue=1;
int hroc=1;//hue rate of change

//Timing Variables
const long interval=50;
long previousMillis=0;


CRGB leds[NUM_LEDS];

void setup(){

   //setup LED strip
   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
   Serial.begin(9600);
}

void loop(){

    bluetooth_Data=Serial.read();
    if(bluetooth_Data==1){
    state= 1;}
    if(bluetooth_Data==0){
    state=0;}
    if(bluetooth_Data>=2){
      hue=bluetooth_Data;
    }
  
  unsigned long currentMillis= millis();
  
  if(currentMillis - previousMillis >= interval && state==1){
  previousMillis=currentMillis;
  for (int i=0; i<NUM_LEDS; i++){
  leds[i]=CHSV(hue,187,200); //Using hue, saturation, and brightness to set LED colour
  }
  /*hue+=hroc;
  
  if(hroc==244){
    hroc=-1;
  }
  if(hroc==0){
    hroc=1;
  }*/
  FastLED.show();
  Serial.println("LED: On");
  }

  if(state==0){
    for (int i=0; i<NUM_LEDS; i++){
    leds[i]=CRGB(0,0,0);
    }
  FastLED.show();
  Serial.println("LED: Off");
  }

}

