#include "motor.h"
#include <Arduino.h>

Motor::Motor(
    int pwmL, int in1L, int in2L,
    int pwmR, int in1R, int in2R
) : 
    _pwmL(pwmL), _in1L(in1L), _in2L(in2L),
    _pwmR(pwmR), _in1R(in1R), _in2R(in2R) {}

void Motor::begin() {
    pinMode(_pwmL, OUTPUT);
    pinMode(_in1L, OUTPUT);
    pinMode(_in2L, OUTPUT);
    pinMode(_pwmR, OUTPUT);
    pinMode(_in1R, OUTPUT);
    pinMode(_in2R, OUTPUT);
    
    // Initialize motors to stop
    (*this)(0, 0);
}

void Motor::operator()(int leftSpeed, int rightSpeed) {
    leftSpeed = constrain(leftSpeed, -100, 100);
    rightSpeed = constrain(rightSpeed, -100, 100);

    // Left motor control
    if (leftSpeed > 0) {
        digitalWrite(_in1L, HIGH);
        digitalWrite(_in2L, LOW);
        analogWrite(_pwmL, map(leftSpeed, 0, 100, 0, 255));
    } 
    else if (leftSpeed < 0) {
        digitalWrite(_in1L, LOW);
        digitalWrite(_in2L, HIGH);
        analogWrite(_pwmL, map(-leftSpeed, 0, 100, 0, 255));
    } 
    else {
        digitalWrite(_in1L, LOW);
        digitalWrite(_in2L, LOW);
        analogWrite(_pwmL, 0);
    }

    // Right motor control
    if (rightSpeed > 0) {
        digitalWrite(_in1R, HIGH);
        digitalWrite(_in2R, LOW);
        analogWrite(_pwmR, map(rightSpeed, 0, 100, 0, 255));
    } 
    else if (rightSpeed < 0) {
        digitalWrite(_in1R, LOW);
        digitalWrite(_in2R, HIGH);
        analogWrite(_pwmR, map(-rightSpeed, 0, 100, 0, 255));
    } 
    else {
        digitalWrite(_in1R, LOW);
        digitalWrite(_in2R, LOW);
        analogWrite(_pwmR, 0);
    }
}