close all;
a=-3;
b=3;
itr=1000000;
dt=(b-a)/itr;
func=zeros(itr,1);
t=zeros(itr,1);
for i=1:itr
    func(i)=(1-exp(-(a+(i-1)*dt)^2));          %SAME CODE IN MATLAB
    t(i)=a+(i-1)*dt;
end
plot(t,func)
