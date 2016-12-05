
    result=zeros(5,1);
    len=3;
    t=1;
    h=0.1
    ah=[2;1;0];
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
        ans=ans+(AS(i)*fx2(t + ah(i)));
    end
    ans
    result(1)=ans;
    
 
    
   
    len=3;
    t=1;
    h=0.05
    ah=[2;1;0];
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
        ans=ans+(AS(i)*fx2(t + ah(i)));
    end
    ans
    result(2)=ans;
    
 
    
   
    len=3;
    t=1;
    h=0.025
    ah=[2;1;0];
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
        ans=ans+(AS(i)*fx2(t + ah(i)));
    end
    ans
    
    result(3)=ans;
 
    
   
    len=3;
    t=1;
    h=0.0125
    ah=[2;1;0];
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
        ans=ans+(AS(i)*fx2(t + ah(i)));
    end
    ans
    
    result(4)=ans;
 
    
       
   
    len=3;
    t=1;
    h=0.00625
    ah=[2;1;0];
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
        ans=ans+(AS(i)*fx2(t + ah(i)));
    end
    ans
    
    result(5)=ans;
 
    
    
    
    actual=fdx2(t)
    err=result-actual
    err=err.*err
    hs=[0.1;0.05;0.025;0.0125;0.00625]
    plot(hs,err)
    title('squared error')
