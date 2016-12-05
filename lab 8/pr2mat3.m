
    len=5;
    t=1;
    h=0.025
    ah=[-2;-1;0;1;2];
    b=[0;0;1];
    for i=1:len
        ah(i)=ah(i)*(h);
    end
    coeff=zeros(len,len);
    for i=1:len
        for j=1:len
            coeff(i,j)=(ah(i).^(j-1))/factorial(j-1);
        end
    end
    
    AS=coeff'^-1*b
    
    
    
  
    
    ans=0;
    for i=1: len
        t + ah(i)* h;
        ans=ans+(AS(i)*fx2(t + ah(i)* h));
    end
    ans
    
 
    
    
