%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
diary /tmp/outputs
% These outputs which you may not want to save
% for a long time will be deleted after reboot.


%% Discription

%  for a test
%  Inputs:    nil
%  Outputs:   nil
%  nil

%% The codes start  here


x = [-10:0.05:10]
y = sin(2.*x)


plot(x,y,'b-')

t = y.^2
hold on
plot(x,t,'-r')












































diary off
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
