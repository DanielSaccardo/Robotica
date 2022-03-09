#include "motore.h"

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

void motorFWD_ALL(byte power, byte offsetR, byte offsetL)
{
    MOT_L_FWD;
    MOT_R_FWD;
    
    MOT_L_PWM(power, offsetL); 
    MOT_R_PWM(power, offsetR);
}

void motorBCK_ALL(byte power, byte offsetR, byte offsetL)
{
    MOT_L_BCK;
    MOT_R_BCK;
    
    MOT_L_PWM(power, offsetL); 
    MOT_R_PWM(power, offsetR);
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

void motorStop(bool side)
{
    if (side)
    {       
        MOT_R_STOP;
    }
    else
    {
        MOT_L_STOP;
    }            
}

void motorStop_ALL(void)
{
    MOT_R_STOP;
    
    MOT_L_STOP;
}

void motorBreak(bool side, byte power, bool direction)
{
    motorStop(side);

    if (direction)      motorBCK(side, power);
    else                motorFWD(side, power);

    delay(1);

    motorStop(side);
}

void motorBreak_ALL(byte power, bool direction)
{
    motorStop_ALL();

    if (direction)      motorBCK_ALL(power);
    else                motorFWD_ALL(power);

    delay(1);
    
    motorStop_ALL();
}
