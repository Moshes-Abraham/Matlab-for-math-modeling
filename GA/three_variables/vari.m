function gnew = vari(gold,pos)   % 在该位置下转换0和1
  gnew = gold;
  if (gnew(pos) == '1')
    gnew(pos) = '0';   % one bug is here: typo of 0 to o :(
  else
    gnew(pos) = '1';
  end
end
