# CMakeList.txt : CMake project for geometric, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.3)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

project ("geometric")

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

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET geometric PROPERTY CXX_STANDARD 20)
endif()

install(TARGETS geometric
        RUNTIME DESTINATION bin)

# TODO: Add tests and install targets if needed.
