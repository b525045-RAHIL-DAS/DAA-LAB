#include <stdio.h>
#include <math.h>

int main()
{
    double n = 1024.0;

    double f1 = n * log2(n);            
    double f2 = 12*pow(n, 0.5);           
    double f3 = 1.0 / n;                
    double f4 = pow(n,log2(n));                
    double f5 = (100)*n*n + 6*n;
    double f6 = pow(n,0.51);
    double f7 = pow(n,2) - 324;
    double f8 = 50*sqrt(n);
    double f9 = 2*pow(n,3);
    double f10 = pow(3,n);
    double f11 = pow(2,32)*n;
    double f12 = log2(n);

    char *name[] =
    {
        "n log2 n",
        "12*n^0.5",
        "1/n",
        "n^log2 n",
        "100*n^2 + 6n",
        "n^0.51",
        "n^2 -324",
        "50sqrt(n)",
        "2*n^3",
        "3^n",
        "2^32 * n",
        "log2 n"
    };

    double value[] =
    {
        f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12
    };

    int size=12;

    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(value[j]>value[j+1])
            {
                double temp=value[j];
                value[j]=value[j+1];
                value[j+1]=temp;

                char *t=name[j];
                name[j]=name[j+1];
                name[j+1]=t;
            }
        }
    }

    printf("Increasing Order of Growth (for n = %.0lf)\n\n",n);

    for(int i=0;i<size;i++)
    {
        printf("%d. %s %lf\n",i+1,name[i],value[i]);
    }

    return 0;
}