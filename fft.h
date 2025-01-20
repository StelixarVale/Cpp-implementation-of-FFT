/**
 * @file fft.h
 * @brief 快速傅里叶变换(FFT)算法的头文件
 *
 * 本文件定义了FFT算法的主要接口和辅助函数。
 * 使用Eigen库进行矩阵运算，支持对向量和矩阵进行FFT变换。
 */
//头文件保护
#ifndef FFT_IMPLEMENTATION_FFT_H
#define FFT_IMPLEMENTATION_FFT_H
#include <Eigen/Dense> // Eigen库的密集矩阵运算功能
#include <Eigen/Core> // Eigen库的核心功能
#include <complex>
#include <vector>
#include <cmath>

namespace FFTLibrary {
    /**
     * @brief 对输入数据进行FFT变换
     * @param X 输入数据（矩阵）
     * @return 返回FFT变换结果
     * 注：如果输入是矩阵，默认对列进行FFT变换
     */
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& X);

    /**
     * @brief 对输入数据进行指定长度的FFT变换
     * @param X 输入数据
     * @param n FFT变换的目标长度（会进行补零或截断）
     * @return 返回FFT变换结果
     */
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& X, int n);

    /**
     * @brief 对输入矩阵在指定维度上进行FFT变换
     * @param X 输入矩阵
     * @param n FFT变换的目标长度
     * @param dim 进行FFT的维度（1表示对列变换，2表示对行变换）
     * @return 返回FFT变换结果
     */
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& X, int n, int dim);
    //——————————以下是内部函数————————————
    namespace detail {
        /**
         * @brief FFT算法的核心实现函数
         * @param x 输入复数向量
         * @return 返回FFT变换结果
         */
        std::vector<std::complex<double>> fft_impl(const std::vector<std::complex<double>>& x);

        /**
         * @brief 将输入向量调整到指定长度（通过补零或截断）
         * @param x 输入向量
         * @param n 目标长度
         * @return 返回调整后的向量
         */
        std::vector<std::complex<double>> pad_or_truncate(const std::vector<std::complex<double>>& x, int n);

        /**
         * @brief 判断一个数是否为2的幂
         * @param n 输入数字
         * @return 如果是2的幂返回true，否则返回false
         */
        bool is_power_of_two(int n);

        /**
         * @brief 计算大于等于输入数的最小2的幂
         * @param n 输入数字
         * @return 返回最小的大于等于n的2的幂
         */
        int next_power_of_two(int n);
    }
}

#endif // FFT_IMPLEMENTATION_FFT_H