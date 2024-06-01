# MicroROS ESP32 WiFi Controlled Robot

Welcome to the MicroROS ESP32 WiFi controlled robot project! This repository contains all the necessary files and instructions to build, program, and integrate a fully functional robot using the ESP32 and MicroROS with ROS2.
![main](https://github.com/noshluk2/MicroROS-ESP32-WiFi-Controlled-Robot/blob/main/resources/thumbnail.png)
- **[[Get course Access]](https://robotisim.com/project-based-course/)**
## Introduction

If you're passionate about robotics and eager to dive into hands-on hardware and ROS2 projects, this course is perfect for you. We'll guide you step-by-step in building a fully functional robot using the ESP32 and MicroROS with ROS2 over Wifi.

### Course Overview

**Section 1: Building the Robot**
- Assemble your robot from the ground up
- Utilize 3D-printed parts and resources we provide
- Learn about electronic connections and power distribution
![main](https://github.com/noshluk2/MicroROS-ESP32-WiFi-Controlled-Robot/blob/main/resources/1_microROS_bot_circuit.png)
**Section 2: Basic Programming**
- Get started with programming using PlatformIO to control your robot's movements
- Write simple code to drive the robot and navigate basic paths
- Create your custom libraries for motor driving
- Integrate the OLED display into your robot
![main](https://github.com/noshluk2/MicroROS-ESP32-WiFi-Controlled-Robot/blob/main/resources/2_basic_programing.png)
**Section 3: MicroROS Integration**
- Integrate MicroROS with your ESP32 robot
- Enhance your robot’s capabilities with advanced communication using ROS2
![main](https://github.com/noshluk2/MicroROS-ESP32-WiFi-Controlled-Robot/blob/main/resources/3_microROS_integeration.png)
By the end of this course, you'll have a deeper understanding of robotics, from hardware assembly to software integration, and you'll walk away with a robot that you built and programmed yourself.

### Directory Details

- **microROS_bot/include**: This directory contains the README file for the include directory, where you can provide information about the headers and any specific instructions or documentation.

- **microROS_bot/lib**: This directory houses different libraries used in the project.
  - **motor_control**: Contains `motor_control.cpp` and `motor_control.h` files for controlling the robot's motors.
  - **oled_display**: Contains `oled_display.cpp` and `oled_display.h` files for managing the OLED display integration.
  - **ros_communication**: Contains `ros_communication.cpp` and `ros_communication.h` files for integrating ROS communication capabilities.
  - **README**: Provides information about the libraries and their usage.

- **microROS_bot/platformio.ini**: This is the PlatformIO configuration file, which contains the settings and dependencies for the project.

- **microROS_bot/src**: Contains the main source code file `main.cpp`, which is the entry point of the robot's program.

- **microROS_bot/test**: Contains a README file for providing information about any tests or testing framework used in the project.

- **resources**: This directory includes all the resources needed for building the robot.
  - **3d models**: Contains STL files for 3D printing the robot parts.
    - `base.stl`, `caster_holder.stl`, `cover.stl`, `motor_holder.stl`
  - **circuit_design.png**: Image of the circuit design for the robot.
  - **robot_model.png**: Image of the complete robot model.

## How to Run

1. **Assemble the Robot**: Follow the instructions provided in the `resources` directory. Use the 3D models and the circuit design to assemble your robot.

2. **Set Up Your Development Environment**:
   - Install [PlatformIO](https://platformio.org/install/ide?install=vscode) in your preferred IDE (e.g., VSCode).
   - Clone this repository to your local machine.
   - Open the project folder in your IDE.

3. **Program the Robot**:
   - Navigate to the `microROS_bot` directory.
   - Modify the `src/main.cpp` file as needed to customize the robot's behavior.
   - Use PlatformIO to build and upload the code to your ESP32.

4. **Integrate MicroROS**:
   - Ensure you have ROS2 installed on your computer.
   - Follow the instructions in the `lib/ros_communication` directory to integrate MicroROS with your ESP32 robot.

