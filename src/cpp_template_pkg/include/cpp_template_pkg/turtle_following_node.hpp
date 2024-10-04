#ifndef TURTLE_FOLLOWING_NODE_H__
#define TURTLE_FOLLOWING_NODE_H__

#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/spawn.hpp"
#include "turtlesim/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"

class TurtleFollowingNode : public rclcpp::Node
{
public:
    TurtleFollowingNode();
    ~TurtleFollowingNode();

private:
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr turtle1_pose_sub_, turtle2_pose_sub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr turtle2_twist_pub_;

    void loadParameters();
    void initPubSub();
    void spawnSecondTurtle();
    void turtle1PoseCallback(const turtlesim::msg::Pose::SharedPtr msg);
    void turtle2PoseCallback(const turtlesim::msg::Pose::SharedPtr msg);

    double turtle2_init_pose_x_;
    double turtle2_init_pose_y_;
    double turtle2_init_pose_theta_;
    double kp_linear_;
    double kp_angular_;

    double turtle1_x_;
    double turtle1_y_;
    double turtle1_theta_;
    double turtle2_x_;
    double turtle2_y_;
    double turtle2_theta_;
};

#endif
