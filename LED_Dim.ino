// This is an example of using the Pulse Width Modulation (PWM) pins to
// control the dimming of an LED

// by ben (https://github.com/GeneralBen)

// If console printing is wanted, uncomment this header file 
/*#include <Streaming.h>*/ // if you dont have this library, get it.  It makes printing much nicer (c++ ish)

// the arduino board has a few PWM pins.  If 3 is taken, 5, 6, 9, 10 and 11 are also PWM.
#define PWM_LED_PIN 3

void setup()
{
  // serial could begin here.. (uncomment if wanted)
  /*Serial.begin(9600);*/
  
  // initialize the PWM pin to be an output pin
  pinMode(PWM_LED_PIN, OUTPUT);
}

void loop()
{
  // loop up from 0 - 255 by 5.  (This can be adjusted)
  for(int i = 0; i < 255; i += 5)
  {
    analogWrite(PWM_LED_PIN, i);
    
    // If you want to see the output of the pin on the serial, uncomment this block
    /*printPWM(i);*/
    
    // adjust the delay as you see fit
    delay(200);
  }
  
  // loop back down from 255 - 0 by 5.  (Again, this can be adjusted)
    for(int j = 255; j > 0; j -= 5)
  {
    analogWrite(PWM_LED_PIN, j);
    
    // If you want to see the output of the pin on the serial, uncomment this block
    /*printPWM(j);*/
    
    // adjust the delay as you see fit
    delay(200);
  }
}

// this is just a simple print block so you don't have to write it twice
// i commented this out also so if you want to run this you'll need to uncomment this function
/*
void printPWM(int value)
{
  Serial << " PWM = " << value << endl;
}
*/
