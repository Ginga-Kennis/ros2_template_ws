# Dockerイメージのビルド
```
docker-compose build
```

# Xサーバーの設定
```
xhost +local:
```

# Dockerコンテナの起動
- `docker-compose.yml` 内の/PATH/TO/ros2_template_wsをホストマシン上のワークスペースの絶対パスに置き換えてください

```
docker-compose up
```

# コンテナに再接続
```
docker-compose start
docker attach ros2_template_ws_cont
```

# 別のターミナルからコンテナに入る
```
docker exec -it ros2_template_ws_cont /bin/bash
```
