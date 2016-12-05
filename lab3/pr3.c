#include<stdio.h>
#include<math.h>
const double e=M_E;
const double eps=0.000001;
double coeff[3][3];
double coeff2[2][2];

double b[3];
double b2[2];



// for calculating f(x)
double f1(double x1,double x2,double x3,double eff[3],double bp)
{
    return eff[0]*x1+eff[1]*x2+eff[2]*x3-bp;
}





int main()
{
    //IMPLEMENTED GAUSSIAN ELIMINATION METHOD IN C
    // VERY FAST AND EFFICIENT TO IMPLEMENT IN MATLAB
    //HAVE TO WRITE MATRIX INVERSE(SORT OF CODE) IN C 
    //THAT'S  WHY WHOLE FUNCTION IS HARDCODED
    coeff[0][0]=10;
    coeff[0][1]=-1;
    coeff[0][2]=2;
    b[0]=4;
    
    coeff[1][0]=1;
    coeff[1][1]=10;
    coeff[1][2]=-1;
    b[1]=3;
    
    coeff[2][0]=2;
    coeff[2][1]=3;
    coeff[2][2]=20;
    b[2]=7;
    
    
    coeff2[0][0] = (coeff[0][0]*coeff[1][2])/coeff[0][2]   - coeff[1][0]  ;
    coeff2[0][1] = (coeff[0][1]*coeff[1][2])/coeff[0][2]   - coeff[1][1]  ;
    
    b2[0] = (b[0]*coeff[1][2])/coeff[0][2]  - b[1] ;
    
    
    coeff2[1][0] = (coeff[1][0]*coeff[2][2])/coeff[1][2]   - coeff[2][0]  ;
    coeff2[1][1] = (coeff[1][1]*coeff[2][2])/coeff[1][2]   - coeff[2][1]  ;
    b2[1] = (b[1]*coeff[2][2])/coeff[1][2]  - b[2] ;
    
    double a1=coeff2[0][0];
    double b1=coeff2[0][1];
    double a2=coeff2[1][0];
    double bb=coeff2[1][1];
    
    double c1=b2[0];  
    double c2=b2[1];
    
    double x1= ((c1*bb)/b1-c2)/((bb*a1)/b1-a2); 
    double x2= (c1-a1*x1)/b1; 
    double x3=(b[0]-coeff[0][0]*x1-coeff[0][1]*x2)/coeff[0][2];
    
    
    printf("x1= %lf     x2= %lf   x3= %lf \n",x1,x2,x3);   
      
    return 0;
}
