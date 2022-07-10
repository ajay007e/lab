#include<stdio.h>
int leap(int);

int main()
{
  int y,r;
  printf("Enter a year:");
  scanf("%d",&y);
  r=leap(y);
  if(r)
    printf("%d is a leap year",y);
  else
    printf("%d is not a leap year",y);

  return 0;
}

int leap(int year)
{
  int r=0;
  if((year%4==0)&&(year%100!=0)||(year%400==0))
    r=1;
  return r;
}
