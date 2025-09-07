# Source files for geometric executable

# Add source to this project's executable.
add_executable (geometric WIN32
    "main.cpp" 
     "Model/IFigure.h"
     "Model/EFigureType.h"
     "Model/Circle.cpp"
     "Model/Circle.h"
     "Model/Square.cpp"
     "Model/Square.h"
     "Model/Triangle.h" 
     "Model/Triangle.cpp" 
     "Model/Rectangle.h" 
     "Model/Rectangle.cpp" 
     "Model/FigureFabric.h" 
     "Model/FigureFabric.cpp" 
     "GUI/MainWindow.h"
 "GUI/MainWindow.cpp"   "GUI/IWindow.h" "GUI/ToolsWindow.h" "GUI/ToolsWindow.cpp" "GUI/IWindow.cpp" "GUI/ToolsCircle.h" "GUI/ToolsCircle.cpp" "Common/TransferParams.h" "GUI/ToolsTriangle.h" "GUI/ToolsTriangle.cpp" "GUI/ToolsRectangle.h" "GUI/ToolsRectangle.cpp")

# Set output directory
set_target_properties(geometric PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/RelWithDebInfo"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/MinSizeRel"
)

# Install target
install(TARGETS geometric
    RUNTIME DESTINATION .
)
