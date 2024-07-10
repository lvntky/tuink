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
#include <sys/ioctl.h>
#include <unistd.h>
    #include <string.h>

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
static inline void enable_raw_mode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
    static inline void move_cursor(int x, int y) {
        printf("\033[%d;%dH", y, x);
        printf(" ");  // Cursor represented by 'X'
        fflush(stdout);
    }

    static inline void draw_cursor(int x, int y) {
        move_cursor(x, y);
        printf(".");
        fflush(stdout);
    }

    // Function to clear the cursor at (x, y)
    static inline void clear_cursor(int x, int y) {
        move_cursor(x, y);
        printf(" ");
        fflush(stdout);
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
    void draw_button(int x, int y, int width, int height, const char *label) {
        move_cursor(x, y);
        printf("┏");
        for (int i = 0; i < width - 2; i++) printf("━");
        printf("┓");

        for (int i = 0; i < height - 2; i++) {
            move_cursor(x, y + i + 1);
            printf("┃");
            move_cursor(x + width - 1, y + i + 1);
            printf("┃");
        }

        move_cursor(x, y + height - 1);
        printf("┗");
        for (int i = 0; i < width - 2; i++) printf("━");
        printf("┛");

        move_cursor(x + (width - strlen(label)) / 2, y + height / 2);
        printf("%s", label);
        fflush(stdout);
    }
void tuink_init()
{
	enable_raw_mode();
        draw_button(10, 10, 20, 20, "TUINK v0.1.0");
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
