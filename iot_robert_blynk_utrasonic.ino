#define BLYNK_TEMPLATE_ID "TMPL3TKr6DiFF"
#define BLYNK_TEMPLATE_NAME "iotsystem40"
#define BLYNK_AUTH_TOKEN "J418dHuGjU6t2zSeuosTGAyzD1zf8gcm"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int pinValue1;
int pinValue2;
int pinValue3;
int pinValue4;
int pinValue5;
#define echoPin D7
#define trigPin D8


long duration;
int distance;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "admin";
char pass[] = "123456789";
int led = D0;
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V1) {
  pinValue1 = param.asInt();  // assigning incoming value from pin V1 to a variable
}
BLYNK_WRITE(V2) {
  pinValue2 = param.asInt();  // assigning incoming value from pin V1 to a variable
}
BLYNK_WRITE(V3) {
  pinValue3 = param.asInt();  // assigning incoming value from pin V1 to a variable
}
BLYNK_WRITE(V4) {
  pinValue4 = param.asInt();  // assigning incoming value from pin V1 to a variable
}
BLYNK_WRITE(V5) {
  pinValue5 = param.asInt();  // assigning incoming value from pin V1 to a variable
}

void setup() {

  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);
}

void loop() {

  Blynk.run();
  ultrasonic();
  Serial.println(distance);
  if (pinValue1 == 1) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
  }

  if (pinValue2 == 1) {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
  }
  if (pinValue3 == 1) {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
  }
  if (pinValue4 == 1) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
  }
  if (pinValue5 == 1) {
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
  }

  if (distance < 15 && distance != 0) {
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
    delay(1000);
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    delay(2000);
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    delay(1000);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
  }
}

void ultrasonic() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)
}
