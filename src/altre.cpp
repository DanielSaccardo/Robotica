#include "altre.h"

    

  /*********************
      FUNZIONI PER IL
      SENSORE AD
      ULTRASUONI
  **********************/

  void setupUltra(void)
  {
      pinMode (ECHO, INPUT);
      pinMode (TRIG, OUTPUT);
  }

  int DistanceUltra (void)
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




  /*********************
      FUNZIONI PER IL
      SENSORE AD
      INFRAROSSI
  **********************/

  void setupTrackers(void)
  {
    pinMode(TS_CLOCK, OUTPUT);
    pinMode(TS_ADDR, OUTPUT);
    pinMode(TS_CS, OUTPUT);
    pinMode(TS_DATAOUT, INPUT);
  }

  void readAllTrackers(uint16_t trackersArry[])
  {
    unsigned int values[N_TRACKERS + 1];

    for (int8_t i = 0; i < N_TRACKERS + 1; i++) values[i] = 0;

    for(uint8_t j = 0; j < N_TRACKERS + 1; j++)
    {
      digitalWrite(TS_CS, LOW);
      
      for(uint8_t i=0;i<10;i++)
      {
        //0 to 4 clock transfer channel address
        if ((i < 4) && (j >> (3 - i) & 0x01))   digitalWrite(TS_ADDR, HIGH);
        
        else  digitalWrite(TS_ADDR, LOW);

        //0 to 10 clock receives the previous conversion result
        values[j] <<= 1;
        
        if(digitalRead(TS_DATAOUT))   values[j] |= 0x01;
        
        digitalWrite(TS_CLOCK, HIGH);
        digitalWrite(TS_CLOCK, LOW);
      }
      //sent 11 to 16 clock 
      for(uint8_t i = 0;i < 6;i++)
      {
        digitalWrite(TS_CLOCK, HIGH);
        digitalWrite(TS_CLOCK, LOW);
      }
      digitalWrite(TS_CS, HIGH);
    }

    for(uint8_t i = 0; i < (uint8_t)5; i++)
    {
      trackersArry[i] = values[i + 1];
    }
  }

  uint16_t readOneTracker(uint8_t n_tracker)
  {
    unsigned int values[N_TRACKERS + 1];

    for (int8_t i = 0; i < N_TRACKERS + 1; i++) values[i] = 0;

    for(uint8_t j = 0;j < 5 + 1;j++)
    {
      digitalWrite(TS_CS,LOW);
      for(uint8_t i=0;i<10;i++)
      {
        //0 to 4 clock transfer channel address
        if((i < 4) && (j >> (3 - i) & 0x01))
        digitalWrite(TS_ADDR, HIGH);
        else
        digitalWrite(TS_ADDR, LOW);

        //0 to 10 clock receives the previous conversion result
        values[j] <<= 1;
        if(digitalRead(TS_DATAOUT)) 
        values[j] |= 0x01;
        digitalWrite(TS_CLOCK, HIGH);
        digitalWrite(TS_CLOCK, LOW);
      }

      //sent 11 to 16 clock 
      for(uint8_t i = 0;i < 6;i++)
      {
        digitalWrite(TS_CLOCK, HIGH);
        digitalWrite(TS_CLOCK, LOW);
      }
      digitalWrite(TS_CS, HIGH);
    }

    return values[n_tracker+1];
  }



  /*********************
      FUNZIONI PER LA 
      GESTIONE DEI LED
  **********************/

  /// Oggetto per la gestione dei LED
  Adafruit_NeoPixel RGB(4, 7, NEO_GRB + NEO_KHZ800);

  void setLEDS(int led[][3], byte brightness)
  {
      RGB.begin();

      RGB.setBrightness(brightness);
      for (int i = 0; i < N_LED; i++)
      {
        RGB.setPixelColor(i, RGB.Color(led[i][0], led[i][1], led[i][2]));
      }

      RGB.show();     // turn on LEDs
  }
  