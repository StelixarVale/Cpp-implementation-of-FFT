cmake_minimum_required(VERSION 3.28)
project(Cpp_implementation_of_FFT)
# 设置vcpkg工具链文件
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/vcpkg-master/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "Vcpkg工具链文件的路径")
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)# 强制使用指定的C++标准，如果C++标准不匹配，则报错

find_package(Eigen3 3.4 REQUIRED NO_MODULE)

message(STATUS "Eigen3版本: ${EIGEN3_VERSION_STRING}")

add_executable(Cpp_implementation_of_FFT 
                main.cpp
                fft.cpp)

# 链接Eigen库
target_link_libraries(Cpp_implementation_of_FFT PRIVATE Eigen3::Eigen)