% MATLAB验证脚本
% 用于验证C++实现的FFT和卷积结果

% 创建测试矩阵
X = [1+0i, 4+0i;
     2+0i, 5+0i;
     3+0i, 6+0i];

% 显示原始矩阵
disp('原始矩阵 X:');
disp(X);

% 示例1：对列进行4点FFT
Y1_col1 = fft(X(:,1), 4);  % 第一列
Y1_col2 = fft(X(:,2), 4);  % 第二列
Y1 = [Y1_col1, Y1_col2];
disp('示例1 - 4点FFT变换结果:');
disp(Y1);

% 示例2：对列进行8点FFT
Y2_col1 = fft(X(:,1), 8);  % 第一列
Y2_col2 = fft(X(:,2), 8);  % 第二列
Y2 = [Y2_col1, Y2_col2];
disp('示例2 - 8点FFT变换结果:');
disp(Y2);

% 示例3：对行进行8点FFT
Y3 = zeros(3,8);  % 预分配结果矩阵
for i = 1:3
    Y3(i,:) = fft(X(i,:), 8);  % 对每一行进行FFT
end
disp('示例3 - 对行进行8点FFT变换结果:');
disp(Y3);

% 示例4：对列进行IFFT
Y4_col1 = ifft(Y1_col1);  % 第一列
Y4_col2 = ifft(Y1_col2);  % 第二列
Y4 = [Y4_col1, Y4_col2];
disp('示例4 - IFFT变换结果:');
disp(Y4);

% 示例5：对列进行8点IFFT
Y5_col1 = ifft(Y2_col1);  % 第一列
Y5_col2 = ifft(Y2_col2);  % 第二列
Y5 = [Y5_col1, Y5_col2];
disp('示例5 - 8点IFFT变换结果:');
disp(Y5);

% 示例6：对行进行8点IFFT
Y6 = zeros(3,8);  % 预分配结果矩阵
for i = 1:3
    Y6(i,:) = ifft(Y3(i,:));  % 对每一行进行IFFT
end
disp('示例6 - 对行进行8点IFFT变换结果:');
disp(Y6);

% 示例7：卷积验证
disp('示例7 - 一维卷积验证:');

% 创建输入信号
x = [1+0i; 2+0i; 3+0i; 4+0i];
disp('输入信号 x:');
disp(x);

% 创建卷积核
h = [0.5+0i; 1+0i; 0.5+0i];
disp('卷积核 h:');
disp(h);

% 执行不同模式的卷积
% full模式
y_full = conv(x, h, 'full');
disp('卷积结果 (full模式):');
disp(y_full);

% same模式
y_same = conv(x, h, 'same');
disp('卷积结果 (same模式):');
disp(y_same);

% valid模式
y_valid = conv(x, h, 'valid');
disp('卷积结果 (valid模式):');
disp(y_valid);