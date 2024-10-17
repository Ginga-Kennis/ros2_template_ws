# ros2_template_ws

このリポジトリは、ROS2の基本的な機能をカバーしたテンプレートワークスペースです。  
launchファイルやサービス、トピックなど、ROS2のさまざまな機能を実装するための基本的なパッケージ構成を提供しています。  

## 環境構築

環境構築の手順については、`ros2_template_ws/docker/README.md`の内容に従って進めてください。  

## ROS2を使ったプログラミング
### 1. ワークスペースの作成 & ビルド
ワークスペースの作成
```bash
mkdir -p ~/ros2_ws/src
```
ワークスペースのビルド
```bash
cd ~/ros2_ws
colcon build [オプション]
```
| オプション              | 説明                                          |
|-------------------------|---------------------------------------------|
| `--symlink-install`      | Pythonファイルやリソースを変更した際にビルドが不要 |
| `--packages-select PKG`   | 指定したPKGパッケージのみをビルド               |
| `--packages-skip PKG`    | 指定したPKGパッケージをスキップしてビルド         |

環境のソース
```bash
source install/setup.bash
```
| オプション              | 説明                                          |
|-------------------------|---------------------------------------------|
| `install/steup.bash`      |  underlay + overlay |
| `install/local_steup.bash`   | overlay |


