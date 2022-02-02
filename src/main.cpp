//programma AlphaBot2-Ar by Daniel Saccardo & Enrico Caldaro
/*
 *
 * INCLUDES
 *
 */

#include <Arduino.h>


/*
 * DEFINES:
 * 
 * PINS
 */

#define AIN1                A0     // Motore L avanti
#define AIN2                A1     // Motore L indietro
#define PWM_L               6      // Pin di comando potenza motore L

#define BIN2                A2     // Motore R avanti
#define BIN1                A3     // Motore R indietro
#define PWM_R               5      // Pin di comando potenza motore R


/*
 * DEFINES:
 *
 * MACROS
*/

#define MOT_R_FWD                 digitalWrite(BIN1, HIGH); digitalWrite(BIN2, LOW)
#define MOT_R_BCK                 digitalWrite(BIN1, LOW); digitalWrite(BIN2, HIGH)
#define MOT_R_PWM(x,y)            analogWrite(PWM_R, x+y)

#define MOT_L_FWD                 digitalWrite(AIN1, HIGH); digitalWrite(AIN2, LOW)
#define MOT_L_BCK                 digitalWrite(AIN1, LOW); digitalWrite(AIN2, HIGH)
#define MOT_L_PWM(x,y)            analogWrite(PWM_L, x+y)

#define MOT_ALL_FWD               MOT_L_FWD; MOT_R_FWD
#define MOT_ALL_BCK               MOT_L_BCK; MOT_R_BCK
#define MOT_ALL_PWM(x,yR,yL)      MOT_R_PWM(x,yR); MOT_L_PWM(x,yL)

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
