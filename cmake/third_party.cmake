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
