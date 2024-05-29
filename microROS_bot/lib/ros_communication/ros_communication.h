#ifndef ROS_COMMUNICATION_H
#define ROS_COMMUNICATION_H


#include <micro_ros_platformio.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <geometry_msgs/msg/twist.h>

class RosCommunication{
    public:
        RosCommunication();
        void initialize();
        void subscriber_define();
        static void cmd_vel_callback(const void *msg_recv);
        void start_receiving_msgs();
        void executors_start();


    private:

    static float linear_vel;
    static float angular_vel;

};


#endif