# Python, numpy, and pybind11
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
execute_process(COMMAND ${Python3_EXECUTABLE} -m pybind11 --cmake
                OUTPUT_VARIABLE pybind11_DIR OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND ${Python3_EXECUTABLE} -c "import numpy;print(numpy.get_include())"
                OUTPUT_VARIABLE NUMPY_INCLUDE_DIR OUTPUT_STRIP_TRAILING_WHITESPACE)

message("-- Python: Using ${Python3_EXECUTABLE} as the interpreter")
message("    version: ${Python3_VERSION}")
message("    include: ${Python3_INCLUDE_DIRS}")
message("    library: ${Python3_LIBRARY_DIRS}")
message("    numpy include: ${NUMPY_INCLUDE_DIR}")

include_directories(${NUMPY_INCLUDE_DIR})

find_package(pybind11 CONFIG REQUIRED)
