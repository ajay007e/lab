#include<stdio.h>
int main()
{
  char a[50],b[50];
  int i,l;
  printf("Enter string 1 :");
  scanf("%[^\n]%*c",a);
  printf("Enter string 2 :");
  scanf("%[^\n]%*c",b);
  l=strlen(a);
  for(i=0;b[i]!='\0';i++)
  {
    a[l+i]=b[i];
  }
  a[l+i]='\0';
  printf("%s",a);
  return 0;
}
