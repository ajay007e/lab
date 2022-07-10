#include<stdio.h>
int main()
{
  int num[100],i,n,s,p=0;
  printf("Enter number of values :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("enter num%d:",i+1);
    scanf("%d",&num[i]);
  }
  printf("Enter the number to be search :");
  scanf("%d",&s);
  for(i=0;i<n;i++)
  {
    if(s==num[i])
        {
         p=1;
         break;
        }
  }
  if(p==1)
     printf("%d is found at position %d\n",s,i+1);
  else
      printf("%d is not found..!\n",s);
  return 0;
}
