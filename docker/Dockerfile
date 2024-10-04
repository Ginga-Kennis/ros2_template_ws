FROM osrf/ros:humble-desktop-full

# ビルドプロセス中の対話型プロンプトを防止
ENV DEBIAN_FRONTEND=noninteractive

# 必要なツールのインストール
RUN apt-get update && apt-get install -y \
    vim \
    git \
    && rm -rf /var/lib/apt/lists/*

# 初期ディレクトリをルートディレクトリに設定
WORKDIR /root

RUN echo "source /opt/ros/humble/setup.bash" >> /root/.bashrc 

# コンテナ起動時にデフォルトでbashシェルを開く
CMD ["bash"]
