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


#define ECHO 2
#define TRIG 3
int Distance = 0;
int DistanceUltra (void);
int time = 0;
void setup() 
{
    setupMotors();

    pinMode (ECHO, INPUT);	// Define the ultrasonic echo input pin
    pinMode (TRIG, OUTPUT);	// Define the ultrasonic trigger input pin 
    Serial.begin (9600);
    Serial.print ("Sensore Ultrasuoni: ");
}

void loop() 
{
    // Algoritmo per fermata in caso di ostacolo
    int distanceCM = DistanceUltra ();
    Serial.print(distanceCM);
    Serial.println ("cm");


    if (distanceCM < 17){
        motorStop_ALL();
        motorBCK_ALL(70);
        delay(1);
        motorStop_ALL();
        motorFWD(LEFT, 70);
        delay(360);
    } 

    else 
    {
        motorFWD_ALL(70, 2, 0);
        delay(10);
        time ++;
    }

    if (time  >= 150)
    {
        motorStop_ALL();
        motorFWD(LEFT, 70);
        delay(360);
        time = 0;
    }
    
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