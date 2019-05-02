/*******************************************
* Exercise 2: Using the GPIO pins of the   *
*             ESP8266                      *
* Authors: Osiris Roman, Winter Morejon,   *
*          Sergio Hidalgo.                 *
********************************************/
#include "ESP8266WiFi.h"

void setup() { 
  // put your setup code here, to run once: 
  pinMode(2, OUTPUT);
}

void loop() { 
  // put your main code here, to run repeatedly: 
  digitalWrite(2, HIGH); 
  delay(1000); 
  digitalWrite(2, LOW); 
  delay(1000); 
}
