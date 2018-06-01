#ifndef ORBBEC_3DPG_INIT_PARAMETERS_H_
#define ORBBEC_3DPG_INIT_PARAMETERS_H_
#pragma once

#include <calibration_parameters.h>
#include <string>
#include <orbbec_3dpg.h>

namespace Orbbec_3dpg
{

struct ORBBEC_3DPG_API InitParameters
{
    /**
     * Camera name or index.
     *
     * default values:
     *   - Windows: MYNTEYE
     *   - Mac: 0
     *   - Linux: 0
     */
    std::string name;

    /**
     * Camera framerate & IMU frequency.
     *
     * default: ::RATE_LAST, ignored
     *
     * @note Only supported on Linux now.
     */
    Rate rate;

    /**
     * Calibration parameters.
     *
     * If not specified, we will download from our server by serial number.
     *
     * default: nullptr
     */
    const CalibrationParameters *calib_params;

    InitParameters();
    InitParameters(const std::string &name,
                   const CalibrationParameters *calib_params = nullptr);
    InitParameters(const std::string &name,
                   const Rate &rate,
                   const CalibrationParameters *calib_params = nullptr);
    ~InitParameters();

    Status Load(const std::string &filename);
    Status Save(const std::string &filename);
};

}

ORBBEC_3DPG_API std::ostream &operator <<(std::ostream &os, const Orbbec_3dpg::InitParameters &params);

#endif // ORBBEC_3DPG_INIT_PARAMETERS_H_
