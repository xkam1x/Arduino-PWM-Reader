#include "PWM.hpp"
// Global variables for ISR routines
unsigned int value[6];
byte last_state[6];
byte trigger_state[6];
unsigned long timers[6];
// ISR for pin 2
void ISR_2() {
    unsigned long now = micros();
    byte state_now = digitalRead(2);
    if (state_now != last_state[0]) {
        if (state_now == trigger_state[0]) {
            timers[0] = now;
        } else {
            value[0] = now - timers[0];
        }
        last_state[0] = state_now;
    }
}
// ISR for pin 3
void ISR_3() {
    unsigned long now = micros();
    byte state_now = digitalRead(3);
    if (state_now != last_state[1]) {
        if (state_now == trigger_state[1]) {
            timers[1] = now;
        } else {
            value[1] = now - timers[1];
        }
        last_state[1] = state_now;
    }
}
// ISR for pin 18
void ISR_18() {
    unsigned long now = micros();
    byte state_now = digitalRead(18);
    if (state_now != last_state[2]) {
        if (state_now == trigger_state[2]) {
            timers[2] = now;
        } else {
            value[2] = now - timers[2];
        }
        last_state[2] = state_now;
    }
}
// ISR for pin 19
void ISR_19() {
    unsigned long now = micros();
    byte state_now = digitalRead(19);
    if (state_now != last_state[3]) {
        if (state_now == trigger_state[3]) {
            timers[3] = now;
        } else {
            value[3] = now - timers[3];
        }
        last_state[3] = state_now;
    }
}
// ISR for pin 20
void ISR_20() {
    unsigned long now = micros();
    byte state_now = digitalRead(20);
    if (state_now != last_state[4]) {
        if (state_now == trigger_state[4]) {
            timers[4] = now;
        } else {
            value[4] = now - timers[4];
        }
        last_state[4] = state_now;
    }
}
// ISR for pin 21
void ISR_21() {
    unsigned long now = micros();
    byte state_now = digitalRead(21);
    if (state_now != last_state[5]) {
        if (state_now == trigger_state[5]) {
            timers[5] = now;
        } else {
            value[5] = now - timers[5];
        }
        last_state[5] = state_now;
    }
}
// Begin function to setup interrupt and attach ISR
void PWM::begin(byte pin, byte state) {
    my_pin = pin;
    switch (pin) {
        case 2:
            trigger_state[0] = state;
            last_state[0] = digitalRead(pin);
            attachInterrupt(digitalPinToInterrupt(pin), ISR_2, CHANGE);
            break;
        case 3:
            trigger_state[1] = state;
            last_state[1] = digitalRead(pin);
            attachInterrupt(digitalPinToInterrupt(pin), ISR_3, CHANGE);
            break;
        case 18:
            trigger_state[2] = state;
            last_state[2] = digitalRead(pin);
            attachInterrupt(digitalPinToInterrupt(pin), ISR_18, CHANGE);
            break;
        case 19:
            trigger_state[3] = state;
            last_state[3] = digitalRead(pin);
            attachInterrupt(digitalPinToInterrupt(pin), ISR_19, CHANGE);
            break;
        case 20:
            trigger_state[4] = state;
            last_state[4] = digitalRead(pin);
            attachInterrupt(digitalPinToInterrupt(pin), ISR_20, CHANGE);
            break;
        case 21:
            trigger_state[5] = state;
            last_state[5] = digitalRead(pin);
            attachInterrupt(digitalPinToInterrupt(pin), ISR_21, CHANGE);
            break;
        default:
            break;
    }
}
// Function to return channel value
unsigned int PWM::getValue() {
    switch (my_pin) {
        case 2:
            return value[0];
        case 3:
            return value[1];
        case 18:
            return value[2];
        case 19:
            return value[3];
        case 20:
            return value[4];
        case 21:
            return value[5];
        default:
            break;
    }
}

