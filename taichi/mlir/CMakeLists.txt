option(LLVM_INCLUDE_TOOLS "Generate build targets for the LLVM tools." ON)
option(LLVM_BUILD_TOOLS "Build the LLVM tools. If OFF, just generate build targets." ON)

find_package(MLIR REQUIRED CONFIG)

set(LLVM_MLIR_BINARY_DIR ${MLIR_DIR}/../../../bin)
set(LLVM_MLIR_SOURCE_DIR ${MLIR_DIR}/../../../../mlir)

list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")

include(TableGen)
include(AddLLVM)
include(AddMLIR)
include(HandleLLVMOptions)

# Boning project.
set(BONING_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/taichi/mlir)
set(BUDDY_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(BUDDY_EXAMPLES_DIR ${BUDDY_SOURCE_DIR}/examples)
set(BUDDY_INCLUDE_DIR ${BUDDY_SOURCE_DIR}/include/)
set(BUDDY_THIRDPARTY_INCLUDE_DIR ${BUDDY_SOURCE_DIR}/thirdparty/include/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUDDY_BINARY_DIR})

set(BUDDY_EXAMPLES OFF CACHE BOOL "Build examples")
set(BUDDY_ENABLE_OPENCV OFF CACHE BOOL "Enable OpenCV support.")

# Add MLIR and LLVM headers to the include path
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${MLIR_INCLUDE_DIRS})

# Add BUDDY files to the include path
include_directories(${BUDDY_MAIN_INCLUDE_DIR})
include_directories(${BUDDY_INCLUDE_DIR})
include_directories(${BUDDY_INCLUDE_DIR}/Interface)
include_directories(${BUDDY_INCLUDE_DIR}/Dialect)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/Dialect)
include_directories(${BUDDY_SOURCE_DIR}/lib)
include_directories(${BUDDY_THIRDPARTY_INCLUDE_DIR})

add_subdirectory(include)
add_subdirectory(lib)
