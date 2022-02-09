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

void motorFWD(bool side, byte power, byte offset = 0)
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

void motorFWD_ALL(byte power, byte offsetR = 0, byte offsetL = 0)
{
    MOT_L_FWD;
    MOT_R_FWD;
    
    MOT_L_PWM(power, offsetL); 
    MOT_R_PWM(power, offsetR);
}

void motorBCK_ALL(byte power, byte offsetR = 0, byte offsetL = 0)
{
    MOT_L_BCK;
    MOT_R_BCK;
    
    MOT_L_PWM(power, offsetL); 
    MOT_R_PWM(power, offsetR);
}

void motorBCK(bool side, byte power, byte offset = 0)
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

void motorBreak(bool side, byte power)
{
    motorStop(side);
    motorBCK(side, 70);
    delay(1);
    motorStop(side);
}

void motorBreak_ALL(byte power)
{
    motorStop_ALL();
    motorBCK_ALL(power);
    delay(1);
    motorStop_ALL();
}

#endif