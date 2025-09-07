# Geometric Shapes Drawing Application

A Windows desktop application for drawing geometric shapes using Win32 API and modern C++.

## Overview

This application provides an interactive GUI for creating and displaying various geometric shapes including circles, triangles, rectangles, and squares. Built with native Win32 API, it offers a lightweight and responsive user experience.

## Features

- **Interactive Shape Creation**: Draw circles, triangles, rectangles, and squares with customizable parameters
- **Modal Configuration Dialogs**: Configure shape properties (size, position, angles) before drawing
- **Random Positioning**: Option to randomly place shapes on the canvas
- **Shape Management**: Clear all shapes or remove the last added shape
- **Real-time Rendering**: Immediate visual feedback when adding shapes
- **Fullscreen Canvas**: Utilizes the entire screen for maximum drawing space

## Architecture

The application follows a clean Model-View architecture with the following components:

### Model Layer (`src/Model/`)
- `IFigure`: Abstract base class for all geometric shapes
- `Circle`, `Triangle`, `Rectangle`, `Square`: Concrete shape implementations
- `FigureFabric`: Factory pattern implementation for shape creation
- `EFigureType`: Enumeration of supported shape types

### GUI Layer (`src/GUI/`)
- `IWindow`: Base window interface
- `MainWindow`: Main application window with drawing canvas
- `ToolsWindow`: Base class for configuration dialogs
- `ToolsCircle`, `ToolsTriangle`, `ToolsRectangle`: Shape-specific configuration dialogs

### Common (`src/Common/`)
- `TransferParams`: Data transfer object for shape parameters

## Requirements

- Windows 10 or later
- Visual Studio 2022 or later
- CMake 3.3 or later
- C++20 compiler support

## Building from Source

### Prerequisites

1. Install Visual Studio 2022 with C++ desktop development workload
2. Install CMake (3.3 or later)

### Build Steps

```bash
# Clone the repository
git clone https://github.com/yourusername/geometric.git
cd geometric

# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build in Release mode
cmake --build . --config Release

# The executable will be in build/Release/geometric.exe
```

### Build Configurations

The project supports standard CMake build configurations:
- **Debug**: Includes debugging symbols, no optimization
- **Release**: Optimized build for distribution
- **RelWithDebInfo**: Optimized build with debugging symbols
- **MinSizeRel**: Optimized for minimal size

## Usage

1. Run `geometric.exe` to start the application
2. The application opens in fullscreen mode with a black canvas
3. Use the shape buttons at the bottom to create shapes:
   - Click a shape button (Circle, Triangle, Rectangle)
   - Configure shape properties in the dialog
   - Click OK to add the shape to the canvas
4. Use control buttons:
   - **CLOSE**: Exit the application
   - **CLEAR**: Remove all shapes from the canvas
   - **Remove Last**: Remove the most recently added shape

### Shape Configuration

#### Circle
- **Radius**: Size of the circle
- **Position X/Y**: Center coordinates
- **Random position**: Checkbox for random placement

#### Triangle
- **Angle**: Angle between two sides (degrees)
- **Side A/B**: Length of triangle sides
- **Position X/Y**: Starting vertex coordinates
- **Random position**: Checkbox for random placement

#### Rectangle
- **Width/Height**: Rectangle dimensions
- **Position X/Y**: Top-left corner coordinates
- **Random position**: Checkbox for random placement

## Project Structure

```
geometric/
├── CMakeLists.txt          # Root CMake configuration
├── README.md               # This file
├── src/
│   ├── CMakeLists.txt      # Source CMake configuration
│   ├── main.cpp            # Application entry point
│   ├── Model/              # Shape models
│   │   ├── IFigure.h       # Shape interface
│   │   ├── Circle.cpp/h    # Circle implementation
│   │   ├── Triangle.cpp/h  # Triangle implementation
│   │   ├── Rectangle.cpp/h # Rectangle implementation
│   │   ├── Square.cpp/h    # Square implementation
│   │   └── FigureFabric.cpp/h # Shape factory
│   ├── GUI/                # User interface
│   │   ├── IWindow.cpp/h   # Window base class
│   │   ├── MainWindow.cpp/h # Main application window
│   │   ├── ToolsWindow.cpp/h # Dialog base class
│   │   └── Tools*.cpp/h    # Shape configuration dialogs
│   └── Common/             # Shared components
│       └── TransferParams.h # Parameter transfer structure
└── build/                  # Build output (generated)
    └── Release/
        └── geometric.exe   # Final executable
```

## Design Patterns

- **Factory Pattern**: `FigureFabric` creates shape instances based on type
- **Abstract Factory**: Shape creation abstraction
- **Template Method**: Window creation and message handling
- **Polymorphism**: Shape rendering through virtual `paint()` method

## Technical Details

- **Language**: C++20
- **GUI Framework**: Native Win32 API
- **Build System**: CMake
- **Runtime**: Static linking (/MT for Release, /MTd for Debug)
- **Compiler**: MSVC (Visual Studio 2022)

## Known Issues

1. Currently only 4 shapes are implemented (Circle, Triangle, Rectangle, Square) though the UI shows buttons for additional shapes
2. Shapes are drawn with red outlines only (no fill color customization)
3. No save/load functionality for drawings
4. No undo/redo beyond removing the last shape

## Author

Zykov Ivan
