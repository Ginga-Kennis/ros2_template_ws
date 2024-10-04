#include "cpp_template_pkg/turtle_following_node.hpp"
#include "cpp_template_pkg/pid_following.hpp"

TurtleFollowingNode::TurtleFollowingNode() : Node("turtle_following_node") 
{
    loadParameters();
    initPubSub();
    spawnSecondTurtle();
}

void TurtleFollowingNode::loadParameters() {
    this->declare_parameter("turtle2_init_pose_x", 0.0);
    this->declare_parameter("turtle2_init_pose_y", 0.0);
    this->declare_parameter("turtle2_init_pose_theta", 0.0);
    this->declare_parameter("kp_linear", 1.5);
    this->declare_parameter("kp_angular", 6.0);

    this->get_parameter("turtle2_init_pose_x", turtle2_init_pose_x_);
    this->get_parameter("turtle2_init_pose_y", turtle2_init_pose_y_);
    this->get_parameter("turtle2_init_pose_theta", turtle2_init_pose_theta_);
    this->get_parameter("kp_linear", kp_linear_);
    this->get_parameter("kp_angular", kp_angular_);
}

void TurtleFollowingNode::initPubSub() {
    turtle1_pose_sub_ = this->create_subscription<turtlesim::msg::Pose>(
        "turtle1/pose", 1, std::bind(&TurtleFollowingNode::turtle1PoseCallback, this, std::placeholders::_1));

    turtle2_pose_sub_ = this->create_subscription<turtlesim::msg::Pose>(
        "turtle2/pose", 1, std::bind(&TurtleFollowingNode::turtle2PoseCallback, this, std::placeholders::_1));

    turtle2_twist_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle2/cmd_vel", 1);
}

void TurtleFollowingNode::spawnSecondTurtle() {
    auto client = this->create_client<turtlesim::srv::Spawn>("spawn");
    auto request = std::make_shared<turtlesim::srv::Spawn::Request>();
    request->x = turtle2_init_pose_x_;
    request->y = turtle2_init_pose_y_;
    request->theta = turtle2_init_pose_theta_;
    request->name = "turtle2";

    while (!client->wait_for_service(std::chrono::seconds(1))) {
        RCLCPP_WARN(this->get_logger(), "Waiting for the spawn service to be available...");
    }

    auto result = client->async_send_request(request);
    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) == rclcpp::FutureReturnCode::SUCCESS) {
        RCLCPP_INFO(this->get_logger(), "Second turtle spawned successfully.");
    } else {
        RCLCPP_ERROR(this->get_logger(), "Failed to spawn second turtle.");
    }
}

TurtleFollowingNode::~TurtleFollowingNode() {}

void TurtleFollowingNode::turtle1PoseCallback(const turtlesim::msg::Pose::SharedPtr msg) {
    turtle1_x_ = msg->x;
    turtle1_y_ = msg->y;
    turtle1_theta_ = msg->theta;
}

void TurtleFollowingNode::turtle2PoseCallback(const turtlesim::msg::Pose::SharedPtr msg) {
    turtle2_x_ = msg->x;
    turtle2_y_ = msg->y;
    turtle2_theta_ = msg->theta;

    geometry_msgs::msg::Twist twist_msg = computeCmdVel(
        turtle1_x_, turtle1_y_, turtle2_x_, turtle2_y_, turtle2_theta_,
        kp_linear_, kp_angular_
    );
    turtle2_twist_pub_->publish(twist_msg);
}

int main(int argc, char** argv) 
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleFollowingNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
