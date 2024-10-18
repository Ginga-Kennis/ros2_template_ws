#ifndef MINIMAL_PUBLISHER_HPP_
#define MINIMAL_PUBLISHER_HPP_

// Standard C++ headers
#include <chrono>
#include <functional>
#include <memory>
#include <string>

// ROS related headers
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

// Create the node class MinimalPublihser by inheriting from rclcpp::Node
class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher(); 

private:
  void timer_callback();
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};

#endif // MINIMAL_PUBLISHER_HPP_
