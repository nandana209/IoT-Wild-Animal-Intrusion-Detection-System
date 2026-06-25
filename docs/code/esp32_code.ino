#include <Arduino.h>

#if defined(ESP32) || defined(ARDUINO_RASPBERRY_PI_PICO_W)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

// ======================================================
// Configuration (Safe for GitHub)
// ======================================================

#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

#define API_KEY "YOUR_FIREBASE_API_KEY"
#define DATABASE_URL "YOUR_FIREBASE_DATABASE_URL"

#define rxPin 18
#define txPin 19

HardwareSerial sim800(1);

String PHONE = "YOUR_PHONE_NUMBER";

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

bool signupOK = false;

const int buzzer = 5;
const int LEDPIN = 15;

unsigned long previousMillis = 0;
unsigned long alertMillis = 0;

const long interval = 3000;
const long alertInterval = 120000;

bool switchval = false;
String label = "";
