#ifndef FFT_IMPLEMENTATION_FFT_H
#define FFT_IMPLEMENTATION_FFT_H
#include <Eigen/Dense> 
#include <Eigen/Core> 
#include <complex>
#include <cmath>
#include <iostream>
#include <algorithm>
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

        VectorXcd ifft_impl(const VectorXcd& x);

        /**
         * @brief 将输入向量调整到指定长度（通过补零或截断）
         * @param x 输入向量
         * @param n 目标长度
         * @return 返回调整后的向量
         */
        VectorXcd pad_or_truncate(const VectorXcd& x, int n);

        bool is_power_of_two(int n);

        int next_power_of_two(int n);
    }
}

#endif // FFT_IMPLEMENTATION_FFT_H