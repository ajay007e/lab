#include<stdio.h>

int data(int m[][10],int r ,int c);
int add(int m1[][10],int m2[][10],int s[][10],int r,int c);
int display(int m[][10],int r,int c);
int multiply(int m1[][10],int m2[][10],int s[][10],int r1,int c1,int c2);
int transpose(int m[][10],int l[][10],int r,int c);
int main()
{
  int a[10][10],b[10][10],l[10][10],r,c,s,r1,c1;
  printf("Enter 1 for addition\n");
  printf("Enter 2 for multipilcation\n");
  printf("Enter 0 for transpose\n");
  scanf("%d",&s);
  switch(s)
  {
    case 1:
      printf("Enter row and column:\n");
      scanf("%d%d",&r,&c);
      printf("\nEnter matrix 1\n");
      data(a,r,c);
      printf("\nEnter matrix 2\n");
      data(b,r,c);
      add(a,b,l,r,c);

      display(l,r,c);
      break;
    case 2:
      printf("Enter row and column of matrix 1:\n");
      scanf("%d%d",&r,&c);
      printf("Enter row and column of matrx 2:\n");
      scanf("%d%d",&r1,&c1);
      while(c!=r1)
      {
        printf("Erorr..!!");
        printf("Enter row and column of matrix 1:\n");
        scanf("%d%d",&r,&c);
        printf("Enter row and column of matrx 2:\n");
        scanf("%d%d",&r1,&c1);
      }
      printf("\nEnter matrix 1\n");
      data(a,r,c);
      printf("\nEnter matrix 2\n");
      data(b,r1,c1);
      multiply(a,b,l,r,c,c1);
      display(l,r,c1);
      break;
    case 0:
      printf("Enter row and column:\n");
      scanf("%d%d",&r,&c);
      printf("\nEnter matrix \n");
      data(a,r,c);
      transpose(a,l,r,c);
      display(l,c,r);
      break;
    default:
      printf("Error..!!\nProgramme Exiting..!");
  }
  return 0;
}

int data(int m[][10],int r,int c)
{
  int i,j;;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      printf("Enter a%d%d\n",i+1,j+1);
      scanf("%d",&m[i][j]);
    }
  }
  printf("\nMatrix\n");
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      printf("%d  ",m[i][j]);
      if(j==c-1)
        printf("\n");
    }
  }
  return 0;
}

int add(int m1[][10],int m2[][10],int s[][10],int r,int c)
{
  int i,j;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    s[i][j]=m1[i][j]+m2[i][j];
  }
  return 0;
}

int display(int m[][10],int r,int c)
{
  int i,j;
  printf("\nResult Matrix\n");
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      printf("%d  ",m[i][j]);
      if(j==c-1)
        printf("\n");
    }
  }

  return 0;
}

int multiply(int m1[][10],int m2[][10],int s[][10],int r1,int c1,int c2)
{
  int i,j,k;
  for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            for (int k = 0; k < c1; ++k)
            {
                s[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return 0;
}

int transpose(int m[][10],int l[][10],int r,int c)
{
  int i,j;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
       l[j][i]=m[i][j];
    }
  }
  return 0;
}
