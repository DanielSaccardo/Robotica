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


void setup() 
{
    pinMode(PWM_L, OUTPUT);
    pinMode(PWM_R, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
}

void loop() 
{
    
    MOT_ALL_FWD;
    MOT_ALL_PWM(70,2,0);
    delay(3500);
    MOT_ALL_PWM(0,0,0);
    
    MOT_L_FWD;
    MOT_L_PWM(40,0);
    delay(675);
    
}
