# Turtlebot Walker

## Overview

* In this package, I have created a node that makes a turtlebot to behave like a Roomba robot. It senses the environment by checking if there are obstacles around. If there are no obstacles, the robot moves forward. If it detects an obstacle, it will rotate in place until it stops detecting it. The node subscribes to the laser scan data provided by the robot and publishes velocity commands to the velocity topic.

## Dependencies

* ROS Kinetic
* Catkin
* roscpp package
* std_msgs package
* genmsg package
* geometry_msgs package

## How to build

* Create a catkin workspace if it was not created previously:

```
mkdir ros_ws
cd ros_ws
mkdir src
catkin_make
```
* Clone the repository and build the package:
```
cd ros_ws
cd src
git clone https://github.com/mayankpathak10/turtlebot_walker.git
cd ..
catkin_make
```

## How to run

* To run the package, just run the next two commands:

```
cd ~/ros_ws
source devel/setup.bash
roslaunch turtlebot_walker turtle.launch
```

Gazebo will start with the corridor map and a turtlebot moving around as it is supposed: turning when it detects an obstacle or moving forward when there is no obstacle.

![gazebo](https://github.com/mayankpathak10/turtlebot_walker/blob/master/results/gazebo.png)

## Recording and inspecting bag files

To record using rosbag, you have to launch `turtle.launch`but with the argument _rosbagFlag_ as true. If called as false or not called at all, the data will not be recorded.

* To record data:

```
cd ~/ros_ws
source devel/setup.bash
roslaunch turtlebot_walker turtle.launch rosbagFlag:=true
```
This will record the data in the `~/.ros` folder. To access it and see its information:

```
cd ~/.ros
rosbag info turtlebot_walker_bagfile.bag
```

* If the data recording is not needed, just launch:

`roslaunch turtlebot_walker turtle.launch` or `roslaunch turtlebot_walker turtle.launch rosbagFlag:=false`

## Bag file playback

Once the bag file is generated, we can replay it by running the following commands in the directory where the bag file is*

```
rosbag play turtlebot_walker_bagfile.bag
```

The bag file inside the results folder was compressed due to size issues, to run it, follow the next commands:

```
cd ~/ros_ws/src/turtlebot_walker/results
rosbag decompress -f turtlebot_walker_bagfile.bag
rosbag play turtlebot_walker_bagfile.bag
```
*(Since Gazebo should not be running for the replay, `roscore` has to be launched in a first terminal)
