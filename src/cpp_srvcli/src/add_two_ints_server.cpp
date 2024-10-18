#include "cpp_srvcli/add_two_ints_server.hpp"

AddTwoIntsServer::AddTwoIntsServer() : Node("add_two_ints_server")
{
  // std::placeholders::_1 & std::placeholders::_2 for input of two numbers
  service_ = this->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", 
    std::bind(&AddTwoIntsServer::add, this, std::placeholders::_1, std::placeholders::_2));

  RCLCPP_INFO(this->get_logger(), "Ready to add two ints.");
}

void AddTwoIntsServer::add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
                           std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
{
  response->sum = request->a + request->b;
  RCLCPP_INFO(this->get_logger(), "Incoming request\na: %ld b: %ld", request->a, request->b);
  RCLCPP_INFO(this->get_logger(), "Sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AddTwoIntsServer>());
  rclcpp::shutdown();
  return 0;
}
