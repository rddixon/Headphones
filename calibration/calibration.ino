#include <uspeech.h>
signal voice(A0);

int rotPin = 2;
char c = 'a';
char old_c = 'a';
int led = 13;

void setup() {
  voice.calibrate();
  voice.econstant = 4;
  voice.aconstant = 5;
  voice.vconstant = 2;
  voice.shconstant = 9; //maybe 9
  voice.fconstant = 235;
  Serial.begin(9600);
  pinMode(led, OUTPUT);  
  pinMode(rotPin, OUTPUT);
}

void loop() {
  
  c = voice.getPhoneme();
  Serial.println(c);  
  
  if (c == 'h' && old_c != 'h') {
     Serial.println("yay!");
     digitalWrite(rotPin, HIGH);
     
     for (int i = 0; i < 10; i++){
          digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(100);               // wait for a second
          digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
          delay(100);
      }
      
      digitalWrite(rotPin, LOW);
     
  }
  
  old_c = c;
}
