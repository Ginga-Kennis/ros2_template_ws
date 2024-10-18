#include "cpp_parameters/cpp_parameter_node.hpp"

MinimalParam::MinimalParam() : Node("minimal_param_node")
{
  // create a parameter named "my_parameter" with default value of "world"   
  this->declare_parameter("my_parameter", "world");

  timer_ = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&MinimalParam::timer_callback, this));
}

void MinimalParam::timer_callback()
{
  std::string my_param = this->get_parameter("my_parameter").as_string();
  RCLCPP_INFO(this->get_logger(), "Hello %s!", my_param.c_str());

  // Reset the parameter back to the default value   
//   std::vector<rclcpp::Parameter> all_new_parameters{rclcpp::Parameter("my_parameter", "world")};
//   this->set_parameters(all_new_parameters);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalParam>());
  rclcpp::shutdown();
  return 0;
}
