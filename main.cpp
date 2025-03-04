#include "fft.h"
#include "conv.h"
using namespace std;
using namespace Eigen;
using namespace CONV;
int main() {
    // 创建一个3x2的复数矩阵作为测试数据
    MatrixXcd X(3, 2);
    X <<  complex<double>(1, 0), complex<double>(4, 0),
            complex<double>(2, 0), complex<double>(5, 0),
            complex<double>(3, 0), complex<double>(6, 0);

    // 默认对列进行变换
    // 输出长度将自动调整为大于等于原长度的最小2的幂
    MatrixXcd Y1 = FFTLibrary::fft(X);
    cout << "示例1 - 基本FFT变换 fft(X):" << endl << Y1 << endl << endl;

    // 示例2：指定长度的FFT变换
    // 将FFT变换的结果长度设置为8
    // 如果原长度小于8，将通过补零实现
    int n = 8;
    MatrixXcd Y2 = FFTLibrary::fft(X, n);
    cout << "示例2 - 指定长度FFT变换 fft(X, n=8):" << endl << Y2 << endl << endl;

    // 示例3：指定维度的FFT变换
    // dim=1表示对列进行变换（默认值）
    // dim=2表示对行进行变换
    int dim = 2;  // 对行进行变换
    MatrixXcd Y3 = FFTLibrary::fft(X, n, dim);
    cout << "示例3 - 指定维度FFT变换 fft(X, n=8, dim=2):" << endl << Y3 << endl;

    // 示例4：对FFT结果进行IFFT变换（应该恢复原始数据）
    MatrixXcd Y4 = FFTLibrary::ifft(Y1);
    cout << "示例4 - 基本IFFT变换 ifft(Y1):" << endl << Y4 << endl << endl;

    // 示例5：对指定长度FFT结果进行IFFT变换
    MatrixXcd Y5 = FFTLibrary::ifft(Y2, n);
    cout << "示例5 - 指定长度IFFT变换 ifft(Y2, n=8):" << endl << Y5 << endl << endl;

    // 示例6：对指定维度FFT结果进行IFFT变换
    MatrixXcd Y6 = FFTLibrary::ifft(Y3, n, dim);
    cout << "示例6 - 指定维度IFFT变换 ifft(Y3, n=8, dim=2):" << endl << Y6 << endl;

    // 示例7: 一维卷积示例
    cout << "\n示例7 - 一维卷积 conv(x, h):" << endl;
    // 创建输入信号
    VectorXcd x(4);
    x << complex<double>(1, 0), complex<double>(2, 0), 
         complex<double>(3, 0), complex<double>(4, 0);
    
    // 创建卷积核
    VectorXcd h(3);
    h << complex<double>(0.5, 0), complex<double>(1, 0), 
         complex<double>(0.5, 0);
    
    cout << "输入信号 x:" << endl << x << endl << endl;
    cout << "卷积核 h:" << endl << h << endl << endl;
    
    // 执行不同模式的卷积
    VectorXcd y_full = conv(x, h, "full");
    cout << "卷积结果 (full模式):" << endl << y_full << endl << endl;
    
    VectorXcd y_same = conv(x, h, "same");
    cout << "卷积结果 (same模式):" << endl << y_same << endl << endl;
    
    VectorXcd y_valid = conv(x, h, "valid");
    cout << "卷积结果 (valid模式):" << endl << y_valid << endl;

    return 0;
}