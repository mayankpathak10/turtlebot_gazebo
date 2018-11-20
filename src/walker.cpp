// @Copyright 2018
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
#include <cstdlib>
#include <string>
#include "ros/ros.h"
#include "robot.hpp"

/**
 * @brief      main function to execute walker.cpp
 *
 * @param[in]  argc  The argc
 * @param      argv  The argv
 *
 * @return     0
 */
int main(int argc, char **argv) {
    ros::init(argc, argv, "walker");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise <geometry_msgs::Twist
                                 > ("/cmd_vel_mux/input/teleop", 1000);
    ros::Subscriber sub = n.subscribe("/scan", 1000, chatterCallback);
    robot turtle;
    ros::Rate loop_rate(10);

    ros::Publisher pub = n.advertise<geometry_msgs
                         ::Twist>("/cmd_vel_mux/input/teleop", 1000);
    ros::Subscriber sub = n.subscribe
                          ("/scan", 1000, &robot::scanCallback, &turtle);
    ros::spin();
    return 0;
}
