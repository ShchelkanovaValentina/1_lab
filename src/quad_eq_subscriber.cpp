#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <sstream>

void callback(const std_msgs::Float64MultiArray::ConstPtr& msg) {
    double root1 = msg->data[0];
    double root2 = msg->data[1];

    std::stringstream ss;
    ss << "x1 = " << root1 << ", x2 = " << root2;

    ROS_INFO("%s", ss.str().c_str());
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "quad_eq_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber subscriber = nh.subscribe("quadratic_equation", 10, callback);

    ros::spin();

    return 0;
}
