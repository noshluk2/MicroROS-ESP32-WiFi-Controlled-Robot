#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

// Pin Definitions
#define motor_right_b 12
#define motor_right_a 13
#define motor_left_a 14
#define motor_left_b 27

// Channels
#define pwm_channel_mr_a 0
#define pwm_channel_mr_b 1
#define pwm_channel_ml_a 2
#define pwm_channel_ml_b 3

// Functions
void forward(int speed);
void stop();
void left(int speed);
void right(int speed);
void reverse(int speed);
void motor_setup();
std::pair<int,int> error_motor_drive(int error);

#endif
