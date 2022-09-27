//
// Created by 詹荣瑞 on 2022/9/20.
//

#include "taichi/python/export.h"

namespace taichi {

PYBIND11_MODULE(taichi_python, m) {
  m.doc() = "taichi_python";

  //  for (auto &kv : InterfaceHolder::get_instance()->methods) {
  //    kv.second(&m);
  //  }

  export_ui(m);
}
}  // namespace taichi