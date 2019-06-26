function str = vec2str(vec)
  % convert num vector to string.
  len = length(vec);
  str = '';
  for i = 1:len
    temp = num2str(vec(i));
    str = strcat(str,temp);
  end
end
