#include <ros/ros.h>

using namespace  std;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "param_demo");
    ros::NodeHandle n;
    ros::NodeHandle pn("~");
  
    string s;
    int num;
    
    pn.param<string>("string_param", s, "default_string");
    pn.param<int>("int_param", num, 2333);

//    n.setParam("string_param","default_string"); 
//    pn.setParam("int_param",2333);   


    printf("\nstring_param:  %s\n", s.c_str());//输出初始化值
    printf("int_param:  %d\n\n", num);//输出初始化值
    
    ros::Rate loop_rate(0.5);

    while (ros::ok())
    {
        pn.getParam("string_param",s);	
        printf("string_param:  %s\n", s.c_str());
        pn.getParam("int_param",num);
        printf("int_param:  %d\n\n", num);
        
		ros::spinOnce();
		loop_rate.sleep();
    }
}

