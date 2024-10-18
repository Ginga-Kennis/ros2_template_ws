# Docker のインストール（OS : Ubuntu）
### インストール
```
curl -fsSL https://get.docker.com -o get-docker.sh # Dockerインストールスクリプトをダウンロード
sudo sh ./get-docker.sh                           # スクリプトを実行してDockerをインストール
```
### インストール後のセットアップ
```
sudo groupadd docker          # 'docker' グループを作成（既に存在する場合は無視される）
sudo usermod -aG docker $USER # 現在のユーザーを 'docker' グループに追加
newgrp docker                 # グループ変更を反映させる
docker run hello-world        # Dockerのインストール確認
```

# Docker の使い方
### Xサーバーの設定
- GUI を使用するためのコマンド
```
xhost +local:
```

### Dockerコンテナの作成 & 起動
- `docker-compose.yml` 内の指定された箇所の変更が必要
```
docker compose up -d
```

### コンテナに入る
```
docker exec -it ros2_template_ws_cont /bin/bash
```

### コンテナから抜ける
コンテナ内で `exit` と入力，もしくは `Ctrl + d` を実行

