/*******************************************
* Exercise 3: Station Mode Operation -     *
*             Connect to a WIFI network    *
* Authors: Osiris Roman, Winter Morejon,   *
*          Sergio Hidalgo.                 *
********************************************/
// Include the libs 
#include <ESP8266WiFi.h>

//Parameters WIFI 
const char* ssid = "HUAWEI P10"; 
const char* password = "1857047ec008"; 

void setup() { 
  // put your setup code here, to run once: 
  Serial.begin(115200); 
  delay(20); 
  // Connect to the WIFI 
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED){ 
    delay(500); 
    Serial.print("."); 
  }

  Serial.println(""); 
  Serial.println("Wi−Fi connected!"); 
  Serial.println(WiFi.localIP());
}

void loop() { }
