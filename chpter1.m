%% example-1
x = [1:9];
y = [9 7 6 3 -1 2 5 7 20];

p = polyfit(x,y,3)

xi = 0:.1:10;
yi = polyval(p,xi);
plot(xi,yi,'-b',x,y,'r*')


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
diary ~/.tmp/matlab-log/test.txt
% The outputs below will be store in a tmp file.
%% 人口几预测模几型
clear
clc
% 读取数据
Y = [33815 33918 34004 34165 34212 34327 34344 34458 34498 34476 34483 34488 34513 34497 34511 34520 34507 34509 34521 34513 34515 34517 34519 34519 34521 34521 34523 34525 34525 34527];
T = 1:30;

% 线性化处理
for t = 1:30
  x(t) = exp(-t);
  y(t) = 1/Y(t);
end

c = zeros(30,1) + 1;
X = [c,x'];
B = inv(X'*X)*X'*y';

for i = 1:30
  z(i) = B(1,1) + B(2,1) * x(i);

  s(i) = y(i) - sum(y)/30;

  w(i) = z(i) -y(i);
end

S = s*s';

Q = w*w';

U = S - Q;

F = 28 * U/Q;
for j = 1:30
  Y(j) = 1/(B(1,1) + B(2,1) * exp(-j));
end
plot(T,Y)

diary off
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% example-2

