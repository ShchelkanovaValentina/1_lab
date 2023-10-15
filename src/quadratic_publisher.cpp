#include "ros/ros.h"
#include "/home/valentina/catkin_ws/src/quadratic_solver/include/quadratic.h"
#include "std_msgs/Float64MultiArray.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "quadratic_publisher");
  if (argc != 4)
  {
    ROS_INFO("Usage: quadratic_publisher a b c");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<quadratic_solver::quadratic>("quadratic");
  ros::Publisher pub = n.advertise<std_msgs::Float64MultiArray>("quadratic_roots", 1000);
  ros::Rate loop_rate(10);

  quadratic_solver::quadratic srv;
  srv.request.a = atof(argv[1]);
  srv.request.b = atof(argv[2]);
  srv.request.c = atof(argv[3]);
  
  while (ros::ok())
  {
    if (client.call(srv))
    {
      std_msgs::Float64MultiArray msg;
      msg.data.push_back(srv.response.x1);
      msg.data.push_back(srv.response.x2);

      pub.publish(msg);

      ROS_INFO("Quadratic equation: %f x^2 + %f x + %f = 0", srv.request.a, srv.request.b, srv.request.c);
      ROS_INFO("Roots: x1 = %f, x2 = %f", srv.response.x1, srv.response.x2);
    }
    else
    {
      ROS_ERROR("Failed to call service quadratic");
      return 1;
    }

    ros::spinOnce();

    loop_rate.sleep();
    
  }

  return 0;
}
