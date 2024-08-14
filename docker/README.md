# Build Docker image
```
sudo docker build -t ros2_template_ws_img .
```

# Set up X server
```
xhost +local:
```

# Run Docker container
```
sudo docker run -it \
    -e DISPLAY=$DISPLAY \
    --user oinarisan \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v /home/oinarisan/ros2_template_ws:/ros2_template_ws \
    --name ros2_template_ws_cont \
    ros2_template_ws_img /bin/bash
```

# Reconnect to the container
```
sudo docker start ros2_template_ws_container
sudo docker attach ro2_template_ws_container
```

# Enter the container from another terminal
```
sudo docker exec -it ros2_template_ws_container /bin/bash
```
