#include "ros_communication.h"
#include "motor_control.h"
#include "oled_display.h"

rcl_subscription_t cmd_vel_sub;
geometry_msgs__msg__Twist cmd_vel_msg;

rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

Adafruit_SSD1306 display;

RosCommunication::RosCommunication(){
}

void RosCommunication::initialize(){
    Serial.begin(115200);
    Serial.println("ROS Communication node started");
    setupDisplay(display);



    // Adding Wifi
    IPAddress agent_ip(192, 168, 100, 21);
    size_t agent_port = 8888;

     char ssid[] = "Jhelum.net [Luqman House]";
    char psk[]= "7861234786";

    set_microros_wifi_transports(ssid, psk, agent_ip, agent_port);
    // set_microros_serial_transports(Serial);

    delay(2000);

    allocator = rcl_get_default_allocator();
    rclc_support_init(&support, 0, NULL, &allocator);
    rclc_node_init_default(&node, "cmd_vel_sub", "", &support);
}


void RosCommunication::executors_start(){
  rclc_executor_init(&executor, &support.context, 1, &allocator);
  rclc_executor_add_subscription(&executor, &cmd_vel_sub, &cmd_vel_msg,&RosCommunication::cmd_vel_callback, ON_NEW_DATA);

  Serial.println("Executors Started");
}
void RosCommunication::subscriber_define(){

    rclc_subscription_init_default(
    &cmd_vel_sub,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "/cmd_vel");

}

void RosCommunication::cmd_vel_callback(const void *msg_recv){
    const geometry_msgs__msg__Twist * recieved_data = (const geometry_msgs__msg__Twist *) msg_recv ;
    float linear_vel = recieved_data->linear.x;
    float angular_vel = recieved_data->angular.z;

    Serial.print(linear_vel);Serial.print(" / ");Serial.println(angular_vel);

    if(linear_vel > 0) {
        Serial.println("Forward");
        forward(linear_vel * 255);
        drawForwardArrow(display);
    } else if(linear_vel < 0) {
        Serial.println("Reverse");
        reverse(-linear_vel * 255);
        drawBackwardArrow(display);
    } else if(angular_vel < 0) {
        Serial.println("right");
        right(-angular_vel *255);
        drawRightArrow(display);
    } else if(angular_vel > 0) {
        Serial.println("left");
        drawLeftArrow(display);
        left(angular_vel *255);
    } else {
        Serial.println("Stop");
        stop();
        drawStopCircle(display);
    }




}
void RosCommunication::start_receiving_msgs(){
      rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
        delay(100);
}