%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% These outputs which you may not want to save
% for a long time will be deleted after reboot.


%% Discription

%  This is a file for ...
%  Inputs:    ...
%  Outputs:   ...
%  something else ...

%% The codes start  here
function pso(N,M)

  % Initial settings
  % M = 20, popsize
  % N = 1000, max interactive times
  if ( nargin < 2 )
    M = 20;
  end
  if ( nargin < 1 )
    N = 1000;
  end

  % set constant values
  w = 0.9; c1 = 2; c2 = 2; vmax = 3;

  % Initial group
  P(:,1) = 200 * rand(M,1) - 100;   %第一列为x
  P(:,2) = 6 * rand(M,1) - 3;   %第二列为v
  [g,pbest] = pb(P);   % g的第一列为f(x1,x2)的最小值，二列为x, 即g为全局最优解．pbest的第一列为所有粒子的函数值，二列为x

  % Loop for result
  j = 0; % 迭代计数器
  tic
  while j < N
    for i = 1:M
      % Exchange message between each other
      if( f(P(i,1)) < f(pbest(i,2)) )
        pbest(i,2) = P(i,1);
        pbest(i,1) = f(P(i,1));
      end
      g = pbest(i,:);   % update g by Piself
      g = betterNeibor(pbest,i,g);   % update g vs neighbour

      % update position and speed of Pi
      % update Px
      P(i,2) = w * P(i,2) + c1 * rand * (pbest(i,1) - P(i,1)) ...
        + c2 * rand * (g(2) - P(i,1));
      P(i,2) = P2Vmax(P(i,2),vmax);
      % update Pv
      P(i,1) = P(i,1) + P(i,2);
    end
    j = j + 1;
  end
  time = toc;

  result(g,time)


end



















































%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
