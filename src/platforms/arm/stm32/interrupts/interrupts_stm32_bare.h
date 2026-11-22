// ok no namespace fl
#pragma once

// IWYU pragma: private

/// @file interrupts_stm32_bare.h
/// Interrupt control for bare-metal STM32 builds (FASTLED_STM32_BARE)
///
/// Interrupt control is provided by fl::interruptsDisable() and
/// fl::interruptsEnable() in fl/isr.h (implemented in isr_stm32.hpp), which
/// use the CMSIS __disable_irq()/__enable_irq() intrinsics.

#include "platforms/is_platform.h"

#ifndef FL_IS_STM32_BARE
#error "This header is only for bare-metal STM32 builds (FASTLED_STM32_BARE)"
#endif
