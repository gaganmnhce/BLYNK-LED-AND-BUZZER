// Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Define the Blynk Authentication Token

// #define BLYNK_TEMPLATE_ID ""  // Replace with your template ID  
// #define BLYNK_TEMPLATE_NAME "" // Replace with your template name
#define BLYNK_AUTH_TOKEN ""  // Replace with your auth token

// Define Wi-Fi credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";  // Replace with your Wi-Fi name
char pass[] = "";  // Replace with your Wi-Fi password

// Define the pins for the LEDs and buzzers
#define LED1_PIN D4
#define BUZZER1_PIN D4
#define LED2_PIN D5
#define BUZZER2_PIN D5
#define LED3_PIN D6
#define BUZZER3_PIN D6

// Get the button value from the Blynk app (virtual pins V0, V1, V2)
BLYNK_WRITE(V0) {
  int state = param.asInt();  // Get the button state (0 or 1)
  digitalWrite(LED1_PIN, state);  // Turn LED1 on/off
  digitalWrite(BUZZER1_PIN, state);  // Turn Buzzer1 on/off
}

BLYNK_WRITE(V1) {
  int state = param.asInt();  // Get the button state (0 or 1)
  digitalWrite(LED2_PIN, state);  // Turn LED2 on/off
  digitalWrite(BUZZER2_PIN, state);  // Turn Buzzer2 on/off
}

BLYNK_WRITE(V2) {
  int state = param.asInt();  // Get the button state (0 or 1)
  digitalWrite(LED3_PIN, state);  // Turn LED3 on/off
  digitalWrite(BUZZER3_PIN, state);  // Turn Buzzer3 on/off
}

void setup() {
  // Set the LED and Buzzer pins as output
  pinMode(LED1_PIN, OUTPUT);
  pinMode(BUZZER1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(BUZZER2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(BUZZER3_PIN, OUTPUT);

  // Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);  // Classic Blynk server
}

void loop() {
  // Run the Blynk library
  Blynk.run();
}
