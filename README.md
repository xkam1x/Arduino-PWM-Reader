Arduino PWM Reader!
=
This library uses interrupts to read PWM values. It is capable of reading high pulse (normal pwm) or low pulse (inverted pwm). With upto 20 different PWM signals on supporting boards. To find the pins capable of 'CHANGE' external interrupts on your board, look at:
https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/

Solo Example:
-

```
#include "PWM.hpp"

PWM my_pwm(2); // Setup pin 2 for PWM

void setup() {
    Serial.begin(115200); // Serial for debug
    my_pwm.begin(true); // PWM on pin 2 reading PWM HIGH duration
}

void loop() {
    Serial.print("Value: ");
    Serial.print(my_pwm.getValue());
    Serial.print("\tAGE: ");
    Serial.println(my_pwm.getAge());
    delay(100);
}
```

Multi Example:
-------------

```
#include "PWM.hpp"

PWM ch1(2); // Setup pin 2 for input
PWM ch2(3); // Setup pin 3 for input
PWM ch3(18); // Setup pin 18 for input
PWM ch4(19); // Setup pin 19 for input
PWM ch5(20); // Setup pin 20 for input
PWM ch6(21); // Setup pin 21 for input

void setup() {
    Serial.begin(115200); // Serial for debug
    ch1.begin(true); // ch1 on pin 2 reading PWM HIGH duration
    ch2.begin(true); // ch2 on pin 3 reading PWM HIGH duration
    ch3.begin(true); // ch3 on pin 18 reading PWM HIGH duration
    ch4.begin(true); // ch4 on pin 19 reading PWM HIGH duration
    ch5.begin(true); // ch5 on pin 20 reading PWM HIGH duration
    ch6.begin(true); // ch6 on pin 21 reading PWM HIGH duration
}

void loop() {
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
