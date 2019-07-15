function P = P2Vmax(P,Vmax)
  % > Vmax
  P(P > Vmax) = Vmax;  % Limit the velocity, if it's too high, set to vmax
  % < -Vmax
  P(P < -Vmax) = -Vmax;   % If the speed is too low, set to -vmax
end
