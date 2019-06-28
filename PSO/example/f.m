function g = f(x1,x2)
  g = 0.5 + (sin(sqrt(x1.^2 + x2.^2)).^2 - 0.5) ./ (1 + 0.001 * (x1.^2 + x2.^2)).^2;
end
