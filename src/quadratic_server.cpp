#include "ros/ros.h"
#include "../include/quadratic.h"
#include <cmath>

bool solve(quadratic_solver::quadratic::Request  &req,
           quadratic_solver::quadratic::Response &res)
{
  double a = req.a;
  double b = req.b;
  double c = req.c;
  double d = b * b - 4 * a * c;
  if (d >= 0) {
    res.x1 = (-b + sqrt(d)) / (2 * a);
    res.x2 = (-b - sqrt(d)) / (2 * a);
    ROS_INFO("Solving quadratic equation: %f x^2 + %f x + %f = 0", a, b, c);
    ROS_INFO("Sending back response: x1 = %f, x2 = %f", res.x1, res.x2);
    return true;
  } else {
    ROS_ERROR("Quadratic equation has no real roots");
    return false;
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "quadratic_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("quadratic", solve);
  ROS_INFO("Ready to solve quadratic equations");
  ros::spin();

  return 0;
}
