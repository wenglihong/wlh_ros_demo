#include "ros/ros.h"
#include "std_msgs/String.h"

class multiReceiver
{
public:
	multiReceiver()
	{	
		sub = nh.subscribe("chatter1", 1, &multiReceiver::chatterCallback1,this);
		sub2 = nh.subscribe("chatter2", 1, &multiReceiver::chatterCallback2,this);
	}
	void chatterCallback1(const std_msgs::String::ConstPtr& msg);
	void chatterCallback2(const std_msgs::String::ConstPtr& msg);

private:
	ros::NodeHandle nh;
	ros::Subscriber sub;
	ros::Subscriber sub2;
  
};


void multiReceiver::chatterCallback1(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  ros::Rate loop_rate(0.5);//block chatterCallback2()
  loop_rate.sleep();
}

void multiReceiver::chatterCallback2(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
  

int main(int argc, char **argv)
{

  ros::init(argc, argv, "multi_sub");

  multiReceiver recOb;
  ros::spin();

  return 0;
}


