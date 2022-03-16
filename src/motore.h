#pragma once

/************************
    VARIE FUNZIONI CHE
    GESTISCONO I MOTORI
************************/

#ifndef __HEADERS_H__
    #define __HEADERS_H__

    #include "headers.h"



    /***************
        DEFINES:
        MACROS
    ***************/

    #define MOT_R_FWD                                   digitalWrite(BIN1, HIGH); digitalWrite(BIN2, LOW)
    #define MOT_R_BCK                                   digitalWrite(BIN1, LOW); digitalWrite(BIN2, HIGH)
    #define MOT_R_PWM(pwm, offset)                      analogWrite(PWM_R, pwm + offset)
    #define MOT_R_STOP                                  digitalWrite(BIN1, LOW); digitalWrite(BIN2, LOW)


    #define MOT_L_FWD                                   digitalWrite(AIN1, HIGH); digitalWrite(AIN2, LOW)
    #define MOT_L_BCK                                   digitalWrite(AIN1, LOW); digitalWrite(AIN2, HIGH)
    #define MOT_L_PWM(pwm, offset)                      analogWrite(PWM_L, pwm + offset)
    #define MOT_L_STOP                                  digitalWrite(AIN1, LOW); digitalWrite(AIN2, LOW)



    /***************
        FUNZIONI
    ***************/

    /// Inizializzazione pin
    void setupMotors(void);

    /*!
        Il motore selezionato girerà in avanti

        @param side 1 Destra; 0 Sinistra
        
        @param power 0->255 potenza ai motori

    */
    void motorFWD(bool side, byte power);

    /*!
        Tutti i motori girano in avanti
        
        @param power 0->255 potenza ai motori
        
        @param offsetR sfasamento di potenza motore destra

        @param offsetL sfasamento di potenza motore sinistra

    */
    void motorFWD_ALL(byte power, byte offsetR = 0, byte offsetL = 0);


    /*!
        Il motore selezionato girerà indietro

        @param side 1 Destra; 0 Sinistra
        
        @param power 0->255 potenza ai motori

    */
    void motorBCK(bool side, byte power);


    /*!
        Tutti i motori girano indietro
        
        @param power 0->255 potenza ai motori
        
        @param offsetR sfasamento di potenza motore destra

        @param offsetL sfasamento di potenza motore sinistra

    */
    void motorBCK_ALL(byte power, byte offsetR = 0, byte offsetL = 0);

    /*!
        Ferma il motore selezionato

        @param side 1 Destra; 0 Sinistra
    */
    void motorStop(bool side);


    /*!
       @brief Ferma tutti i motori
    */
    void motorStop_ALL(void);

    /*!
        Simula una frenata per un motore applicando
        per 1 ms la potenza nella direzione opposta

        @param side 1 Destra; 0 Sinistra

        @param power 0->255 potenza di frenata

        @param direction 0 Stavo andando avanti; 1 Stavo retrocedendo
    */
    void motorBreak(bool side, byte power, bool direction);

    /*!
        Simula una frenata per tutti i motori applicando
        per 1 ms la potenza nella direzione opposta

        @param power 0->255 potenza di frenata

        @param direction 0 Stavo andando avanti; 1 Stavo retrocedendo
    */
    void motorBreak_ALL(byte power, bool direction);

#endif