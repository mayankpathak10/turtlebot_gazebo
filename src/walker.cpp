// @Copyright 2018
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
 *
 * @param[in]  argc  The argc
 * @param      argv  The argv
 *
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
    ros::Rate loop_rate(10);

    ros::Publisher pub = n.advertise<geometry_msgs
                         ::Twist>("/cmd_vel_mux/input/teleop", 1000);
    ros::Subscriber sub = n.subscribe
                          ("/scan", 1000, &robot::scanCallback, &turtle);

    while (ros::ok()) {
        // If not obstacle detect in front of the robot
        // goes straight
        // if obstacle is detected
        // Turns clockwise
        if (!turtle.obstacle(turtle.lasers)) {
            ROS_INFO("All clear");
            velocity.linear.x = 0.25;
            velocity.angular.z = 0.0;
        } else if (turtle.obstacle(turtle.lasers)) {
            ROS_INFO("Obstacle");
            velocity.linear.x = 0.0;
            velocity.angular.z = 0.25;
        }

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
