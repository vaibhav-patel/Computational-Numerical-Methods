#include<stdio.h>
#include<math.h>
const double e=M_E;
const double eps=0.000001;
/*
1.4
1.6
1.8
2.0
𝑦(𝑋𝑖)
*/

double finddivider()
{

} 

int main()
{
    int n=0;
    printf("Enter the number of input points   ");
    scanf("%d",&n);
    printf("\n");
    int i;
    printf("Enter the values of x and fx");
    
    double x[n];
    double fx[n];
    for(i=0;i<n;i++)
    {
        printf("enter x(%d)   ", i);
        scanf("%lf",&x[i]);
        printf("      enter fx(%lf)   ", x[i]);
        scanf("%lf",&fx[i]);
        printf("\n");
    }
    /*
    x[0]=1.4;
    x[1]=1.6;
    x[2]=1.8;
    x[3]=2.0;

    fx[0]=0.9192;
    fx[1]=0.9452;
    fx[2]=0.9641;
    fx[3]=0.9772;
    */
    
    double divs[n][n];
    for (i=0;i<n;i++)
    {
        divs[0][i]=fx[i];
    }
    
    for(i=1;i<n;i++)
    {
        int j;
        for(j=0;j<n-i;j++)
        {
            divs[i][j]= (divs[i-1][j+1]-divs[i-1][j])/(x[j+i]-x[j]);
            printf("divs  %lf     %lf    %lf  %lf    %lf     %d   %d \n",divs[i][j],divs[i-1][j+1],divs[i-1][j],x[j+i],x[j],i,j);
        }
    }
    
    
    //now interpolating
    
    double q=0;
    printf("Enter query   ");
    scanf("%lf",&q);
    
    double mult[n-1];
    mult[0]=q-x[0];
    for(i=1;i<n-1;i++)
    {
        mult[i]=mult[i-1]*(q-x[i]);
    }
    
    double ans=fx[0];
    for(i=1;i<n;i++)
    {
        ans+= (divs[i][0] *mult[i-1]);
    }
    printf("%lf \n",ans);

        
}

