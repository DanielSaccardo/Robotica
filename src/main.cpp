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

/***************************************
 * NOTA:
 * 
 * I pin dell'Oled sono quelli dell'I2C
 * 
 * SDA -> pin 17
 * 
 * SCL -> pin 18
 * 
 * DA SISTEMARE IL PROGRAMMA SAPENDO CIO'
 * 
 ***************************************/

void setup() 
{
    setupMotors();
    setupUltra();
    setupTrackers();

    Serial.begin (9600);

    Wire.begin();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(15,20);
    display.println("Robotica");
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
        Serial.print ("Sensore Ultrasuoni: "); Serial.print(distanceCM); Serial.println ("cm");

        if (distanceCM < 17)
        {
            motorBreak_ALL(70);
            motorFWD(MOT_LEFT, 70);
        }
        else
            motorFWD_ALL(30);

    }

    if (trackArry[0] < NERO && trackArry[1] < NERO) // ANGOLO
    {
        motorFWD(MOT_LEFT, 10);
        motorFWD(MOT_RIGHT, 50);
    }

    if (trackArry[4] < NERO && trackArry[3] < NERO) // ANGOLO
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
}
