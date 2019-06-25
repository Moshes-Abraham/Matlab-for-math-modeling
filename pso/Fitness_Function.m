
% ------------------------------------------------------------------------------%
% 适应度函数，本程序使用的是第三个适应度函数Ackley
function Fitness = Fitness_Function(Pos,F_n,Dimension)
 switch F_n
    case 1
        Func_Sphere=Pos(:)'*Pos(:);
        Fitness=Func_Sphere;
    % Griewank函数
    case 2
        res1 = Pos(:)'*Pos(:)/4000;
        res2 = 1;
        for row = 1:Dimension
            res2 = res2 * cos(Pos(row) / sqrt(row));
        end
        Func_Griewank = res1 - res2 + 1;
        Fitness = Func_Griewank;
     case 3
        %Ackley 函数
        %输入x,给出相应的y值,在x=(0,0,…,0) 处有全局极小点0,为得到最大值，返回值取相反数
        %编制人：
        %编制日期：
        [row,col]=size(Pos');
        Fitness = -20*exp(-0.2*sqrt((1/col)*(sum(Pos'.^2))))-exp((1/col)*sum(cos(2*pi.*Pos')))+exp(1)+20;
        Fitness = -Fitness;

  end
end
