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


/*
 *
 * INCLUDES
 *
 */

#include <Arduino.h>
#include "defines.h"
#include "comandi.h"
#include "altre.h"
#include "timerAVR.h"
#include "Adafruit_SSD1306.h"

TimerAVR timer1;
uint16_t trackArry[N_TRACKERS];
Adafruit_SSD1306 display(OLED_RESET, OLED_SA0);

#define NERO 450

void setup() 
{
    setupMotors();
    setupUltra();
    setupTrackers();

    Serial.begin (9600);
    Serial.println ("Sensore Ultrasuoni: ");

    Wire.begin();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(15,20);
    display.println("RoboMac Junior 2020");
    display.display();
    delay(5000);
    display.clearDisplay();
}

void loop() 
{
    readAllTrackers(trackArry);

    /*for (uint8_t i = 0; i < N_TRACKERS; i++)
    {
        Serial.print("Tracker "); Serial.print(i + 1); Serial.print(": "); Serial.println(trackArry[i]);
    }*/

    if (trackArry[2] < NERO)
    {
        int distanceCM = DistanceUltra();
        Serial.print(distanceCM);
        Serial.println ("cm");

        if (distanceCM < 0)
        {
            motorBreak_ALL(70);
            motorFWD(LEFT, 70);
            delay(360); // Tempo per girare di 90°
        }
        else
            motorFWD_ALL(30);

    }

    if (trackArry[0] < NERO && trackArry[1] < NERO) // ANGOLO
    {
        motorFWD(LEFT, 10);
        motorFWD(RIGHT, 50);
    }

    if (trackArry[4] < NERO && trackArry[3] < NERO) // ANGOLO
    {
        motorFWD(RIGHT, 10);
        motorFWD(LEFT, 50);
    }

    if (trackArry[0] < NERO) // Gira Sinistra di più
    {
        motorFWD(LEFT, 10);
        motorFWD(RIGHT, 30);
    }

    if (trackArry[1] < NERO) // Gira sinistra
    {
        motorFWD(LEFT, 20);
        motorFWD(RIGHT, 30);
    } 

    if (trackArry[3] < NERO) // Gira destra
    {
        motorFWD(RIGHT, 20);
        motorFWD(LEFT, 30);
    }

    if (trackArry[4] < NERO) // Gira destra di più
    {
        motorFWD(RIGHT, 10);
        motorFWD(LEFT, 30);
    }
}
