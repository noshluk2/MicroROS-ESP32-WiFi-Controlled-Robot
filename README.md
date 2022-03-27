# ESP32 Based ROS  Mobile Robot

### Introduction
This repository is based on the course on mobile robotics interface with ROS Noetic



<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#About-this-Repository">About This Repository</a></li>
    <li><a href="#Using-this-Repository">Using this Repository</a></li>
        <li><a href="#Features">Features</a></li>
    <li><a href="#Pre-Course-Requirments">Pre-Course Requirments</a></li>
    <li><a href="#Link-to-the-Course">Link to the Course</a></li>
    <li><a href="#Instructors">Instructors</a></li>
    <li><a href="#License">License</a></li>
  </ol>
</details>

## About this Repository
We will start with installation of **Rosserial Package**  installation into our system . Which is going to be utilized for ESP32 and ROS Communication

[![alt text](https://github.com/noshluk2/ROS-ESP32-Mobile-Robotics/tree/main/ros_esp_mr/images/cover.png)](https://www.udemy.com/course/mastering-mobile-robot-with-ros-ardunio-car-sensors-to-ros/?couponCode=ROS_HW "Click to Watch Intro Video")
----

- **esp_src** : Contains scripts for esp32 microcontroller
- **src** : contains scripts of nodes basedon ROS1
- **notes** : Contains all lecture notes taught during the course

Source Codes and lectures are arranged with the following Order

    - **Section 1:** Basic ROS - ESP32 Interfacing
        - Led Toggling
        - Ultrasonic Sensor controlling Turtlesim
    - **Section 2:** ROS based Car driving
        - Motor Controlling
        - cmd_vel to Pwm Serial
        - Car Control over Wifi
    - **Section 3:** Robot car and ROS services
        - Encoders interfacing
        - ROS Service Nodes
        - Drove robot through Services on Time.
    - **Section 4:** Odometery publishing Car Driving
        - Encoders ticks profiling
        - Odom differential Drive Rviz
        - transforms



## Using this Repository
* Clone the repository in you Workspace
```
mkdir -p ~/catkin_ws/src ## if not already created
cd ~/catkin_ws/src
git clone https://github.com/noshluk2/ROS-ESP32-Mobile-Robotics.git
```
* Source your ROS installation
 ```
source /opt/ros/noetic/setup.bash
 ```
- Build your workspace
 ```
 cd ~/catkin_ws
 catkin_make
  ```


* Source your Workspace in any terminal you open to Run files from this workspace ( Basic thing of ROS )
```
source ~/catkin_ws/devel/setup.bash
```

----
## Features
* **TurtleSim Obstical Avoiding using real World Sensor**
  -  ![alt text](https://github.com/noshluk2/ROS-ESP32-Mobile-Robotics/tree/main/ros_esp_mr/images/turtlesim_ultra_sonic_drive.gif)
* **Encoders Publishing Node from ESP32**
  -  ![alt text](https://github.com/noshluk2/ROS-ESP32-Mobile-Robotics/tree/main/ros_esp_mr/images/encoder_publisher.gif)
* **Robot Driving over WiFi using teleOp package**
  - ![alt text](https://github.com/noshluk2/ROS-ESP32-Mobile-Robotics/tree/main/ros_esp_mr/images/teleop_drive.gif)
* **ROS Service for Encoder Ticks Calculation**
  - ![alt text](https://github.com/noshluk2/ROS-ESP32-Mobile-Robotics/tree/main/ros_esp_mr/images/encoder_service_counter.gif)

* **Transforms and Odometery of Robot to Rviz**
  - ![alt text](https://github.com/noshluk2/ROS-ESP32-Mobile-Robotics/tree/main/ros_esp_mr/images/odometery_transforms.gif)


----
## Pre-Course Requirments
**Hardware Requirments**
- ESP32
- Robotic Car Kit
- Battery and Charger
- Ultrasonic Sensor
- Motor Driver ( L298D)
- Jumper Wires

**Software Based**
* Ubuntu 20.04 (LTS)
* ROS2 - Foxy Fitzroy
* Python 3.6
* Arduino Ide
* Vscode

**Skill Based**
* Basic C++ and Python Programming
* Basic ROS1 Nodes Communication
* Launch Files
* Motivated mind :)
---
## Link to the Course

**[[Discounted Link]](https://www.udemy.com/course/mastering-mobile-robot-with-ros-ardunio-car-sensors-to-ros/?couponCode=ROS_HW)**

----

## Instructor
Muhammad Luqman (ROS Simulation and Control Systems) - [Profile Link](https://www.linkedin.com/in/muhammad-luqman-9b227a11b/)

----
## License

Distributed under the GNU-GPL License. See `LICENSE` for more information.

