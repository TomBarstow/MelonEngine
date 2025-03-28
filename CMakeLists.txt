# CMakeList.txt : CMake project for MelonEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("MelonEngine")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories (Headers)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Library directories
link_directories(${PROJECT_SOURCE_DIR}/lib)

# Include external dependencies
find_package(OpenGL REQUIRED)


# Add source to this project's executable.
add_executable (MelonEngine src/main.cpp src/renderer.cpp src/shader.cpp)

# Link libraries
target_link_libraries(MelonEngine glfw3 glew32 OpenGL::GL)

