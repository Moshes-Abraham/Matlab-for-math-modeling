%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
diary /tmp/min
% These outputs which you may not want to save
% for a long time will be deleted after reboot.


%% Discription

%  For find the minimum of a function with 2 variables.
%  Inputs:    ...
%  Outputs:   ...
%  main function

%% The codes start  here


%% genetic algorithm

clc; close all; clear all;

% 进化的代数
T = 100;
optionsOrigin = gaotimset('Generations',T/2)
[x,fval,reason,output,finnal_pop] = ga(@graph,2,optionsOrigin)

% 进行第二次接力进化
optionsl = gaoptimset('Generations',T/2,;InitialPopulation,finnal_pop,'PlotFcns',@gaplotbestf);
[x,fval,reason,output,finnal_pop] = ga(@graph,2,optionsl);
Best_x = x
BestFval = fval










%
