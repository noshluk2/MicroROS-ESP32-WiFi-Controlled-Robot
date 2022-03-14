
/*

*/

#define ROSSERIAL_ARDUINO_TCP
#include "WiFi.h"
#include <ros.h>
#include <std_msgs/Int16.h>
#include <rosserial_arduino/Test.h>
using rosserial_arduino::Test;


const uint8_t R_PWM =  12;
const uint8_t R_BACK = 14;
const uint8_t R_FORW = 27;

const uint8_t L_PWM =  33;
const uint8_t L_BACK = 25;
const uint8_t L_FORW = 26;
const int enc_r = 5;
const int enc_l = 18;
int count_r=0;
int count_l=0;
const uint8_t channel_L =0;
const uint8_t channel_R= 1;
int time_in_seconds;

IPAddress server(192, 168, 100, 7);
uint16_t serverPort = 11411;
const char*  ssid = "Luqman IT";
const char*  password = "222333444";

void srv_profile(const Test::Request & req, Test::Response & res);
void srv_clear_data(const Test::Request & req, Test::Response & res);

ros::NodeHandle  nh;
std_msgs::Int16 enc_r_msg;
std_msgs::Int16 enc_l_msg;
ros::Publisher right_enc("enc_r_values", &enc_r_msg );
ros::Publisher left_enc("enc_l_values", &enc_l_msg );
ros::ServiceServer<Test::Request, Test::Response> car_motion_time_srv("profile",&srv_profile);
ros::ServiceServer<Test::Request, Test::Response> clear_enc_data("clear_enc_data",&srv_clear_data);

void setup(){


    Serial.begin(115200);
    setupWiFi();
    nh.getHardware()->setConnection(server, serverPort);
    nh.initNode();
    nh.advertiseService(car_motion_time_srv);
    nh.advertiseService(clear_enc_data);
    nh.advertise(right_enc);
    nh.advertise(left_enc);


    pin_def();
    stop();
    Serial.println("Get Ready");
    delay(2000);

}

void pin_def(){

  const int freq = 5000;
  const int res = 8;
  
  pinMode(L_PWM,  OUTPUT);
  pinMode(L_FORW, OUTPUT);
  pinMode(L_BACK, OUTPUT);
  pinMode(R_PWM,  OUTPUT);
  pinMode(R_FORW, OUTPUT);
  pinMode(R_BACK, OUTPUT);
  
  ledcSetup(channel_R ,freq , res);
  ledcSetup(channel_L ,freq , res);

  ledcAttachPin(R_PWM,channel_R);
  ledcAttachPin(L_PWM,channel_L);
    pinMode(enc_r,INPUT);
    pinMode(enc_l,INPUT);
    attachInterrupt(digitalPinToInterrupt(enc_r),Update_encR,CHANGE);
    attachInterrupt(digitalPinToInterrupt(enc_l),Update_encL,CHANGE);

}


void loop(){
    right_enc.publish(&enc_r_msg);
    left_enc.publish(&enc_l_msg);
    nh.spinOnce();
}

void srv_profile(const Test::Request & req, Test::Response & res){

    String value_in = req.input;
    profile = value_in.toInt();

    move_forward();
    
    if ( profile == 1 ){
        delay(300);
        stop();
    }
    else if (profile == 2 ){
        delay(500);
        stop();
    }
    else if (profile == 3 ){
        delay(800);
        stop();
    }

    res.output = "Profile Served ";
    //call clearing data service

}

void srv_clear_data(const Test::Request & req, Test::Response & res){
    enc_r_msg.data=0;
    enc_l_msg.data=0;
    count_l=0;count_r=0;
    res.output = "Data has been cleared ";
}

void setupWiFi()
{  
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) { delay(500);Serial.print("."); }
   Serial.print("SSID: ");
   Serial.println(WiFi.SSID());
   Serial.print("IP:   ");
   Serial.println(WiFi.localIP());

}





void move_forward (){
    digitalWrite(L_FORW, 1 );
    digitalWrite(L_BACK, 0);
    digitalWrite(R_FORW, 1 );
    digitalWrite(R_BACK, 0);
    ledcWrite(channel_R, 150);  
    ledcWrite(channel_L, 150);
}

void stop()
{
   
   ledcWrite(channel_R, 0);  
   ledcWrite(channel_L, 0);
}


void Update_encR(){
    enc_r_msg.data=count_r ++;
    
}

void Update_encL(){
    enc_l_msg.data=count_l ++;

}