function splineans = spl(ansv,q,xs)
int=1;
n=size(xs,1);
for i=1:n-1
    if(xs(i)<=q  && xs(i+1)>=q)
        int=i;
    end
end



val=0;
for i=1:4
    ind=(n-1)*(i-1) +int;
    tmp=(q-xs(int));
    tmp=tmp^(i-1);
    val=val+ tmp* ansv(ind)  ; 
end

splineans=val;