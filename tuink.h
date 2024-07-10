// tuink.h - v0.1.0 - public domain Levent Kaya 2024
// Library for creating Immediate Mode Text User Interfaces
//
// This file provides both the interface and the implementation.
// To instantiate the implementation,
//      #define TUINK_IMPLEMENTATION
// in *ONE* source file, before #including this file.
//
//
// History:
//      0.0.1: First public Release
//
// Status:
//      Lack of many functionalities (10/07/2024)
//
// Contributors:
//
// LICENSE
//
//   See end of file for license information.

#ifndef TUINK_H_
#define TUINK_H_

#ifdef __cplusplus
extern "C" {
#endif

// =============================================================================
//                                  HEADER
// =============================================================================
#include <termios.h>
#include <stdio.h>

// =============================================================================
//                                  MACROS
// =============================================================================
#define MAJOR_VERSION 0
#define MINOR_VERSION 1
#define PATCH_VERSION 0

// -----------------------------------------------------------------------------
//                                 Utility functions
// -----------------------------------------------------------------------------

static inline char *tuink_current_version()
{
	static char version[16];
	snprintf(version, sizeof(version), "%d.%d.%d", MAJOR_VERSION,
		 MINOR_VERSION, PATCH_VERSION);
	return version;
}

// -----------------------------------------------------------------------------
//                                  Structures
// -----------------------------------------------------------------------------

typedef struct tuink_screen {
	int x;
	int y;
} tuink_screen_t;

// -----------------------------------------------------------------------------
//                                Function declarations
// -----------------------------------------------------------------------------

// Example function declarations
void tuink_init();
void tuink_cleanup();

// -----------------------------------------------------------------------------
//                                 Implementation
// -----------------------------------------------------------------------------

#ifdef TUINK_IMPLEMENTATION
void tuink_init()
{
	printf("%s\n", tuink_current_version());
}
#endif // TUINK_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // TUINK_H_

/*
------------------------------------------------------------------------------
This software is available under 2 licenses -- choose whichever you prefer.
------------------------------------------------------------------------------
ALTERNATIVE A - MIT License
Copyright (c) 2017 Levent Kaya
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
------------------------------------------------------------------------------
ALTERNATIVE B - Public Domain (www.unlicense.org)
This is free and unencumbered software released into the public domain.
Anyone is free to copy, modify, publish, use, compile, sell, or distribute this
software, either in source code form or as a compiled binary, for any purpose,
commercial or non-commercial, and by any means.
In jurisdictions that recognize copyright laws, the author or authors of this
software dedicate any and all copyright interest in the software to the public
domain. We make this dedication for the benefit of the public at large and to
the detriment of our heirs and successors. We intend this dedication to be an
overt act of relinquishment in perpetuity of all present and future rights to
this software under copyright law.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
------------------------------------------------------------------------------
*/