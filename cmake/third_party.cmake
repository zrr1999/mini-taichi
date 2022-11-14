# glfw
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(third_party/glfw)
include_directories(third_party/glfw/include)
include_directories(third_party/glfw/deps)
# glm
add_subdirectory(third_party/glm)
include_directories(third_party/glm)
# llvm/mlir
# TODO use add_subdirectory in the future
# add_subdirectory(third_party/llvm)
find_package(MLIR REQUIRED CONFIG)
set(LLVM_MLIR_BINARY_DIR ${MLIR_DIR}/../../../bin)
set(LLVM_MLIR_SOURCE_DIR ${MLIR_DIR}/../../../../mlir)
list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(TableGen)
include(AddLLVM)
include(AddMLIR)
include(HandleLLVMOptions)
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${MLIR_INCLUDE_DIRS})


