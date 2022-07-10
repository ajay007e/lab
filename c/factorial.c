#include<stdio.h>
int factorial(int num);

int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    int f=factorial(a);
    printf("Factorial of %d is %d",a,f);
    return 0;
}

int factorial(int num)
{
    int i,f=1;
    for(i=1;i<=num;i++)
    {
        f*=i;
    }
    return f;
}
