#include <Arduino.h>
#include <WiFi.h>
#include <time.h>

const long offset_sec = -18000;
const int daylight = 0;

char *ssid = "Usergioarboleda";
char *password = "ceskqyw2012";
char *ntpServer = "pool.ntp.org";

void imprimirhora();

void setup() { 
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting to WiFi... \n");
  }
  Serial.println("Connected to the WiFi network");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());  
  configTime(offset_sec, daylight, ntpServer);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  imprimirHora();
}

void imprimirHora() {
  struct tm timeInfo;
  if(!getLocalTime(&timeInfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeInfo, "%A, %B %d %Y %H:%M:%S");
}
