//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "" //Enter your blynk auth token4


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";//Enter your WIFI name
char pass[] = "";//Enter your WIFI password

//Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(D4, param.asInt());
}

void setup() {
  //Set the LED pin as an output pin
  pinMode(D4, OUTPUT);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}

