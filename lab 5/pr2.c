
// THIS IS GENERALIZED
// ONE CAN EVEN CHANGE LEN OF THE INPUT ARRAY#include<stdio.h>
#include<stdio.h>
#include<math.h>
const double e=M_E;   //VALUE OF e
const double eps=0.000001; // STOPPING CRITERIA



int main()
{

    int n=0;
    int i;
 
    
    double x[n];
    double fx[n];

        // we can comment this portion out and can take input from standard in  
    
    // this is generalized implementation of 
            // NEWTON'S FORWARD DIFFERENCE
     i=0;
    double mul=-1;
    
    //just the way we are finding the value of the function
    for(i=0;i<n;i++)
    {
        x[i]=mul;
        mul+=0.2;
        fx[i]=exp(mul);
    }

    

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
        }
    }
    
    
    
    double q=0;
  scanf("%lf",&q);
    
  
  int k=0;
 double st=-1; 
     //FINDING QUERY ANSWER USING THIS IMPLEMENTATIONS
  for (;k<1000;k++)
   {
   q=st;
    double ans=fx[0];
    double mult=1.0;
     double fact=1.0;
    for(i=1;i<n;i++)
    {
        mult *=  ((q-x[i-1])/h);
        mult/=fact;
        ans+= (divs[i][0] * mult);
       fact*=(i+1);
    }
    printf("%lf ;\n",ans);
    st+=0.002;
}
        
}

