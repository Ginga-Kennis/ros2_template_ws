#include "cpp_pubsub/minimal_publisher.hpp"

// Name the node as "minimal_publisher"
MinimalPublisher::MinimalPublisher() : Node("minimal_publisher"), count_(0)
{
  // Initialize publisher (message type : String, topic name : "topic", queue size : 10)
  publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
  // Initialize timer, which causes the timer_callback function to be executed twice a second
  timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
}

// Set and publish messages
void MinimalPublisher::timer_callback()
{
  auto message = std_msgs::msg::String();
  message.data = "Hello, world! " + std::to_string(count_++);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
  publisher_->publish(message);
}

// Main function where the node actually executes
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);  // initialize ROS2
  rclcpp::spin(std::make_shared<MinimalPublisher>());  // start node
  rclcpp::shutdown();
  return 0;
}
