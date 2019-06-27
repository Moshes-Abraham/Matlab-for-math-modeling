%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% These outputs which you may not want to save
% for a long time will be deleted after reboot.


%% Discription

%  This is a file for providing a function of optimizing a function using GA algorithm. The codes below is for calculating the maximum value for a function with 2 variables. You can change the function imputs to (n,f) to support more functions.
%  Inputs:    ...
%  Outputs:   ...
%  something else ...

%% The codes start  here
function here(n)
% Objective function

f = @(x1,x2)21.5 + x1 * sin (4 * pi * x1) + x2 * sin(20 * pi * x2);

% Initial group
v = cell(1,20);

for i = 1:20
  temp1 = round(rand(1,33));   % 初始化染色体编码
  temp2 = vec2str(temp1);
  v{i} = temp2;
end
clear temp1 temp2   % 记得清除之后无用的变量

% 计算初始组的适应度，并计算其中的最大值
record = adapt(v,f);
maxrec = maxrecord(record,v);

% Loop for better result
tic   %记录运算时间
for i = 1:n
  v = chfather(v,record);   %选择父染色体

  % genetic operator
  v = opcrossover(v);   %杂交
  v = variation(v);   %变异

  record = adapt(v,f);   %计算新的适应度
  temp = maxrecord(record,v);

  if (temp(1,1) > maxrec(1,1))   %保持最优值
    maxrec = temp;
    mark = i;  % another typo :'(
  end
end

time = toc;

% Outputs
format long
fprintf('            x1: %f\n',maxrec(2));
fprintf('            x2: %f\n',maxrec(3));
fprintf('      f(x1,x2): %f\n',maxrec(1));
fprintf('          from: %1.0f(th) generation \n',mark);
fprintf('          time: %f s\n',time);
end
















































