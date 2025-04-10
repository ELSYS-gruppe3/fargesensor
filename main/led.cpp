#include "led.h"

Led::Led(int redPin, int greenPin, int bluePin) : 
    _redPin(redPin), 
    _greenPin(greenPin), 
    _bluePin(bluePin) 
{
}


void Led::setup() {
    pinMode(_redPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);
    pinMode(_bluePin, OUTPUT);
}

void Led::setColor(String color) {
    if (color == "Red") {  // Using String comparison
        digitalWrite(_greenPin, LOW);
        digitalWrite(_bluePin, LOW);
        digitalWrite(_redPin, HIGH);
        Serial.println("Color set to Red");
    }
    else if (color == "Blue") {
        digitalWrite(_redPin, LOW);
        digitalWrite(_greenPin, LOW);
        digitalWrite(_bluePin, HIGH);
        Serial.println("Color set to blue");
    }
    else if (color == "Green") {
        digitalWrite(_redPin, LOW);
        digitalWrite(_bluePin, LOW);
        digitalWrite(_greenPin, HIGH);
        Serial.println("Color set to green");
    }
    else {
        Serial.println("No matching color");
    }
}
