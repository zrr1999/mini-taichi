FROM ubuntu:focal
LABEL author="Rongrui Zhan"
RUN apt-get update
RUN apt-get install vim passwd openssl openssh-server clang cmake gdb python3.8-dev -y
RUN apt-get install libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libxext-dev  -y
RUN apt-get install mesa-common-dev  -y
RUN ln /usr/bin/python3 /usr/bin/python
RUN ln /usr/bin/pip3 /usr/bin/pip
RUN pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
RUN pip install pybind11 numpy

CMD service ssh restart
