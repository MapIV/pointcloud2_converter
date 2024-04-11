#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <sensor_msgs/PointCloud2.h>

#include "pointcloud2_converter/point_type.hpp"
#include <map4_point_type/map4_point_type.h>

int main(int argc, char **argv) {
  // Specify the bag file path
  std::string input_bagfile = argv[1];
  std::string topic_name = argv[2];
  std::string output_bagfile = argv[3];

  // Open the bag file
  rosbag::Bag input_bag;
  input_bag.open(input_bagfile, rosbag::bagmode::Read);

  // Create a view to read messages from the bag file
  rosbag::View view(input_bag);

  // Iterate through the messages in the bag file
  rosbag::Bag output_bag(output_bagfile, rosbag::bagmode::Write);
  for (const rosbag::MessageInstance &m : view) {
    if (m.getTopic() == topic_name) {

      // Convert the PointCloud2 message to pcl::PointCloud
      sensor_msgs::PointCloud2::ConstPtr cloud_msg =
          m.instantiate<sensor_msgs::PointCloud2>();
      pcl::PointCloud<PointXYZIRS>::Ptr cloud(new pcl::PointCloud<PointXYZIRS>);
      pcl::fromROSMsg(*cloud_msg, *cloud);

      pcl::PointCloud<PointXYZIRT>::Ptr out_cloud(
          new pcl::PointCloud<PointXYZIRT>);

      double first_timestamp = (*cloud)[0].timestamp;
      for (const auto &pi : *cloud) {
        PointXYZIRT po;
        po.getVector3fMap() = pi.getVector3fMap();
        po.intensity = pi.intensity;
        po.ring = pi.ring;
        po.time = float(pi.timestamp - first_timestamp) * 1.0e-9;
        out_cloud->push_back(po);
      }

      sensor_msgs::PointCloud2 out_msg;
      pcl::toROSMsg(*out_cloud, out_msg);
      out_msg.header = cloud_msg->header;
      out_msg.height = cloud_msg->height;
      out_msg.width = cloud_msg->width;
      output_bag.write(m.getTopic(), m.getTime(), out_msg);
    } else {
      output_bag.write(m.getTopic(), m.getTime(), m);
    }

    // Now 'cloud' contains the converted point cloud data
    // You can perform further processing on 'cloud' as needed
  }

  return 0;
}
