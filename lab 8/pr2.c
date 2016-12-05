#include<stdio.h>
#include<math.h>
const double e=M_E;
const double eps=0.000001;

double fx(double x)
{
    return atan(100*x*x -199*x+100);
}
int fact(int i)
{
   int ans=1;
   int j=0;
   for(j=0;j<i;j++)
   {
        ans=ans*(j+1);
   }
   return ans;
}
void taylor(double *arr,int len,double h)
{ 
    int i;
    for(i=0;i<len;i++)
    {
        arr[i]=pow(h,i)/(fact(i)*1.0);
    }
    
}
int main()
{
    
    int n;
    scanf("%d",&n);
    double ah[n], b[n];
    int i, j;
    for(i = 0; i < n; i++) scanf("%lf",&ah[i]);
    for(i = 0; i < n; i++) scanf("%lf",&b[i]);
    double coeff[n][n];
    for(i = 0; i < n; i++)
    {
        taylor(coeff[i], n, ah[i]);
    }
    //for(i = 0; i < n; i++) {for(j = 0; j < n; j++) {printf("%lf ",coeff[i][j]);} printf("\n");}
    
    
}

