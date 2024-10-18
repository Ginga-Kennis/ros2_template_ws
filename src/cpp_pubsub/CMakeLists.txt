cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Add directory for header files
include_directories(include)

# Add executable so you can run your node using ros2 run
add_executable(talker src/minimal_publisher.cpp)
ament_target_dependencies(talker rclcpp std_msgs)
add_executable(listener src/minimal_subscriber.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

# Add target so ros2 run can find your executable
install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})

# Install launch files
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
