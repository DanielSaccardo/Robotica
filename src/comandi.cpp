#include "comandi.h"

#ifndef COMANDI_H
#define COMANDI_H

void setupMotors(void)
{
    pinMode(PWM_L, OUTPUT);
    pinMode(PWM_R, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
}

void motorFWD(bool side, byte power)
{
    if (side) // R
    {
       MOT_R_FWD;
       MOT_R_PWM(power, 0); 
    }

    else // L
    {
        MOT_L_FWD;
        MOT_L_PWM(power, 0); 
    }
}

void motorFWD(bool side, byte power, byte offset)
{
    if (side) // R
    {
       MOT_R_FWD;
       MOT_R_PWM(power, offset); 
    }

    else // L
    {
        MOT_L_FWD;
        MOT_L_PWM(power, offset); 
    }
}

void motorFWD_ALL(byte power, byte offsetR, byte offsetL)
{
    MOT_L_FWD;
    MOT_R_FWD;
    
    MOT_L_PWM(power, offsetL); 
    MOT_R_PWM(power, offsetR);
}

void motorFWD_ALL(byte power)
{
    MOT_L_FWD;
    MOT_R_FWD;
    
    MOT_L_PWM(power, 0); 
    MOT_R_PWM(power, 0);
}

void motorBCK_ALL(byte power, byte offsetR, byte offsetL)
{
    MOT_L_BCK;
    MOT_R_BCK;
    
    MOT_L_PWM(power, offsetL); 
    MOT_R_PWM(power, offsetR);
}

void motorBCK_ALL(byte power)
{
    MOT_L_BCK;
    MOT_R_BCK;
    
    MOT_L_PWM(power, 0); 
    MOT_R_PWM(power, 0);
}

void motorBCK(bool side, byte power)
{
    if (side) // R
    {
       MOT_R_BCK;
       MOT_R_PWM(power, 0); 
    }

    else // L
    {
        MOT_L_BCK;
        MOT_L_PWM(power, 0); 
    }
}

void motorBCK(bool side, byte power, byte offset)
{
    if (side) // R
    {
       MOT_R_BCK;
       MOT_R_PWM(power, offset); 
    }

    else // L
    {
        MOT_L_BCK;
        MOT_L_PWM(power, offset); 
    }
}

void motorStop(bool side)
{
    if (side) // R
    {
       digitalWrite(BIN1, LOW); 
       digitalWrite(BIN2, LOW);
    }

    else // L
    {
         digitalWrite(AIN1, LOW); 
         digitalWrite(AIN2, LOW);
    }
}

void motorStop_ALL(void)
{
    digitalWrite(AIN1, LOW); 
    digitalWrite(AIN2, LOW);
    
    digitalWrite(BIN1, LOW); 
    digitalWrite(BIN2, LOW);
}

#endif