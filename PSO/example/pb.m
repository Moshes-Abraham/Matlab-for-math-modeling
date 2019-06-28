function [g,pbes] = pb(P)
  pbes(:,1) = f(P(:,1),P(:,2));   % first col save f(x1,x2)
  pbes(:,2:3) = P(:,1:2);
  [~,temp1] = min(pbes);   % minimum
  temp1 = min(temp1);   % avoid repeative value
  g(1) = pbes(temp1);
  g(2:3) = P(temp1,1:2);
end
