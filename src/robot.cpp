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
 *@file   robot.cpp
 *@author Mayank Pathak
 *@brief  This file is a part of ros package to implement obstacle
 *        avoidance behavior on turtlebot on gazebo corridor world.
 *		  Here the functions that weredeclared in the header file are
 *		  defined.
 */

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <string>
#include "ros/ros.h"
#include "robot.hpp"

/**
 * @brief      Scans a callback.
 * @param[in]  laser  LaserScan message
 */
void robot::scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser) {
    robot::lasers.clear();
    for (int i = 0; i < laser->ranges.size(); i++) {
        robot::lasers.push_back(laser->ranges[i]);
    }
}

/**
 * @brief      to determine presence of obstacle
 * @param[in]  laserscans  The laserscans
 * @return     boolean Obstacle status
 */
bool robot::obstacle(std::vector<double> laserscans) {
    double min = 80.0;
    for (int i = 0; i < laserscans.size(); i++) {
        if (laserscans[i] < min) {
            min = laserscans[i];
        }
    }

    if (min < 0.85) {
        // std::cout << "Obstacle" << std::endl;
        return true;
    } else {
        // std::cout << "All Clear" << std::endl;
        return false;
    }
}
