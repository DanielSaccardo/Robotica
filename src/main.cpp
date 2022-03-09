/*
                                
           _       _           ____        _   ___               _____     
     /\   | |     | |         |  _ \      | | |__ \        /\   |  __ \    
    /  \  | |_ __ | |__   __ _| |_) | ___ | |_   ) |_____ /  \  | |__) |   
   / /\ \ | | '_ \| '_ \ / _` |  _ < / _ \| __| / /______/ /\ \ |  _  /    
  / ____ \| | |_) | | | | (_| | |_) | (_) | |_ / /_     / ____ \| | \ \    
 /_/    \_\_| .__/|_| |_|\__,_|____/ \___/ \__|____|   /_/    \_\_|  \_\   
  _         | |                                                            
 | |        |_|                                                            
 | |__  _   _                                                              
 | '_ \| | | |                                                             
 | |_) | |_| |                                                             
 |_.__/ \__, |                                                             
  _____  __/ |       _      _    _____                             _       
 |  __ \|___/       (_)    | |  / ____|                           | |      
 | |  | | __ _ _ __  _  ___| | | (___   __ _  ___ ___ __ _ _ __ __| | ___  
 | |  | |/ _` | '_ \| |/ _ \ |  \___ \ / _` |/ __/ __/ _` | '__/ _` |/ _ \ 
 | |__| | (_| | | | | |  __/ |  ____) | (_| | (_| (_| (_| | | | (_| | (_) |
 |_____/ \__,_|_| |_|_|\___|_| |_____/ \__,_|\___\___\__,_|_|  \__,_|\___/ 
  ______            _              _____      _     _                      
 |  ____|          (_)            / ____|    | |   | |                     
 | |__   _ __  _ __ _  ___ ___   | |     __ _| | __| | __ _ _ __ ___       
 |  __| | '_ \| '__| |/ __/ _ \  | |    / _` | |/ _` |/ _` | '__/ _ \      
 | |____| | | | |  | | (_| (_) | | |___| (_| | | (_| | (_| | | | (_) |     
 |______|_| |_|_|  |_|\___\___/   \_____\__,_|_|\__,_|\__,_|_|  \___/      
  _____   /\                                                               
 | ____| |/\|   /\          /\                                             
 | |__         /  \ ______ /  \                                            
 |___ \       / /\ \______/ /\ \                                           
  ___) |     / ____ \    / ____ \                                          
 |____/     /_/    \_\  /_/    \_\                                   


*/


/***************
    INCLUDES
***************/

#include "headers.h"
#include "motore.h"
#include "altre.h"
#include "timerAVR.h"



/***************
    OGGETTI /
    VARIABILI
***************/
TimerAVR timer1;
uint16_t trackArry[N_TRACKERS];



/**************
    SETUP
**************/

void setup() 
{
    setupMotors();
    setupUltra();
    setupTrackers();

    Serial.begin(9600);

    int led_col[N_LED][3] = {
        {255, 255, 255},    // Primo led
        {255, 255, 255},    // Secondo led
        {255, 255, 255},    // Terzo led
        {255, 255, 255}     // Quarto led
    };

    setLEDS(led_col, 128);
}



/*************
    LOOP
*************/

void loop() 
{
    readAllTrackers(trackArry);

    // Se la seriale attiva stampa i log altrimenti no ==> Rallenta il funzionamento
    if (Serial)
    {
        for (uint8_t i = 0; i < N_TRACKERS; i++)
        {
            Serial.print("Tracker "); Serial.print(i + 1); Serial.print(": "); Serial.println(trackArry[i]);
        }
    }
    

    if (trackArry[2] < NERO && trackArry[4] > NERO && trackArry[3] > NERO && trackArry[4] > NERO && trackArry[1] > NERO && trackArry[0] > NERO)
    {
        int distanceCM = DistanceUltra();
        
        if (Serial)
        {
            Serial.print ("Sensore Ultrasuoni: "); Serial.print(distanceCM); Serial.println ("cm");
        }
            

        if (distanceCM < 17)
        {
            //motorBreak_ALL(70, 1);
            motorStop_ALL();
            motorFWD(MOT_LEFT, 70);
        }
        else
            motorFWD_ALL(20);

        
    }

    /*
    if (trackArry[0] > 700 &&  trackArry[0] > 930 && trackArry[1] > 700 &&  trackArry[1] > 930) // ANGOLO con colore
    {
        motorFWD(MOT_LEFT, 10);
        motorFWD(MOT_RIGHT, 50);
    }

    if (trackArry[3] > 700 &&  trackArry[3] > 930 && trackArry[4] > 700 &&  trackArry[4] > 930) // ANGOLO con colore
    {
        motorFWD(MOT_RIGHT, 10);
        motorFWD(MOT_LEFT, 50);
    }
    */


    if (trackArry[0] < NERO && trackArry[1] < NERO) // ANGOLO no colore
    {
        motorFWD(MOT_LEFT, 10);
        motorFWD(MOT_RIGHT, 50);
    }

    if (trackArry[4] < NERO && trackArry[3] < NERO) // ANGOLO no colore
    {
        motorFWD(MOT_RIGHT, 10);
        motorFWD(MOT_LEFT, 50);
    }
    
    if (trackArry[0] < NERO) // Gira Sinistra di più
    {
        motorFWD(MOT_LEFT, 10);
        motorFWD(MOT_RIGHT, 30);
    }

    if (trackArry[1] < NERO) // Gira sinistra
    {
        motorFWD(MOT_LEFT, 20);
        motorFWD(MOT_RIGHT, 30);
    } 

    if (trackArry[3] < NERO) // Gira destra
    {
        motorFWD(MOT_RIGHT, 20);
        motorFWD(MOT_LEFT, 30);
    }

    if (trackArry[4] < NERO) // Gira destra di più
    {
        motorFWD(MOT_RIGHT, 10);
        motorFWD(MOT_LEFT, 30);
    }

    
    if (trackArry[4] > NERO && trackArry[3] > NERO && trackArry[2] > NERO && trackArry[1] > NERO && trackArry[0] > NERO)
    {
        // TODO: Algoritmo di ricerca della linea nera
    }
    
}
