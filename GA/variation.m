function V = variation(V)
  % variate operator
  pm = 0.01;
  for i = 1:20
    r = rand(33,1);
    k = find(r < pm);
    for j = 1:numel(k)
      V{i} = vari(V{i},k(j));
    end
  end
end
