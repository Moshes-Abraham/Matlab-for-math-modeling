function gnew = vari(gold,pos)
  gnew = gold;
  if (gnew(pos) == '1')
    gnew(pos) = 'o';
  else
    gnew(pos) = '1';
  end
end
