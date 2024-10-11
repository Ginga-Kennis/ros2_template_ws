#ifndef MINIMAL_SUBSCRIBER_HPP_
#define MINIMAL_SUBSCRIBER_HPP_

#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber();

private:
  void topic_callback(const std_msgs::msg::String & msg) const;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

#endif // MINIMAL_SUBSCRIBER_HPP_
