#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


int main(int argc, char **argv)
{

	ros::init(argc, argv, "multi_pub");


	ros::NodeHandle n;


	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter1", 1);
	ros::Publisher pub2 = n.advertise<std_msgs::String>("chatter2", 1);

	ros::Rate loop_rate(10);


	int count = 0;
	while (ros::ok())
	{

		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();

		std_msgs::String msg2;
		std::stringstream ss2;
		ss2 << "hello " << count;
		msg2.data = ss2.str();

		ROS_INFO("%s", msg.data.c_str());
		ROS_INFO("%s", msg2.data.c_str());

		chatter_pub.publish(msg);
		pub2.publish(msg2);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}


	 return 0;
}
