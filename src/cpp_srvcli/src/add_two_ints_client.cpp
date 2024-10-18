#include "cpp_srvcli/add_two_ints_client.hpp"

AddTwoIntsClient::AddTwoIntsClient() : Node("add_two_ints_client")
{
    client_ = this->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
}

bool AddTwoIntsClient::send_request(int64_t a, int64_t b)
{
    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = a;
    request->b = b;

    while (!client_->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
            return false;
        }
        RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
    }

    auto result = client_->async_send_request(request);

    if (rclcpp::spin_until_future_complete(this->shared_from_this(), result) == 
        rclcpp::FutureReturnCode::SUCCESS) {
        RCLCPP_INFO(this->get_logger(), "Sum: %ld", result.get()->sum);
        return true;
    } else {
        RCLCPP_ERROR(this->get_logger(), "Failed to call service add_two_ints");
        return false;
    }
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    if (argc != 3) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: add_two_ints_client X Y");
        return 1;
    }

    auto node = std::make_shared<AddTwoIntsClient>();
    int64_t a = atoll(argv[1]);
    int64_t b = atoll(argv[2]);

    node->send_request(a, b);

    rclcpp::shutdown();
    return 0;
}
