%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
diary ~/.tmp/matlab-log/outputs
% The outputs below will be store in a tmp file.

% Linear programming
%% test1
c = [2 3 1]';
a = [1 4 2;3 2 0];
b = [8;6];
[~,y] = linprog(c,-a,-b,[],[],zeros(3,1));



diary off
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% test2
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
diary ~/.tmp/matlab-log/outputs
% The outputs below will be store in a tmp file.

z = [-5;-4;-6];
a = [1 -1 1;3 2 4;3 2 0];
b = [20;42;30];
[x,fval,exitflag,output,lambda] = linprog(z,a,b,[],[],zeros(3,1));

diary off
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

