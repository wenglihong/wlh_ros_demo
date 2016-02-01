#include "node_example/node_example_core.h"

NodeExample::NodeExample()
{
	// Set up a dynamic reconfigure server.
  // Do this before parameter server, else some of the parameter server
  // values can be overwritten.
  cb = boost::bind(&NodeExample::configCallback, this, _1, _2);
  dr_srv.setCallback(cb);

  // Initialize node parameters from launch file or command line.
  // Use a private node handle so that multiple instances of the node can be run simultaneously
  // while using different parameters.
  ros::NodeHandle pnh("~");
  pnh.param("a", a_, 1);
  pnh.param("b", b_, 2);
  pnh.param("message", message_, std::string("hello"));
  pnh.param("rate", rate_, 40);

}

NodeExample::~NodeExample()
{
}

void NodeExample::publishMessage(ros::Publisher *pub_message)
{
  node_example::NodeExampleData msg;
  msg.message = message_;
  msg.a = a_;
  msg.b = b_;

  pub_message->publish(msg);
}

void NodeExample::messageCallback(const node_example::NodeExampleData::ConstPtr &msg)
{
  message_ = msg->message;
  a_ = msg->a;
  b_ = msg->b;

  // Note that these are only set to INFO so they will print to a terminal for example purposes.
  // Typically, they should be DEBUG.
  ROS_INFO("message is %s", message_.c_str());
  ROS_INFO("sum of a + b = %d", a_ + b_);
}



void NodeExample::configCallback(node_example::nodeExampleConfig &config, uint32_t level)
{
  // Set class variables to new values. They should match what is input at the dynamic reconfigure GUI.
  message_ = config.message.c_str();
  a_ = config.a;
  b_ = config.b;
}
