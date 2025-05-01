#include "motor.h"

Motor myMotor;  // Uses default pins (7,5,6,4,3,2)
// Format: myMotor(left_PWM, EN1, EN2, right_PWM, EN1, EN2)

void setup() {
    myMotor.begin();
}

void loop() {
    myMotor(80, 80);  // Forward
    delay(2000);
    myMotor(-50, 50); // Turn left
    delay(1000);
    myMotor(0, 0);    // Stop
    delay(500);
}
