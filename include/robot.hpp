// @Copyright 2018

#ifndef INCLUDE_ROBOT_HPP_
#define INCLUDE_ROBOT_HPP_
#include <sensor_msgs/LaserScan.h>
#include "ros/ros.h"
class robot {
  public:  //NOLINT
    void scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser);
};
#endif  // INCLUDE_ROBOT_HPP_
