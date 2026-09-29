#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3fxG6v9lb"
#define BLYNK_TEMPLATE_NAME "IOT based home automation"
#define BLYNK_AUTH_TOKEN "JkrCNvZuX75oTLvqCDZvwlxWL4mfMI3U"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "wifi_name";
char pass[] = "Wifi_password";

#define WHITE_LIGHT 23
#define FAN         22
#define BLUE_LIGHT  21

void setup()
{
  Serial.begin(9600);

  pinMode(WHITE_LIGHT, OUTPUT);
  pinMode(FAN, OUTPUT);
  pinMode(BLUE_LIGHT, OUTPUT);

  // OFF state for active LOW relay
  digitalWrite(WHITE_LIGHT, HIGH);
  digitalWrite(FAN, HIGH);
  digitalWrite(BLUE_LIGHT, HIGH);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}

// V0 → White Light
BLYNK_WRITE(V0) {
  digitalWrite(WHITE_LIGHT, !param.asInt());
}

// V1 → Fan
BLYNK_WRITE(V1) {
  digitalWrite(FAN, !param.asInt());
}

// V2 → Blue Light
BLYNK_WRITE(V2) {
  digitalWrite(BLUE_LIGHT, !param.asInt());
}
