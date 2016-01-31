cmake_minimum_required(VERSION 2.8.3)
project(custom_msgs_demo)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)



## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   Message1.msg
 )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )


# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )


catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ros_msg
  CATKIN_DEPENDS roscpp rospy std_msgs
  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(custom_msgs_pub src/custom_msgs_pub.cpp)
target_link_libraries(custom_msgs_demo ${catkin_LIBRARIES})
#add_dependencies(string_publish ros_msg_generate_messages_cpp)

add_executable(custom_msgs_sub src/custom_msgs_sub.cpp)
target_link_libraries(custom_msgs_sub ${catkin_LIBRARIES})
#add_dependencies(string_receive ros_msg_generate_messages_cpp)




