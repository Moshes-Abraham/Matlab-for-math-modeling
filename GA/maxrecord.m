function maxrec = maxrecord(record,V)
  % Keep the max value
  [m,i] = max(record);
  maxrec(1,1) = m;
  temp1 = V{i};
  temp2 = temp1(1:18);
  temp3 = temp1(19:end);
  maxrec(2,1) = bin_x(temp2,1);
  maxrec(3,1) = bin_x(temp3,2);
end
