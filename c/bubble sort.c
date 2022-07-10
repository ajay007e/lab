#include<stdio.h>
void sort(int arr[],int n);

int main()
{
  int arr[100],i,s,n,r;
  printf("enter the size of array:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("enter arr%d:",i+1);
      scanf("%d",&arr[i]);
    }
  sort(arr,n);
  return 0;
}

void sort(int arr[],int n)
{
  int i,s,r;
  for(i=0;i<n-1;i++)
    {
      for(s=0;s<n-i-1;s++)
      {
        if(arr[s]>arr[s+1])
          {
           r=arr[s];
           arr[s]=arr[s+1];
           arr[s+1]=r;
          }
      }
    }
  printf("Sorted list :\n");
  for(i=0;i<n;i++)
  {
    printf("%d\n",arr[i]);
  }
}
