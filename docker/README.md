# Dockerイメージのビルド
```
docker build -t ros2_template_ws_img .
```

# Xサーバーの設定
```
xhost +local:
```

# Dockerコンテナの起動
- /PATH/TO/ros2_template_wsをホストマシン上のROSワークスペースの絶対パスに置き換えてください
```
docker run -it \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    --device=/dev/dri \
    -v /PATH/TO/ros2_template_ws:/root/ros2_template_ws \
    --name ros2_template_ws_cont \
    ros2_template_ws_img 
```

# コンテナに再接続
```
docker start ros2_template_ws_cont
docker attach ro2_template_ws_cont
```

# 別のターミナルからコンテナに入る
```
docker exec -it ros2_template_ws_cont /bin/bash
```
