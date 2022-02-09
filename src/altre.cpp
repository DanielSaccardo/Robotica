#include "altre.h"

#ifndef ALTRE_H
#define ALTRE_H

void setupUltra(void)
{
    pinMode (ECHO, INPUT);
    pinMode (TRIG, OUTPUT);
}

int DistanceUltra (void)		// Measure the distance
{
  digitalWrite (TRIG, LOW);	// set trig pin low 2N<s
  delayMicroseconds (2);
  
  digitalWrite (TRIG, HIGH);	// set trig pin 10N<s 10us
  delayMicroseconds (10);
  digitalWrite (TRIG, LOW);	// set trig pin low
  
  float Fdistance = pulseIn (ECHO, HIGH);	// Read echo pin high level time (us)
  Fdistance = Fdistance / 58.31;	
  return (int) Fdistance;
}

#endif