//  #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>
// #include <Servo.h>  // Include the Servo library
// #include <Wire.h>   // I2C communication
// #include <LiquidCrystal_I2C.h>  // LCD library

// // Define GPIO pins for LED, Buzzer, Motion Detection, and Servo
// #define LED_PIN      0    // D3 (GPIO 0) for LED
// #define BUZZER_PIN   2    // D4 (GPIO 2) for Buzzer
// #define BUZZER_PIN2  14   // D5 (GPIO 14) for Buzzer 2
// #define MOTION_PIN   12   // D6 (GPIO 12) for IR Motion Sensor
// #define SERVO_PIN    13   // D7 (GPIO 13) for Servo motor

// // Wi-Fi credentials
// const char* ssid = "NARZO Turbo";
// const char* password = "whatyouwant";

// // Create Servo object
// Servo myServo;

// LiquidCrystal_I2C lcd(0x27, 16, 2);

// // Define states for devices
// bool ledState = LOW;
// bool buzzerState = LOW;
// bool buzzerState2 = LOW;
// bool irActive = false;

// // Initialize the web server on port 80
// ESP8266WebServer server(80);

// // Debounce variables for motion sensor
// unsigned long lastMotionTime = 0;
// const unsigned long debounceDelay = 500;  // 500ms debounce delay

// // Function to handle the main webpage
// String generateHTML() {
//   String html = "<html><body>";
//   html += "<h1>ESP8266 Web Control</h1>";

//   // LED Control
//   html += "<h2>LED Control</h2>";
//   html += "<form action='/led_on'><button type='submit'>Turn LED On</button></form>";
//   html += "<form action='/led_off'><button type='submit'>Turn LED Off</button></form>";

//   // Buzzer Control
//   html += "<h2>Buzzer Control</h2>";
//   html += "<form action='/buzzer_on'><button type='submit'>Turn Buzzer On</button></form>";
//   html += "<form action='/buzzer_off'><button type='submit'>Turn Buzzer Off</button></form>";

//   // Servo Control
//   html += "<h2>Servo Control</h2>";
//   html += "<form action='/servo_0'><button type='submit'>Move Servo to 0 degrees</button></form>";
//   html += "<form action='/servo_90'><button type='submit'>Move Servo to 90 degrees</button></form>";
  
//   // Motion sensor status
//   html += "<h2>Motion Sensor Status: ";
//   if (irActive) {
//     html += "Motion Detected";
//   } else {
//     html += "No Motion Detected";
//   }
//   html += "</h2>";

//   html += "</body></html>";
//   return html;
// }

// // Web handler functions
// void handleRoot() {
//   server.send(200, "text/html", generateHTML());
// }

// void handleLEDOn() {
//   ledState = HIGH;
//   digitalWrite(LED_PIN, ledState);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleLEDOff() {
//   ledState = LOW;
//   digitalWrite(LED_PIN, ledState);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleBuzzerOn() {
//   buzzerState = HIGH;
//   digitalWrite(BUZZER_PIN, buzzerState);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleBuzzerOff() {
//   buzzerState = LOW;
//   digitalWrite(BUZZER_PIN, buzzerState);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleServo0() {
//   myServo.write(0);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleServo90() {
//   myServo.write(90);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void setup() {
//   // Serial port for debugging purposes
//   Serial.begin(115200);

//   // Set LED, Buzzer, and Motion pins as inputs/outputs
//   pinMode(LED_PIN, OUTPUT);
//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(BUZZER_PIN2, OUTPUT);
//   pinMode(MOTION_PIN, INPUT);

//   // Set initial states of the devices to OFF
//   digitalWrite(LED_PIN, LOW);
//   digitalWrite(BUZZER_PIN, LOW);
//   digitalWrite(BUZZER_PIN2, LOW);

//   // Initialize servo motor
//   myServo.attach(SERVO_PIN);
//   myServo.write(90);  // Initial position at 90 degrees

//   // Initialize the LCD with 16 columns and 2 rows
//   lcd.init();
//   delay(500);  // Delay to ensure LCD initializes properly
//   lcd.backlight();  // Turn on the backlight
//   lcd.setCursor(0, 0);
//   lcd.print("System Ready");

//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to WiFi...");
//   }
//   Serial.println("Connected to WiFi");
//   Serial.println(WiFi.localIP());

//   // Define web handlers for the control actions
//   server.on("/", HTTP_GET, handleRoot);
//   server.on("/led_on", HTTP_GET, handleLEDOn);
//   server.on("/led_off", HTTP_GET, handleLEDOff);
//   server.on("/buzzer_on", HTTP_GET, handleBuzzerOn);
//   server.on("/buzzer_off", HTTP_GET, handleBuzzerOff);
//   server.on("/servo_0", HTTP_GET, handleServo0);
//   server.on("/servo_90", HTTP_GET, handleServo90);

//   // Start the web server
//   server.begin();
// }

// void loop() {
//   server.handleClient();  // Handle incoming client requests

//   // Check the motion sensor state
//   int motionState = digitalRead(MOTION_PIN);
//   unsigned long currentTime = millis();

//   if (motionState == LOW && (currentTime - lastMotionTime > debounceDelay)) {  // LOW means motion detected for most sensors
//     lcd.clear();  // Clear previous message
//     lcd.setCursor(0, 0);
//     lcd.print("Motion Detected");
//     irActive = true;  // IR sensor has triggered
//     myServo.write(0);  // Rotate the servo to 0 degrees when motion is detected
//     lastMotionTime = currentTime;  // Update last motion time
//   } else if (motionState == HIGH && irActive) {
//     lcd.clear();  // Clear previous message
//     lcd.setCursor(0, 0);
//     lcd.print("System Ready");
//     irActive = false;  // IR sensor is inactive
//     myServo.write(90);  // Return the servo to its initial position (90 degrees) when no motion is detected
//   }
// }







// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>
// #include <Servo.h>  // Include the Servo library
// #include <Wire.h>   // I2C communication
// #include <LiquidCrystal_I2C.h>  // LCD library

// // Define GPIO pins for LED, Buzzer, Motion Detection, and Servo
// #define LED_PIN      0    // D3 (GPIO 0) for LED
// #define BUZZER_PIN   2    // D4 (GPIO 2) for Buzzer 1
// #define BUZZER_PIN2  14   // D5 (GPIO 14) for Buzzer 2
// #define MOTION_PIN   12   // D6 (GPIO 12) for IR Motion Sensor
// #define SERVO_PIN    13   // D7 (GPIO 13) for Servo motor

// // Wi-Fi credentials
// const char* ssid = "NARZO Turbo";
// const char* password = "whatyouwant";

// // Create Servo object
// Servo myServo;

// LiquidCrystal_I2C lcd(0x27, 16, 2);

// // Define states for devices
// bool ledState = LOW;
// bool buzzerState = LOW;
// bool buzzerState2 = LOW;
// bool irActive = false;

// // Initialize the web server on port 80
// ESP8266WebServer server(80);

// // Debounce variables for motion sensor
// unsigned long lastMotionTime = 0;
// const unsigned long debounceDelay = 500;  // 500ms debounce delay

// // Function to handle the main webpage
// String generateHTML() {
//   String html = "<html><body>";
//   html += "<h1>ESP8266 Web Control</h1>";

//   // LED Control
//   html += "<h2>LED Control</h2>";
//   html += "<form action='/led_on'><button type='submit'>Turn LED On</button></form>";
//   html += "<form action='/led_off'><button type='submit'>Turn LED Off</button></form>";

//   // Buzzer Control
//   html += "<h2>Buzzer Control</h2>";
//   html += "<form action='/buzzer_on'><button type='submit'>Turn Buzzer 1 On</button></form>";
//   html += "<form action='/buzzer_off'><button type='submit'>Turn Buzzer 1 Off</button></form>";
  
//   html += "<form action='/buzzer2_on'><button type='submit'>Turn Buzzer 2 On</button></form>";
//   html += "<form action='/buzzer2_off'><button type='submit'>Turn Buzzer 2 Off</button></form>";

//   // Servo Control
//   html += "<h2>Servo Control</h2>";
//   html += "<form action='/servo_0'><button type='submit'>Move Servo to 0 degrees</button></form>";
//   html += "<form action='/servo_90'><button type='submit'>Move Servo to 90 degrees</button></form>";
  
//   // Motion sensor status
//   html += "<h2>Motion Sensor Status: ";
//   if (irActive) {
//     html += "Motion Detected";
//   } else {
//     html += "No Motion Detected";
//   }
//   html += "</h2>";

//   // Add JavaScript to auto-refresh the page every 5 seconds
//   html += "<script>setTimeout(function(){ location.reload(); }, 5000);</script>";

//   html += "</body></html>";
//   return html;
// }

// // Web handler functions
// void handleRoot() {
//   server.send(200, "text/html", generateHTML());
// }

// void handleLEDOn() {
//   ledState = HIGH;
//   digitalWrite(LED_PIN, ledState);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleLEDOff() {
//   ledState = LOW;
//   digitalWrite(LED_PIN, ledState);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleBuzzerOn() {
//   buzzerState = HIGH;
//   digitalWrite(BUZZER_PIN, buzzerState);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleBuzzerOff() {
//   buzzerState = LOW;
//   digitalWrite(BUZZER_PIN, buzzerState);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleBuzzer2On() {
//   buzzerState2 = HIGH;
//   digitalWrite(BUZZER_PIN2, buzzerState2);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleBuzzer2Off() {
//   buzzerState2 = LOW;
//   digitalWrite(BUZZER_PIN2, buzzerState2);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleServo0() {
//   myServo.write(0);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void handleServo90() {
//   myServo.write(90);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void setup() {
//   // Serial port for debugging purposes
//   Serial.begin(115200);

//   // Set LED, Buzzer, and Motion pins as inputs/outputs
//   pinMode(LED_PIN, OUTPUT);
//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(BUZZER_PIN2, OUTPUT);
//   pinMode(MOTION_PIN, INPUT);

//   // Set initial states of the devices to OFF
//   digitalWrite(LED_PIN, LOW);
//   digitalWrite(BUZZER_PIN, LOW);
//   digitalWrite(BUZZER_PIN2, LOW);

//   // Initialize servo motor
//   myServo.attach(SERVO_PIN);
//   myServo.write(90);  // Initial position at 90 degrees

//   // Initialize the LCD with 16 columns and 2 rows
//   lcd.init();
//   delay(500);  // Delay to ensure LCD initializes properly
//   lcd.backlight();  // Turn on the backlight
//   lcd.setCursor(0, 0);
//   lcd.print("System Ready");

//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to WiFi...");
//   }
//   Serial.println("Connected to WiFi");
//   Serial.println(WiFi.localIP());

//   // Define web handlers for the control actions
//   server.on("/", HTTP_GET, handleRoot);
//   server.on("/led_on", HTTP_GET, handleLEDOn);
//   server.on("/led_off", HTTP_GET, handleLEDOff);
//   server.on("/buzzer_on", HTTP_GET, handleBuzzerOn);
//   server.on("/buzzer_off", HTTP_GET, handleBuzzerOff);
//   server.on("/buzzer2_on", HTTP_GET, handleBuzzer2On);
//   server.on("/buzzer2_off", HTTP_GET, handleBuzzer2Off);
//   server.on("/servo_0", HTTP_GET, handleServo0);
//   server.on("/servo_90", HTTP_GET, handleServo90);

//   // Start the web server
//   server.begin();
// }

// void loop() {
//   server.handleClient();  // Handle incoming client requests

//   // Check the motion sensor state
//   int motionState = digitalRead(MOTION_PIN);
//   unsigned long currentTime = millis();

//   if (motionState == LOW && (currentTime - lastMotionTime > debounceDelay)) {  // LOW means motion detected for most sensors
//     lcd.clear();  // Clear previous message
//     lcd.setCursor(0, 0);
//     lcd.print("Motion Detected");
    
//     // Update web page status
//     irActive = true;  // IR sensor has triggered
//     digitalWrite(BUZZER_PIN, HIGH);  // Turn on Buzzer 1
//     digitalWrite(BUZZER_PIN2, HIGH);  // Turn on Buzzer 2
//     myServo.write(0);  // Rotate the servo to 0 degrees when motion is detected
//     lastMotionTime = currentTime;  // Update last motion time
//   } else if (motionState == HIGH && irActive) {
//     lcd.clear();  // Clear previous message
//     lcd.setCursor(0, 0);
//     lcd.print("System Ready");

//     // Update web page status
//     irActive = false;  // IR sensor is inactive
//     digitalWrite(BUZZER_PIN, LOW);  // Turn off Buzzer 1
//     digitalWrite(BUZZER_PIN2, LOW);  // Turn off Buzzer 2
//     myServo.write(90);  // Return the servo to its initial position (90 degrees) when no motion is detected
//   }
// }





#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>  // Include the Servo library
#include <Wire.h>   // I2C communication
#include <LiquidCrystal_I2C.h>  // LCD library

// Define GPIO pins for LED, Buzzer, Motion Detection, and Servo
#define LED_PIN      0    // D3 (GPIO 0) for LED
#define BUZZER_PIN   2    // D4 (GPIO 2) for Buzzer 1
#define BUZZER_PIN2  14   // D5 (GPIO 14) for Buzzer 2
#define MOTION_PIN   12   // D6 (GPIO 12) for IR Motion Sensor
#define SERVO_PIN    13   // D7 (GPIO 13) for Servo motor

// Wi-Fi credentials
const char* ssid = "NARZO Turbo";
const char* password = "whatyouwant";

// Create Servo object
Servo myServo;

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define states for devices
bool ledState = LOW;
bool buzzerState = LOW;
bool buzzerState2 = LOW;
bool irActive = false;

// Initialize the web server on port 80
ESP8266WebServer server(80);

// Debounce variables for motion sensor
unsigned long lastMotionTime = 0;
const unsigned long debounceDelay = 500;  // 500ms debounce delay

// Function to handle the main webpage
String generateHTML() {
  String html = "<!DOCTYPE html><html lang='en'><head>";
  html += "<meta charset='UTF-8'>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<title>ESP8266 Web Control</title>";
  html += "<style>";
  html += "body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #e0f7fa; color: #333; display: flex; flex-direction: column; align-items: center; justify-content: center; height: 100vh; box-sizing: border-box; }";
  html += "h1 { font-size: 2.5em; margin-bottom: 0.5em; color: #00796b; }";
  html += "h2 { font-size: 1.5em; margin: 1em 0 0.5em; color: #00796b; }";
  html += "h2, .status { font-weight: bold; }";
  html += "h3 { font-size: 1.5em; margin: 1em 0 0.5em; color: #f44336; }";
  html += ".container { max-width: 800px; width: 100%; padding: 20px; background-color: white; border-radius: 10px; box-shadow: 0px 4px 12px rgba(0, 0, 0, 0.1); margin-top: 20px; }";
  html += ".status { margin-top: 1em; font-size: 1.2em; color: #00796b; }";
  html += ".switch { position: relative; display: inline-block; width: 60px; height: 34px; }";
  html += ".switch input { opacity: 0; width: 0; height: 0; }";
  html += ".slider { position: absolute; cursor: pointer; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; transition: 0.4s; border-radius: 34px; }";
  html += ".slider:before { position: absolute; content: ''; height: 26px; width: 26px; border-radius: 50%; left: 4px; bottom: 4px; background-color: white; transition: 0.4s; }";
  html += "input:checked + .slider { background-color: #4CAF50; }";
  html += "input:checked + .slider:before { transform: translateX(26px); }";
  html += ".servo-buttons { display: flex; justify-content: space-around; gap: 10px; margin-top: 1em; }";
  html += ".servo-button { padding: 10px 20px; background-color: #00796b; color: white; border: none; border-radius: 5px; font-size: 1.1em; cursor: pointer; transition: background-color 0.3s; }";
  html += ".servo-button:hover { background-color: #004d40; }";
  html += "@media (max-width: 600px) { body { padding: 20px; } h1 { font-size: 2em; } h2 { font-size: 1.2em; } .container { padding: 15px; } .servo-buttons { flex-direction: column; align-items: center; } }";
  html += "</style>";
  html += "</head><body>";

  html += "<h1>PHARMA SERVE</h1>";
  html += "<h3>MEDICINE DISPENSER AND REMAINDER</h3>";

  // Container div for the control buttons
  html += "<div class='container'>";

  // LED Control with switch
  html += "<h2>LED Control</h2>";
  html += "<label class='switch'><input type='checkbox' onchange='window.location.href=this.checked ? \"/led_on\" : \"/led_off\"' ";
  if (ledState) html += "checked";
  html += "><span class='slider'></span></label>";

  // Buzzer 1 Control with switch
  html += "<h2>Buzzer 1 Control</h2>";
  html += "<label class='switch'><input type='checkbox' onchange='window.location.href=this.checked ? \"/buzzer_on\" : \"/buzzer_off\"' ";
  if (buzzerState) html += "checked";
  html += "><span class='slider'></span></label>";

  // Buzzer 2 Control with switch
  html += "<h2>Buzzer 2 Control</h2>";
  html += "<label class='switch'><input type='checkbox' onchange='window.location.href=this.checked ? \"/buzzer2_on\" : \"/buzzer2_off\"' ";
  if (buzzerState2) html += "checked";
  html += "><span class='slider'></span></label>";

  // Servo Control
  html += "<h2>Servo Control</h2>";
  html += "<div class='servo-buttons'>";
  html += "<a href='/servo_0'><button class='servo-button'>Move Servo to 0°</button></a>";
  html += "<a href='/servo_90'><button class='servo-button'>Move Servo to 90°</button></a>";
  html += "</div>";

  // Motion sensor status
  html += "<div class='status'>Motion Sensor Status: ";
  if (irActive) {
    html += "<span style='color: green;'>Motion Detected</span>";
  } else {
    html += "<span style='color: red;'>No Motion Detected</span>";
  }
  html += "</div>";

  // Add JavaScript to auto-refresh the page every 5 seconds
  html += "<script>setTimeout(function(){ location.reload(); }, 5000);</script>";

  html += "</div>"; // End of container div
  html += "</body></html>";
  return html;
}


// Web handler functions
void handleRoot() {
  server.send(200, "text/html", generateHTML());
}

void handleLEDOn() {
  ledState = HIGH;
  digitalWrite(LED_PIN, ledState);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLEDOff() {
  ledState = LOW;
  digitalWrite(LED_PIN, ledState);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleBuzzerOn() {
  buzzerState = HIGH;
  digitalWrite(BUZZER_PIN, buzzerState);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleBuzzerOff() {
  buzzerState = LOW;
  digitalWrite(BUZZER_PIN, buzzerState);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleBuzzer2On() {
  buzzerState2 = HIGH;
  digitalWrite(BUZZER_PIN2, buzzerState2);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleBuzzer2Off() {
  buzzerState2 = LOW;
  digitalWrite(BUZZER_PIN2, buzzerState2);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleServo0() {
  myServo.write(0);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleServo90() {
  myServo.write(90);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);

  // Set LED, Buzzer, and Motion pins as inputs/outputs
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUZZER_PIN2, OUTPUT);
  pinMode(MOTION_PIN, INPUT);

  // Set initial states of the devices to OFF
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(BUZZER_PIN2, LOW);

  // Initialize servo motor
  myServo.attach(SERVO_PIN);
  myServo.write(90);  // Initial position at 90 degrees

  // Initialize the LCD with 16 columns and 2 rows
  lcd.init();
  delay(500);  // Delay to ensure LCD initializes properly
  lcd.backlight();  // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("System Ready");

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  // Define web handlers for the control actions
  server.on("/", HTTP_GET, handleRoot);
  server.on("/led_on", HTTP_GET, handleLEDOn);
  server.on("/led_off", HTTP_GET, handleLEDOff);
  server.on("/buzzer_on", HTTP_GET, handleBuzzerOn);
  server.on("/buzzer_off", HTTP_GET, handleBuzzerOff);
  server.on("/buzzer2_on", HTTP_GET, handleBuzzer2On);
  server.on("/buzzer2_off", HTTP_GET, handleBuzzer2Off);
  server.on("/servo_0", HTTP_GET, handleServo0);
  server.on("/servo_90", HTTP_GET, handleServo90);

  // Start the web server
  server.begin();
}

void loop() {
  server.handleClient();  // Handle incoming client requests

  // Check the motion sensor state
  int motionState = digitalRead(MOTION_PIN);
  unsigned long currentTime = millis();

  if (motionState == LOW && (currentTime - lastMotionTime > debounceDelay)) {  // LOW means motion detected for most sensors
    lcd.clear();  // Clear previous message
    lcd.setCursor(0, 0);
    lcd.print("Motion Detected");
    
    // Update web page status
    irActive = true;  // IR sensor has triggered
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer 1 OFF
    digitalWrite(BUZZER_PIN2, HIGH);  // Buzzer 2 ON
    myServo.write(0);  // Rotate the servo to 0 degrees when motion is detected
    lastMotionTime = currentTime;  // Update last motion time
  } else if (motionState == HIGH && irActive) {
    lcd.clear();  // Clear previous message
    lcd.setCursor(0, 0);
    lcd.print("System Ready");

    // Update web page status
    irActive = false;  // IR sensor is inactive
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer 1 OFF
    digitalWrite(BUZZER_PIN2, LOW);  // Buzzer 2 OFF
    myServo.write(90);  // Return the servo to its initial position (90 degrees) when no motion is detected
  }
}
