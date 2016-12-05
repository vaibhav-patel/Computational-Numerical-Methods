close all;
tic;
A=[4 4 0 1;
    1 4 1 0;
    0 1 4 1;
    1 0 1 4];

b=[2;-2;2;-2];

D=zeros(size(A));  % the diagonal matrix
U=zeros(size(A)); % the upper triangular matrix
L=zeros(size(A)); %the lower triangular matrix


% initializing the Matrices*
for i=1:size(A,1)
    for j=1: size(A,2)
        if(i<j)
            U(i,j)=A(i,j);
        end
        if(i>j)
            L(i,j)=A(i,j);
        end
        if(i==j)
            D(i,i)=A(i,i);
        end
    end
end

inDpL=(D+L)^-1;
%the H
H=inDpL*(U);
H=-H;

%the C
C=inDpL*b;

iter=50;
X=[0;0;0;0];
for i=1: iter
    X=H*X+C;
    err=A*X-b;
    sum=0;
    if i==4
        'after 4 iterations answer'
        X
        'but the accurate answer is'
    end
    for j=1:size(err,1)
        sum=sum+abs(err(j));
    end
    if sum<0.0006&&sum>-0.0006
        'number of iterations are' 
        i
        break;
    end
end
X

'Here we can see that it is taking less number of iterations than the Jacobi iteration method '
'Because here we are taking inverse of D+L '
'But calculating its inverse is much slower process'

toc;