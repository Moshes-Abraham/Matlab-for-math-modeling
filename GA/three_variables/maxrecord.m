function maxrec = maxrecord(record,V)
  % Keep the max value
  [m,i] = max(record);   % stord the maximum value to m and the index of it to i.
  maxrec(1,1) = m;
  temp1 = V{i};
  temp2 = temp1(1:11);
  temp3 = temp1(12:22);
  temp4 = temp1(23:end);
  maxrec(2,1) = bin_x(temp2,1);    % stands for x1
  maxrec(3,1) = bin_x(temp3,2);    % stands for x2
  maxrec(4,1) = bin_x(temp4,3);    % stands for x3
end
