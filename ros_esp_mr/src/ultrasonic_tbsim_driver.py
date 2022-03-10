#!/usr/bin/env python
import rospy
from std_msgs.msg import Int16
from geometry_msgs.msg import Twist

def callback(data):
    global pub

    tbsim_vel = Twist()
    ultrasonic_value = data.data


    if( ultrasonic_value < 25 ):
        tbsim_vel.angular.z= 0.1
    else :
        tbsim_vel.linear.x=0.2

    pub.publish(tbsim_vel)
    
def listener():
    global  pub
    rospy.init_node('ultrasonic_tbsim_driver_node', anonymous=True)
    pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=10)
    rospy.Subscriber("ultrasonic_values", Int16, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()