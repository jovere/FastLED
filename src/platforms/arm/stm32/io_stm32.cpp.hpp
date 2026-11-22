#pragma once

// IWYU pragma: private
#include "platforms/arm/stm32/is_stm32.h"

// ok no namespace fl

#if defined(FL_IS_STM32_BARE)
#include "platforms/arm/stm32/io_stm32_bare.hpp"
#elif defined(FL_IS_STM32)
#include "platforms/arduino/io_arduino.hpp"
#endif
