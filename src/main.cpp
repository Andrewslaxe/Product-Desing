#include <Arduino.h>
#include <WiFi.h>
#include <time.h>

const long offset = 0;
const int daylight = 3600;

char *ssid = "Usergioarboleda";
char *password = "ceskqyw2012";
char *ntpServer = "pool.ntp.org";

void imprimirHora() {
  struct tm timeInfo;
  if(!getLocalTime(&timeInfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeInfo, "%A, %B %d %Y %H:%M:%S");
}

void setup() { 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  Serial.print("Entró al loop");  
  configTime(offset, daylight, ntpServer);
  imprimirHora();
}