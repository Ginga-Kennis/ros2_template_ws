cmake_minimum_required(VERSION 3.8)
project(composition)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)

# ビルド時に「include」ディレクトリをインクルードパスに追加
# ソースファイルから「include」ディレクトリ内のヘッダーファイルが見えるようにする
include_directories(include)

# src/talker_component.cpp」を元に共有ライブラリ（SHARED）として「talker_component」をビルド
add_library(talker_component SHARED
  src/talker_component.cpp
)
# talker_componentの依存関係を設定
ament_target_dependencies(talker_component
  rclcpp
  rclcpp_components
  std_msgs
)
# talker_componentをコンポーネントとして登録し、別名"talker"で実行できるようする
rclcpp_components_register_node(
    talker_component
    PLUGIN "composition::Talker"
    EXECUTABLE talker
)

# talker_componentライブラリのインストール
install(
  TARGETS talker_component
  EXPORT export_talker_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# launchファイルのインストール
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
