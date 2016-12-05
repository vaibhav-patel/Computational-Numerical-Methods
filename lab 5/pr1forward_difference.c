// THIS IS GENERALIZED
// ONE CAN EVEN CHANGE LEN OF THE INPUT ARRAY

#include<stdio.h>
#include<math.h>
const double e=M_E;   //VALUE OF e
const double eps=0.000001; // STOPPING CRITERIA
double finddivider()
{

} 

int main()
{
    printf("forward difference ::\n");
    int n=5;
    int i;
  
    double x[n];
    double fx[n];

        // we can comment this portion out and can take input from standard in  
    
    // this is generalized implementation of 
            // NEWTON'S FORWARD DIFFERENCE
    x[0]=.1;
    x[1]=.2;
    x[2]=.3;
    x[3]=.4;
    x[4]=.5;
    

    fx[0]=0.09983;
    fx[1]=0.19867;
    fx[2]=0.29552;
    fx[3]=0.38942;
    fx[4]=0.47943;

    double h=x[1]-x[0];
    double divs[n][n];
    //FIRST LAYER
    for (i=0;i<n;i++)
    {
        divs[0][i]=fx[i];
    }
    
    
    // FINDING FORWARD DIFFERENCE IN A LOOP
    for(i=1;i<n;i++)
    {
        int j;
        for(j=0;j<n-i;j++)
        {
            divs[i][j]= (divs[i-1][j+1]-divs[i-1][j]);
            printf("divs  %lf     %lf    %lf  %lf    %lf     %d   %d \n",divs[i][j],divs[i-1][j+1],divs[i-1][j],x[j+i],x[j],i,j);
        }
    }
    
    
    //now interpolating
    double q=0;
    printf("Enter query   ");
    scanf("%lf",&q);
    
   
    double ans=fx[0];
    double mult=1.0;
    double fact=1.0;
    
    //FINDING QUERY ANSWER USING THIS IMPLEMENTATIONS
    for(i=1;i<n;i++)
    {
        mult *=  ((q-x[i-1])/h);
                printf(" qu   %lf \n",(q-x[i-1]));    
        
        mult/=fact;
        ans+= (divs[i][0] * mult);
        printf(" div %lf \n",(divs[i][0] ));
        fact*=(i+1);
    }
    
    printf("%lf \n",ans);

        
}
