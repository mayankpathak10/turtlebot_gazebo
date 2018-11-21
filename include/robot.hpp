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
 *@file robot.hpp
 *@author Mayank Pathak
 *@brief This file is a part of ros package to implement obstacle
 * avoidance behavior on turtlebot on gazebo corridor world.
 */

#ifndef INCLUDE_ROBOT_HPP_
#define INCLUDE_ROBOT_HPP_
#pragma once
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <vector>
#include "ros/ros.h"

/**
 * @brief Definition of the robot class.
 * 		  functions are declared to read laserscans
 * 		  and classify as obstacle.
 */
class robot {
  public:  //NOLINT
    std::vector<double> lasers;
    void scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser);
    bool obstacle(std::vector<double> laserscans);
};
#endif  // INCLUDE_ROBOT_HPP_
