#include <WiFi.h>
#include <Firebase_ESP_Client.h>

/* WiFi Credentials */
#define WIFI_SSID "Pradeep_2.4GEXT"
#define WIFI_PASSWORD "0836422031"

/* Firebase Credentials */
#define API_KEY "AIzaSyBAd7nGuGO-_2Q0DSMRJlyiAlf-OItHkgE"
#define USER_EMAIL "ramharakhnikeel@gmail.com"
#define USER_PASSWORD "123456"
#define DATABASE_URL "https://geezaflick-default-rtdb.firebaseio.com/"

/* Pin Definitions */
#define CONTROL_PIN 4  // Pin for ESP32 to Arduino (Servo control)
#define LED_PIN 2      // LED control (if applicable)

/* Firebase Objects */
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(CONTROL_PIN, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
  }

  /* Firebase Setup */
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;

  Firebase.reconnectNetwork(true);
  fbdo.setBSSLBufferSize(4096, 1024);
  fbdo.setResponseSize(2048);
  Firebase.begin(&config, &auth);
  Firebase.setDoubleDigits(5);
  config.timeout.serverResponse = 10 * 1000;
}

void loop() {
  if (Firebase.ready() && (millis() - sendDataPrevMillis > 1000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();

    // Read servo state from Firebase
    if (Firebase.RTDB.getInt(&fbdo, "/servo/state")) {
      int servoState = fbdo.to<int>();

      // Send the servo state (HIGH or LOW) to the Arduino
      digitalWrite(CONTROL_PIN, servoState ? HIGH : LOW);
    }

    // Read LED state from Firebase (if necessary)
    if (Firebase.RTDB.getInt(&fbdo, "/led/state")) {
      int ledState = fbdo.to<int>();
      digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    }
  }
  delay(100);
}
