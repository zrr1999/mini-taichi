#!/usr/bin/env python
# _*_ coding: utf-8 _*_
# @Time : 2022/9/18 17:36
# @Author : Rongrui Zhan
# @desc : 本代码未经授权禁止商用
from taichi import PyWindow

window = PyWindow()
window.add_shader("#version 330\n"
                  "in vec2 vPos;\n"
                  "out vec3 color;\n"
                  "void main()\n"
                  "{\n"
                  "    gl_Position = vec4(vPos, 0.0, 1.0);\n"
                  "    color = vec3(0.2, 0.0, 0.4);\n"
                  "}\n", 0x8b31)
window.add_shader("#version 330\n"
                  "in vec3 color;\n"
                  "out vec4 fragment;\n"
                  "void main()\n"
                  "{\n"
                  "    fragment = vec4(color, 1.0);\n"
                  "}\n", 0x8b30)
program = window.add_program(window.shaders())
pos = window.get_location("vPos", program, False)

vbo = window.create_buffer()
vao = window.create_array()
window.set_attrib(pos, 2, 0x1406, 0, 8, 0)
while window.is_running():
    window.clear()
    window.use_program(program)
    window.set_buffer([1.0, 1., 0.0, 0.0, 0, 0.5])
    window.show()
