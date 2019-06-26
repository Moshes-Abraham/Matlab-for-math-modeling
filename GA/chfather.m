function V = chfather(V,record)
  %选择父染色体
  F = sum(record);   %计算所有染色体适应度之和
  pk = record / F;   %计算每个染色体选择概率
  %计算每个染色体积累概率
  qk = zeros(20,1,'double');
  for i = 1:20
    qk(i) = sum(pk(1:i));
  end

% 模拟转动轮盘20次
r = rand(20,1);   %r储存随机数，同时后续保存选择的染色体号
  for i = 1:20
    k = 1;
    while (r(i) > qk(k))
      k = k + 1;
    end
    r(i) = k;
  end
  %保存选择的新序列
  temp = V;
  for i = i:20
    V(i) = temp{r(i)};
  end
end

