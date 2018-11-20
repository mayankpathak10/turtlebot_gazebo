// Copyright 2018
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
 *
 * @param[in]  laser  LaserScan message
 */
void robot::scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser) {
    robot::lasers.clear();
    for (int i = 0; i < laser->ranges.size(); i++) {
        std::cout << laser->ranges[i] << std::endl;
        robot::lasers.push_back(laser->ranges[i]);
    }
}

/**
 * @brief      to determine presence of obstacle
 *
 * @param[in]  laserscans  The laserscans
 *
 * @return     boolean Obstacle status
 */
bool robot::obstacle(std::vector<double> laserscans) {
    double min = 65.0;
    for (int i = 0; i < laserscans.size(); i++) {
        if (laserscans[i] < min) {
            min = laserscans[i];
        }
    }

    if (min < 0.6) {
        std::cout << "Obstacle" << std::endl;
        return true;
    } else {
        std::cout << "All clear" << std::endl;
        return false;
    }
}
