function tw=tolsortvec(utw,dw,CIC,RIC)
    tw=dw*utw;
    CR=utw'*CIC/(utw'*RIC);
    CR
    if CR>=0.10
        disp('层次总排序没通过一致性检验，请重新调整判断矩阵');
    else
        disp('层次总排序通过一致性检验');
    end
end
