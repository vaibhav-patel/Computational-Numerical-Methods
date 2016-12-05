clear all;
pts=100;

test_x_start=-4
test_x_end=4

input_x_start=-1
input_x_end=1

xmanypts=linspace(test_x_start,test_x_end,pts);
y1=exp(xmanypts);
plot(xmanypts,y1);   % plotting e^x
% above were the true fucntion values




%now the interpolating polynomial
x=linspace(input_x_start,input_x_end,5);
n=5;   % number of data points we have
y=zeros(n,1);
for i=1:n
    y(i)=exp(x(i));   % and their true value for those 5 data points
end



% now we are interpolating this using above 5 points
% and checking them with 100 data points in this range
z=linspace(test_x_start,test_x_end,pts);
interpolate=zeros(pts,1);
% lagrange interpolating polynomial
%initialization


%for every point using the interpolation formula

for  i=1: pts
   p=z(i); %point
   
       inter=0;
   for j=1:n
      
       inner_value=1;
       for k=1:n
           if(k==j)
               continue
           end
           inner_value=inner_value*(p-x(k))/(x(j)-x(k));
           % finding lagrange polynomial
       end
       inter=inter +inner_value*y(j);
       
   end
   interpolate(i)=inter;
end


hold on
plot(z,interpolate);


% now we are implementing taylor series
% and checking them with 100 data points in this range
z=linspace(test_x_start,test_x_end,pts);
taylor=zeros(pts,1);

% taylor series
%for every point using the taylor series

for  i=1: pts
   p=z(i); %point
   x0=0;  %index =1
   idx=1; %index of X0
   h= p-x0;  %difference between p and X0
   % here, any higher order differentiation is simply the function itself
   taylor_value= y(idx) + h*y(idx)+ (h^2)*y(idx)/2 + (h^3)*y(idx)/6 +(h^4)*y(idx)/24 ;
   taylor(i)=taylor_value;
end


hold on;
plot(z,taylor);
legend('e^x (exact)','interpolating','taylor values');
title('comparing all the methods  (nearly exact in [-1,1]) (interpolation is accurate)');
%interpolation is more accurate



