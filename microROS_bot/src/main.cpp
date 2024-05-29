#include <Arduino.h>
#include "ros_communication.h"
#include "motor_control.h"
RosCommunication ros_communication ;


void setup() {
    motor_setup();
    ros_communication.initialize();
    ros_communication.subscriber_define();
    ros_communication.executors_start();
}

void loop() {
    ros_communication.start_receiving_msgs();

}