#pragma once

#include <Arduino.h>

class TimerAVR
{
    private:
        int state;
        long long t1;
        long long t2;
        long long time_span;

    public:
        long long ET;
        bool Q;

        TimerAVR();

        void reset();

        void TON(bool IN, long long PT); // PT in milliseconds
};