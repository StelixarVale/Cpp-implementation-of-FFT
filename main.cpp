#include "fft.h"

using namespace std;
using namespace Eigen;

int main() {
    // 创建一个3x2的复数矩阵作为测试数据
    MatrixXcd X(3, 2);
    X <<  complex<double>(1, 0), complex<double>(4, 0),
            complex<double>(2, 0), complex<double>(5, 0),
            complex<double>(3, 0), complex<double>(6, 0);

    // 示例1：基本FFT变换
    // 对矩阵X进行FFT变换，默认对列进行变换
    // 输出长度将自动调整为大于等于原长度的最小2的幂
    MatrixXcd Y1 = FFTLibrary::fft(X);
    cout << "示例1 - 基本FFT变换 fft(X):" << endl << Y1 << endl << endl;

    // 示例2：指定长度的FFT变换
    // 将FFT变换的结果长度设置为4
    // 如果原长度小于4，将通过补零实现
    int n = 8;
    MatrixXcd Y2 = FFTLibrary::fft(X, n);
    cout << "示例2 - 指定长度FFT变换 fft(X, n=8):" << endl << Y2 << endl << endl;

    // 示例3：指定维度的FFT变换
    // dim=1表示对列进行变换（默认值）
    // dim=2表示对行进行变换
    int dim = 2;  // 对行进行变换
    MatrixXcd Y3 = FFTLibrary::fft(X, n, dim);
    cout << "示例3 - 指定维度FFT变换 fft(X, n=8, dim=2):" << endl << Y3 << endl;

    return 0;
}