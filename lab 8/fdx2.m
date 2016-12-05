function y = fdx2(x)
    p=(100*x*x -199*x+100);
    pp=1+p*p;
    dp=200*x-199;
    y=(pp*200 -dp*2*p*dp)/(pp*pp);
end