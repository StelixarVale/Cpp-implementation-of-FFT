#ifndef FFT_IMPLEMENTATION_FFT_H
#define FFT_IMPLEMENTATION_FFT_H
#include <Eigen/Dense> 
#include <complex>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using namespace Eigen;
namespace FFTLibrary {

    MatrixXcd fft(const MatrixXcd& X);

    MatrixXcd fft(const MatrixXcd& X, int n);

    MatrixXcd fft(const MatrixXcd& X, int n, int dim);

    MatrixXcd ifft(const MatrixXcd& X);

    MatrixXcd ifft(const MatrixXcd& X, int n);

    MatrixXcd ifft(const MatrixXcd& X, int n, int dim);

    //——————————以下是内部函数————————————
    namespace detail {

        VectorXcd fft_impl(const VectorXcd& x);

        VectorXcd ifft_impl(const VectorXcd& x, bool is_top_level = true);

        /**
         * @brief 将输入向量调整到指定长度（通过补零或截断）
         * @param x 输入向量
         * @param n 目标长度
         * @return 返回调整后的向量
         */
        VectorXcd pad_or_truncate(const VectorXcd& x, int n);

        bool is_power_of_two(int n);

        int next_power_of_two(int n);

        /**
         * @brief 清除接近于0的微小值，处理浮点数计算精度导致的舍入误差
         * @param X 输入矩阵
         * @param epsilon 阈值，默认为1e-10
         * @return 处理后的矩阵
         */
        MatrixXcd clear_small_values(const MatrixXcd& X, double epsilon = 1e-10);

        /**
         * @brief 清除接近于0的微小值，处理浮点数计算精度导致的舍入误差
         * @param x 输入向量
         * @param epsilon 阈值，默认为1e-10
         * @return 处理后的向量
         */
        VectorXcd clear_small_values(const VectorXcd& x, double epsilon = 1e-10);
    }
}

#endif // FFT_IMPLEMENTATION_FFT_H