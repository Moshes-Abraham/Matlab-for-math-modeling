function gnew = vari(gold,pos)
  gnew = gold;
  if (gnew(pos) == '1')
    gnew(pos) = '0';   % one bug is here: typo of 0 to o :(
  else
    gnew(pos) = '1';
  end
end
