
#include <ros.h>
#include <std_msgs/Int16.h>


const int enc_r = 5;
const int enc_l = 18;
int count_r=0;
int count_l=0;


ros::NodeHandle  nh;

std_msgs::Int16 enc_r_msg;
std_msgs::Int16 enc_l_msg;
ros::Publisher right_enc("enc_r_values", &enc_r_msg );
ros::Publisher left_enc("enc_l_values", &enc_l_msg );



void setup(){
    
    nh.initNode();
    nh.advertise(right_enc);
    nh.advertise(left_enc);
    pin_defination();

}

void loop(){
    right_enc.publish(&enc_r_msg);
    left_enc.publish(&enc_l_msg);
    nh.spinOnce();
    
}

void pin_defination(){
    pinMode(enc_r,INPUT);
    pinMode(enc_l,INPUT);
    attachInterrupt(digitalPinToInterrupt(enc_r),Update_encR,CHANGE);
    attachInterrupt(digitalPinToInterrupt(enc_l),Update_encL,CHANGE);
}

void Update_encR(){
    enc_r_msg.data=count_r ++;
    
}

void Update_encL(){
    enc_l_msg.data=count_l ++;

}
