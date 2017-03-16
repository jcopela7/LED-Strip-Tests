#include <FastLED.h>

#define NUM_LEDS 25
#define DATA_PIN 6

//Bluetooth Comunication Variables
int state=0;
int bluetooth_Data=0;

//Colour Variables
int rainbow=1;
int hue=1;
int hroc=1;//hue rate of change

//Timing Variables
const long interval=50;
long previousMillis=0;
long previousMillis2=0;


CRGB leds[NUM_LEDS];

void setup(){

   //setup LED strip
   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
   Serial.begin(9600);
}

void loop(){

    //Collect Data via SPI communication 
    bluetooth_Data=Serial.read();//read incoming data
    
    // Turn Strip On
    if(bluetooth_Data==1){
    state= 1;
    }

    //Turn Strip Off
    if(bluetooth_Data==0){
    state=0;
    }

    //Rainbow Mode
    if(bluetooth_Data==2){
    state=2;
    }

    //Manual Hue Change
    if(bluetooth_Data>=3 && bluetooth_Data<=256){
      hue=bluetooth_Data;
    }


  
  unsigned long currentMillis= millis();
  
  if(currentMillis - previousMillis >= interval && state==1){
    previousMillis=currentMillis;
    manualHueChange(hue);
  }

  if(state==0){
    LED_Off();
  }
 
  unsigned long currentMillis2=millis();

  if(currentMillis2 - previousMillis2 >= interval && state==2){
    previousMillis2=currentMillis2;
    rainbowAutoChange();
  }

  FastLED.show();
}

void LED_Off(){
  
  for (int i=0; i<NUM_LEDS; i++){
    leds[i]=CRGB(0,0,0);
  }

  Serial.println("LED: Off");  
}

void manualHueChange (int hue){
  
  for (int i=0; i<NUM_LEDS; i++){
  leds[i]=CHSV(hue,187,200); //Using hue, saturation, and brightness to set LED colour
  }

  Serial.println("LED: On");  
}


void rainbowAutoChange(){
  for (int i=0; i<NUM_LEDS; i++){
  leds[i]=CHSV(rainbow,187,200); //Using hue, saturation, and brightness to set LED colour
  }

  rainbow+=hroc;
  
  if(rainbow==244){
    hroc=-1;
  }
  if(rainbow==0){
    hroc=1;
  }
  
  FastLED.show();

  Serial.println("Rainbow Mode");
  
}




