#include "composition/listener_component.hpp"

namespace composition
{

Listener::Listener(const rclcpp::NodeOptions & options) : Node("listener", options)
{
  sub_ = create_subscription<std_msgs::msg::String>(
    "chatter",
    10,
    std::bind(&Listener::topic_callback, this, std::placeholders::_1)
  );
}

void Listener::topic_callback(const std_msgs::msg::String & msg)
{
  RCLCPP_INFO(this->get_logger(), "I heard: [%s]", msg.data.c_str());
}

}  // namespace composition

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(composition::Listener)
