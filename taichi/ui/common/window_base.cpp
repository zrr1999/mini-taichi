#include "iostream"
#define GLAD_GL_IMPLEMENTATION
#include "glad/gl.h"
#include "taichi/ui/common/window_base.h"
namespace taichi {
namespace ui {

WindowBase::WindowBase(const std::string name) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  glfw_window_ = glfwCreateWindow(640, 480, name.c_str(), NULL, NULL);
  glfwMakeContextCurrent(glfw_window_);
  if (glfw_window_ == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return;
  }

  gladLoadGL(glfwGetProcAddress);
  glfwSwapInterval(1);

  //  float vertices[] = {0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.0f, -0.5f, 0.5f, 0.5f};
  //  unsigned int VAO, VBO;
  //  glGenVertexArrays(1, &VAO);
  //  glGenBuffers(1, &VBO);
  //  glBindVertexArray(VAO);
  //  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  //  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  //  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

  //  glBindBuffer(GL_ARRAY_BUFFER, 0);
  //  glBindVertexArray(0);
}
void WindowBase::use_program(GLuint program) { glUseProgram(program); }

void WindowBase::set_attrib(
    GLint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) {
  glEnableVertexAttribArray(index);
  glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
void WindowBase::set_uniform(GLint index, GLint size, GLboolean normalized, const GLfloat* pointer) {
  glUniformMatrix4fv(index, size, normalized, pointer);
}
GLuint WindowBase::create_buffer() {
  GLuint vertex_buffer;
  glGenBuffers(1, &vertex_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
  return vertex_buffer;
}

GLuint WindowBase::create_array() {
  GLuint vertex_array;
  glGenVertexArrays(1, &vertex_array);
  glBindVertexArray(vertex_array);
  return vertex_array;
}

void WindowBase::set_buffer(std::vector<float> buffer) {
  glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float), buffer.data(), GL_STREAM_DRAW);
}

void WindowBase::show() {
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(glfw_window_);
    glfwPollEvents();
}

void WindowBase::clear() {
    int width, height;
    glfwGetFramebufferSize(glfw_window_, &width, &height);
    glViewport(0, 0, width, height);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

std::vector<GLuint> WindowBase::shaders() { return shaders_; }
std::vector<GLuint> WindowBase::programs() { return programs_; }
GLuint WindowBase::add_shader(const std::string shader_text, int shader_type) {
  char* c_str;
  c_str = new char[shader_text.size() + 1];
  strcpy(c_str, shader_text.c_str());
  GLuint vertex_shader = glCreateShader(shader_type);
  glShaderSource(vertex_shader, 1, &c_str, NULL);
  glCompileShader(vertex_shader);
  shaders_.push_back(vertex_shader);
  return vertex_shader;
}
GLuint WindowBase::add_program(std::vector<GLuint> shaders) {
  GLuint program = glCreateProgram();
  for (auto shader : shaders) {
    glAttachShader(program, shader);
  }
  glLinkProgram(program);
  programs_.push_back(program);
  return program;
}
GLint WindowBase::get_location(std::string var_name, GLuint program, GLboolean use_uniform) {
  if (use_uniform) {
    return glGetUniformLocation(program, var_name.c_str());
  } else {
    return glGetAttribLocation(program, var_name.c_str());
  }
}

CanvasBase* WindowBase::get_canvas() { return canvas_; }
bool WindowBase::is_running() { return !glfwWindowShouldClose(glfw_window_); }
WindowBase::~WindowBase() {
    glfwDestroyWindow(glfw_window_);
  glfwTerminate(); }
}  // namespace ui
}  // namespace taichi