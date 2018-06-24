#include <Arduino.h>

class PWM {
    byte my_isr;
    
public:
    PWM(byte pin);
    
    /**
     Enables interrupt.

     @param measure_pulse_high true: High Pulse duration is measured (normal pwm), false: Low Pulse duration is measured (inverted pwm).
     
     @return 0 Success.
     @return -1 Error.
     */
    int begin(bool measure_pulse_high);
    
    /**
     Returns the most recent PWM value received.

     @return PWM duration in microseconds.
     @return -1 Error.
     */
    int getValue();
    
    /**
     Disables interrupt.
     */
    void end();
};
