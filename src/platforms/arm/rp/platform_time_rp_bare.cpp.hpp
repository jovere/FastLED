#pragma once

// IWYU pragma: private

/// @file platform_time_rp_bare.cpp.hpp
/// fl::platforms timing for bare Pico SDK builds (RP2040/RP2350 without an
/// Arduino core). Uses the SDK's 64-bit 1 MHz system timer.

#include "platforms/arm/rp/is_rp.h"

#if defined(FL_IS_RP) && !defined(ARDUINO)

#include "platforms/time_platform.h"
#include "pico/time.h"

namespace fl {
namespace platforms {

fl::u32 millis() FL_NO_EXCEPT {
    return static_cast<fl::u32>(to_ms_since_boot(get_absolute_time()));
}

fl::u32 micros() FL_NO_EXCEPT {
    return static_cast<fl::u32>(to_us_since_boot(get_absolute_time()));
}

void delayMicroseconds(fl::u32 us) FL_NO_EXCEPT { busy_wait_us_32(us); }

void delay(fl::u32 ms) FL_NO_EXCEPT { sleep_ms(ms); }

}  // namespace platforms
}  // namespace fl

#endif  // FL_IS_RP && !ARDUINO
