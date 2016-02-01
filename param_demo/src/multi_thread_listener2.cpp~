#include "ros/ros.h"
#include "std_msgs/String.h"
#include <boost/thread.hpp>


class multiThreadListener
{
public:
	multiThreadListener()
	{	
		sub = n.subscribe("chatter1", 1, &multiThreadListener::chatterCallback1,this);
		sub2 = n.subscribe("chatter2", 1, &multiThreadListener::chatterCallback2,this);
	}
	void chatterCallback1(const std_msgs::String::ConstPtr& msg);
	void chatterCallback2(const std_msgs::String::ConstPtr& msg);

private:
	ros::NodeHandle n;
	ros::Subscriber sub;
	ros::Subscriber sub2;
  
};


void multiThreadListener::chatterCallback1(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  ros::Rate loop_rate(0.5);//block chatterCallback2()
  loop_rate.sleep();
}


void multiThreadListener::chatterCallback2(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
  

int main(int argc, char **argv)
{

  ros::init(argc, argv, "multi_sub");

  multiThreadListener listener_obj;
  
  ros::AsyncSpinner spinner(2); // Use 2 threads
  spinner.start();
  ros::waitForShutdown();

  return 0;
}


