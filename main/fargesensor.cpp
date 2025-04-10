#include "fargesensor.h"

// In fargesensor.cpp
Fargesensor::Fargesensor(SparkFun_APDS9960* apds) :
                            _ambient_light(0),
                            _red_light(0),
                            _green_light(0),
                            _blue_light(0)
{
    _apds = apds;
}

bool Fargesensor::init() {
    Wire.begin();
    // _apds->enableColor(true);
    if (_apds->init()) {
        if (_apds->enableLightSensor(false)) {
            delay(500);
            return true;
        }
    }
    return false;
}

void Fargesensor::oppdaterFarger(){
    //Leser fra adps sensor, sender så avlest data til PI.
    if (  !_apds -> readAmbientLight(_ambient_light) ||
          !_apds -> readRedLight(_red_light) ||
          !_apds ->readGreenLight(_green_light) ||
          !_apds ->readBlueLight(_blue_light) ) 
    {
    Serial.println("Error reading light values");
    } 
  else 
    {
    Serial.println("Read light values");
    }
}

uint16_t Fargesensor::returnerAmbient(){
    //Returnerer verdien av ambient light
    return _ambient_light;
}

uint16_t Fargesensor::returnerRod(){
    //Returnerer verdien av red light
    return _red_light;
}

uint16_t Fargesensor::returnerGronn(){
    //Returnerer verdien av green light
    return _green_light;
}

uint16_t Fargesensor::returnerBlaa(){
    //Returnerer verdien av blue light
    return _blue_light;
}



void Fargesensor::lesFargeDebug(){
    //Leser fra adps, sender så avlest data over seriell til datamaskin for debugging.
    if (  !_apds -> readAmbientLight(_ambient_light) ||
          !_apds -> readRedLight(_red_light) ||
          !_apds -> readGreenLight(_green_light) ||
          !_apds -> readBlueLight(_blue_light) ) 
    {
    Serial.println("Error reading light values");
    } 
  else 
    {
    Serial.print("Ambient: ");
    Serial.print(_ambient_light);
    Serial.print(" Red: ");
    Serial.print(_red_light);
    Serial.print(" Green: ");
    Serial.print(_green_light);
    Serial.print(" Blue: ");
    Serial.println(_blue_light);
    }
}


