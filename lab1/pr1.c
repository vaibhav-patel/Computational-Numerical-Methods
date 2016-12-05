#include<stdio.h>
#include<math.h>
const double e=M_E;
double f(double x)  // this is fx
{
    return (1-pow(e,-x*x));
}
double fd(double x) //this is f'x
{
    return (2*x)*(pow(e,-x*x));
}

int main()
{
    int itr=100;  //hardcoded the number of iterations
                   // FOR STOPPING CRITERIA
    double ratio[itr]; // stores the ratio
                        //speed of decreasing slope
    double xs[itr];     // xs stores the updated value of x at every point
    xs[0]=1.0;
    int i=1;
    for(;i<itr;i++)
    {
        xs[i]=xs[i-1] - (f(xs[i-1])) /  (fd(xs[i-1]));    
        if((xs[i]-xs[i-1]>=-0.000000001)&&(xs[i]-xs[i-1]<=0.000000001))   //STOPPING CONDITION, IF CONVERGES IN FEWER THAN 100 ITERATIONS
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
    return 0;
}
