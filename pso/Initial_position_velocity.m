
%--------------------------------------------------------------%
% 初始化函数
function [Position,Velocity] = Initial_position_velocity(Dimension,Size,Xmax,Xmin,Vmax,Vmin)
  for i=1:Dimension
      % 产生合理范围内的随机位置，rand(1,Size)用于产生一行Size个随机数
      Position(i,:)=Xmin(i)+(Xmax(i)-Xmin(i))*rand(1,Size);
      Velocity(i,:)=Vmin(i)+(Vmax(i)-Vmin(i))*rand(1,Size);
  end
end
