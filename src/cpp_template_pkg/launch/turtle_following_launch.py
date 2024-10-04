from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    config_file = os.path.join(
        get_package_share_directory('cpp_template_pkg'),
        'config',
        'turtle_following.yaml'
    )
    
    return LaunchDescription([
        Node(
            package='turtlesim',
            # namespace='turtlesim1',
            executable='turtlesim_node',
            name='turtlesim_node'
        ),
        Node(
            package='cpp_template_pkg',
            executable='turtle_following_node',
            name='turtle_following_node',
            parameters=[config_file]
        )
    ])