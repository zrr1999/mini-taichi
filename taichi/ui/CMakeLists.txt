add_library(taichi_ui SHARED
        common/window_base.cpp
        backends/vulkan/canvas.cpp
        backends/vulkan/window.cpp
        backends/vulkan/renderer.cpp
        )

target_include_directories(taichi_ui
        PRIVATE
        ${PROJECT_SOURCE_DIR}/third_party/eigen
        ${PROJECT_SOURCE_DIR}/third_party/volk
        ${PROJECT_SOURCE_DIR}/third_party/Vulkan-Headers/include
        ${LLVM_INCLUDE_DIRS}
        PUBLIC
        )
target_link_libraries(taichi_ui PUBLIC glfw)
