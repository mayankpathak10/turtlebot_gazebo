// @Copyright 2018

#ifndef INCLUDE_ROBOT_HPP_
#define INCLUDE_ROBOT_HPP_
#pragma once
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <vector>
#include "ros/ros.h"


class robot {
  public:  //NOLINT
    std::vector<double> lasers;
    void scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser);
    bool obstacle(std::vector<double> laserscans);
};
#endif  // INCLUDE_ROBOT_HPP_
