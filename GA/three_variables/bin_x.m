function num = bin_x(bin,opt)
  %直接将二进制字符串转化为题中的x1
  switch opt
    case 1
      num = -3.0 + bin2dec(bin) * ((12.1 - (-3.0))/(2^11 - 1));
    case 2
      num = 4.1 + bin2dec(bin) * ((5.8 - 4.1)/(2^11 - 1));
    case 3
      num = 2.1 + bin2dec(bin) * (6.7 - 2.1)/(2^11 - 1);
  end
end
