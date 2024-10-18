import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    config = os.path.join(
      get_package_share_directory('cpp_parameters'),
      'config',
      'params.yaml'
      )
   
    return LaunchDescription([
        Node(
            package="cpp_parameters",
            executable="minimal_param_node",
            name="minimal_param_node",
            output="screen",
            emulate_tty=True,
            parameters=[config]
        )
    ])