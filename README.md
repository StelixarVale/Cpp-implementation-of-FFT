# C++实现快速傅里叶(逆)变换（FFT/IFFT）

实现基于C++的快速傅里叶变换算法。

## 功能特点

- 支持对复数矩阵进行FFT变换
- 提供三种FFT/IFFT变换方式：

  - 基本FFT/IFFT变换（自动补零到2的幂次方长度）
  - 指定长度的FFT/IFFT变换
  - 指定维度的FFT/IFFT变换（支持行方向和列方向）

## 依赖项

- C++14或更高版本
- Eigen 3.4或更高版本
- CMake 3.28或更高版本
- vcpkg（用于管理依赖）

## 代码结构

- `fft.h`: FFT/IFFT库的头文件，定义了接口
- `fft.cpp`: FFT/IFFT算法的具体实现
- `main.cpp`: 使用示例
- `CMakeLists.txt`: CMake构建配置文件

## 验证结果

提供MATLAB验证脚本（`verify_fft.m`），可以用来验证C++实现的正确性。
