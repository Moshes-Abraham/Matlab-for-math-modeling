function P = P2Vmax(P,Vmax)
  % > Vmax
  P(P > Vmax) = Vmax;
  % < -Vmax
  P(P < -Vmax) = -Vmax;
end
