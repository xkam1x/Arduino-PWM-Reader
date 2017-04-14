/*This library uses interrupts to read PWM values. It is only intended to be used with Arduino Uno or Mega boards.
 * It is capable of reading high pulse (normal pwm) or low pulse (inverted pwm).
 * 
 * Usage:
 * 1. Copy PWM.cpp and PWM.hpp in your project folder.
 * 1. Include PWM.hpp in your program. example #include "PWM.hpp"
 * 2. Create a PWM instance variable and call it what you want. example: PWM my_pwm;
 * 3. Initialise PWM instance you made and provide pin and trigger condition. example my_pwm.begin(2, 1);
 * 4. Call getValue to get PWM value. example *some_variable* = my_pwm.getValue();
 */

#include <Arduino.h>
// PWM class 
class PWM {
    byte my_pin;
public:
    void begin(byte pin, byte state);
    // pin = the digital pin to attach interrupt
    // On Arduino Uno, Nano, Mini, other 328-based, only pins 2 & 3 are usable for interrupts
    // On Arduino Mega, Mega2560, MegaADK, only pins 2, 3, 18, 19, 20 & 21 are usable for interrupts
    // State = 1 => the library will measure the duration of HIGH pulse (normal pwm)
    // State = 0 => the library will measure the duration of LOW pulse (inverted pwm)
    unsigned int getValue();
    // returns the pwm value
};
