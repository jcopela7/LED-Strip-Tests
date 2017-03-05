int ledPin=13;
int state=0;
int flag=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
    if(Serial.read()==1){
    state= 1;}
    if(Serial.read()==0){
      state=0;}
    flag=0;
 
  if(state==0){
    digitalWrite(ledPin,LOW);
    if(flag==0){
      Serial.println("LED: Off");
      flag=1;
    }
  }
  if(state ==1){
    digitalWrite(ledPin,HIGH);
    if(flag==0){
      Serial.println("LED: On");
      flag=1;
    }
    }

  
}
