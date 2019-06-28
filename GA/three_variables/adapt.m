function record = adapt(V,f)
  % 计算二级制的适应值
  record = zeros(20,1,'double');
  for i = 1:20
    temp1 = V{i};
    temp2 = temp1(1:11);   % Stands for x1
    temp3 = temp1(12:22);   % Stands for x2
    temp4 = temp1(23:end);   % Stands for x3
    record(i,1) = f(bin_x(temp2,1),bin_x(temp3,2),bin_x(temp4,3));
  end
end
