/*******************************************
* Exercise 8: Humidity & Temperature       *
*             Monitoring using DHT11 & 8266*
*             on Blynk app                 *
* Authors: Osiris Roman, Winter Morejon,   *
*          Sergio Hidalgo.                 *
********************************************/

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "45d20ab8456c4950bc46c5bc0d2df1ea";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "posi";
char pass[] = "12345678";

#define DHTPIN 2          // What digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE, 27);
BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(humidity) || isnan(temperature)) {
    Serial.print("\nFailed to read from DHT sensor!");
    return;
  } else {
    Serial.print("\nSend to Blynk");
    Serial.print("\n    Temperature: ");
    Serial.print(temperature);
    Serial.print(" | Humidity: ");
    Serial.print(humidity);
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V0, temperature);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
