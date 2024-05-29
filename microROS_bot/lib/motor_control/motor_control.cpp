#include "motor_control.h"
int l_pwm , r_pwm,integral_error,base_pwm=120;
float kp=10,ki=0.5,total_error,proportional_error;

void motor_setup(){
  ledcSetup(pwm_channel_mr_a , 5000, 8 ); //2^8 = 256 , 0-255
  ledcSetup(pwm_channel_mr_b , 5000, 8 ); //2^8 = 256 , 0-255
  ledcSetup(pwm_channel_ml_a , 5000, 8 ); //2^8 = 256 , 0-255
  ledcSetup(pwm_channel_ml_b , 5000, 8 ); //2^8 = 256 , 0-255


  ledcAttachPin(motor_right_a,pwm_channel_mr_a);
  ledcAttachPin(motor_right_b,pwm_channel_mr_b);
  ledcAttachPin(motor_left_a,pwm_channel_ml_a);
  ledcAttachPin(motor_left_b,pwm_channel_ml_b);
}

void forward(int speed) {
  ledcWrite(pwm_channel_mr_a, speed);
  ledcWrite(pwm_channel_ml_a, speed);
  ledcWrite(pwm_channel_mr_b, 0);
  ledcWrite(pwm_channel_ml_b, 0);
}

void reverse(int speed) {
  ledcWrite(pwm_channel_mr_b, speed);
  ledcWrite(pwm_channel_ml_b, speed);
  ledcWrite(pwm_channel_mr_a, 0);
  ledcWrite(pwm_channel_ml_a, 0);
}

void stop() {
  ledcWrite(pwm_channel_mr_a, 0);
  ledcWrite(pwm_channel_ml_a, 0);
  ledcWrite(pwm_channel_mr_b, 0);
  ledcWrite(pwm_channel_ml_b, 0);
}

void right(int speed) {
  ledcWrite(pwm_channel_mr_a, 0);
  ledcWrite(pwm_channel_ml_a, speed);
  ledcWrite(pwm_channel_mr_b, 0);
  ledcWrite(pwm_channel_ml_b, 0);
}

void left(int speed) {
  ledcWrite(pwm_channel_mr_a, speed);
  ledcWrite(pwm_channel_ml_a, 0);
  ledcWrite(pwm_channel_mr_b, 0);
  ledcWrite(pwm_channel_ml_b, 0);
}

std::pair<int,int> error_motor_drive(int error){
  // Dynamic Speed Adjustment
  int dynamic_base_pwm = base_pwm;
  if(abs(error) == 0) {  // For faster straight Line Movement
    dynamic_base_pwm = base_pwm + 120;
  }

  integral_error = constrain(integral_error + error, -100, 100);
  integral_error = ki * integral_error;
  proportional_error = kp * error;
  total_error = proportional_error + integral_error;

  l_pwm =  dynamic_base_pwm - total_error;
  r_pwm = dynamic_base_pwm + total_error;

  l_pwm = constrain(l_pwm+5, 70, 255);
  r_pwm = constrain(r_pwm, 70, 255);

  ledcWrite(pwm_channel_mr_a, r_pwm);
  ledcWrite(pwm_channel_ml_a, l_pwm);
  ledcWrite(pwm_channel_mr_b, 0);
  ledcWrite(pwm_channel_ml_b, 0);

  return std::make_pair(l_pwm, r_pwm);
}
