#!/usr/bin/env python
# _*_ coding: utf-8 _*_
# @Time : 2022/9/26 12:30
# @Author : Rongrui Zhan
# @desc : 本代码未经授权禁止商用
import os, sys

# pyd所在路径
os.chdir("/Users/zhanrongrui/CLionProjects/mini-taichi/python/taichi")
# sys.path.append(os.path.join())
import taichi_python
print(os.getcwd())
module_name = "taichi_python"
exec("import %s" % module_name)

from pybind11_stubgen import ModuleStubsGenerator

module = ModuleStubsGenerator(module_name)
module.parse()
module.write_setup_py = False

with open("%s.pyi" % module_name, "w") as fp:
    fp.write("#\n# Automatically generated file, do not edit!\n#\n\n")
    fp.write("\n".join(module.to_lines()))
