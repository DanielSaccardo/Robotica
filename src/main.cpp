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
/*
    int led_col[N_LED][3] = {
        {255, 255, 255},    // Primo led
        {255, 255, 255},    // Secondo led
        {255, 255, 255},    // Terzo led
        {255, 255, 255}     // Quarto led
    };*/

    int led_col[N_LED][3] = {
        {0, 0, 0},    // Primo led
        {0, 0, 0},    // Secondo led
        {0, 0, 0},    // Terzo led
        {0, 0, 0}    // Quarto led
    };

    setLEDS(led_col, 255);
}



/*************
    LOOP
*************/

void loop() 
{
    readAllTrackers(trackArry);

    // Se la seriale attiva stampa i log altrimenti no ==> Rallenta il funzionamento
    /*if (Serial)
    {
        for (uint8_t i = 0; i < N_TRACKERS; i++)
        {
            Serial.print("Tracker "); Serial.print(i + 1); Serial.print(": "); Serial.println(trackArry[i]);
        }
    }*/
    
    if (DistanceUltra() < 10)
    {
        /* if (Serial)
        {
            Serial.print ("Sensore Ultrasuoni: "); Serial.print(DistanceUltra()); Serial.println ("cm");
        }
         */

        superaOstacolo(MOT_RIGHT, 250, 1750);
    }
    else
    {
        if (trackArry[2] < NERO && trackArry[4] > NERO && trackArry[3] > NERO && trackArry[4] > NERO && trackArry[1] > NERO && trackArry[0] > NERO)
        {
            motorFWD_ALL(20);
        }

        else if (trackArry[0] < NERO && trackArry[1] < NERO) // ANGOLO no colore
        {
            motorFWD(MOT_LEFT, 10);
            motorFWD(MOT_RIGHT, 50);
        }

        else if (trackArry[4] < NERO && trackArry[3] < NERO) // ANGOLO no colore
        {
            motorFWD(MOT_RIGHT, 10);
            motorFWD(MOT_LEFT, 50);
        }

        else if (trackArry[0] < NERO) // Gira Sinistra di più
        {
            motorFWD(MOT_LEFT, 10);
            motorFWD(MOT_RIGHT, 30);
        }

        else if (trackArry[1] < NERO) // Gira sinistra
        {
            motorFWD(MOT_LEFT, 20);
            motorFWD(MOT_RIGHT, 30);
        } 

        else if (trackArry[3] < NERO) // Gira destra
        {
            motorFWD(MOT_RIGHT, 20);
            motorFWD(MOT_LEFT, 30);
        }

        else if (trackArry[4] < NERO) // Gira destra di più
        {
            motorFWD(MOT_RIGHT, 10);
            motorFWD(MOT_LEFT, 30);
        }
    }
       
}