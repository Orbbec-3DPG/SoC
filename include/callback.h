#ifndef ORBBEC_3DPG_CALLBACK_H_
#define ORBBEC_3DPG_CALLBACK_H_
#pragma once

#include <functional>
#include <opencv2/core/core.hpp>
#include <orbbec_3dpg.h>

namespace Orbbec_3dpg
{

using ErrorCallback = std::function<void(const Status &code)>;
using ProcessCallback = std::function<void(cv::Mat &image)>;
using ProcessCallbackStereo = std::function<void(cv::Mat &imageLeft, cv::Mat &imageRight)>;

using GrabErrorCallback = ErrorCallback;
using GrabPreProcessCallback = std::function<void()>;
using GrabPostProcessCallback = ProcessCallbackStereo;

using RectifyPreProcessCallback = ProcessCallback;
using RectifyPostProcessCallback = ProcessCallbackStereo;

using DepthMapPreProcessCallback = ProcessCallback;
using DepthMapPostProcessCallback = ProcessCallbackStereo;

using PointCloudPreProcessCallback = ProcessCallback;
using PointCloudPostProcessCallback = ProcessCallbackStereo;

} // namespace Orbbec_3dpg


#endif // ORBBEC_3DPG_CALLBACK_H_
