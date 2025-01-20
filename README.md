# C++实现的快速傅里叶变换（FFT）

实现基于C++的快速傅里叶变换算法。

## 功能特点

- 支持对复数矩阵进行FFT变换
- 提供三种FFT变换方式：

  - 基本FFT变换（自动补零到2的幂次方长度）
  - 指定长度的FFT变换
  - 指定维度的FFT变换（支持行方向和列方向）

## 依赖项

- C++14或更高版本
- Eigen 3.4或更高版本
- CMake 3.28或更高版本
- vcpkg（用于管理依赖）

## 构建说明

1. 确保已安装vcpkg和Eigen库：

```bash
vcpkg install eigen3:x64-windows
```

2. 使用CMake构建项目：

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## 使用示例

```cpp
#include <Eigen/Dense>
#include "fft.h"

// 创建测试矩阵
Eigen::MatrixXcd X(3, 2);
X << std::complex<double>(1, 0), std::complex<double>(4, 0),
     std::complex<double>(2, 0), std::complex<double>(5, 0),
     std::complex<double>(3, 0), std::complex<double>(6, 0);

// 基本FFT变换
MatrixXcd Y1 = FFTLibrary::fft(X);

// 指定长度的FFT变换
MatrixXcd Y2 = FFTLibrary::fft(X, 8);

// 指定维度的FFT变换（对行进行变换）
MatrixXcd Y3 = FFTLibrary::fft(X, 8, 2);
```

## 代码结构

- `fft.h`: FFT库的头文件，定义了接口
- `fft.cpp`: FFT算法的具体实现
- `main.cpp`: 使用示例
- `CMakeLists.txt`: CMake构建配置文件

## 验证结果

提供MATLAB验证脚本（`verify_fft.m`），可以用来验证C++实现的正确性。

### 使用验证脚本

1. 运行C++程序，记录输出结果
2. 打开MATLAB
3. 运行 `verify_fft.m` 脚本
4. 对比MATLAB的输出和C++的输出

验证脚本使用了与C++代码相同的测试数据，包括：

- 对3×2矩阵的列方向4点FFT
- 对3×2矩阵的列方向8点FFT
- 对3×2矩阵的行方向8点FFT

---

