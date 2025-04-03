
/*
Ren fargesensor og LED-kode

Fargesensor sender data over I2C, standard SDA pin 21, og SCL pin 22.
LED satt til pin 15.

LED lyser i et lite øyeblikk før sensoren tar målingen, og skrur seg av igjen.
*/

#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;

void setup() {
  Serial.begin(115200);

  if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  //enable color sensign mode
  apds.enableColor(true);

  pinMode(15,OUTPUT);
  digitalWrite(15,HIGH);
  delay(500);
  digitalWrite(15,LOW);
}

void loop() {
  //create some variables to store the color data in
  uint16_t r, g, b, c;
  
  //wait for color data to be ready
  while(!apds.colorDataReady()){
    delay(5);
  }

  //get the data and print the different channels
  digitalWrite(15,HIGH);
  delay(200);
  apds.getColorData(&r, &g, &b, &c);
  Serial.print("red: ");
  Serial.print(r);
  
  Serial.print(" green: ");
  Serial.print(g);
  
  Serial.print(" blue: ");
  Serial.print(b);
  
  Serial.print(" clear: ");
  Serial.println(c);
  Serial.println();
  digitalWrite(15,LOW);

  
  delay(500);
}


