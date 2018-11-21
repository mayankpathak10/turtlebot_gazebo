/**
 *MIT License

Copyright (c) 2018 Mayank Pathak

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

 *@copyright Copyright 2018 Mayank Pathak
 *@file   walker.cpp
 *@author Mayank Pathak
 *@brief  This file is a part of ros package to implement obstacle
 *        avoidance behavior on turtlebot on gazebo corridor world.
 *        Here, subscriber is defined to read the Laser scans and
 *        publisher is defined to publish the velocity to turtlebot.
 */

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
#include <cstdlib>
#include <string>
#include "ros/ros.h"
#include "ros/console.h"
#include "robot.hpp"

/**
 * @brief      main function to execute walker.cpp
 * @param[in]  argc  The argc
 * @param      argv  The argv
 * @return     0
 */
int main(int argc, char **argv) {
    ros::init(argc, argv, "walker");
    // robot object
    robot turtle;
    // node handle
    ros::NodeHandle n;
    // message object created
    geometry_msgs::Twist velocity;
    // publishing frequency


    ros::Publisher pub = n.advertise<geometry_msgs
                         ::Twist>("/cmd_vel_mux/input/teleop", 1000);
    ros::Subscriber sub = n.subscribe
                          ("/scan", 100, &robot::scanCallback, &turtle);

    ros::Rate loop_rate(10);
    while (ros::ok()) {
        // If not obstacle detect in front of the robot
        // goes straight
        // if obstacle is detected
        // Turns clockwise
        if (!turtle.obstacle(turtle.lasers)) {
            ROS_INFO("All clear");
            // angular velocity 0
            velocity.linear.x = 0.25;
            velocity.angular.z = 0.0;
        }
        if (turtle.obstacle(turtle.lasers)) {
            ROS_INFO("Obstacle");
            // forward velocity 0
            velocity.linear.x = 0.0;
            velocity.angular.z = 0.25;
        }
        pub.publish(velocity);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
