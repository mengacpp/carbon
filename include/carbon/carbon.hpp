#pragma once

#if defined(_WIN32) || defined(__APPLE__)

#define CRBN

#else

#warning Carbon not tested on this platform. The library might not work as expected.

#endif

#include "core.hpp"

#include "cursor.hpp"
