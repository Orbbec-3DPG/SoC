#ifndef ORBBEC_3DPG_RESOLUTION_H_
#define ORBBEC_3DPG_RESOLUTION_H_
#pragma once

#include <orbbec_3dpg.h>

namespace Orbbec_3dpg {

/**
 * Image resolution about width and height.
 */
struct ORBBEC_3DPG_API Resolution {
    std::int32_t width;   /**< image width in pixels */
    std::int32_t height;  /**< image height in pixels */

    /** Constructor. */
    Resolution(const std::int32_t &w = 0, const std::int32_t &h = 0);
    /** Destructor. */
    ~Resolution();

    /**
     * Returns the area of the image.
     * @return The number of pixels of the image.
     */
    std::int32_t Area() const;

    /**
     * Tests if the given Resolution has the same properties.
     * @param that the given Resolution.
     * @see operator!=()
     * @return True if same, false different.
     */
    bool operator==(const Resolution &that) const;

    /**
     * Tests if the given Resolution has different properties.
     * @param that the given Resolution.
     * @see operator==()
     * @return True if same, false different.
     */
    bool operator!=(const Resolution &that) const;
};

}  // namespace Orbbec_3dpg

ORBBEC_3DPG_API std::ostream &operator<<(std::ostream &os, const Orbbec_3dpg::Resolution &res);
#endif // ORBBEC_3DPG_RESOLUTION_H_
