#include "composition/talker_component.hpp"

namespace composition
{

Talker::Talker(const rclcpp::NodeOptions & options) : Node("talker", options), count_(0)
{
    pub_ = create_publisher<std_msgs::msg::String>("chatter", 10);
    timer_ = create_wall_timer(std::chrono::seconds(1), [this]() {return this->on_timer();});
}

void Talker::on_timer()
{
    auto msg = std::make_unique<std_msgs::msg::String>();
    msg->data = "Hello World: " + std::to_string(++count_);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg->data.c_str());
    std::flush(std::cout);
    pub_->publish(std::move(msg));
} 

}  // namespace composition

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(composition::Talker)
