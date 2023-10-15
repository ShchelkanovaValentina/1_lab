#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"

void rootsCallback(const std_msgs::Float64MultiArray::ConstPtr& msg)
{
  ROS_INFO("Roots: x1 = %f, x2 = %f", msg->data[0], msg->data[1]);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "quadratic_subscriber");

  
  ros::NodeHandle n;

  
  ros::Subscriber sub = n.subscribe("quadratic_roots", 1000, rootsCallback);

  
  ros::spin();

  return 0;
}
