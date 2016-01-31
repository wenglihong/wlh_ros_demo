#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/Header.h"

//--------subscribe std_msgs/String messages----------
void stringCallback(const std_msgs::String::ConstPtr& msg)
{
    printf("String: %s\n", msg->data.c_str());
}
	
//----------subscribe std_msgs/Int8 messages----------
void int8Callback(const std_msgs::Int8 val_int8)
{
	printf("Int8: %d\n",val_int8.data);
}

//----------subscribe std_msgs/Float64MultiArray messages----------
void doubleCallback(const std_msgs::Float64MultiArray vec_double)
{
	printf("double_array: %f,%f,%f\n",vec_double.data[0],vec_double.data[1],vec_double.data[2]);
}

//-----------subscribe std_msgs/Header messages----------
void headerCallback(const std_msgs::Header header)
{
	printf("seq: %d frame_id: %s\n",header.seq,header.frame_id.c_str());
}


int main(int argc, char **argv)
{

  ros::init(argc, argv, "std_msgs_listener");
  
  ros::NodeHandle nh;
  
  ros::Subscriber sub_string = nh.subscribe("topic_string", 10, stringCallback);
  ros::Subscriber sub_int8 = nh.subscribe("topic_int8", 10, int8Callback);
  ros::Subscriber sub_double = nh.subscribe("topic_double", 10, doubleCallback);
  ros::Subscriber sub_header = nh.subscribe("topic_header", 10, headerCallback);
  
  ros::spin();

  return 0;
}

