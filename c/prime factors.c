#include<stdio.h>
int pfactor(int num);

int main()
{
    int a;
    printf("enter a number:\n");
    scanf("%d",&a);
    printf("The prime factors:\n");
    pfactor(a);
    return 0;
}

int pfactor(int num)
{
    int i=2,j;
    while(num!=0)
    {
        if(num%i==0)
        {
            printf("%d\n",i);
            num=num/i;
        }
        else
            i++;
    }
    return 0;
}
