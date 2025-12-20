#define BLYNK_TEMPLATE_ID "......................."
#define BLYNK_TEMPLATE_NAME "RGB Connect"
#define BLYNK_AUTH_TOKEN "........................"


#include "WiFi.h"
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = ".....................";
char pass[] = ".....................";


int redValue = 0;
int greenValue = 0;
int blueValue = 0;
int CWValue = 0;
int WWValue = 0;


#define RED_PIN  3
#define GREEN_PIN 4
#define BLUE_PIN  5

#define CW  0
#define WW  1

BLYNK_WRITE(V0) {  // Red
  redValue = param.asInt();
  analogWrite(RED_PIN, redValue);
  Serial.println(redValue);
}

BLYNK_WRITE(V1) {  // Green
  greenValue = param.asInt();
  analogWrite(GREEN_PIN, greenValue);
  Serial.println(greenValue);
}

BLYNK_WRITE(V2) {  // Blue
  blueValue = param.asInt();
  analogWrite(BLUE_PIN, blueValue);
  Serial.println(blueValue);
}

BLYNK_WRITE(V4) {  // Cold White
  CWValue = param.asInt();
  analogWrite(CW, CWValue);
  Serial.println(CWValue);
}

BLYNK_WRITE(V3) {  // Warm White
  WWValue = param.asInt();
  analogWrite(WW, WWValue);
  Serial.println(WWValue);
}

void setup()
{
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}
