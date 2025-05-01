#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
public:
    Motor(
        int pwmL = 7, int in1L = 5, int in2L = 6,
        int pwmR = 4, int in1R = 3, int in2R = 2
    );
    
    void begin();  // Initialize motor pins
    
    // Operator overloading for direct motor control
    void operator()(int leftSpeed, int rightSpeed);

private:
    int _pwmL, _in1L, _in2L;  // Left motor pins
    int _pwmR, _in1R, _in2R;  // Right motor pins
};

#endif