//
// Created by 詹荣瑞 on 2022/9/20.
//

#pragma once
#include <glm/glm.hpp>

namespace taichi {
namespace ui {

struct CirclesInfo {
  //  RenderableInfo renderable_info;
  glm::vec3 color;
  float radius{0};
};

class CanvasBase {
 public:
  //  virtual void set_background_color(const glm::vec3 &color) = 0;
  //  virtual void set_image(const SetImageInfo &info) = 0;
  //  virtual void set_image(taichi::lang::Texture *tex) = 0;
  //  virtual void triangles(const TrianglesInfo &info) = 0;
  virtual void circles(const CirclesInfo &info) = 0;
  //  virtual void lines(const LinesInfo &info) = 0;
  //  virtual void scene(SceneBase *scene) = 0;
  virtual ~CanvasBase() = default;
};

}  // namespace ui
}  // namespace taichi