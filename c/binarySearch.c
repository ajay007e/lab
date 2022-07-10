#include<stdio.h>
#include<stdlib.h>
int i,s,n,r,*arr;
int bSearch(int s,int l,int h)
{
   while(l<=h)
   {
       int  m=l+(h-l)/2;
        if(s==arr[m])
          return m;
        if(s>arr[m])
          l=m+1;
        else
          h=m-1;
   }
   return 1;
}
int main()
{
  printf("Enter the size:");
  scanf("%d",&n);
  arr = (int *) malloc(n * sizeof(int));
  printf("Enter the number in increasing order..!\n");
  for(i=0;i<n;i++)
    {
      printf("Enter num%d:",i+1);
      scanf("%d",&arr[i]);

    }
  printf("Enter the number to be search:");
  scanf("%d",&s);
  r=bSearch(s,0,n-1);
  if(r==1)
    printf("%d is not found",s);
  else
    printf("%d is found at position %d",s,r+1);
  return 0;
}
