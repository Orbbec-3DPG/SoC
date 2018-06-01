#ifndef ORBBEC_3DPG_CAMERA_INFO_H_
#define ORBBEC_3DPG_CAMERA_INFO_H_
#pragma once

#include<string>
#include<orbbec_3dpg.h>

namespace Orbbec_3dpg
{

struct ORBBEC_3DPG_API CameraInformation
{
    /**
     * The serial number.
     */
    std::string serial;

    /**
     * The firmware version.
     */
    std::string version;

    /**
     * The product name.
     */
    std::string product;

    /**
     * The manufacturer name.
     */
    std::string manufacturer;

    /**
     * The product id.
     */
    uint16_t product_id;

    /**
     * The vendor id.
     */
    uint16_t vendor_id;

    Status Load(const std::string &filepath);
    Status Save(const std::string &filepath);

};

} // namespace Orbbec_3dpg

ORBBEC_3DPG_API std::ostream &operator <<(std::ostream &os, const Orbbec_3dpg::CameraInformation &info);
#endif // ORBBEC_3DPG_CAMERA_INFO_H_
