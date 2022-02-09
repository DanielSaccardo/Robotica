#pragma once
/*

Varie funzioni per movimento bot


*/

#include <Arduino.h>
#include "defines.h"

void setupMotors(void);                                     // Impostazione iniziale

void motorFWD(bool side, byte power, byte offset = 0);          // side => 1: R, 0: L

void motorFWD_ALL(byte power, byte offsetR = 0, byte offsetL = 0);  // Motori avanti + offset

void motorBCK(bool side, byte power, byte offset = 0);          // side => 1: R, 0: L

void motorBCK_ALL(byte power, byte offsetR = 0, byte offsetL = 0);  // Motori indietro + offset

void motorStop(bool side);                                  // side => 1: R, 0: L
void motorStop_ALL(void);                                   // Ferma tutti i motori

void motorBreak(bool side, byte power);                     // side => 1: R, 0: L
void motorBreak_ALL(byte power);