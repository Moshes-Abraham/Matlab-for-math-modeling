function V = variation(V)
  % variate operator
  pm = 0.01;   %设定变异概率为0.01
  for i = 1:20
    r = rand(33,1);
    k = find(r < pm);   % 随机产生需要变异的位置
    for j = 1:numel(k)
      V{i} = vari(V{i},k(j));
    end
  end
end
