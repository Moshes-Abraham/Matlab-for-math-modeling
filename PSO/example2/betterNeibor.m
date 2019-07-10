function g = betterNeibor(pbest,i,g)
  % 在邻居中寻找最好的替代g
  M = size(pbest,1);
  pbe(1:i,:) = pbest(1:i,2);
  pbe(i+1:M,:) = pbest(i+1:M,2);
  temp0 = f(pbe(:,1));   % except i
  [~,temp] = min(temp0);   % minimum index
  temp = min(temp);   % min (minimum index)
  g(1) = temp0(temp);
  g(2) = pbe(temp,:);
end
