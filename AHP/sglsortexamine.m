function [RI,CI]=sglsortexamine(maxeigval,A,RIT)
    n=size(A,1);
    % RIT=[0,0,0.58,0.90,1.12,1.24,1.32,1.41,1.49,1.51];
    RI=RIT(n);
    CI=(maxeigval-n)/(n-1);
    CR=CI/RI;
    CI
    CR
    if CR>=0.10
        disp('矩阵没通过一致性检验，请重新调整判断矩阵');
    else
        disp('矩阵通过一致性检验');
    end
end
