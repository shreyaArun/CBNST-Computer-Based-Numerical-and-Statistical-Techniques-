#include<stdio.h>
#include<math.h>

float nebula(float y[], int d, int c,int val) // y->Array    d-> till where loop will run    c-> Counter     val->index of array to be returned
{
    if(d==c)
        return (y[val]);
    else
        return (nebula(y,d,c-1,val)-nebula(y,d,c-1,val-1));
}

int main()
{
    int i,j,n;
    float N,D,u,h,y,x,sum=0;
    FILE *fp;
    fp=fopen("NBIM.txt","r");
    //printf("Enter number of terms to enter: ");
    fscanf(fp,"%d",&n);
    float X[n],Y[n];
    for(i=0;i<n;i++)
    {
        //printf("Enter X[%d] & Y[%d] : ",i,i);
        fscanf(fp,"%f %f",&X[i],&Y[i]);
        printf("%f %f\n",X[i],Y[i]);
    }
    fclose(fp);
    printf("Enter value of x: ");
    scanf("%f",&x);
    h=X[1]-X[0];
    u=(float)(x-X[n-1])/h;
    printf("h = %f\nu = %f\n",h,u);
    for(i=0;i<n;i++)
    {
        N=1;
        D=1;
        for(j=1;j<=i;j++) // 0!, 1!, 2!, 3!, ...
        {
            D=D*j;
        }
        for(j=1;j<=i;j++) // 1, u, u*(u+1), u*(u+1)*(u+2), ...
        {
            N=N*(u+j-1);
        }
        y=nebula(Y,n-1-i,n-1,n-1); // yn, \/yn, \/^2 yn, \/^3 yn, ...
        //printf("%f\t",y);
        y=(float)((N*y)/D);
        sum=sum+y;
        //printf("%f\n",y);
    }
    printf("Y[%f] = %f",x,sum); // OUTPUT
    return 0;
}
