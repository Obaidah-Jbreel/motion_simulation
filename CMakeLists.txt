cmake_minimum_required(VERSION 3.16)
project(MotionSimulator VERSION 1.0
  LANGUAGES CXX
  DESCRIPTION "Simple motion simulation"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    )
FetchContent_MakeAvailable(SFML)


file(GLOB SOURCE_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE includes)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(WIN32)
  add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM)
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
