/**
  * @defgroup Enumeration types
  */

#ifndef ORBBEC_3DPG_H_
#define ORBBEC_3DPG_H_
#pragma once
#include <ostream>
#include <cstdint>

//#TODO doxygen
#define STRINGIFY_HELPER(X) #X
#define STRINGIFY(X) STRINGIFY_HELPER(X)

#ifdef _WIN32
    #define DECL_EXPORT __declspec(dllexport)
    #define DECL_IMPORT __declspec(dllimport)
    #define DECL_HIDDEN
#else
    #define DECL_EXPORT __attribute__((visibility("default")))
    #define DECL_IMPORT __attribute__((visibility("default")))
    #define DECL_HIDDEN __attribute__((visibility("hidden")))
#endif

#ifdef DOXYGEN_WORKING

#define ORBBEC_3DPG_API

#else

#ifdef ORBBEC_3DPG_EXPORTS
    #define ORBBEC_3DPG_API DECL_EXPORT
#else
    #define ORBBEC_3DPG_API DECL_IMPORT
#endif

#endif

#if defined(CXX11) || defined(CXX0X)
    #define ENUM(name) enum class name : std::int8_t
#else
    #define ENUM(name) enum name
#endif


/**
  * Orbbec_3dpg namespace
  */
namespace Orbbec_3dpg
{

ENUM(Status)
{
    /** Standard code for successful behavior. */
    SUCCESS = 0,
    /** Standard code for unsuccessful behavior. */
    ERROR_FAILURE,
//    ERROR_FILE_OPEN_FAILED,
//    ERROR_CAMERA_OPEN_FAILED,
//    ERROR_CAMERA_NOT_OPENED,
//    ERROR_CAMERA_GRAB_FAILED,
//    ERROR_CAMERA_GRAB_TIMEOUT,
//    ERROR_CAMERA_RETRIEVE_FAILED,
//    ERROR_CAMERA_RETRIVE_NOT_READY,
//    ERROR_FEATURE_NOT_ACTIVATED,
//    ERROR_LAST
};

//ENUM(Mode) {
//    /** Auto detect. */
//    MODE_AUTO_DETECT,
//    /** CPU. */
//    MODE_CPU,
//    /** GPU. */
//    MODE_GPU,
//    /** Last guard. */
//    MODE_LAST
//};

//#TODO arbitrary values for Rate, need to modify later
ENUM(Rate) {
    /** Image 50 FPS, IMU 500 Hz. */
    RATE_50_FPS_500_HZ,
    /** Image 25 FPS, IMU 500 Hz. */
    RATE_25_FPS_500_HZ,
    /** Image 10 FPS, IMU 200 Hz. */
    RATE_10_FPS_200_HZ,
    /** Last guard. */
    RATE_LAST
};

ENUM(ExposureSettings) {
    /**
     * Auto-exposure mode.
     *
     *   0: auto-exposure
     *   1: manual-exposure
     *
     * @note If auto-exposure is enabled, desired-brightness, max-gain and max-exposure-time could be set.
     * @note If manual-exposure is enabled, brightness, contrast and gain could be set.
     */
    CT_PROP_AUTO_EXPOSURE_MODE,
    /**
     * Brightness.
     *
     * The value range is `[0,240]`.
     */
    CT_PROP_BRIGHTNESS,
    /**
     * Contrast.
     *
     * The value range is `[0,255]`.
     */
    CT_PROP_CONTRAST,
    /**
     * Gain.
     *
     * The value range is `[0,48]`.
     */
    CT_PROP_GAIN,
    /**
     * Desired brightness.
     *
     * The value range is `[0,255]`.
     */
    CT_PROP_DESIRED_BRIGHTNESS,
    /**
     * Max exposure time.
     *
     * The value range is `[0,240]`.
     */
    CT_PROP_MAX_EXPOSURE_TIME,
    /**
     * Max gain.
     *
     * The value range is `[0,48]`.
     */
    CT_PROP_MAX_GAIN,
    /**
     * IR intensity.
     *
     * The value range is `[0,160]`.
     */
    CT_PROP_IR_CONTROL,
    /**
     * HDR.
     *
     * The value range is `[0,1]`.
     */
    CT_PROP_HDR,
    /** Last guard. */
    CT_PROP_LAST
};

ENUM(ImageProcess) {
    /** Process grab. */
    PROC_GRAB,
    /** Process rectification. */
    PROC_RECTIFY,
    /** Process depth map. */
    PROC_DEPTH_MAP,
    /** Process point cloud. */
    PROC_POINT_CLOUD,
    /** Last guard. */
    PROC_LAST
};

/**
 * @ingroup enumerations
 * @brief firmware version.
 */
ENUM(FirmWare) {
    /** general version. */
    FW_GENERAL,
    /** no more than 1.5. */
    FW_NO_MORE_THAN_0105,
    /** more than 1.5. */
    FW_MORE_THAN_0105,
    /** Last guard. */
    FW_LAST
};
} // namespace Orbbec_3dpg

ORBBEC_3DPG_API std::ostream &operator<<(std::ostream &os, const Orbbec_3dpg::Status &code);
//ORBBEC_3DPG_API std::ostream &operator<<(std::ostream &os, const Orbbec_3dpg::Mode &mode);
//ORBBEC_3DPG_API std::ostream &operator<<(std::ostream &os, const Orbbec_3dpg::View &view);
ORBBEC_3DPG_API std::ostream &operator<<(std::ostream &os, const Orbbec_3dpg::Rate &rate);
ORBBEC_3DPG_API std::ostream &operator<<(std::ostream &os, const Orbbec_3dpg::ExposureSettings &exposure);
ORBBEC_3DPG_API std::ostream &operator<<(std::ostream &os, const Orbbec_3dpg::ImageProcess &proc);
//ORBBEC_3DPG_API std::ostream &operator<<(std::ostream &os, const Orbbec_3dpg::Gravity &gravity);
ORBBEC_3DPG_API std::ostream &operator<<(std::ostream &os, const Orbbec_3dpg::FirmWare &firmware);
#endif // ORBBEC_3DPG_H_
