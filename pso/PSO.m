%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
diary /tmp/PSO
% These outputs which you may not want to save
% for a long time will be deleted after reboot.


%% Discription

%  This is a file for trying an algorithm called PSO
%  Inputs:    ...
%  Outputs:   ...
%  something else ...

%% The codes start  here


% POS主程序
c1=1;%学习率
c2=1;%学习率
Dimension=20;
Size=30;
Tmax=600;
V_max=200;%粒子最大速度

F_n=3;%测试函数名

Fun_Ub=800;%函数上下界
Fun_Lb=-800;
Position=zeros(Dimension,Size);%粒子位置
Velocity=zeros(Dimension,Size);%粒子速度
Vmax(1:Dimension)=V_max;%粒子速度上下界
Vmin(1:Dimension)=-V_max;
Xmax(1:Dimension)=Fun_Ub;%粒子位置上下界，即函数自变量的上下界
Xmin(1:Dimension)=Fun_Lb;
[Position,Velocity]=Initial_position_velocity(Dimension,Size,Xmax,Xmin,Vmax,Vmin);

Ebest_Pos=Position;%粒子的历史最优位置，初始值为粒子的起始位置，存储每个粒子的历史最优位置
Gbest_position=zeros(Dimension,1);%全局最优的那个粒子所在位置，初始值认为是第1个粒子

for j=1:Size
    Pos=Position(:,j);%取第j列，即第j个粒子的位置
    fz(j)=Fitness_Function(Pos,F_n,Dimension);%计算第j个粒子的适应值
end
[Gbest_Fitness,I]=min(fz);%求出所有适应值中最小的那个适应值，并获得该粒子的位置
Gbest_position=Position(:,I);%取最小适应值的那个粒子的位置，即I列

for itrtn=1:Tmax
    time(itrtn)=itrtn;

    Weight=1;
    r1=rand(1);
    r2=rand(1);

    for i=1:Size
        Velocity(:,i)=Weight*Velocity(:,i)+c1*r1*(Ebest_Pos(:,i)-Position(:,i))+c2*r2*(Gbest_position-Position(:,i));
    end
    %限制速度边界
    for i=1:Size
        for row=1:Dimension
            if Velocity(row,i)>Vmax(row)
                Veloctity(row,i)=Vmax(row);
            elseif Velocity(row,i)<Vmin(row)
                Veloctity(row,i)=Vmin(row);
            else
            end
        end
    end

    Position=Position+Velocity;

    %限制位置边界
    for i=1:Size
        for row=1:Dimension
            if Position(row,i)>Xmax(row)
                Position(row,i)=Xmax(row);
            elseif Position(row,i)<Xmin(row)
                Position(row,i)=Xmin(row);
            else
            end
        end
    end

    for j=1:Size
        P_position=Position(:,j)';%取一个粒子的位置
        fitness_p(j)=Fitness_Function(P_position,F_n,Dimension);
        if fitness_p(j)< fz(j) %粒子的适应值比运动之前的适应值要好，更新原来的适应值
            Ebest_Pos(:,j)=Position(:,j);
            fz(j)=fitness_p(j);
        end
        if fitness_p(j)<Gbest_Fitness
            Gbest_Fitness=fitness_p(j);
        end
    end
    [Gbest_Fitness_new,I]=min(fz);% 更新后的所有粒子的适应值，取最小的那个，并求出其编号
    Best_fitness(itrtn)=Gbest_Fitness_new; % 记录每一代的最好适应值
    Gbest_position=Ebest_Pos(:,I);% 最好适应值对应的个体所在位置
end
plot(time,Best_fitness);
xlabel('迭代的次数');ylabel('适应度值F');
















































diary off
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
