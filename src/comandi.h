/*

Varie funzioni per movimento bot


*/

#include <Arduino.h>
#include "defines.h"

void setupMotors(void); 

void motorFWD(bool side, byte power);                       // side => 1: R, 0: L
void motorFWD(bool side, byte power, byte offset);          // side => 1: R, 0: L

void motorFWD_ALL(byte power);
void motorFWD_ALL(byte power, byte offsetR, byte offsetL);

void motorBCK(bool side, byte power);                       // side => 1: R, 0: L
void motorBCK(bool side, byte power, byte offset);          // side => 1: R, 0: L

void motorBCK_ALL(byte power);
void motorBCK_ALL(byte power, byte offsetR, byte offsetL);

void motorStop(bool side);                                  // side => 1: R, 0: L
void motorStop_ALL(void);