% MATLAB验证脚本
% 用于验证C++实现的FFT结果

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
disp('示例3 - 行方向8点FFT变换结果:');
disp(Y3);
