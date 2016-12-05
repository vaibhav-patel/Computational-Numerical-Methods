#include<stdio.h>
#include<math.h>
const double e=M_E;   //VALUE OF e
const double eps=0.000001; // STOPPING CRITERIA

int main()
{
    int    len=4;
    double x[len];   
    double fx[len];
    
    // we can comment this portion out and can take input from standard in  
    
    // this is generalized implementation of 
            // NEWTON'S DIVIDED DIFFERENCE
    x[0]=1.4;
    x[1]=1.6;
    x[2]=1.8;
    x[3]=2.0;

    fx[0]=0.9192;    
    fx[1]=0.9452;
    fx[2]=0.9641;
    fx[3]=0.9772;
    
    len--;
    int i=0;
    
    
    //FIRST LAYER OF DIVIDED DIFFERENCE
    double fx2[len];
    for(;i<len;i++)
    {
        fx2[i]=(fx[i+1]-fx[i])/(x[i+1]-x[i]);
        printf("fx2  %d %d    %lf\n",i,i+1,fx2[i]);
    }
    
    len--;
    double fx3[len];
    i=0;
    //SECOND LAYER OF DIVIDED DIFFERENCE
    for(;i<len;i++)
    {
        fx3[i]=(fx2[i+1]-fx2[i])/(x[i+2]-x[i]);
        printf("fx3  %d %d  %d  %lf     %lf %lf\n",i,i+1,i+2,fx2[i+1],fx2[i],fx3[i]);
    }
    
    len--;
    //THIRD LAYER OF DIVIDED DIFFERENCE
    double fx4[len];
    i=0;
    for(;i<len;i++)
    {
        fx4[i]=(fx3[i+1]-fx3[i])/(x[i+3]-x[i]);
        printf("fx4   %lf     %lf %lf\n",fx3[i+1],fx3[i],fx3[i]);
    }

    // for finding f(1.65)
    
    double ans=0,query;
    scanf("%lf",&query);  //GIVE YOUR INPUT
    
    ans=fx[0] + (query - x[0])*(fx2[0]) + (query-x[0])*(query-x[1])*fx3[0] + (query-x[0])*(query-x[1])*(query-x[2])*fx4[0] ; //CALCULATING ANSWER USING NEWTON'S METHOD
    
    printf ("answer   ==  for query  %lf    is %lf  \n",query,ans);

    
}

