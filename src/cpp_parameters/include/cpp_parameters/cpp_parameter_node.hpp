#ifndef MINIMAL_PARAM_HPP_
#define MINIMAL_PARAM_HPP_

#include <chrono>
#include <functional>
#include <string>

#include "rclcpp/rclcpp.hpp"

class MinimalParam : public rclcpp::Node
{
public:
  MinimalParam();

private:
  void timer_callback();
  rclcpp::TimerBase::SharedPtr timer_;
};

#endif // MINIMAL_PARAM_HPP_
