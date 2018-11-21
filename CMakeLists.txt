cmake_minimum_required(VERSION 2.8.3)
project(turtlebot_walker)

find_package(catkin REQUIRED COMPONENTS message_generation roscpp tf rospy std_msgs geometry_msgs)

catkin_package()

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(walker src/walker.cpp src/robot.cpp)
target_link_libraries(walker ${catkin_LIBRARIES})
