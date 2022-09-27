#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <set>
#include <stdexcept>
#include <vector>

#include "taichi/ui/common/canvas_base.h"

namespace taichi {
namespace ui {

namespace vulkan {

class Canvas final : public CanvasBase {
 public:
  void circles(const CirclesInfo &info) override;

};

}  // namespace vulkan

}  // namespace ui
}  // namespace taichi
