function [g,pbes] = pb(P)
  pbes(:,1) = f(P(:,1));   % first col save f(x1,x2)
  pbes(:,2) = P(:,1);
  [~,temp1] = min(pbes);   % minimum
  %temp1 = min(temp1);   % avoid repeative value
  temp1 = temp1(1);   % avoid repeative value
  g(1) = pbes(temp1);
  g(2) = P(temp1,1);
end
