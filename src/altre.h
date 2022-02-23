#include <Arduino.h>
#include "defines.h"

void setupUltra(void);

int DistanceUltra (void);

void setupTrackers(void);

void readAllTrackers(uint16_t trackersArry[]);

uint16_t readOneTracker(uint8_t n_tracker);
