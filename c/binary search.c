#include<stdio.h>
int bsearch(int arr[],int s,int l,int h)
{
   while(l<h)
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
  int arr[100],i,s,n,r;
  printf("enter the size of array:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("enter num%d:",i+1);
      scanf("%d",&arr[i]);
    }
  printf("enter the number to be search:");
  scanf("%d",&s);
  r=bsearch(arr,s,0,n-1);
  if(r==1)
    printf("%d is not found",s);
  else
    printf("%d is found at index %d(position :%d)",s,r,r+1);
  return 0;
}
