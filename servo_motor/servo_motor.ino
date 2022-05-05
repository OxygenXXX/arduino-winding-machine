#include <Servo.h>

#define SERVO_PIN_S1 1 // SELECT 
#define SERVO_PIN_S2 2 // SELECT

Servo SERVO_CONTROL_S1;
Servo SERVO_CONTROL_S2;

void ServoMotorInit()
{
    SERVO_CONTROL_S1.attach(SERVO_PIN_S1);
    SERVO_CONTROL_S1.attach(SERVO_PIN_S2);
}