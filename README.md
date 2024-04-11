# Pointcloud2 Converter

This repository convert sensor_msgs::PointCloud2 msg for map4_engine

## Sensors

* Livox mid-360

## Install

```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
git clone https://github.com/MapIV/map4_point_type.git
git clone https://github.com/MapIV/pointcloud2_converter.git
cd ../
catkin_make -DCMAKE_BUILD_TYPE=Release
```

## Usage

```
./devel/lib/pointcloud2_converter/pointcloud2_converter <INPUT_BAGFILE> <TOPIC_NAME> <OUTPUT_BAGFILE>
```