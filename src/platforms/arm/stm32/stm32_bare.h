// ok no namespace fl
#pragma once

// IWYU pragma: private

/// @file stm32_bare.h
/// Shared definitions for bare-metal STM32 builds (-DFASTLED_STM32_BARE).
///
/// Bare-metal mode is for projects built directly on ST's CMSIS device headers
/// (STM32CubeMX, LL or HAL drivers, plain CMake/Make) without any Arduino core.
///
/// The application must:
/// - Define the STM32 family macro (e.g. -DSTM32F4xx) next to the usual CMSIS
///   device macro (e.g. -DSTM32F411xE), and put the CMSIS Device and Core
///   include directories on the include path.
/// - Provide a millisecond and a microsecond clock with C linkage:
///       extern "C" uint32_t millis(void);
///       extern "C" uint32_t micros(void);
///   (e.g. from SysTick, HAL_GetTick() or a free-running timer). FastLED
///   builds delay()/delayMicroseconds() on top of these.
/// - Enable the RCC clock of any GPIO port it asks FastLED to drive.
///
/// Serial I/O (FL_WARN, fl::print, ...) is a no-op in this mode.

#include "fl/stl/stdint.h"
#include "fl/stl/has_include.h"
#include "fl/stl/noexcept.h"

// CMSIS device header: register definitions, DWT, __disable_irq(), ...
#if (defined(STM32F1) || defined(STM32F1xx) || defined(STM32F10X_MD)) && FL_HAS_INCLUDE("stm32f1xx.h")
  #include "stm32f1xx.h"  // ok include
#elif (defined(STM32F2XX) || defined(STM32F2xx)) && FL_HAS_INCLUDE("stm32f2xx.h")
  #include "stm32f2xx.h"  // ok include
#elif (defined(STM32F4) || defined(STM32F4xx)) && FL_HAS_INCLUDE("stm32f4xx.h")
  #include "stm32f4xx.h"  // ok include
#elif (defined(STM32F7) || defined(STM32F7xx)) && FL_HAS_INCLUDE("stm32f7xx.h")
  #include "stm32f7xx.h"  // ok include
#elif (defined(STM32L4) || defined(STM32L4xx)) && FL_HAS_INCLUDE("stm32l4xx.h")
  #include "stm32l4xx.h"  // ok include
#elif (defined(STM32H7) || defined(STM32H7xx)) && FL_HAS_INCLUDE("stm32h7xx.h")
  #include "stm32h7xx.h"  // ok include
#elif (defined(STM32G0) || defined(STM32G0xx)) && FL_HAS_INCLUDE("stm32g0xx.h")
  #include "stm32g0xx.h"  // ok include
#elif (defined(STM32G4) || defined(STM32G4xx)) && FL_HAS_INCLUDE("stm32g4xx.h")
  #include "stm32g4xx.h"  // ok include
#elif (defined(STM32U5) || defined(STM32U5xx)) && FL_HAS_INCLUDE("stm32u5xx.h")
  #include "stm32u5xx.h"  // ok include
#else
  #error "FASTLED_STM32_BARE: STM32 family not detected or its CMSIS device header (e.g. stm32f4xx.h) is not on the include path. Define the family macro (e.g. -DSTM32F4xx) and add the CMSIS Device/Include directory."
#endif

// Clock functions supplied by the application. Same declarations as the
// stub platform (platforms/stub/time_stub.h) so the two never conflict.
extern "C" {
    fl::u32 millis(void) FL_NO_EXCEPT;
    fl::u32 micros(void) FL_NO_EXCEPT;
}
