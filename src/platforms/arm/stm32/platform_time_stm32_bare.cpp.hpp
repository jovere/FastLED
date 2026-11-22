#pragma once

// IWYU pragma: private

/// @file platform_time_stm32_bare.cpp.hpp
/// fl::platforms timing for bare-metal STM32 builds (FASTLED_STM32_BARE).
/// millis()/micros() come from the application; delays are built on micros().

#include "platforms/arm/stm32/is_stm32.h"

#if defined(FL_IS_STM32_BARE)

#include "platforms/time_platform.h"
#include "platforms/arm/stm32/stm32_bare.h"

namespace fl {
namespace platforms {

fl::u32 millis() FL_NO_EXCEPT { return ::millis(); }

fl::u32 micros() FL_NO_EXCEPT { return ::micros(); }

void delayMicroseconds(fl::u32 us) FL_NO_EXCEPT {
    const fl::u32 start = ::micros();
    while (static_cast<fl::u32>(::micros() - start) < us) {
    }
}

void delay(fl::u32 ms) FL_NO_EXCEPT {
    while (ms--) {
        delayMicroseconds(1000);
    }
}

}  // namespace platforms
}  // namespace fl

#endif  // FL_IS_STM32_BARE
