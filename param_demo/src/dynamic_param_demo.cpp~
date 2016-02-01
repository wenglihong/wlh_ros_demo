#include <ros/ros.h>

// Dynamic reconfigure includes.
#include <dynamic_reconfigure/server.h>
// Auto-generated from cfg/ directory.
#include <param_demo/dynamic_paramConfig.h>

using namespace  std;

string s;
int num;

void paramConfigCallback(param_demo::dynamic_paramConfig &config, uint32_t level)
{
	s = config.s;
	num = config.num;
	printf("\nstring_param:  %s\n", s.c_str());
    printf("int_param:  %d\n\n", num);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "dynamic_param_demo");
    ros::NodeHandle pnh("~");
    
    dynamic_reconfigure::Server<param_demo::dynamic_paramConfig> dr_srv;
  	dynamic_reconfigure::Server<param_demo::dynamic_paramConfig>::CallbackType cb;
  	
  	cb = boost::bind(&paramConfigCallback, _1, _2);
    dr_srv.setCallback(cb);
  
    
    pnh.param<string>("string_param", s, "default_string");
    pnh.param<int>("int_param", num, 2333);

    printf("\nstring_param:  %s\n", s.c_str());//输出初始化值
    printf("int_param:  %d\n\n", num);//输出初始化值
    
    ros::spin();  
}

