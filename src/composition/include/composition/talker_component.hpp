#ifndef COMPOSITION__COMPOSITION_HPP_
#define COMPOSITION__COMPOSITION_HPP_

#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "composition/visibility_control.h"

namespace composition
{

class Talker : public rclcpp::Node
{
public:
  COMPOSITION_PUBLIC
  explicit Talker(const rclcpp::NodeOptions & options);

protected:
  void on_timer();

private:
  size_t count_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

} // namespace composition

#endif  // COMPOSITION__COMPOSITION_HPP_
