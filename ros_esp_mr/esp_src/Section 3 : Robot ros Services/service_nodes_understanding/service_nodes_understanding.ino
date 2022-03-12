/*
 * rosserial Service Server
 */

#include <ros.h>
#include <std_msgs/Int16.h>
#include <rosserial_arduino/Test.h>

ros::NodeHandle  nh;
using rosserial_arduino::Test;

int count;
int i ;
void callback(const Test::Request & req, Test::Response & res){

  if((i++)%2)
    res.output = req.input;
  else{
     delay(4000); 
    res.output = "Next time get input back";
  }
}

ros::ServiceServer<Test::Request, Test::Response> esp32_server("counter_pub_service",&callback);

std_msgs::Int16 counter_msg;
ros::Publisher counter_node("iterator", &counter_msg);

char hello[13] = "hello world!";

void setup()
{
  nh.initNode();
  nh.advertiseService(esp32_server);
  nh.advertise(counter_node);
}

void loop()
{ count ++;
  counter_msg.data = count;
  counter_node.publish( &counter_msg );
  nh.spinOnce();
  delay(10);
}
