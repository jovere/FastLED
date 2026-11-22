// ok no namespace fl
#pragma once

// IWYU pragma: private

/// @file led_sysdefs_stm32_bare.h
/// LED system definitions for bare-metal STM32 builds (FASTLED_STM32_BARE).
/// See platforms/arm/stm32/stm32_bare.h for what the application must provide.

#include "platforms/is_platform.h"
#include "fl/stl/stdint.h"

#ifndef FL_IS_STM32_BARE
#error "This header is only for bare-metal STM32 builds (FASTLED_STM32_BARE)"
#endif

#include "platforms/arm/stm32/stm32_bare.h"

// ============================================================================
// CPU Frequency
// ============================================================================
// Default to the CMSIS SystemCoreClock variable (runtime value, kept current
// by SystemCoreClockUpdate()), matching STM32duino. Define F_CPU yourself to
// use a compile-time constant instead.
#ifndef F_CPU
  #define F_CPU SystemCoreClock
#endif
