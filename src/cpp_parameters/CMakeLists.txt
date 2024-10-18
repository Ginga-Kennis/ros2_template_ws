cmake_minimum_required(VERSION 3.8)
project(cpp_parameters)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Add directory for header files
include_directories(include)

add_executable(minimal_param_node src/cpp_parameter_node.cpp)
ament_target_dependencies(minimal_param_node rclcpp)

install(TARGETS
  minimal_param_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)

ament_package()
