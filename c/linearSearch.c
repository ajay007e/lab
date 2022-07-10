#include<stdio.h>
int main()
{
  int i,n,s,p=0;
  printf("Enter Size :");
  scanf("%d",&n);
  int num[n];
  for(i=0;i<n;i++)
  {
    printf("enter num%d:",i+1);
    scanf("%d",&num[i]);
  }
  while(!p)
  {
    printf("Enter the number to be search :");
    scanf("%d",&s);
    for(i=0;i<n;i++)
    {
        if(s==num[i])
        {
            if(i!=0)
                num[i-1] = num[i]+num[i-1]-(num[i]=num[i-1]);
            p=1;
            break;
        }
    }
    if(p==1)
        printf("%d is found at position %d\n",s,i+1);
    else
        printf("%d is not found..!\n",s);
    printf("\nDo you want search again?\nEnter 0 for Continue\nEnter any number to Exit\n");
    scanf("%d",&p);
  }
  return 0;
}
