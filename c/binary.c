#include<stdio.h>
int main()
{
  int arr[20],n,i;
  printf("enter the number:");
  scanf("%d",&n);
  for(i=0;n>0;i++)
    {
      arr[i]=n%2;
      n=n/2;
    }
  for(i--;i>=0;i--)
    {
      printf("%d \t",arr[i]);
    }
    printf("\n");
    return 0;
}
