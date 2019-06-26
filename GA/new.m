%%
x = -pi/2:0.01:pi;
y = sin(x)+2*cos(x);
figure(1)
plot(x,y.^2,'-b')
grid on

diary ~/.tmp/matlab-log/outputs
% The outputs below will be store in a tmp file.


figure(2)
t = 0:0.01:pi
v = log(t) .* abs(sin(t))
plot(t,v,'-r')
grid on

diary off


%%
diary ~/.tmp/matlab-log/outputs
% The outputs below will be store in a tmp file.

x = -3:0.1:3;
y = sinh(x)
plot(x,y,'-r')

diary off




%　这里可以写中文注释！

diary ~/.tmp/matlab-log/outputs
% The outputs below will be store in a tmp file.



diary off











