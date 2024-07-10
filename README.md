# tuink - Immediate Mode Text User Interface Library

**Version:** v0.1.0
**Author:** Levent Kaya  
**License:** [MIT](./LICENSE) or [Public Domain](./LICENSE_2)

## Overview

`tuink` is a minimalistic library for creating Immediate Mode Text User Interfaces. It aims to provide a simple and easy-to-use interface for building text-based user interfaces in C.

## Getting Started

This library is designed to be header-only. To use `tuink` in your project, simply include `tuink.h` in your source files.

### Installation

Copy `tuink.h` to your project's include directory and include it in your source files.

### Usage

To instantiate the implementation, define `TUINK_IMPLEMENTATION` in **one** source file before including `tuink.h`.

```c
#define TUINK_IMPLEMENTATION
#include "tuink.h"

int main() {
    tuink_init();
    // Your code here
    tuink_cleanup();
    return 0;
}
```