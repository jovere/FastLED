#pragma once

// IWYU pragma: private

/// @file io_rp_bare.hpp
/// Serial I/O for bare Pico SDK builds (RP2040/RP2350 without an Arduino core).
///
/// There is no Arduino Serial object, so output is discarded and input is
/// always empty (same policy as io_stm32_bare.hpp). Applications that want
/// FastLED's diagnostics can route pico_stdio themselves.

#include "platforms/io.h"
#include "fl/stl/noexcept.h"

namespace fl {
namespace platforms {

void begin(u32 baudRate) FL_NO_EXCEPT { (void)baudRate; }

void print(const char* str) FL_NO_EXCEPT { (void)str; }

void println(const char* str) FL_NO_EXCEPT { (void)str; }

int available() FL_NO_EXCEPT { return 0; }

int peek() FL_NO_EXCEPT { return -1; }

int read() FL_NO_EXCEPT { return -1; }

int readLineNative(char delimiter, fl::string& out) FL_NO_EXCEPT {
    (void)delimiter;
    (void)out;
    return -1;
}

bool flush(u32 timeoutMs) FL_NO_EXCEPT {
    (void)timeoutMs;
    return true;
}

size_t write_bytes(const u8* buffer, size_t size) FL_NO_EXCEPT {
    (void)buffer;
    return size;
}

bool serial_ready() FL_NO_EXCEPT { return false; }

bool serial_is_buffered() FL_NO_EXCEPT { return false; }

}  // namespace platforms
}  // namespace fl
