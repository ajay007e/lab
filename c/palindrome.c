#include<stdio.h>
int main()
{
  char a[100];
  int i,k;
  printf("Enter the string:");
  scanf("%[^\n]%*c",a);
  int j = strlen(a);
  for(i=0;i<j;i++)
  {
    if(a[j-1]!=a[i])
      {
        k=1;
        break;
      }
    j--;

  }
  for(i=0;i<j;i++)
  {

  }
  if(k==1)
    {
      printf("%s is palindrome",a);
    }
  else
    {
      printf("%s is not a palindrome",a);
    }
  return 0;
}
