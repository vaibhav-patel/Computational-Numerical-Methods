#include<stdio.h>
#include<math.h>
const double e=M_E;
const double eps=0.000001;

// for calculating f(x)
double f(double x)
{
    return (cos(x) -x*pow(e,x));
}

// for calculating f'(x)
double fd(double x)
{
    return (-sin(x) - pow(e,x)*(1+x));
}

// for calculating f"(x)
double fdd(double x)
{
    return (-cos(x) - pow(e,x)*(2+x) );
}
int main()
{
    int itr=1000;
    double ratio[itr];
    double xs[itr];
    xs[0]=0;
    int i=1;
    
    // iterative solution starts here
    for(;i<itr;i++)
    {
        xs[i]=xs[i-1] - (f(xs[i-1])) /  (fd(xs[i-1])); // calculating x(n+1) using x(n)
       
        // stopping method if error is less than eps
        double ft=xs[i]-xs[i-1];
        if(ft<0) ft=ft*-1;
        double st=f(xs[i]);
        if(st<0) st=st*-1;
        if(ft+st <=eps)
            break;
                        
    }
    
    printf("answer by newton's method %lf with iterations %d\n",xs[i],i);
    
    
    
    //secant method
    
    double x[itr];
    x[0]=0.0;
    x[1]=1;
    int j=2;
    
    // iterative solution starts here
    for (;j<=itr-1;j++)
    {
        double fxk=f(x[j-1]);
        double fxkm=f(x[j-2]);
        
        x[j]=x[j-1]-((x[j-1]-x[j-2])/ (fxk-fxkm) ) *(fxk); // calculating x(n+1) using x(n) and x(n-1)
           // stopping method if error is less than eps
        double ft=x[j]-x[j-1];
        if(ft<0) ft=ft*-1;
        double st=f(x[j]);
        if(st<0) st=st*-1;
        
        if(ft+st <=eps)
            break;
    }
    
    printf("answer by secant method %lf   with iterations   %d\n",x[j],j);
  
    // another method
    double x3[itr];
    x3[0]=1;
    int k=1;
    
    // iterative solution starts here
    for (;k<=itr-1;k++)
    {
        double fx=f(x3[k-1]);
        double fdx=fd(x3[k-1]);
        double fddx=fdd(x3[k-1]);
        
        
        x3[k]=x3[k-1] -(fx/fdx) -0.5*(fx/fdx)*(fx/fdx)*(fddx/fdx);    // calculating x(n+1) using x(n)      
        double ft=x3[k]-x3[k-1];
        
        // stopping method if error is less than eps
        if(ft<0) ft=ft*-1;
        double st=f(x3[k]);
        if(st<0) st=st*-1;
        if(ft+st <=eps)
            break;
    }
    
    printf("answer by another method %lf   with iterations   %d\n",x3[k],k);

    
   
    return 0;
}
