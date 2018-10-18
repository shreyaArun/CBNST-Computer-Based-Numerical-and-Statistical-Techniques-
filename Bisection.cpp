#include<iostream>
#include<math.h>
using namespace std;

inline double fn(double x, int a[], int n)
{
    int i;
    double res=0;
    for(i=0;i<=n;i++)
        res=res+pow(x,i)*a[i];
    return (res);
}

void input_eqn(int n, int a[])
{
    int i ;
    for(i=n;i>=0;i--)
    {
        cout<<"Enter Cofficient of degree "<<i<<" : ";
        cin>>a[i];
    }
}


int main()
{
    double a,b,fa,fb,x,fx;
    int I,i,n;
    cout<<"Enter Highest degree of Equation : ";
    cin>>n;
    int arr[n+1];
    input_eqn(n,arr);
    cout<<"Enter Range a & b :";
    cin>>a>>b;
    fa=fn(a,arr,n);
    fb=fn(b,arr,n);
    if(fb<0 && fa>0)
    {
        swap(a,b);
    }
    cout<<"Enter Number of Iterations: ";
    cin>>I;
    i=I;
    for(;I>0;I--)
    {
        x=(double)(a+b)/2;
        fx=fn(x,arr,n);
        if(fx==0)
        {
            break;
        }
        else if(fx>0)
        {
            b=x;
        }
        else
        {
            a=x;
        }
        cout<<"\nIteration "<<i-I+1<<" is "<<x;
    }
    cout<<"\n\nRoot is "<<x<<"\n";
    return 0;
}
