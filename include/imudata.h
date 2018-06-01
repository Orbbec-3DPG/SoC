#ifndef ORBBEC_3DPG_IMUDATA_H_
#define ORBBEC_3DPG_IMUDATA_H_
#pragma once

#include"orbbec_3dpg.h"
namespace Orbbec_3dpg
{
    /**
     * IMU (inertial measurement unit) data.
     */

struct ORBBEC_3DPG_API IMUData
{
    std::uint32_t time;
    std::int16_t time_offset;

    //accelerometer
    float acc_x;
    float acc_y;
    float acc_z;

    //gyro
    float gyro_x;
    float gyro_y;
    float gyro_z;

    //#TODO maybe raw acc, gyro and quaternion or put in another header file
//    //accelerometer
//    float acc_raw_x;
//    float acc_raw_y;
//    float acc_raw_z;

//    //gyro
//    float gyro_raw_x;
//    float gyro_raw_y;
//    float gyro_raw_z;

      //quat
//    float quaternion_x;
//    float quaternion_y;
//    float quaternion_z;
//    float quaternion_w;

    //temperature
    float tempeture;

};
}   // namespace Orbbec_3dpg

ORBBEC_3DPG_API std::ostream &operator <<(std::ostream &os, const Orbbec_3dpg::IMUData &data);


#endif // ORBBEC_3DPG_IMUDATA_H_
