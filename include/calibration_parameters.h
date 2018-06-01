#ifndef ORBBEC_3DPG_CALIBRATION_PARAMETERS_H_
#define ORBBEC_3DPG_CALIBRATION_PARAMETERS_H_
#pragma once

#include <string>
#include <orbbec_3dpg.h>
#include <opencv2/core/core.hpp>

namespace Orbbec_3dpg
{

struct ORBBEC_3DPG_API CalibrationParameters
{
    // Intrinsic parameters

    /**
     * Input/output left camera matrix.
     * @see cameraMatrix1 parameter of <a href="http://docs.opencv.org/master/d9/d0c/group__calib3d.html#ga246253dcc6de2e0376c599e7d692303a">stereoCalibrate()</a>
     */
    cv::Mat M1;

    /**
     * Input/output lens distortion coefficients for left camera.
     * @see distCoeffs1 parameter of <a href="http://docs.opencv.org/master/d9/d0c/group__calib3d.html#ga246253dcc6de2e0376c599e7d692303a">stereoCalibrate()</a>
     */
    cv::Mat D1;

    /**
     * Input/output right camera matrix.
     * @see cameraMatrix1 parameter of <a href="http://docs.opencv.org/master/d9/d0c/group__calib3d.html#ga246253dcc6de2e0376c599e7d692303a">stereoCalibrate()</a>
     */
    cv::Mat M2;

    /**
     * Input/output lens distortion coefficients for right camera.
     * @see distCoeffs2 parameter of <a href="http://docs.opencv.org/master/d9/d0c/group__calib3d.html#ga246253dcc6de2e0376c599e7d692303a">stereoCalibrate()</a>
     */
    cv::Mat D2;

    // Extrinsic parameters

    /**
     * Output rotation matrix between left and right camera coordinate systems.
     * @see R parameter of <a href="http://docs.opencv.org/master/d9/d0c/group__calib3d.html#ga246253dcc6de2e0376c599e7d692303a">stereoCalibrate()</a>
     */
    cv::Mat R;

    /**
     * Output translation vector between the coordinate systems of the cameras.
     * @see T parameter of <a href="http://docs.opencv.org/master/d9/d0c/group__calib3d.html#ga246253dcc6de2e0376c599e7d692303a">stereoCalibrate()</a>
     */
    cv::Mat T;

    CalibrationParameters();
    CalibrationParameters(const cv::Mat &M1, const cv::Mat &D1,
                          const cv::Mat &M2, const cv::Mat &D2,
                          const cv::Mat &R, const cv::Mat &T);
    ~CalibrationParameters();

    Status Load(const std::string &filepath);
    Status Load(const std::string &intrinsic_filepath, const std::string &extrinsic_filepath);
    Status Save(const std::string &filepath);

};
}
ORBBEC_3DPG_API std::ostream &operator<<(std::ostream &os, const Orbbec_3dpg::CalibrationParameters &params);

#endif // ORBBEC_3DPG_CALIBRATION_PARAMETERS_H_
