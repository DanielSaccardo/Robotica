//programma AlphaBot2-Ar by Daniel Saccardo & Enrico Caldaro 5AA
/*
 *
 * INCLUDES
 *
 */

#include <Arduino.h>
#include "defines.h"


void setup() 
{
    pinMode(PWM_L, OUTPUT);
    pinMode(PWM_R, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
}

void loop() 
{
    
    MOT_ALL_FWD;
    MOT_ALL_PWM(70,2,0);
    delay(3500);
    MOT_ALL_PWM(0,0,0);
    
    MOT_L_FWD;
    MOT_L_PWM(40,0);
    delay(675);
    
}
