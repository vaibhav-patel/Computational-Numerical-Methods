#include<stdio.h>
#include<math.h>
const double e=M_E;
double f(double x)// this is fx
{
    return (x+pow(e,x));
}
double fd(double x)//this is f'x
{
    return 1+f(x)-x;
}
int main()
{
    int itr=100;    //hardcoded the number of iterations
                    // FOR STOPPING CRITERIA
    double ratio[itr];  // stores the ratio
                        //speed of decreasing slope
    double xs[itr];     // xs stores the updated value of x at every point
    xs[0]=1.0;
    int i=1;
    for(;i<itr;i++)
    {
        xs[i]=xs[i-1] - (f(xs[i-1])) /  (fd(xs[i-1]));
        if((xs[i]-xs[i-1]>=-0.00000001)&&(xs[i]-xs[i-1]<=0.00000001))  //STOPPING CONDITION, IF CONVERGES IN FEWER THAN 100 ITERATIONS
            break;
            
    }
    int j=0;
    double alpha=xs[i-1];
    for(;j<i-1;j++)
    {   
        ratio[j]=(alpha - xs[j+1])/ ((alpha-xs[j])*(alpha-xs[j]));
        printf("ratio on itr %d      %lf\n",j+1,ratio[j]);
    }
    printf("%lf %d\n",xs[i],i);
    
    // by bisection method
    double a=-1.000;
    double b=0.000;
    double c;
    int count=0;
    while(1)
    {
        count++;
        c=(a+b)/2.0;
        if((f(c)<0.00000001)&&(f(c)>-0.00000001))          //STOPPING CONDITION, IF CONVERGES IN FEWER THAN 100 ITERATIONS
            break;
        else if(f(c)*f(a) <0.0)                      //IN WHICH DIRECTION TO GO
        {   
            b=c;
        }
        else if(f(c)*f(a) > 0.0 ) //IN WHICH DIRECTION TO GO
        {   
            a=c;
        }
    }
    printf("result by bisection method      %lf   in iter %d \n",c,count);
    
    
    return 0;
}
