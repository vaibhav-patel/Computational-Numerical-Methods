void taylor(double *arr,int len,double h)
{ 
    int i;
    for(i=0;i<len;i++)
    {
        arr[i]=(h^i)/(factorial(i));
    }
    
}