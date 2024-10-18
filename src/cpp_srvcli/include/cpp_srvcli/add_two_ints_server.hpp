#ifndef ADD_TWO_INTS_SERVER_HPP_
#define ADD_TWO_INTS_SERVER_HPP_

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class AddTwoIntsServer : public rclcpp::Node
{
public:
    AddTwoIntsServer();

private:
    void add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
             std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response);

    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service_;
};

#endif // ADD_TWO_INTS_SERVER_HPP_