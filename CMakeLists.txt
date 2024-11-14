cmake_minimum_required(VERSION 3.17)
project(MotionSimulator VERSION 1.0
  LANGUAGES CXX
  DESCRIPTION "Simple motion simulation"
)
# Setiing some important variables .

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
file(GLOB SOURCE_FILES src/*.cpp)

# option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# look for SFML IN the system .
find_package(SFML COMPONENTS graphics window system REQUIRED)

# Adding sourcecode for compiling .
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Adding our headers for compiling .
target_include_directories(${PROJECT_NAME} PRIVATE headers)

# Adding SFML Library compiling .
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)

#target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(WIN32)
  set(SFML_SOURCE_DIR "${VCPKG_ROOT}/installed/x64-windows")

  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
      message(STATUS "This is a 64-bit build.")
  elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
      message(STATUS "This is a 32-bit build.")
        add_custom_command(
          TARGET ${PROJECT_NAME}
          COMMENT "Copy OpenAL DLL"
          PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/bin/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
          VERBATIM)
  else()
      message(STATUS "Unknown pointer size: ${CMAKE_SIZEOF_VOID_P}")
  endif()
endif()

# Set the source directory of your data folder
set(DATA_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets/)

# Set the destination directory in the build directory
set(DATA_DEST_DIR ${CMAKE_CURRENT_BINARY_DIR}/bin/)

# Create a custom command to copy the data folder to the build directory
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${DATA_SOURCE_DIR}
            ${DATA_DEST_DIR}
    COMMENT "Copying data folder to build directory"
)

# Create a custom target to make sure the custom command is executed
add_custom_target(CopyData ALL DEPENDS ${DATA_DEST_DIR})
install(TARGETS ${PROJECT_NAME})
