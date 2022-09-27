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

#include "taichi/ui/backends/vulkan/canvas.h"
#include "taichi/ui/common/window_base.h"

namespace taichi {
namespace lang {
class Program;
}  // namespace lang
}  // namespace taichi

namespace taichi {
namespace ui {
namespace vulkan {

class Window final : public WindowBase {

};

}  // namespace vulkan
}  // namespace ui
}  // namespace taichi
