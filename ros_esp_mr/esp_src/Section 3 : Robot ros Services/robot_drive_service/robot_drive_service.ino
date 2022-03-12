
/*

*/

#define ROSSERIAL_ARDUINO_TCP
#include "WiFi.h"
#include <ros.h>
#include <rosserial_arduino/Test.h>
using rosserial_arduino::Test;


const uint8_t R_PWM =  12;
const uint8_t R_BACK = 14;
const uint8_t R_FORW = 27;

const uint8_t L_PWM =  33;
const uint8_t L_BACK = 25;
const uint8_t L_FORW = 26;

const uint8_t channel_L =0;
const uint8_t channel_R= 1;
int time_in_seconds;

IPAddress server(192, 168, 100, 7);
uint16_t serverPort = 11411;
const char*  ssid = "Luqman IT";
const char*  password = "222333444";

void srv_cb(const Test::Request & req, Test::Response & res);

ros::NodeHandle  nh;
ros::ServiceServer<Test::Request, Test::Response> car_motion_time_srv("sec_for_movement",&srv_cb);

void setup(){


    Serial.begin(115200);
    setupWiFi();
    nh.getHardware()->setConnection(server, serverPort);
    nh.initNode();
    nh.advertiseService(car_motion_time_srv);


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

}


void loop(){

  nh.spinOnce();
}

void srv_cb(const Test::Request & req, Test::Response & res){

    String value_in = req.input;
    time_in_seconds = value_in.toInt();
    
    move_forward();
    delay(time_in_seconds * 1000);
    stop();
    res.output = "Service Completed ";

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
