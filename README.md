Arduino PWM Reader!
===================
This library uses interrupts to read PWM values. It is only intended to be used with Arduino Uno or Mega boards. It is capable of reading high pulse (normal pwm) or low pulse (inverted pwm).
 
Usage:
-------------

1. Copy PWM.cpp and PWM.hpp in your project folder.
2. Include PWM.hpp in your program. example #include "PWM.hpp"
3. Create a PWM instance variable and call it what you want. example: PWM my_pwm;
4. Initialise PWM instance you made and provide pin and trigger condition. example my_pwm.begin(2, 1);
5. Call getValue to get PWM value. example 'some_variable' = my_pwm.getValue();

Solo Example:
-------------

```
#include "PWM.hpp"

PWM my_pwm;

void setup() {
  Serial.begin(115200); // Serial for debug
  my_pwm.begin(2, 1); // PWM on pin 2 reading PWM HIGH duration
}

void loop() {
  Serial.println(my_pwm.getValue());
  delay(100);
}
```

Multi Example:
-------------

```
#include "PWM.hpp"

PWM ch1;
PWM ch2;
PWM ch3;
PWM ch4;
PWM ch5;
PWM ch6;

void setup() {
  Serial.begin(115200); // Serial for debug
  ch1.begin(2, 1); // ch1 on pin 2 reading PWM HIGH duration
  ch2.begin(3, 1); // ch2 on pin 2 reading PWM HIGH duration
  ch3.begin(18, 1); // ch3 on pin 18 reading PWM HIGH duration
  ch4.begin(19, 1); // ch4 on pin 19 reading PWM HIGH duration
  ch5.begin(20, 1); // ch5 on pin 20 reading PWM HIGH duration
  ch6.begin(21, 1); // ch6 on pin 21 reading PWM HIGH duration
}

void loop() {
  /*
   Printing values to Serial for demo.
  */
  Serial.print(ch1.getValue());
  Serial.print("\t");
  Serial.print(ch2.getValue());
  Serial.print("\t");
  Serial.print(ch3.getValue());
  Serial.print("\t");
  Serial.print(ch4.getValue());
  Serial.print("\t");
  Serial.print(ch5.getValue());
  Serial.print("\t");
  Serial.print(ch6.getValue());
  Serial.print("\t");
  Serial.println();
  delay(100);
}
```
paypal.me/xkam1x