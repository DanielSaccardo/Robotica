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

#define MOT_R_FWD                                 digitalWrite(BIN1, HIGH); digitalWrite(BIN2, LOW)
#define MOT_R_BCK                                 digitalWrite(BIN1, LOW); digitalWrite(BIN2, HIGH)
#define MOT_R_PWM(pwm, offset)                    analogWrite(PWM_R, pwm + offset)

#define MOT_L_FWD                                 digitalWrite(AIN1, HIGH); digitalWrite(AIN2, LOW)
#define MOT_L_BCK                                 digitalWrite(AIN1, LOW); digitalWrite(AIN2, HIGH)
#define MOT_L_PWM(pwm, offset)                    analogWrite(PWM_L, pwm + offset)

#define MOT_ALL_FWD                               MOT_L_FWD; MOT_R_FWD
#define MOT_ALL_BCK                               MOT_L_BCK; MOT_R_BCK
#define MOT_ALL_PWM(pwm, offset_R, offset_L)      MOT_R_PWM(pwm, offset_R); MOT_L_PWM(pwm, offset_L)


/*
 * DEFINES:
 *
 * ALTRO
*/

#define LEFT 0
#define RIGHT 1