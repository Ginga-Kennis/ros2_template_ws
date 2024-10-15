# Xサーバーの設定
- GUI を使用するためのコマンド
```
xhost +local:
```

# Dockerコンテナの作成 & 起動
- `docker-compose.yml` 内の指定された箇所の変更が必要
```
docker compose up -d
```

# コンテナに入る
```
docker exec -it ros2_template_ws_cont /bin/bash
```

# コンテナから抜ける
コンテナ内で `exit` と入力，もしくは `Ctrl + d` を実行

