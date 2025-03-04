#include "conv.h"
#include "fft.h"
using namespace FFTLibrary;
namespace CONV{
    VectorXcd conv(const VectorXcd& x, const VectorXcd& h, const string& mode) {
        // 卷积的FFT实现
        int n = x.size();
        int m = h.size();
        // 检查valid模式的有效性
        if (mode == "valid" && n < m) {
            throw invalid_argument("valid模式要求输入信号长度不小于卷积核长度");
        }
        // 确定完全卷积的输出长度
        int full_size = n + m - 1;
        // 找到大于等于full_size的最小2的幂
        int fft_size = detail::next_power_of_two(full_size);
        // 对输入信号和卷积核进行补零
        VectorXcd x_padded = detail::pad_or_truncate(x, fft_size);
        VectorXcd h_padded = detail::pad_or_truncate(h, fft_size);
        // 计算FFT(将时域转换为频域)
        VectorXcd X_fft = detail::fft_impl(x_padded);
        VectorXcd H_fft = detail::fft_impl(h_padded);
        // 频域相乘（时域卷积等于频域相乘）
        VectorXcd Y_fft = X_fft.array() * H_fft.array();
        // 计算IFFT(将频域转换为时域)
        VectorXcd y_full = detail::ifft_impl(Y_fft, true);
        int output_size;
        int start_idx = 0;
        if (mode == "full") {
            output_size = full_size;
        } else if (mode == "same") {
            output_size = n;
            start_idx = (full_size - n) / 2;
        } else if (mode == "valid") {
            output_size = n - m + 1;
            start_idx = m - 1;
        } 
        // 虽然y_full大小是fft_size,但只有前full_size个元素是有效的
        VectorXcd y = y_full.segment(start_idx, output_size);
        return detail::clear_small_values(y);
    }
}