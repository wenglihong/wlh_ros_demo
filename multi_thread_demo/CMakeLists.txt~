cmake_minimum_required(VERSION 2.8.3)
project(multi_thread_demo)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)



## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

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


add_executable(multi_topic_pub src/multi_topic_pub.cpp)
target_link_libraries(multi_topic_pub ${catkin_LIBRARIES})


add_executable(multi_topic_sub src/multi_topic_sub.cpp)
target_link_libraries(multi_topic_sub ${catkin_LIBRARIES})

add_executable(multi_thread_listener src/multi_thread_listener.cpp)
target_link_libraries(multi_thread_listener  ${catkin_LIBRARIES})

add_executable(multi_thread_listener2 src/multi_thread_listener2.cpp)
target_link_libraries(multi_thread_listener2  ${catkin_LIBRARIES})

add_executable(custom_callback src/custom_callback_demo.cpp)
target_link_libraries(custom_callback  ${catkin_LIBRARIES})




