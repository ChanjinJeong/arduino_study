#include <Arduino.h>
#line 1 "j:\\vscode\\arduino\\arduino_study\\sketch.ino"
#include <SoftwareSerial.h>
SoftwareSerial bt(8, 9); // TX BT, RX BT

#include "dht.h"
#define dataPin A0
dht DHT;

int temp;
int hum;

void setup() {
 
 Serial.begin(9600); 
 bt.begin(9600); 

   
}

void loop(){
  int readData = DHT.read11(dataPin);

  hum = DHT.humidity;
  temp = DHT.temperature;


Serial.print(temp); //send temperature to serial 
 Serial.print(";");
 Serial.print(hum); //send humidity to serial 
 Serial.println(";");


  
 bt.print(temp); //send temperature to MIT App
 bt.print(";");
 bt.print(hum); //send humidity to MIT App 
 bt.println(";");
  
  delay(500);
}
