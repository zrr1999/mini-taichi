#pragma once
#include "GLFW/glfw3.h"
#include "taichi/ui/common/canvas_base.h"
#include "string"
#include "vector"

namespace taichi {
namespace ui {


class WindowBase {
 public:
  WindowBase(const std::string name);
  CanvasBase *get_canvas();
  void debug_set_image(uint32_t* image, size_t length);
  bool is_running();
  void show();
  std::vector<GLuint> shaders();
  std::vector<GLuint> programs();
  GLint get_location(std::string var_name, GLuint program, GLboolean use_uniform=false);

  GLuint create_buffer();
  void set_buffer(std::vector<float> buffer) ;

  GLuint create_array();
  void set_array(std::vector<float> array) ;

  GLuint add_shader(const std::string shader_text, int shader_type);
  GLuint add_program(std::vector<GLuint> shaders);
  void use_program(GLuint program);
  void clear();

  void set_attrib(GLint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
  void set_uniform(GLint index, GLint size, GLboolean normalized, const GLfloat* pointer);
  ~WindowBase();
 protected:
  GLFWwindow *glfw_window_{nullptr};
  CanvasBase *canvas_{nullptr};
  // used for FPS counting
  double last_record_time_{0.0};
  int frames_since_last_record_{0};
  std::vector<GLuint> shaders_;
  std::vector<GLuint> programs_;
};
}  // namespace ui
}  // namespace taichi