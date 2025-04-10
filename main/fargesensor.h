#pragma once

#ifndef FARGESENSOR
#define FARGESENSOR



#include <Wire.h>
#include "SparkFun_APDS9960.h"


class Fargesensor{
    public:
    Fargesensor(SparkFun_APDS9960* apds);
    bool init(); // Add this method
    
    void oppdaterFarger();
    
    uint16_t returnerAmbient();
    uint16_t returnerRod();
    uint16_t returnerGronn();
    uint16_t returnerBlaa();

    void lesFargeDebug();

    private:
    SparkFun_APDS9960* _apds;

    uint16_t _ambient_light;
    uint16_t _red_light;
    uint16_t _green_light;
    uint16_t _blue_light;

};


#endif