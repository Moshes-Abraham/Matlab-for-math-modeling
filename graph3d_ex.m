[x1,x2] = meshgrid(-3.0:.2:12.1);
Z = 21.5 + x1 * sin(4*pi*x1) + x2 * sin(20*pi*x2);
surf(Z)
