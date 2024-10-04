cmake_minimum_required(VERSION 3.8)
project(cpp_template_pkg)

# コンパイラオプションの設定
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 依存パッケージの検索
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)

# パッケージのインクルードディレクトリ
include_directories(
  include
)

# ライブラリの作成
add_library(pid_following src/pid_following.cpp)
ament_target_dependencies(pid_following
  rclcpp
  geometry_msgs
)

# 実行ファイルの作成
add_executable(turtle_following_node src/turtle_following_node.cpp)
target_link_libraries(turtle_following_node
  pid_following
)

ament_target_dependencies(turtle_following_node
  rclcpp
  turtlesim
  geometry_msgs
)

# Launchファイルをインストール
install(TARGETS turtle_following_node pid_following
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

# テスト用の設定
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# パッケージ設定
ament_package()
