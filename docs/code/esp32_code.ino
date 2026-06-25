#include <Arduino.h>
#if defined(ESP32) || defined(ARDUINO_RASPBERRY_PI_PICO_W)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
#define WIFI_SSID "WildSense"
#define WIFI_PASSWORD "1234"
#define API_KEY "AIzaSyD8L3KvO9XXmLw5uo2PhE5xM5V0a3xGhRI"
#define DATABASE_URL "https://wildsense-f4d32-default-rtdb.asia-
southeast1.firebasedatabase.app/"
#define rxPin 18
#define txPin 19
HardwareSerial sim800(1);
String PHONE = "+919567383456";
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
bool switchval;
String label;
void setup()
{
Serial.begin(115200);
Serial.println("esp32 serial initialize");
sim800.begin(9600, SERIAL_8N1, rxPin, txPin);
Serial.println("SIM800L serial initialize");
sim800.println("AT+CMGF=1"); // SMS text mode
delay(1000);
sim800.println("AT+CMGD=1,4"); // Delete all saved SMS
delay(1000);
pinMode(buzzer, OUTPUT);
pinMode(LEDPIN, OUTPUT);
digitalWrite(LEDPIN, HIGH);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
while (WiFi.status() != WL_CONNECTED)
{
Serial.println("Connecting...");
delay(300);
}
config.api_key = API_KEY;
config.database_url = DATABASE_URL;
if (Firebase.signUp(&config, &auth, "", ""))
{
signupOK = true;
Serial.println("Firebase Connected");
}
config.token_status_callback = tokenStatusCallback;
Firebase.begin(&config, &auth);
Firebase.reconnectWiFi(true);
}
void loop()
{
unsigned long currentMillis = millis();
if (currentMillis - previousMillis >= interval)
{
previousMillis = currentMillis;
if (Firebase.RTDB.getBool(&fbdo, F("detected_classes/switch")))
{
switchval = fbdo.boolData();
Serial.println(switchval);
}
if (Firebase.RTDB.getString(&fbdo, F("detected_classes/label")))
{
label = fbdo.stringData();
}
}
if (switchval)
{
Serial.println("xdd");
if (alertMillis == 0 || currentMillis - alertMillis >= alertInterval)
{
sendAlert(label);
alertMillis = currentMillis;
}
digitalWrite(LEDPIN, LOW);
for (unsigned char i = 0; i < 80; i++)
{
digitalWrite(buzzer, HIGH);
delay(1);
digitalWrite(buzzer, LOW);
delay(1);
}
for (unsigned char i = 0; i < 100; i++)
{
digitalWrite(buzzer, HIGH);
delay(2);
digitalWrite(buzzer, LOW);
delay(2);
}
}
else
{
digitalWrite(LEDPIN, HIGH);
}
delay(10);
}
void sendAlert(String animal)
{
String sms_data;
sms_data = "Wild Animal Detected: " + animal;
sim800.print("AT+CMGF=1\r");
delay(1000);
sim800.print("AT+CMGS=\"" + PHONE + "\"\r");
delay(1000);
sim800.print(sms_data);
delay(100);
sim800.write(0x1A);
delay(1000);
Serial.println("SMS Sent Successfully.");
delay(1000);
}