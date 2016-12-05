clear all;
pts=10;
x1=linspace(-1,1,pts);
y1=exp(x1);
plot(x1,y1);
x=linspace(-1,1,5);
n=5;
y=zeros(n,1);
for i=1:n
    y(i)=exp(x(i));
end

z=linspace(-1,1,pts);
ans=zeros(pts,1);
for i=1:pts
    p=z(i);
    val1=0;val=1;
    for j=1:5
        val=1;
        for k=1:5
            if(k==j)
                continue; 
            end
            val=val*(p-x(k))/(x(j)-x(k));
        end
        val1=val1+val*y(j);
  %      disp(val1);
    end
    ans(i)=val1;
end
figure;
plot(z,ans);
figure;
ans2=zeros(pts,1);
ans2=y1'-ans;
plot(z,ans2);



