# Project README

## Overview
This project is a simple audio player application that plays different sounds when specific keys are pressed. It uses custom libraries for window and audio handling.

## Features
- Plays sound effects on key press (W, A, S, D).
- Supports multiple operating systems via Makefiles.

## Project Structure
```
Gui_AudioPlayer/
├── build/              # Compiled binaries
├── src/                # Source code directory
│   ├── Main.c          # Entry point of the application
│   └── *.h             # Header files
├── sound/              # Directory containing audio files (WAV format)
├── Makefile.linux      # Linux build configuration
├── Makefile.windows    # Windows build configuration
├── Makefile.wine       # Wine build configuration for Windows cross-compilation
├── Makefile.web        # Emscripten build configuration for WebAssembly
└── README.md           # This file
```

### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools
- ALSA library for Linux audio handling
- X11 library for window management on Linux

## Build & Run
### Linux
To build and run the application on Linux:
```sh
cd Gui_AudioPlayer
make -f Makefile.linux all
./build/Main
```

### Windows
To build and run the application on Windows using MinGW:
```sh
cd Gui_AudioPlayer
make -f Makefile.windows all
build\Main.exe
```

### Wine (Windows cross-compilation)
To compile for Windows using Wine:
```sh
cd Gui_AudioPlayer
make -f Makefile.wine all
wine build\Main.exe
```

### WebAssembly
To compile and run the application in a web browser:
```sh
cd Gui_AudioPlayer
make -f Makefile.web all
emrun --no_browser --port 8080 build/index.html
```

These commands will help you build, clean, and execute your project across different environments.