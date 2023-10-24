#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "quad_eq_publisher");
    ros::NodeHandle nh;

    ros::Publisher publisher = nh.advertise<std_msgs::Float64MultiArray>("quadratic_equation", 10);

    double a, b, c; // коэффициенты квадратного уравнения
    double root1, root2; // корни уравнения

   
    std::cout<<"Enter coefficients (a, b, c): ";
    std::cin>>a>>b>>c;

    double discriminant = (b * b) - (4 * a * c);
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
    }
    else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
    }
    else {
        root1 = root2 = 0; // если нет действительных корней
    }

    ros::Rate rate(10); // Отправка сообщений каждые 0,1 секунды
    while (ros::ok()) {
        std_msgs::Float64MultiArray msg;
        msg.data.push_back(root1); 
        msg.data.push_back(root2);

        publisher.publish(msg);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
