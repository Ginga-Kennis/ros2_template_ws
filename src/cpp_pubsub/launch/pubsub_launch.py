from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cpp_pubsub',
            # namespace='',
            executable='talker',
            name='talker'
        ),
        Node(
            package='cpp_pubsub',
            # namespace='',
            executable='listener',
            name='listener'
        )
    ])