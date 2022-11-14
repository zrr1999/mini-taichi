#include <glad/gl.h>
//
#include <GLFW/glfw3.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "linmath.h"
#include "taichi/ui/common/window_base.h"

typedef struct Vertex {
  vec2 pos;
  vec3 col;
} Vertex;

static const Vertex vertices[3] = {
    {{-0.6f, -0.4f}, {1.f, 0.f, 0.f}}, {{0.6f, -0.4f}, {0.f, 1.f, 0.f}}, {{0.f, 0.6f}, {0.f, 0.f, 1.f}}};

static const char* vertex_shader_text =
    "#version 330\n"
    //"uniform mat4 MVP;\n"
//    "in vec3 vCol;\n"
    "in vec2 vPos;\n"
    "out vec3 color;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = vec4(vPos, 0.0, 1.0);\n"
    "    color = vec3(0.2, 0.3, 0.4);\n"
    "}\n";

static const char* fragment_shader_text =
//    "#version 110\n"
//                  "varying vec3 color;\n"
//                  "void main()\n"
//                  "{\n"
//                  "    gl_FragColor = vec4(color, 1.0);\n"
//                  "}\n"
    "#version 330\n"
    "in vec3 color;\n"
    "out vec4 fragment;\n"
    "void main()\n"
    "{\n"
    "    fragment = vec4(color, 1.0);\n"
    "}\n";

static void error_callback(int error, const char* description) { fprintf(stderr, "Error: %s\n", description); }

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void) {
  taichi::ui::WindowBase window("test");

  const GLuint vertex_shader   = window.add_shader(vertex_shader_text, GL_VERTEX_SHADER);
  const GLuint fragment_shader = window.add_shader(fragment_shader_text, GL_FRAGMENT_SHADER);
  const GLuint program         = window.add_program(window.shaders());

  //    const GLint mvp_location = glGetUniformLocation(program, "MVP");
  const GLint vpos_location = window.get_location("vPos", program);
  //    const GLint vcol_location = glGetAttribLocation(program, "vCol");

  GLuint vertex_buffer = window.create_buffer();
  GLuint vertex_array = window.create_array();
  window.set_attrib(vpos_location, 2, GL_FLOAT, GL_FALSE, 8, (void*)0);
  while (window.is_running()) {
    window.clear();
    window.use_program(program);
      window.set_buffer({-0.6f, -0.4f, 0.6f, -0.4f, 0.f, 0.6f});
    window.show();
  }

  glfwTerminate();
  exit(EXIT_SUCCESS);
}

// #include <iostream>
// #include "glad/gl.h"
// #include <GLFW/glfw3.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include "taichi/ui/common/window_base.h"
//
// #include "linmath.h"
//
////static const struct {
////  float x, y;
////  float r, g, b;
////} vertices[3] = {{-0.6f, -0.4f, 1.f, 0.f, 0.f}, {0.6f, -0.4f, 0.f, 1.f, 0.f}, {0.f, 0.6f, 0.f, 0.f, 1.f}};
//
// static void error_callback(int error, const char* description) { fprintf(stderr, "Error: %s\n", description); }
//
// static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
//  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GLFW_TRUE);
//}
//
// int main(void) {
//  taichi::ui::WindowBase window("test");
//
//  GLuint vertex_buffer = window.create_buffer();
//  // NOTE: OpenGL error checks have been omitted for brevity
//  float vertices[3][5] = {{-0.6f, -0.4f, 1.f, 0.f, 0.f}, {0.6f, -0.4f, 0.f, 1.f, 0.f}, {0.f, 0.6f, 0.f, 0.f, 1.f}};
//
//  static const char* vertex_shader_text =
//      "#version 110\n"
////      "uniform mat4 MVP;\n"
////      "attribute vec3 vCol;\n"
//      "attribute vec2 vPos;\n"
//      "varying vec3 color;\n"
//      "void main()\n"
//      "{\n"
//      "    gl_Position = vec4(vPos, 0.0, 1.0);\n"
//      "    color = vec3(1.0, 0.5, 0.2);\n"
//      "}\n";
////  auto vertex_shader = window.add_shader(vertex_shader_text, GL_VERTEX_SHADER);
//
//  GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
//  glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
//  glCompileShader(vertex_shader);
//
//  static const char* fragment_shader_text =
//      "#version 110\n"
//      "varying vec3 color;\n"
//      "void main()\n"
//      "{\n"
//      "    gl_FragColor = vec4(color, 1.0);\n"
//      "}\n";
//
////  auto fragment_shader = window.add_shader(fragment_shader_text, GL_FRAGMENT_SHADER);
//
//  GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
//  glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
//  glCompileShader(fragment_shader);
//
//  auto program = glCreateProgram();
//  glAttachShader(program, vertex_shader);
//  glAttachShader(program, fragment_shader);
//  glLinkProgram(program);
////  mvp_location  = glGetUniformLocation(program, "MVP");
//
////  auto vpos_location = window.get_location("vPos", program);
//  auto vcol_location = glGetAttribLocation(program, "vPos");
////  window.set_attrib(vpos_location, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void*)0);
//  glEnableVertexAttribArray(vcol_location);
//  glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void*)(sizeof(float) * 2));
//
//  while (window.is_running()) {
//    window.clear();
//
////    mat4x4_identity(m);
////    mat4x4_rotate_Z(m, m, (float)glfwGetTime());
////    mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
////    mat4x4_mul(mvp, p, m);
//    glUseProgram(program);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);
////    glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*)mvp);
//    glDrawArrays(GL_TRIANGLES, 0, 3);
//    window.show();
//  }
//
//  glfwTerminate();
//  exit(EXIT_SUCCESS);
//}