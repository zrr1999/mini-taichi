#pragma once
#include "glad/gl.h"
#include "pybind11/pybind11.h"
#include "pybind11/operators.h"
#include "pybind11/stl.h"

namespace taichi {

namespace py = pybind11;

void export_lang(py::module &m);

void export_math(py::module &m);

void export_misc(py::module &m);

void export_visual(py::module &m);

void export_ui(py::module &m);

}  // namespace taichi
