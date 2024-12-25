// #include <SPI.h>
// #include <MFRC522.h>

// #define SS_PIN 10
// #define RST_PIN 9
// MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

// #define LED_PIN 6       // Pin for authorized access LED
// #define BUZZER_PIN 7    // Pin for unauthorized access buzzer

// void setup() 
// {
//   pinMode(LED_PIN, OUTPUT);    // Set the LED pin as output
//   pinMode(BUZZER_PIN, OUTPUT); // Set the buzzer pin as output
  
//   Serial.begin(9600);   // Initiate a serial communication
//   SPI.begin();      // Initiate SPI bus
//   mfrc522.PCD_Init();   // Initiate MFRC522
//   Serial.println("Approximate your card to the reader...");
//   Serial.println();
// }

// void loop() 
// {
//   // Look for new cards
//   if ( ! mfrc522.PICC_IsNewCardPresent()) 
//   {
//     return;
//   }
  
//   // Select one of the cards
//   if ( ! mfrc522.PICC_ReadCardSerial()) 
//   {
//     return;
//   }
  
//   // Show UID on serial monitor
//   Serial.print("UID tag :");
//   String content = "";
//   byte letter;
//   for (byte i = 0; i < mfrc522.uid.size; i++) 
//   {
//      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
//      Serial.print(mfrc522.uid.uidByte[i], HEX);
//      content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
//      content.concat(String(mfrc522.uid.uidByte[i], HEX));
//   }
//   Serial.println();
//   Serial.print("Message : ");
//   content.toUpperCase();
  
//   if (content.substring(1) == "E9 21 0F E3") // Change here the UID of the card/cards you want to give access
//   {
//     Serial.println("Authorized access");
//     Serial.println();
    
//     // Blink LED for authorized access
//     digitalWrite(LED_PIN, HIGH);  // Turn LED ON
//     delay(200);
//     digitalWrite(LED_PIN, LOW);   // Turn LED OFF
//     delay(200);
//     digitalWrite(LED_PIN, HIGH);  // Turn LED ON
//     delay(200);
//     digitalWrite(LED_PIN, LOW);   // Turn LED OFF
//     delay(200);
//     digitalWrite(LED_PIN, HIGH);  // Turn LED ON
//     delay(200);
//     digitalWrite(LED_PIN, LOW);   // Turn LED OFF
//     delay(1000);
//   }
//   else 
//   {
//     Serial.println("Access denied");
//     Serial.println();
    
//     // Sound buzzer for unauthorized access
//     digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer ON
//     delay(200);
//     digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer OFF
//     delay(200);
//     digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer ON
//     delay(200);
//     digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer OFF
//     delay(200);
//     digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer ON
//     delay(200);
//     digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer OFF
//     delay(1000);
//   }
// }





// /*
//  * ISD1820 Arduino Voice Recorder
//  * to record and playback sound using Arduino and ISD1820 Sound Recorder

//  * Watch the video https://youtu.be/IfK8z_o5vbk
//  * get this code from http://robojax.com/learn/arduino/
//  * Get this code and other Arduino codes from Robojax.com
 
// Learn Arduino step by step in structured course with all material, wiring diagram and library
// all in once place. Purchase My course on Udemy.com http://robojax.com/L/?id=62

// Get early access to my videos and have your name shown at the end of my vidoes by joining on  Patreon http://robojax.com/L/?id=63

// /*
//  * ISD1820 Arduino Voice Recorder
//  * Code Written by Ahmad Shamshiri for Robojax.com
//  * on Jan 04, 2018 at 08:57, in Ajax, Ontario, Canada
//   * Permission granted to share this code given that this
//  * note is kept with the code.
//  * Disclaimer: this code is "AS IS" and for educational purpose only.
//  */
// #define REC 2 // pin 2 is used for recording
// #define PLAY_E 3 // pin 3 is used for playback-edge trigger
// // when PLAY_E goes HIGH device will playbak STARTS and continues
// // ISD1820 Arduino Voice Recorder for Robojax.com 

// #define PLAY_L 4 // pin 4 is used for playback  
// // when PLAY_L is HIGH it will playback. As soon as it goes LOW playback STOPS
// // So you have to keep it HIGH to keep playing


// #define FT 5 // pin 5 is used for feed through
// // if the SPI (speaker) pin is used to send Audio to other device, 
// // set FT to high and any audio from microphone will pass through the SPI connector
// // and will NOT record

// #define playTime 5000 // playback time 5 seconds
// #define recordTime 3000 // recording time 3 seconds
// #define playLTime 900 // press and release playback time 0.9 seconds

// void setup() 
// {
//   // ISD1820 Arduino Voice Recorder for Robojax.com 
//   pinMode(REC,OUTPUT);// set the REC pin as output
//   pinMode(PLAY_L,OUTPUT);// set the PLAY_L pin as output
//   pinMode(PLAY_E,OUTPUT);// set the PLAY_e pin as output
//   pinMode(FT,OUTPUT);// set the FT pin as output  
//   Serial.begin(9600);// set up Serial monitor   
// }

// void loop() {
//   // ISD1820 Arduino Voice Recorder for Robojax.com 
//     while (Serial.available() > 0) {
//           char inChar = (char)Serial.read();
//             if(inChar =='p' || inChar =='P'){
//             digitalWrite(PLAY_E, HIGH);
//             delay(50);
//             digitalWrite(PLAY_E, LOW);  
//               Serial.println("Playbak Started");  
//             delay(playTime);
            
//               Serial.println("Playbak Ended");
//             break; 
//             }// if          
//             else if(inChar =='r' || inChar =='R'){
//               digitalWrite(REC, HIGH);
//               Serial.println("Recording started");
//               delay(recordTime);
//               digitalWrite(REC, LOW);
//               Serial.println("Recording Stopped ");              
//             } 
//             else if(inChar =='l' || inChar =='L'){
//             digitalWrite(PLAY_L, HIGH); 
//               Serial.println("Playbak L Started");  
//             delay(playLTime);
//             digitalWrite(PLAY_L, LOW);
//               Serial.println("Playbak L Ended");            
//             }             
//     // ISD1820 Arduino Voice Recorder for Robojax.com         
//       Serial.println("**** Serial Monitor Exited");      
//   Serial.println("**** Enter r to record, p to play");
//     }// wihile

//   delay(500);
// }  









#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

// Pin definitions
#define LED_PIN A0       // Pin for authorized access LED
#define BUZZER_PIN A1    // Pin for unauthorized access buzzer
#define REC 2           // Pin for recording on ISD1820
#define PLAY_E 3        // Pin for edge-triggered playback
#define PLAY_L 4        // Pin for looped playback
#define FT 5            // Pin for feed-through (used to disable mic recording during playback)

#define playTime 5000   // Playback time 5 seconds
#define recordTime 3000 // Recording time 3 seconds
#define playLTime 900   // Playback loop time 0.9 seconds

void setup() 
{
  pinMode(LED_PIN, OUTPUT);    // Set the LED pin as output
  pinMode(BUZZER_PIN, OUTPUT); // Set the buzzer pin as output
  pinMode(REC, OUTPUT);        // Set the REC pin as output for ISD1820
  pinMode(PLAY_L, OUTPUT);     // Set the PLAY_L pin as output for ISD1820
  pinMode(PLAY_E, OUTPUT);     // Set the PLAY_E pin as output for ISD1820
  pinMode(FT, OUTPUT);         // Set the FT pin as output for ISD1820
  
  Serial.begin(9600);          // Start serial communication
  SPI.begin();                 // Start SPI bus
  mfrc522.PCD_Init();          // Initialize MFRC522

  Serial.println("Approximate your card to the reader...");
  Serial.println();
}

void loop() 
{
  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  
  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  
  // Show UID on serial monitor
  Serial.print("UID tag :");
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println(content);

  if (content.substring(1) == "E9 21 0F E3") { // Authorized UID
    Serial.println("Authorized access");
    Serial.println();
    
    // Blink LED for authorized access
    digitalWrite(LED_PIN, HIGH);  // Turn LED ON
    delay(200);
    digitalWrite(LED_PIN, LOW);   // Turn LED OFF
    delay(200);
    digitalWrite(LED_PIN, HIGH);  // Turn LED ON
    delay(200);
    digitalWrite(LED_PIN, LOW);   // Turn LED OFF
    delay(200);
    digitalWrite(LED_PIN, HIGH);  // Turn LED ON
    delay(200);
    digitalWrite(LED_PIN, LOW);   // Turn LED OFF
    delay(1000);
    
    // Play "Access" voice message
    digitalWrite(PLAY_E, HIGH);   // Start playback
    delay(50);
    digitalWrite(PLAY_E, LOW);    // Stop playback
    delay(playTime);
  }
  else { // Unauthorized UID
    Serial.println("Access denied");
    Serial.println();
    
    // Sound buzzer for unauthorized access
    digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer ON
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer OFF
    delay(200);
    digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer ON
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer OFF
    delay(200);
    digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer ON
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer OFF
    delay(1000);

    // Play "Denied" voice message
    // digitalWrite(PLAY_E, HIGH);   // Start playback
    // delay(50);
    // digitalWrite(PLAY_E, LOW);    // Stop playback
    // delay(playTime);
  }
}
