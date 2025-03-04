#ifndef CONV_H
#define CONV_H

#include <Eigen/Dense>
#include <string>

using namespace std;
using namespace Eigen;

namespace CONV{
    // 使用FFT实现的一维卷积函数
    // mode: 卷积模式，可选 "full"(默认), "same", "valid"
    // full: 完全卷积，输出长度为 x.size() + h.size() - 1
    // same: 输出长度与输入信号x长度相同
    // valid: 仅计算完全重叠部分，输出长度为 x.size() - h.size() + 1 (要求 x.size() >= h.size())
    VectorXcd conv(const VectorXcd& x, const VectorXcd& h, const string& mode = "full");
}

#endif // CONV_H