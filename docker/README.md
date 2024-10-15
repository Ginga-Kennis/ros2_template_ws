# Xサーバーの設定
- GUI を使用するためのコマンド
```
xhost +local:
```

# Dockerコンテナの作成 & 起動
- `docker-compose.yml` 内の /PATH/TO/ros2_template_ws をホストマシン上の ros2_template_ws の絶対パスに置き換えてください
```
docker compose up -d
```

# コンテナに入る
```
docker exec -it ros2_template_ws_cont /bin/bash
```

# コンテナから抜ける
コンテナ内で `exit` と入力，もしくは `Ctrl + d` を実行

