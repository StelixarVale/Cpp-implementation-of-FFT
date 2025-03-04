# C++实现快速傅里叶(逆)变换（FFT/IFFT）和快速一维卷积

实现基于C++的快速傅里叶（逆）变换和快速一维卷积。

## 功能

1. 支持对复数矩阵进行FFT变换
2. 提供三种FFT/IFFT变换方式：

   1. 基本FFT/IFFT变换（自动补零到2的幂次方长度）
   2. 指定长度的FFT/IFFT变换
   3. 指定维度的FFT/IFFT变换（支持行方向和列方向）
3. 支持快速一维卷积

## 依赖项

1. C++14或更高版本
2. Eigen 3.4或更高版本
3. CMake 3.28或更高版本
4. vcpkg（用于管理依赖）

## 文件结构

1. fft.cpp : FFT/IFFT算法的具体实现
2. main.cpp : 使用示例
3. conv.cpp : 卷积实现
4. verify_fft.m : matlab的验证代码
5. CMakeLists.txt : CMake构建配置文件
