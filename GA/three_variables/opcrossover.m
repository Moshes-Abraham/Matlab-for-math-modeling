function V = opcrossover(V)
  % one point crossover
  pc = 0.25;   % 发生杂交的概率
  l = 1;
  while (l == 1)
    r = rand(20,1);
    mk = find(r < pc);
    l = numel(mk);
  end
  if (mod(numel(mk),2) == 1)   % 由奇数个减少一个成偶数个
    mk = mk(1:end-1);
  end
  r1 = randi([1,32],1,numel(mk)/2);
  for i = 1:numel(mk)/2
    [V{mk(2 * (i - 1) + 1)}, V{mk(2 * (i - 1) + 2)}] = onecross(V{mk(2 * (i - 1) + 1)},...
      V{mk(2 * (i - 1) + 2)}, r1(i));   % 随机交换奇偶染色体的某一段编码
  end
end
