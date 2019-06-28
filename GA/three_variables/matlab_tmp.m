  for i = 1:20
    qk(i) = sum(pk(1:i));
  end
delete('matlab_tmp.m');
