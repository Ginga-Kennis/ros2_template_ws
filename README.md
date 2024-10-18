# ros2_template_ws

このリポジトリは、ROS2の基本的な機能をカバーしたテンプレートワークスペースです。  
launchファイルやサービス、トピックなど、ROS2のさまざまな機能を実装するための基本的なパッケージ構成を提供しています。  

## 環境構築

環境構築の手順については、`ros2_template_ws/docker/README.md`の内容に従って進めてください。  

## ROS2を使ったプログラミング
### 1. ワークスペースの作成 & ビルド
ワークスペースの作成
```bash
mkdir -p ~/ros2_template_ws/src
```
ワークスペースのビルド
```bash
cd ~/ros2_template_ws
colcon build [オプション]
```
| オプション              | 説明                                          |
|-------------------------|---------------------------------------------|
| `--symlink-install`      | Pythonファイルやリソースを変更した際にビルドが不要 |
| `--packages-select PKG`   | 指定したパッケージのみをビルド               |
| `--packages-skip PKG`    | 指定したパッケージをスキップしてビルド         |

環境のソース
```bash
source install/setup.bash
```
| オプション              | 説明                                          |
|-------------------------|---------------------------------------------|
| `install/steup.bash`      |  underlay + overlay |
| `install/local_steup.bash`   | overlay |

### 2. パッケージの作成
c++パッケージ
```bash
cd ~/ros2_template_ws/src
ros2 pkg create --build-type ament_cmake --license Apache-2.0 <package_name>
```
| 項目                     | 説明                                                  |
|--------------------------|-------------------------------------------------------|
| **CMakeLists.txt**        | パッケージ内のコードをビルドする方法を記述したファイル                   |
| **include/<package_name>**| パッケージのヘッダーを含むディレクトリ                        |
| **package.xml**           | パッケージに関するメタ情報を含むファイル                       |
| **src**                   | パッケージのソースコードを含むディレクトリ                       |

pythonパッケージ
```bash
cd ~/ros2_template_ws/src
ros2 pkg create --build-type ament_python --license Apache-2.0 <package_name>
```
| 項目                          | 説明                                                                |
|-------------------------------|---------------------------------------------------------------------|
| **package.xml**                | パッケージに関するメタ情報を含むファイル                                        |
| **resource/<package_name>**     | パッケージのマーカーを含むディレクトリ                                        |
| **setup.cfg**                  | パッケージに実行可能ファイルがある場合、`ros2 run` で認識できるようにするために必要なファイル |
| **setup.py**                   | パッケージのインストール方法を指示するファイル                                    |
| **<package_name>**             | パッケージと同じ名前のディレクトリで、`__init__.py` を含み、ソースコードを格納するディレクトリ |


### 3. Publish & Subscribe

シンプルなPublish & Subscribeの実装は、[cpp_pubsub](./src/cpp_pubsub)ディレクトリを参照してください。  

### 4. Service & Client

シンプルなService & Clientの実装は、[cpp_srvcli](./src/cpp_srvcli)ディレクトリを参照してください。 

### 5. Parameters

Parameterを使用したノードの実装は、[cpp_parameters](./src/cpp_parameters)ディレクトリを参照してください。