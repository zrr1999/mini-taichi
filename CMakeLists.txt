cmake_minimum_required(VERSION 3.23)

if(POLICY CMP0077)
  cmake_policy(SET CMP0077 NEW)
endif()

if(POLICY CMP0116)
  cmake_policy(SET CMP0116 OLD)
endif()

project(mini-taichi LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include(cmake/init.cmake)
include(cmake/third_party.cmake)

#add_library(core_api MODULE main.cpp)
#include(cmake/core.cmake)
include(cmake/pybind11.cmake)

add_subdirectory(taichi/ui)

file(GLOB TAICHI_PYBIND_SOURCE
        "taichi/python/*.cpp"
        "taichi/python/*.h"
        )
set(PYTHON_LIBRARY_NAME python_api)
set(CORE_WITH_PYBIND_LIBRARY_NAME taichi_python)
pybind11_add_module(${CORE_WITH_PYBIND_LIBRARY_NAME} NO_EXTRAS ${TAICHI_PYBIND_SOURCE})
target_link_libraries(${CORE_WITH_PYBIND_LIBRARY_NAME} PUBLIC taichi_ui)

add_executable(test test.cpp)
target_link_libraries(test taichi_ui glfw)

#install(TARGETS ${CORE_WITH_PYBIND_LIBRARY_NAME}
#        EXPORT MyLibTargets
#        LIBRARY DESTINATION python/taichi  # 动态库安装路径
#        PUBLIC_HEADER DESTINATION include  # 头文件安装路径
#        )

#target_link_libraries(${CORE_WITH_PYBIND_LIBRARY_NAME} PUBLIC glfw glm)
#
#add_dependencies(${CORE_WITH_PYBIND_LIBRARY_NAME} taichi_ui)
#target_link_libraries(core_api PUBLIC ${glfw3_LIBS})

#file(GLOB_RECURSE PYTHON_SOURCE_FILES ${PYTHON_SOURCE_DIR}/*)
#
#foreach (file ${PYTHON_SOURCE_FILES})
#    file(COPY ${file} DESTINATION ${PROJECT_BINARY_DIR}/python)
#endforeach ()

#target_link_libraries(core_api ${Python3_LIBRARIES})
