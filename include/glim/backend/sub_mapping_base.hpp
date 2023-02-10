#pragma once

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <opencv2/core.hpp>

#include <glim/frontend/estimation_frame.hpp>
#include <glim/backend/sub_map.hpp>

namespace glim {

/**
 * @brief Sub mapping base class
 *
 */
class SubMappingBase {
public:
  virtual ~SubMappingBase() {}

  /**
   * @brief Insert an image
   * @param stamp   Timestamp
   * @param image   Image
   */
  virtual void insert_image(const double stamp, const cv::Mat& image);

  /**
   * @brief Insert an IMU data
   * @param stamp         Timestamp
   * @param linear_acc    Linear acceleration
   * @param angular_vel   Angular velocity
   */
  virtual void insert_imu(const double stamp, const Eigen::Vector3d& linear_acc, const Eigen::Vector3d& angular_vel);

  /**
   * @brief Insert an odometry estimation frame
   * @param odom_frame  Marginalized odometry estimation frame
   */
  virtual void insert_frame(const EstimationFrame::ConstPtr& frame);

  /**
   * @brief Get the created submaps
   * @return Created submaps
   */
  virtual std::vector<SubMap::Ptr> get_submaps() = 0;

  /**
   * @brief Submit the signal to tell end of sequence and collect the remaining submap data
   * @return std::vector<SubMap::Ptr>
   */
  virtual std::vector<SubMap::Ptr> submit_end_of_sequence() { return std::vector<SubMap::Ptr>(); }
};
}