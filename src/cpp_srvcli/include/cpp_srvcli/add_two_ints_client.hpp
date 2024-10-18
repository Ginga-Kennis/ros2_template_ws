#ifndef ADD_TWO_INTS_CLIENT_HPP_
#define ADD_TWO_INTS_CLIENT_HPP_

#include <chrono>
#include <cstdlib>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class AddTwoIntsClient : public rclcpp::Node
{
public:
    AddTwoIntsClient();
    bool send_request(int64_t a, int64_t b);

private:
    rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client_;
};

#endif // ADD_TWO_INTS_CLIENT_HPP_
