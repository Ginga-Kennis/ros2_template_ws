#!/bin/bash

# ROS環境を設定
source /opt/ros/humble/setup.bash

# 引数として渡されたコマンドを実行
exec "$@"
