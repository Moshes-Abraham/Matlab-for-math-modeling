function ri=CalculationRI()
ri=zeros(1,30);
for n=3:30   
    %n=20;  
    times=1000;  
    enum=[9 8 7 6 5 4 3 2 1 1/2 1/3 1/4 1/5 1/6 1/7 1/8 1/9];
    lamda = zeros(1, times);  
    A=ones(n,n);             

    for num=1:times         
        for i=1:n          
            for j=i+1:n
                A(i,j)=enum(ceil(17*rand(1)));
                A(j,i)=1/A(i,j);            
                A(i,i)=1;                  
            end
        end
        V=eig(A);              
        lamda(num)=max(V);    
    end

    k=sum(lamda)/times;  
    ri(n)=(k-n)/(n-1);  
end
ri 
