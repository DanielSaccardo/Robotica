#include "timerAVR.h"

#ifndef _TIMERAVR_H
#define _TIMERAVR_H

TimerAVR::TimerAVR()
{
    reset();
}

void TimerAVR::reset()
{
    Q = false;
	ET = 0;
	state = 0;
}

void TimerAVR::TON(bool IN, long long PT)
{
    if (!IN) // se non è attivo tengo resettato
        reset(); 
    
    else
    {
        switch (state)
        {
            case 0:
                state = 1;
                ET = PT;
                t1 = millis(); // Mi registro i millisecondi da quando il timer e' stato attivato
                break;
            
            case 1:
                t2 = millis();
                time_span = t2 - t1;

                ET = PT - time_span; // Mi ricavo il tempo rimasto tra quello impostato e quello passato

                if (ET <= 0)
                    state = 2;
                break;
            
            case 2:
                Q = true;
                break;
        }
    }
}

#endif