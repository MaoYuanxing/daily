cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)

add_subdirectory(src bin)#添加子目录

install(FILES COPYRIGHT README.md DESTINATION share/doc/cmake/)#相对目录前缀为CMAKE_INSTALL_PREFIX
install(PROGRAMS runTurial.sh DESTINATION bin)
install(DIRECTORY doc/ DESTINATION share/doc/cmake)