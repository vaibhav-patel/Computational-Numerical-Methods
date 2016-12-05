#include<stdio.h>
#include<math.h>
const double e=M_E;  //VALUE OF e
const double eps=0.000001;   // STOPPING CRITERIA
double ans[2][2];
// for calculating f1(x)
double f1xy(double x,double y)
{
    return x*x+x*y+y*y-7;
}

// for calculating f2(x)
double f2xy(double x,double y)
{
    return x*x*x+y*y*y-9;
}

// for calculating f1'(x)
double f1dx(double x,double y)
{
    return 2*x+y;
}

// for calculating f1'(Y)
double f1dy(double x,double y)
{
    return 2*y+x;
}

// for calculating f''(x)
double f2dx(double x,double y)
{
    return 3*x*x;
}


// for calculating f''(Y)
double f2dy(double x,double y)
{
    return 3*y*y;
}



//INVERSE OF THE 2D MATRIX
void inverse (double x,double y)
{
    double div1;
    div1= f1dx(x,y)*f2dy(x,y) - f1dy(x,y)*f2dx(x,y);

    ans[0][0]=f2dy(x,y)/div1;
    ans[1][1]=f1dx(x,y)/div1;
    ans[0][1]=-f1dy(x,y)/div1;
    ans[1][0]=-f2dx(x,y)/div1;
}


int main()
{
    int itr=4; //4 ITERATIONS AS PER THE LAB MANUAL
    double xs[itr];    
    double ys[itr];    
    xs[0]=1.5;
    ys[0]=0.5;
    
    int j=1;
    for (;j<=itr-1;j++)
    {
        inverse(xs[j-1],ys[j-1]);  // INVERSE OF THE MATRIX
        xs[j]=xs[j-1] - ans[0][0]*f1xy(xs[j-1],ys[j-1]) -ans[0][1]*f2xy(xs[j-1],ys[j-1]);    //JACOBI ITERATION UPDATE 
        ys[j]=ys[j-1] - ans[1][0]*f1xy(xs[j-1],ys[j-1]) -ans[1][1]*f2xy(xs[j-1],ys[j-1]);    //JACOBI ITERATION UPDATE
        
        // stopping method if error is less than eps
        double f1t=xs[j]-xs[j-1];
        double f2t=ys[j]-ys[j-1];
        
        
        // FINDING ABSOLUTE VALUE
        if(f1t<0) f1t=f1t*-1;
        if(f2t<0) f2t=f2t*-1;
        
        //MINIMUM OF THE F1 AND F2
        double mini=f1t;
        if(f2t<f1t)
        mini=f2t;
        
        double s1t=f1xy(xs[j],ys[j]);
        if(s1t<0) s1t=s1t*-1;
        
        double s2t=f2xy(xs[j],ys[j]);
        if(s2t<0) s2t=s2t*-1;
        
        //STOPPING POINT
        if(mini+s1t+s2t<=eps)
            break;
    }
    
 printf("x= %lf     y=%lf    and no of iterations = %ld\n",xs[j-1],ys[j-1],j);   
      
    return 0;
}
