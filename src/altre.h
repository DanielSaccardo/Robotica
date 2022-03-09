#pragma once

#ifndef __ALTRE_H__
    #define __ALTRE_H__



    /***************
        INCLUDES
    ***************/

    #include "headers.h"
    #include <SPI.h>
    #include <Wire.h>
    #include "Adafruit_GFX.h"
    #include "Adafruit_NeoPixel.h"

    

    /*********************
        FUNZIONI PER IL
        SENSORE AD
        ULTRASUONI
    **********************/

    /// Inizializzazione pin ultrasonar
    void setupUltra(void);

    /*!
        Prende le informazioni dal sensore
        e calcola la distanza

        @return Distanza in centimetri
    */
    int DistanceUltra(void);



    /*********************
        FUNZIONI PER IL
        SENSORE AD
        INFRAROSSI
    **********************/

    /// Inizializzazione pin sensori ad infrarossi
    void setupTrackers(void);

    /*!
        Legge tutti i sensori e 
        calcola il valore letto

        @param trackersArry Array nel quale registrare i valori per ogni sensore
    */
    void readAllTrackers(uint16_t *trackersArry);


    /*!
        Legge il sensore selezionato e
        calcola il valore letto

        @param n_tracker Numero del sensore

        @return Valore letto
    
    */
    uint16_t readOneTracker(uint8_t n_tracker);

    
    /*********************
        FUNZIONI PER LA 
        GESTIONE DEI LED
    **********************/

    /*!
        Selezionati i colori per ognuno dei
        4 LED li accende

        @param led Array bidimensionale di N elementi primari composti da 3 elementi secondari del tipo {R, G, B} dove R, G, B hanno valore da 0->255
        @param brightness varia la luminosità con un valore da 0->255
    */
    void setLEDS(int led[][3], byte brightness);

#endif