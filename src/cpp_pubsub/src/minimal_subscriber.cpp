#include "cpp_pubsub/minimal_subscriber.hpp"

MinimalSubscriber::MinimalSubscriber() : Node("minimal_subscriber") 
{
  // Use node's create_subscription class to execute the callback
  subscription_ = this->create_subscription<std_msgs::msg::String>(
    "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, std::placeholders::_1));
}

void MinimalSubscriber::topic_callback(const std_msgs::msg::String & msg) const
{
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
