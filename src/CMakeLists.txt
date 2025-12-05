cmake_minimum_required(VERSION 3.30)

set(CMAKE_BUILD_TYPE Debug)
project(Calc)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(MY_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../..")
set(ANTLR_EXECUTABLE "${MY_BASE_DIR}/antlr-4.13.2-complete.jar")
find_path(ANTLR_INCLUDE_DIR
  NAMES antlr4-runtime.h
  PATHS /usr/include /usr/local/include /usr/include/antlr4-runtime /usr/local/include/antlr4-runtime
)
if(NOT ANTLR_INCLUDE_DIR)
  message(FATAL_ERROR "Could not find antlr4-runtime.h. Install the ANTLR C++ runtime (e.g. 'sudo apt install libantlr4-runtime-dev') or set ANTLR_INCLUDE_DIR to the correct path.")
endif()
list(APPEND CMAKE_MODULE_PATH ${MY_BASE_DIR})

if(NOT EXISTS "${ANTLR_EXECUTABLE}")
    message(STATUS "Couldn't find: ${ANTLR_EXECUTABLE}")
    message(STATUS "Trying to download it, you might eed to install java tho.")
    file(DOWNLOAD
    "https://www.antlr.org/download/antlr-4.13.2-complete.jar"
    "${ANTLR_EXECUTABLE}"
    STATUS DOWNLOAD_STATUS TIMEOUT 60)
endif()

if(NOT EXISTS "${MY_BASE_DIR}/FindANTLR.cmake")
    message(STATUS "Couldn't find: FindANTLR.cmake")
    message(STATUS "Trying to download it.")
    # splitting the url in 2 because my OCD can't handle the needy linter
    set(URL1 "https://raw.githubusercontent.com/antlr/antlr4/")
    set(URL2 "refs/heads/dev/runtime/Cpp/cmake/FindANTLR.cmake")
    file(DOWNLOAD
    "${URL1}${URL2}"
    "${MY_BASE_DIR}/FindANTLR.cmake"
    STATUS DOWNLOAD_STATUS TIMEOUT 60)
endif()

find_package(ANTLR)
message(STATUS "Found ANTLR: ${ANTLR_VERSION}")

file(GLOB GFOURS "*.g4")
antlr_target(${PROJECT_NAME} ${GFOURS} LEXER PARSER VISITOR)
message(STATUS "ANTLR generated: ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}")

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

llvm_map_components_to_libnames(llvm_libs all)

file(GLOB SOURCES "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES} ${ANTLR_${PROJECT_NAME}_CXX_OUTPUTS})
target_link_libraries(${PROJECT_NAME} PRIVATE antlr4-runtime LLVM-21)
target_include_directories(
  ${PROJECT_NAME} PRIVATE
  ${ANTLR_INCLUDE_DIR}
  ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}
  ${LLVM_INCLUDE_DIRS}
)
add_definitions(${LLVM_DEFINITIONS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# vim: set ts=4 sw=4 et sts=0 :




