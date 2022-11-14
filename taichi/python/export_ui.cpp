#include "iostream"
#include "pybind11/numpy.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "taichi/ui/backends/vulkan/canvas.h"
#include "taichi/ui/backends/vulkan/window.h"
#include "taichi/ui/common/window_base.h"
namespace py = pybind11;

namespace taichi {
namespace ui {
struct PyCanvas {
  std::unique_ptr<CanvasBase> canvas{nullptr};
  PyCanvas(CanvasBase& canvas) {
    //  this->canvas=std::make_unique<CanvasBase>(canvas);
  }
};
struct PyWindow {
  std::unique_ptr<WindowBase> window{nullptr};

  PyWindow(const std::string name) { window = std::make_unique<WindowBase>(name); }

  GLuint add_shader(const std::string shader_text, int shader_type) { return window->add_shader(shader_text, shader_type); }
  GLuint add_program(const std::vector<GLuint>& shaders) { return window->add_program(shaders); }

  std::vector<GLuint> shaders() {
    return window->shaders(); }

  std::vector<GLuint> programs() { return window->programs(); }

  void set_attrib(GLint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, long pointer) {
    window->set_attrib(index, size, type, normalized, stride, (const GLvoid*)pointer);
  }
  void set_uniform(GLint index, GLint size, GLboolean normalized, long pointer) {
    window->set_uniform(index, size, normalized, (const GLfloat*)pointer);
  }

  GLint get_location(std::string var_name, GLuint program, GLboolean use_uniform) {
    return window->get_location(var_name, program, use_uniform);
  }
  //  py::tuple get_window_shape() {
  //    auto [w, h] = window->get_window_shape();
  //    return pybind11::make_tuple(w, h);
  //  }
  //
  //  void write_image(const std::string &filename) {
  //    window->write_image(filename);
  //  }
  //
  //  void copy_depth_buffer_to_ndarray(Ndarray *depth_arr) {
  //    window->copy_depth_buffer_to_ndarray(*depth_arr);
  //  }
  //
  //  py::array_t<float> get_image_buffer() {
  //    uint32_t w, h;
  //    auto &img_buffer = window->get_image_buffer(w, h);
  //
  //    float *image = new float[w * h * 4];
  //    // Here we must match the numpy 3d array memory layout. Refs:
  //    // https://numpy.org/doc/stable/reference/arrays.ndarray.html
  //    for (int i = 0; i < w; i++) {
  //      for (int j = 0; j < h; j++) {
  //        auto pixel = img_buffer[j * w + i];
  //        for (int k = 0; k < 4; k++) {
  //          // must flip up-down to match the numpy array memory layout
  //          image[i * h * 4 + (h - j - 1) * 4 + k] = (pixel & 0xFF) / 255.0;
  //          pixel >>= 8;
  //        }
  //      }
  //    }
  //    // Here we must pass a deconstructor to free the memory in python scope.
  //    // Refs:
  //    // https://stackoverflow.com/questions/44659924/returning-numpy-arrays-via-pybind11
  //    py::capsule free_imgae(image, [](void *tmp) {
  //      float *image = reinterpret_cast<float *>(tmp);
  //      delete[] image;
  //    });
  //
  //    return py::array_t<float>(
  //        py::detail::any_container<ssize_t>({w, h, 4}),
  //        py::detail::any_container<ssize_t>(
  //            {sizeof(float) * h * 4, sizeof(float) * 4, sizeof(float)}),
  //        image, free_imgae);
  //  }

  void show() { window->show(); }
  void clear() { window->clear(); }
  GLuint create_buffer() { return window->create_buffer(); }
  GLuint create_array() { return window->create_array(); }
  void set_buffer(std::vector<float> buffer) { window->set_buffer(buffer); }
  void use_program(GLuint program){
    window->use_program(program);
  }
  //  bool is_pressed(std::string button) {
  //    return window->is_pressed(button);
  //  }

  bool is_running() { return window->is_running(); }

  void set_is_running(bool value) {
    //      return window->set_is_running(value);
  }

  //
  //  py::list get_events(EventType tag) {
  //    return py::cast(window->get_events(tag));
  //  }
  //
  //  bool get_event(EventType e) {
  //    return window->get_event(e);
  //  }
  //
  //  Event get_current_event() {
  //    return window->get_current_event();
  //  }
  //  void set_current_event(const Event &event) {
  //    window->set_current_event(event);
  //  }

  //    PyCanvas get_canvas() {
  //      PyCanvas canvas(window->get_canvas());
  //      return canvas;
  //    }

  //  PyGui GUI() {
  //    PyGui gui = {window->GUI()};
  //    return gui;
  //  }

  // this is so that the GUI class does not need to use any pybind related stuff
  //  py::tuple py_get_cursor_pos() {
  //    auto pos = window->get_cursor_pos();
  //    float x = std::get<0>(pos);
  //    float y = std::get<1>(pos);
  //    return py::make_tuple(x, y);
  //  }
  //
  //  void destroy() {
  //    if (window) {
  //      window.reset();
  //    }
  //  }
};

}  // namespace ui

void export_ui(py::module& m) {
  m.attr("UI_AVAILABLE") = py::bool_(true);
  py::class_<ui::PyWindow>(m, "PyWindow")
      .def(py::init<const char*>(), py::arg("name") = "untitled")
      .def("show", &ui::PyWindow::show)
      .def("clear", &ui::PyWindow::clear)
      .def("shaders", &ui::PyWindow::shaders)
      .def("add_shader", &ui::PyWindow::add_shader)
      .def("programs", &ui::PyWindow::programs)
      .def("add_program", &ui::PyWindow::add_program)
      .def("use_program", &ui::PyWindow::use_program)
      .def("set_attrib", &ui::PyWindow::set_attrib)
      .def("set_uniform", &ui::PyWindow::set_uniform)
      .def("set_buffer", &ui::PyWindow::set_buffer)
      .def("get_location", &ui::PyWindow::get_location)
      .def("create_buffer", &ui::PyWindow::create_buffer)
      .def("create_array", &ui::PyWindow::create_array)
      //      .def("get_canvas", &ui::PyWindow::get_canvas)
      .def("is_running", &ui::PyWindow::is_running);
}
}  // namespace taichi
