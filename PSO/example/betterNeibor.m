function g = betterNeibor(pbest,i,g)
  % 在邻居中寻找最好的替代g
  M = size(pbest,1);
  pbe(1:i-1,:) = pbest(1:i-1,2:3);
  pbe(1:M-1,:) = pbest(i+1:M,2:3);
  temp0 = f(pbe(:,1),pbe(:,2));   % except i
  [~,temp] = min(temp0);   % minimum index
  temp = min(temp);   % min (minimum index)
  g(1) = temp0(temp);
  g(2:3) = pbe(temp,:);
end
