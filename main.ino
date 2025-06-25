// seguidor-solar-esp32/main.ino
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <FastLED.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET   -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 10
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define LED_PIN 48
#define NUM_LEDS 1
CRGB leds[NUM_LEDS];

Servo servoX, servoY;
int ldrPins[4] = {A0, A1, A2, A3};  // TL, TR, BL, BR
int posX = 90, posY = 90;

void setup() {
  Serial.begin(115200);
  dht.begin();
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  leds[0] = CRGB::Blue;
  FastLED.show();

  servoX.attach(18);
  servoY.attach(19);
  servoX.write(posX);
  servoY.write(posY);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  int TL = analogRead(ldrPins[0]);
  int TR = analogRead(ldrPins[1]);
  int BL = analogRead(ldrPins[2]);
  int BR = analogRead(ldrPins[3]);

  int top = (TL + TR) / 2;
  int bottom = (BL + BR) / 2;
  int left = (TL + BL) / 2;
  int right = (TR + BR) / 2;

  if (abs(top - bottom) > 50) {
    posY += (top > bottom ? 1 : -1);
  }
  if (abs(left - right) > 50) {
    posX += (left > right ? 1 : -1);
  }
  servoX.write(posX);
  servoY.write(posY);

  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  display.clearDisplay();
  display.setCursor(0,0);
  display.print("T:"); display.print(temp); display.print("C ");
  display.print("H:"); display.print(hum); display.println("%");
  display.display();

  leds[0] = (temp > 30 ? CRGB::Red : CRGB::Green);
  FastLED.show();

  delay(1000);
}
