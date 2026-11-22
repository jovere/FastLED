#pragma once

// IWYU pragma: private
#include "platforms/arm/rp/is_rp.h"

// ok no namespace fl

#ifdef FL_IS_RP
#if defined(ARDUINO)
#include "platforms/arduino/io_arduino.hpp"
#else
// Bare Pico SDK build (no Arduino core / Serial object).
#include "platforms/arm/rp/io_rp_bare.hpp"
#endif
#endif
