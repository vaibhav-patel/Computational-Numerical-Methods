close all;
a=-3;
b=3;
itr=1000000;
dt=(b-a)/itr;
func=zeros(itr,1);
t=zeros(itr,1);
for i=1:itr
    func(i)=(exp(-(a+(i-1)*dt)^2))*(2*(a+(i-1)*dt));      % PLOT OF DIFFERENTIATION OF THE FUCNTION
    t(i)=a+(i-1)*dt;
end
plot(t,func)
