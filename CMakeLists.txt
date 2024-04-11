cmake_minimum_required(VERSION 2.8.3)
project(pointcloud2_converter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(catkin REQUIRED COMPONENTS
  pcl_ros
  sensor_msgs
  map4_point_type
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES pointcloud2_converter
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(pointcloud2_converter src/pointcloud2_converter.cpp)
target_link_libraries(pointcloud2_converter ${catkin_LIBRARIES})
add_dependencies(pointcloud2_converter ${catkin_EXPORTED_TARGETS})
