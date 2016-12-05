#include<stdio.h>
#include<math.h>
const double e=M_E;
const double eps=0.000001;


int main()
{
    int n=7;
  /*  printf("Enter the number of input points   ");
    scanf("%d",&n);
    printf("\n");
    printf("Enter the values of x and fx");
*/  
    int i;  
    double x[n];
    double fx[n];
   /* for(i=0;i<n;i++)
    {
        printf("enter x(%d)   ", i);
        scanf("%lf",&x[i]);
        printf("      enter fx(%lf)   ", x[i]);
        scanf("%lf",&fx[i]);
        printf("\n");
    }*/
   
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
         //   printf("divs  %lf     %lf    %lf  %lf    %lf     %d   %d \n",divs[i][j],divs[i-1][j+1],divs[i-1][j],x[j+i],x[j],i,j);
        }
    } 
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
    printf("Divided difference method is slow but it is more accurate. Any of the cubic or quadratic piecewise linear may be better. It acutally depends on function. In this example quadratic one is good\n");   
}

