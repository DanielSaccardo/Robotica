#pragma once


#ifndef _HEADERS_H_
    #define _HEADERS_H_



   #include <Arduino.h>



    /***************
        DEFINES:
        PINS
    ***************/

    // Motori
    #define AIN1                A0     // Motore L avanti
    #define AIN2                A1     // Motore L indietro
    #define PWM_L               6      // Pin di comando potenza motore L

    #define BIN2                A2     // Motore R avanti
    #define BIN1                A3     // Motore R indietro
    #define PWM_R               5      // Pin di comando potenza motore R

    // Ultrasonar
    #define ECHO                2
    #define TRIG                3

    // Trackers
    #define TS_CLOCK            13      // Pin di clock
    #define TS_ADDR             12      // Pin di indirizzo
    #define TS_DATAOUT          11      // Pin di dati
    #define TS_CS               10      // Pin del Chip Select
    #define N_TRACKERS          5       // Numero di line trackers
    
    // LEDS
    #define N_LED               4
    #define LED_PIN             7



    /***************
        DEFINES:
        ALTRO
    ***************/

    #define MOT_LEFT        0
    #define MOT_RIGHT       1
    #define NERO            450     // Valore al di sotto del quale si considera il nero

#endif