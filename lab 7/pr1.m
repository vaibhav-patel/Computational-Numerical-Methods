clear;
close all;
n=6;
xs=zeros(n,1);
fxs=zeros(n,1);

xs(1)=1;
xs(2)=2;
xs(3)=3;
xs(4)=5;
xs(5)=7;
xs(6)=8;

fxs(1)=3;
fxs(2)=6;
fxs(3)=19;
fxs(4)=99;
fxs(5)=291;
fxs(6)=444;

%cubic spline

tot_var=4*(n-1);
arr=zeros(tot_var,tot_var);
b=zeros(tot_var,1);

% first constraint
for i=1:n-1
    arr(i,i)=1;
    b(i)=fxs(i);
end

% second constraint   
l=1;
for i=1:n-1
    for j=1:4
        arr(l*(n-1) + i, (j-1)*(n-1) +  i )=  (xs(i+1)-xs(i))^(j-1) ;
    end
    if(i<=n-2)
        arr(l*(n-1) + i , (n-1) + i +1 )=  -1 ;    
    end
end

%continuity constraint
b(2*(n-1))=fxs(n);

% third constraint   
l=2;
for i=1:n-2
    for j=1:4
        arr(l*(n-1) + i, (j-1)*(n-1) +  i )= (j-1)*((xs(i+1)-xs(i))^(j-1))  ;
    end
        arr(l*(n-1) + i, 2*(n-1) +  i+1 )= -1;    
end
arr(3*(n-1), 2*(n-1) +1) = 1 ;


% fourth constraint   
l=3;
for i=1:n-1
    for j=1:4
        arr(l*(n-1) + i, (j-1)*(n-1) +  i )= (j-2)*(j-1)*((xs(i+1)-xs(i))^(j-1))  ;
    end
    if(i<=n-2)  
        arr(l*(n-1) + i, 3*(n-1) +  i +1 )= -2;
    end
end

arr
b

anst= (arr^(-1));
anst=anst*b;
anst


q=2.5
%spl(ans,q,xs)


spl(anst,3.0,xs);



a=linspace(1,8,1000);
vv=zeros(1000,1);
for i=1:1000
    vv(i)=spl(anst,a(i),xs);
end
plot(a,vv)

