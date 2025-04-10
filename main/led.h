#pragma once

#ifndef LED
#define LED

#include <Arduino.h>

class Led {
    public:
    
    Led(int redPin, int greenPin, int bluePin);

    void setup();

    void setColor(String color);
    
    private:
    int _redPin;
    int _greenPin;
    int _bluePin;
        
};




#endif