/**
 * @file fft.cpp
 * @brief 快速傅里叶变换(FFT)算法的实现文件
 *
 * 本文件实现了FFT算法的核心功能。
 * 采用分治法（Divide and Conquer）的思想，通过递归方式实现FFT。
 */

#define _USE_MATH_DEFINES
#include "fft.h"
#include <stdexcept>
using namespace std;
using namespace Eigen;

namespace FFTLibrary {
    namespace detail {
        bool is_power_of_two(int n) {
            // 使用位运算判断是否为2的幂
            // n & (n-1) 的结果如果为0，说明n是2的幂
            return n > 0 && (n & (n - 1)) == 0;
        }

        int next_power_of_two(int n) {
            // 计算大于等于n的最小2的幂
            int power = 1;
            while (power < n) {
                power *= 2;
            }
            return power;
        }

        VectorXcd pad_or_truncate(const VectorXcd& x, int n) {
            // 将输入向量调整为指定长度
            VectorXcd result(n);
            if (x.size() <= n) {
                // 如果输入长度小于目标长度，补零
                copy(x.begin(), x.end(), result.begin());
                fill(result.begin() + x.size(), result.end(), complex<double>(0.0, 0.0));
            } else {
                // 如果输入长度大于目标长度，截断
                copy(x.begin(), x.begin() + n, result.begin());
            }
            return result;
        }

        VectorXcd fft_impl(const VectorXcd& x) {
            int n = x.size();

            // 基本情况：长度为1时直接返回
            if (n == 1) {
                return x;
            }

            // 将输入序列分为偶数项和奇数项
            VectorXcd even(n/2);
            VectorXcd odd(n/2);
            for (int i = 0; i < n/2; i++) {
                even[i] = x[2*i];      // 偶数位置的元素
                odd[i] = x[2*i + 1];   // 奇数位置的元素
            }

            // 递归计算偶数项和奇数项的FFT
            VectorXcd even_fft = fft_impl(even);
            VectorXcd odd_fft = fft_impl(odd);

            // 使用蝶形运算合并结果
            VectorXcd result(n);
            for (int k = 0; k < n/2; k++) {
                // 计算旋转因子 W_n^k = e^(-2πik/n)
                double angle = -2.0 * M_PI * k / n;
                complex<double> t = polar(1.0, angle) * odd_fft[k];

                // 蝶形运算的合并步骤
                result[k] = even_fft[k] + t;                // 前半部分
                result[k + n/2] = even_fft[k] - t;         // 后半部分
            }

            return result;
        }
    }

    MatrixXcd fft(const MatrixXcd& X) {
        if (X.size() == 0) {
            return X;  // 空矩阵直接返回
        }

        // 对矩阵的每一列进行FFT，长度自动补充到2的幂
        int n = detail::next_power_of_two(X.rows());
        return fft(X, n, 1);  // 调用第三个重载版本
    }

    MatrixXcd fft(const MatrixXcd& X, int n) {
        if (X.size() == 0) {
            return X;
        }

        // 对矩阵的每一列进行n点FFT
        return fft(X, n, 1);
    }

    MatrixXcd fft(const MatrixXcd& X, int n, int dim) {
        if (X.size() == 0) {
            return X;
        }

        // 检查维度参数的有效性
        if (dim != 1 && dim != 2) {
            throw invalid_argument("维度参数必须为1或2");
        }

        MatrixXcd Y;
        if (dim == 1) {  // 对列进行FFT
            Y.resize(n, X.cols());
            for (int i = 0; i < X.cols(); i++) {
                // 提取每一列
                VectorXcd col(X.rows());
                for (int j = 0; j < X.rows(); j++) {
                    col[j] = X(j, i);
                }

                // 调整长度并计算FFT
                col = detail::pad_or_truncate(col, n);
                auto col_fft = detail::fft_impl(col);

                // 将结果存回矩阵
                for (int j = 0; j < n; j++) {
                    Y(j, i) = col_fft[j];
                }
            }
        } else {  // 对行进行FFT
            Y.resize(X.rows(), n);
            for (int i = 0; i < X.rows(); i++) {
                // 提取每一行
                VectorXcd row(X.cols());
                for (int j = 0; j < X.cols(); j++) {
                    row[j] = X(i, j);
                }

                // 调整长度并计算FFT
                row = detail::pad_or_truncate(row, n);
                auto row_fft = detail::fft_impl(row);

                // 将结果存回矩阵
                for (int j = 0; j < n; j++) {
                    Y(i, j) = row_fft[j];
                }
            }
        }
        return Y;
    }
}
