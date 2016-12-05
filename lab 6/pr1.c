#include<stdio.h>
#include<math.h>
const double e=M_E;
const double eps=0.000001;

double quadratic(double x,  double xi0, double xi, double xi1,  double fxi0, double fxi, double fxi1)
{
    double ret = 0;
    ret = ((x - xi) * (x - xi1) * fxi0) / ((xi0 - xi) * (xi0 - xi1)) + ((x - xi0) * (x - xi1) * fxi) / ((xi - xi1) * (xi - xi0)) + ((x - xi0) * (x - xi) * fxi1) / ((xi1 - xi0) * (xi1 - xi));
    return ret;
}
double cubic(double x,  double xi0, double xi, double xi1, double xi2, double fxi0, double fxi, double fxi1, double fxi2)
{
    double ret = 0;
    ret = ((x - xi) * (x - xi1) * (x - xi2) * fxi0) / ((xi0 - xi) *(xi0 - xi2)* (xi0 - xi1)) + ((x - xi0) * (x - xi1) *(x - xi2)* fxi) / ((xi - xi1) * (xi - xi0)* (xi - xi2)) + ((x - xi0) * (x - xi) *(x - xi2)* fxi1) / ((xi1 - xi0) * (xi1 - xi)*(xi1 - xi2)) + ((x - xi) * (x - xi1) * (x - xi0) * fxi2) / ((xi2 - xi) *(xi2 - xi0)* (xi2 - xi1));
    return ret;
}
int main()
{
    int n=7;
    int i;
    double x[n];
    double fx[n];

    x[0]=-1.5;
    x[1]=-1.0;
    x[2]=-0.5;
    x[3]= 0;
    x[4]= 0.5;
    x[5] = 1;
    x[6]= 1.5;
    for(i = 0; i < n; i++)
    {
        fx[i] = 1.0 / (sqrt(1.0 + x[i]*x[i]));
    }
    double q;
    scanf("%lf", &q);
    int l = -1, m = -1;
    for(i = 0; i < n - 1; i++)
    {
        if(x[i] <= q && q <= x[i + 1])
        {
            l = i;
            m = i + 1;
            break;
        }  
    } 
    int r = m + 1;
    if(m == n - 1)
    {
        l = n - 3;
        m = n - 2;
        r = n - 1;
    }
    double ans = quadratic(q, x[l], x[m], x[r], fx[l], fx[m], fx[r]);
    printf("%lf\n", ans);    
    
    int l1, l2, l3, l4;
    for(i = 0; i < n - 3; i++)
    {
        if((x[i + 1] <= q && q <= x[i + 2]) ||(x[i + 2] <= q && q <= x[i + 3]))
        {
            l1 = i;
            l2 = i + 1;
            l3 = i + 2;
            l4 = i + 3;
            break;
        }  
    }
    double ans2 = cubic(q, x[l1], x[l2], x[l3], x[l4], fx[l1], fx[l2], fx[l3], fx[l4]);
    printf("%lf\n", ans2);
    
}

