#include "led.h"
#include <Arduino.h>
#include <Wire.h>
#include "SparkFun_APDS9960.h"
#include "fargesensor.h"


SparkFun_APDS9960 apds = SparkFun_APDS9960();
SparkFun_APDS9960* apds_ptr = &apds;
Fargesensor fargesensor(apds_ptr);

int PWM_LED = 5;
int RED = 17;
int GREEN = 18;
int BLUE = 19;

int START_BUTTON = 16;

Led testLed(RED, GREEN, BLUE);


void setup() {
  Serial.begin(9600);
  while(!Serial); // Wait for serial connection
  Serial.println("Serial initialized");
  pinMode(PWM_LED, OUTPUT);

  pinMode(START_BUTTON,INPUT);
  
  Wire.begin();

  testLed.setup();

  fargesensor.init();

  analogWrite(PWM_LED, 255);

  Serial.println("Sensor initialized");
  

}

String colors[] = {"Red","Green","Blue"};

void loop() {

  if (digitalRead(START_BUTTON) == HIGH) {
    Serial.println("HIGH");

    for (int i = 0; i<3; i++) {
      testLed.setColor(colors[i]);
      analogWrite(PWM_LED,255);
      delay(500);
      fargesensor.oppdaterFarger();
      Serial.println();
      Serial.println("LED: "+colors[i]);
      Serial.println("Rød:"+String(fargesensor.returnerRod())+" Grønn:"+String(fargesensor.returnerGronn())+" Blå:"+String(fargesensor.returnerBlaa()));
      delay(500);
    }
    analogWrite(PWM_LED,0);
  }

}

