/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "" 
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Your WiFi credentials.
char ssid[] = "";
char pass[] = "";

Servo s1;
Servo s2;
Servo s3;

// Define pin numbers for LED and Buzzer
#define LED_PIN   2 // Pin D3 (GPIO 0) for LED
#define BUZZER_PIN 12  // Pin D6 (GPIO 12) for Buzzer

// Servo control
BLYNK_WRITE(V1) {
  s1.write(param.asInt());
}

BLYNK_WRITE(V2) {
  s2.write(param.asInt());
}

BLYNK_WRITE(V3) {
  s3.write(param.asInt());
}

// LED control
BLYNK_WRITE(V4) {
  int ledState = param.asInt();  // 0 or 1 from button widget
  digitalWrite(LED_PIN, ledState);  // Control LED
}

// Buzzer control
BLYNK_WRITE(V5) {
  int buzzerState = param.asInt();  // 0 or 1 from button widget
  if (buzzerState == 1) {
    digitalWrite(BUZZER_PIN, HIGH);  // Turn on Buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Turn off Buzzer
  }
}

void setup() {
  // Debug console
  Serial.begin(115200);

  // Set LED and Buzzer pins as OUTPUT
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Start Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // Attach servos
  s1.attach(2, 700, 2300);  // D4 (GPIO 2)
  s2.attach(16, 700, 2300); // D0 (GPIO 16)
  s3.attach(5, 700, 2300);  // D1 (GPIO 5)
}

void loop() {
  Blynk.run();
}